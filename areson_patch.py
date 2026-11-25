# areson_patch.py — 给原版 Areson Mouse Test 2.023 打二进制补丁 → 8K Pro 版
# 原理（逆向结论，见 ANALYSIS.md）：
#   ① 1K 上限根因一：速率 = 1500ms 窗内事件数 × 2/3，环 2000 格 → 上限 1333Hz
#      → 改为 200ms 窗 × 5（环 2000 格 ≥ 8K×0.2s=1600 事件，上限 10000Hz）
#   ② 根因二：时间戳 (QPC×1000)/QPF 截断为整毫秒，8K 间隔 125µs 不可分辨
#      → 乘数改 ×1000000，µs 分辨率（32 位回绕安全：只比较 <200ms 差值）
#   ③ 注册 {page1,usage0,flags0x20} 经实测 Win11 接受 → 不动注册代码
# 全部为等长字节替换，模式在文件中唯一，PE checksum=0 无需修复。
import sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

SRC = r"D:\12-AI\0-rea\exe2c\Areson Mouse Test  2.023.exe"
DST = r"D:\12-AI\0-rea\pollrate\Areson Mouse Test Pro 8K.exe"

PATCHES = [
    # (名, 偏移, 原字节, 新字节)
    ("P1 时间戳 ms->us (push 1000 -> push 1000000)",
     0x6058,
     bytes.fromhex("68E8030000"),
     bytes.fromhex("6840420F00")),
    ("P2 速率窗 1500ms→200ms (cmp edi,0x5DC→0x30D40=200000us)",
     0x7449,
     bytes.fromhex("81FFDC050000"),
     bytes.fromhex("81FF400D0300")),
    ("P3 换算 ×2/3→×5 (lea edx,[edx+edx*4]+nop)",
     0x745D,
     bytes.fromhex("8D0C12B856555555F7E9"),
     bytes.fromhex("8D149290909090909090")),
    ("P5 标题 Pro 化",
     0x1859C,
     b"Mouse Test by Areson - %s\x00",
     b"Areson Mouse Test Pro %s\x00\x00"),
    # P6: WM_INPUT 零位移检查(8B)改跳 cave —— 模式门控入口
    # cave: [0x41efc4]==0(默认,BSS零初始化)→全报文直接写环; ==1→原位移判断
    # 0x41efc4 由原程序 'B' 键切换(xor dword,0x41efc4,1)且全程序无其他读者(零副作用)
    ("P6 零位移检查→cave 门控 (jmp 0x414A92)",
     0x127E8,
     bytes.fromhex("85F6750485FF7429"),
     bytes.fromhex("E9A5220000" + "909090")),
    ("P7 cave: B 键模式门控 (全报文默认/仅位移)",
     0x14A92,
     bytes.fromhex("00" * 0x27),
     # +00 cmp dword [0x41efc4],0 ; +07 jne +14 ; +09 jmp 0x4127F0(写环)
     # +14 test esi,esi ; +16 jnz +22 ; +18 test edi,edi ; +1A jnz +22
     # +1C jmp 0x412819(跳过) ; +22 jmp 0x4127F0(写环)
     bytes.fromhex(
         "83 3D C4 EF 41 00 00"   # +00 cmp dword [0x41efc4],0
         "75 0B"                  # +07 jne do_check(+14)
         "E9 50 DD FF FF"         # +09 jmp 0x4127F0  全报文→写环
         "90 90 90 90 90 90"      # +0E nop×6
         "85 F6"                  # +14 test esi,esi
         "75 0A"                  # +16 jnz +22
         "85 FF"                  # +18 test edi,edi
         "75 06"                  # +1A jnz +22
         "E9 66 DD FF FF"         # +1C jmp 0x412819  仅位移→两者皆零则跳过
         "90"                     # +21
         "E9 37 DD FF FF"         # +22 jmp 0x4127F0  有位移→写环
     ), "skip_unique"),
    ("P8 .text VirtualSize 0x13A92→0x14000 (保证 cave 映射)",
     0x1E8,
     (0x13A92).to_bytes(4, "little"),
     (0x14000).to_bytes(4, "little")),
    ("P9 模式切换键 B→D (cmp eax,0x42→0x44)",
     0x6105,
     bytes.fromhex("83F842"),
     bytes.fromhex("83F844")),
    ("P10 右下角版本格式 Ver. %s → ver %s",
     0x18910,
     b"Ver. %s\x00",
     b"ver %s\x00\x00"),
    ("P11 版本串 2.0.23 → pro 1.0",
     0x18918,
     b"2.0.23\x00\x00",
     b"pro 1.0\x00"),
    ("P12 旁路格式串去版本号（原 0x1859C，非标题本体）",
     0x1859C,
     b"Areson Mouse Test Pro %s\x00\x00",
     b"Areson Mouse Test Pro\x00\x00\x00\x00\x00"),
    ("P13 真窗口标题 0x18584 Mouse Test by Areson → Areson Mouse Test Pro",
     0x18584,
     b"Mouse Test by Areson\x00\x00\x00\x00",
     b"Areson Mouse Test Pro\x00\x00\x00"),
]

def main():
    data = bytearray(open(SRC, "rb").read())
    ok = True
    for i, entry in enumerate(PATCHES):
        name, off, old, new = entry[0], entry[1], entry[2], entry[3]
        skip_unique = len(entry) > 4 and entry[4] == "skip_unique"
        if len(old) != len(new):
            print(f"[FATAL] {name}: 长度不等 {len(old)} vs {len(new)}")
            ok = False
            continue
        # 唯一性断言（可跳过——如 cave 写入全零区无法唯一化，只校验偏移内容）
        if not skip_unique:
            cnt = bytes(data).count(old)
            if cnt != 1:
                print(f"[FATAL] {name}: 模式出现 {cnt} 次（期望 1）")
                ok = False
                continue
        if bytes(data[off:off + len(old)]) != old:
            print(f"[FATAL] {name}: 偏移 {hex(off)} 处字节不匹配")
            ok = False
            continue
        data[off:off + len(new)] = new
        print(f"[OK] {name} @ {hex(off)}")
    if not ok:
        sys.exit(1)
    open(DST, "wb").write(bytes(data))
    print(f"\n写出: {DST} ({len(data)} bytes)")

if __name__ == "__main__":
    main()
