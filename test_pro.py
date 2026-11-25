# test_pro.py — 验证补丁版 Areson Pro：ReadProcessMemory 直读速率全局 0x41f034
# 用法: python test_pro.py <exe路径> <hz> <秒>
import ctypes, subprocess, sys, time, os
from ctypes import wintypes

k = ctypes.windll.kernel32
u = ctypes.windll.user32

PROCESS_VM_READ = 0x0010
PROCESS_QUERY_INFORMATION = 0x0400

RATE_ADDR   = 0x41F034   # 速率显示值（Hz）
REGOK_ADDR  = 0x41EFB4   # 注册成功标志

def read_mem(h, addr):
    buf = ctypes.c_uint32()
    got = ctypes.c_size_t()
    if not k.ReadProcessMemory(h, ctypes.c_void_p(addr),
                               ctypes.byref(buf), 4, ctypes.byref(got)):
        return None
    return buf.value

def find_pid(name):
    out = subprocess.run(['tasklist', '/FI', f'IMAGENAME eq {name}', '/FO', 'CSV'],
                         capture_output=True, text=True).stdout
    for ln in out.splitlines():
        if ln.lower().startswith(f'"{name.lower()}"'):
            return int(ln.split('","')[1])
    return None

def main():
    exe = sys.argv[1] if len(sys.argv) > 1 else r"D:\12-AI\0-rea\pollrate\Areson Mouse Test Pro 8K.exe"
    hz  = int(sys.argv[2]) if len(sys.argv) > 2 else 1000
    secs = sys.argv[3] if len(sys.argv) > 3 else "3"
    name = os.path.basename(exe)

    subprocess.Popen([exe])
    time.sleep(2.5)
    pid = find_pid(name)
    if not pid:
        print("ERROR: process not found"); return 1
    h = k.OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, False, pid)
    if not h:
        print("ERROR: OpenProcess failed"); return 1
    print(f"pid={pid}  reg_ok={read_mem(h, REGOK_ADDR)}  (期望 1)")

    # 基线（空闲）
    time.sleep(0.8)
    print("idle rate:", read_mem(h, RATE_ADDR))

    # 注入并周期采样
    inj = subprocess.Popen([r"D:\12-AI\0-rea\pollrate\injector.exe", str(hz), secs],
                           stdout=subprocess.PIPE, text=True)
    rates = []
    t0 = time.time()
    while inj.poll() is None and time.time() - t0 < float(secs) + 2:
        r = read_mem(h, RATE_ADDR)
        if r is not None:
            rates.append(r)
        time.sleep(0.12)
    print("injector:", inj.stdout.read().strip() if inj.stdout else "")
    rates = [r for r in rates if r]          # 忽略 0（启动爬升/间隙）
    if rates:
        rates_sorted = sorted(rates)
        med = rates_sorted[len(rates_sorted)//2]
        print(f"rate samples: n={len(rates)} median={med} max={max(rates)} "
              f"(target {hz})")
        dev = abs(med - hz) / hz
        print("RESULT:", "PASS" if dev < 0.10 else "FAIL", f"({(med-hz)/hz*100:+.1f}%)")
    else:
        print("RESULT: no nonzero rate samples")

    # 停止后衰减
    for i in range(10):
        time.sleep(0.15)
        r = read_mem(h, RATE_ADDR)
        if i in (2, 5, 9):
            print(f"decay t+{(i+1)*0.15:.1f}s: {r}")
    k.CloseHandle(h)
    k.TerminateProcess(k.OpenProcess(1, False, pid), 0)
    return 0

if __name__ == "__main__":
    sys.exit(main())
