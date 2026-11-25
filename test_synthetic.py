# test_synthetic.py — 端到端自测：以已知频率注入鼠标移动，验证 MouseRate8K 的测量精度
# 用法: python test_synthetic.py [hz] [seconds]
import ctypes, math, glob, os, sys, time
from ctypes import wintypes

u = ctypes.windll.user32
k = ctypes.windll.kernel32

class MOUSEINPUT(ctypes.Structure):
    _fields_ = [('dx', ctypes.c_long), ('dy', ctypes.c_long),
                ('mouseData', ctypes.c_ulong), ('dwFlags', ctypes.c_ulong),
                ('time', ctypes.c_ulong),
                ('dwExtraInfo', ctypes.POINTER(ctypes.c_ulong))]
class _U(ctypes.Union):
    _fields_ = [('mi', MOUSEINPUT)]
class INPUT(ctypes.Structure):
    _fields_ = [('type', ctypes.c_ulong), ('union', _U)]

def send_move(dx, dy):
    inp = INPUT()
    inp.type = 0
    inp.union.mi.dx = dx
    inp.union.mi.dy = dy
    inp.union.mi.dwFlags = 1          # MOUSEEVENTF_MOVE (relative)
    u.SendInput(1, ctypes.byref(inp), ctypes.sizeof(INPUT))

qpc = k.QueryPerformanceCounter
qpf = k.QueryPerformanceFrequency
freq = ctypes.c_longlong()
qpf(ctypes.byref(freq))
FREQ = freq.value

def now_qpc():
    c = ctypes.c_longlong()
    qpc(ctypes.byref(c))
    return c.value

hz = int(sys.argv[1]) if len(sys.argv) > 1 else 1000
secs = float(sys.argv[2]) if len(sys.argv) > 2 else 4.0

hwnd = u.FindWindowW('MouseRate8KWnd', None)
if not hwnd:
    print('ERROR: MouseRate8K window not found'); sys.exit(1)
print(f'hwnd=0x{hwnd:X}  injecting {hz} Hz for {secs}s ...')

csvdir = os.path.dirname(os.path.abspath(__file__))
before = set(glob.glob(os.path.join(csvdir, 'PollingRate_Log_*.csv')))

u.PostMessageW(hwnd, 0x0100, ord('L'), 0)      # WM_KEYDOWN 'L' → 开始日志
time.sleep(0.15)

N = int(hz * secs)
period = FREQ / hz
t0 = now_qpc()
for i in range(N):
    ang = i * (2 * math.pi / 256)              # 小圆圈，回到原点
    dx = int(round(3 * math.cos(ang)))
    dy = int(round(3 * math.sin(ang)))
    tgt = t0 + int(period * (i + 1))
    while now_qpc() < tgt:
        pass
    send_move(dx, dy)
elapsed = now_qpc() - t0
time.sleep(0.25)
u.PostMessageW(hwnd, 0x0100, ord('L'), 0)      # 停止日志（刷盘关闭）
time.sleep(0.4)

print(f'injected {N} moves in {elapsed/FREQ*1000:.1f} ms → actual {N/(elapsed/FREQ):.1f} Hz')

new = set(glob.glob(os.path.join(csvdir, 'PollingRate_Log_*.csv'))) - before
if not new:
    print('ERROR: no new CSV produced'); sys.exit(1)
path = max(new, key=os.path.getmtime)
rows = open(path).read().strip().splitlines()
print(f'CSV: {os.path.basename(path)}  {len(rows)-1} data rows')
dts = []
for ln in rows[1:]:
    f = ln.split(',')
    if len(f) >= 6:
        try: dts.append(float(f[2]))
        except ValueError: pass
if not dts:
    print('ERROR: no dt data'); sys.exit(1)
dts.sort()
mean = sum(dts) / len(dts)
med = dts[len(dts)//2]
p1, p99 = dts[max(0, len(dts)//100)], dts[min(len(dts)-1, len(dts)*99//100)]
print(f'dt_us: mean={mean:.1f} median={med:.1f} p1={p1:.1f} p99={p99:.1f}')
print(f'implied rate: mean={1e6/mean:.1f} Hz  median={1e6/med:.1f} Hz  (target {hz} Hz)')
ok = abs(1e6/med - hz) / hz < 0.03
print('RESULT:', 'PASS' if ok else 'FAIL', f'({(1e6/med - hz)/hz*100:+.2f}% deviation)')
sys.exit(0 if ok else 2)
