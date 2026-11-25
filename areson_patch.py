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
]

def main():
    data = bytearray(open(SRC, "rb").read())
    ok = True
    for name, off, old, new in PATCHES:
        if len(old) != len(new):
            print(f"[FATAL] {name}: 长度不等 {len(old)} vs {len(new)}")
            ok = False
            continue
        # 唯一性断言
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
