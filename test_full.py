# test_full.py — 用 C 注入器 (injector.exe) 做高频率端到端验证
# 用法: python test_full.py <hz> <seconds>
import ctypes, glob, os, subprocess, sys, time

u = ctypes.windll.user32
hz = int(sys.argv[1]) if len(sys.argv) > 1 else 8000
secs = sys.argv[2] if len(sys.argv) > 2 else "3"

here = os.path.dirname(os.path.abspath(__file__))
hwnd = u.FindWindowW('MouseRate8KWnd', None)
if not hwnd:
    print('ERROR: window not found'); sys.exit(1)

before = set(glob.glob(os.path.join(here, 'PollingRate_Log_*.csv')))
u.SetForegroundWindow(hwnd)                    # 让本 app 作前台（SendInput 注入目标队列畅通）
u.PostMessageW(hwnd, 0x0100, ord('X'), 0)      # 锁定 SendInput 注入通道（防物理鼠标抢占）
time.sleep(0.3)
u.PostMessageW(hwnd, 0x0100, ord('L'), 0)
time.sleep(0.2)
r = subprocess.run([os.path.join(here, 'injector.exe'), str(hz), secs],
                   capture_output=True, text=True)
print(r.stdout.strip())
time.sleep(0.3)
u.PostMessageW(hwnd, 0x0100, ord('L'), 0)
u.PostMessageW(hwnd, 0x0100, ord('X'), 0)      # 解锁，恢复自动
time.sleep(0.4)

new = set(glob.glob(os.path.join(here, 'PollingRate_Log_*.csv'))) - before
if not new:
    print('ERROR: no CSV'); sys.exit(1)
path = max(new, key=os.path.getmtime)
rows = open(path).read().strip().splitlines()
dts = []
for ln in rows[1:]:
    f = ln.split(',')
    if len(f) >= 6:
        try: dts.append(float(f[2]))
        except ValueError: pass
if not dts:
    print(f'ERROR: {path} has no data'); sys.exit(1)
dts.sort()
n = len(dts)
mean = sum(dts) / n
med = dts[n // 2]
p5 = dts[n * 5 // 100]
p95 = dts[n * 95 // 100]
print(f'CSV rows={n}')
print(f'dt_us: median={med:.2f} mean={mean:.2f} p5={p5:.2f} p95={p95:.2f} '
      f'min={dts[0]:.2f} max={dts[-1]:.2f}')
print(f'implied: median={1e6/med:.1f} Hz p5={1e6/p95:.1f} Hz p95={1e6/p5:.1f} Hz '
      f'(target {hz} Hz)')
dev = abs(1e6 / med - hz) / hz
print('RESULT:', 'PASS' if dev < 0.05 else 'FAIL', f'({(1e6/med - hz)/hz*100:+.2f}%)')
