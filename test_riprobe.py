# test_riprobe.py — 独立探针：SendInput 注入的事件是否到达 Raw Input (WM_INPUT)？
import ctypes, math, time
from ctypes import wintypes

u = ctypes.windll.user32
k = ctypes.windll.kernel32

WM_INPUT = 0x00FF
RIM_TYPEMOUSE = 0

class WNDCLASSW(ctypes.Structure):
    _fields_ = [('style', ctypes.c_uint), ('lpfnWndProc', ctypes.WINFUNCTYPE(
                    ctypes.c_longlong, wintypes.HWND, ctypes.c_uint,
                    wintypes.WPARAM, wintypes.LPARAM)),
                ('cbClsExtra', ctypes.c_int), ('cbWndExtra', ctypes.c_int),
                ('hInstance', wintypes.HINSTANCE), ('hIcon', wintypes.HICON),
                ('hCursor', wintypes.HANDLE), ('hbrBackground', wintypes.HBRUSH),
                ('lpszMenuName', wintypes.LPCWSTR), ('lpszClassName', wintypes.LPCWSTR)]

class RAWINPUTDEVICE(ctypes.Structure):
    _fields_ = [('usUsagePage', ctypes.c_ushort), ('usUsage', ctypes.c_ushort),
                ('dwFlags', ctypes.c_ulong), ('hwndTarget', wintypes.HWND)]

class RAWINPUTHEADER(ctypes.Structure):
    _fields_ = [('dwType', ctypes.c_ulong), ('dwSize', ctypes.c_ulong),
                ('hDevice', wintypes.HANDLE), ('wParam', wintypes.WPARAM)]

class RAWMOUSE(ctypes.Structure):
    _fields_ = [('usFlags', ctypes.c_ushort), ('ulButtons', ctypes.c_ulong),
                ('ulRawButtons', ctypes.c_ulong), ('lLastX', ctypes.c_long),
                ('lLastY', ctypes.c_long), ('ulExtraInformation', ctypes.c_ulong)]

class RAWINPUT(ctypes.Structure):
    _fields_ = [('header', RAWINPUTHEADER), ('mouse', RAWMOUSE)]

class MOUSEINPUT(ctypes.Structure):
    _fields_ = [('dx', ctypes.c_long), ('dy', ctypes.c_long),
                ('mouseData', ctypes.c_ulong), ('dwFlags', ctypes.c_ulong),
                ('time', ctypes.c_ulong),
                ('dwExtraInfo', ctypes.POINTER(ctypes.c_ulong))]
class _U(ctypes.Union):
    _fields_ = [('mi', MOUSEINPUT)]
class INPUT(ctypes.Structure):
    _fields_ = [('type', ctypes.c_ulong), ('union', _U)]

stats = {'count': 0, 'hdev': set(), 'move': 0, 'flags0': 0}

@ctypes.WINFUNCTYPE(ctypes.c_longlong, wintypes.HWND, ctypes.c_uint,
                    wintypes.WPARAM, wintypes.LPARAM)
def wndproc(hwnd, msg, wp, lp):
    if msg == WM_INPUT:
        stats['count'] += 1
        rin = RAWINPUT()
        sz = ctypes.c_uint(ctypes.sizeof(RAWINPUT))
        r = u.GetRawInputData(lp, 0x10000003, ctypes.byref(rin), ctypes.byref(sz),
                              ctypes.sizeof(RAWINPUTHEADER))
        if r != -1 and r != 0:
            stats['hdev'].add(rin.header.hDevice)
            if rin.header.dwType == 0:
                if rin.mouse.lLastX or rin.mouse.lLastY:
                    stats['move'] += 1
                stats['flags0'] = rin.mouse.usFlags
    return u.DefWindowProcW(hwnd, msg, wp, lp)

hinst = k.GetModuleHandleW(None)
wc = WNDCLASSW()
wc.style = 0
wc.lpfnWndProc = wndproc
wc.hInstance = hinst
wc.lpszClassName = 'RITestProbe'
atom = u.RegisterClassW(ctypes.byref(wc))
hwnd = u.CreateWindowExW(0, 'RITestProbe', 'probe', 0, 0, 0, 10, 10, None, None, hinst, None)
rid = RAWINPUTDEVICE(0x01, 0x02, 0x00000100, hwnd)   # RIDEV_INPUTSINK
ok = u.RegisterRawInputDevices(ctypes.byref(rid), 1, ctypes.sizeof(RAWINPUTDEVICE))
print('register ok =', bool(ok), ' hwnd =', hwnd)

msg = wintypes.MSG()
deadline = time.time() + 1.0
while time.time() < deadline:
    while u.PeekMessageW(ctypes.byref(msg), None, 0, 0, 1):
        u.TranslateMessage(ctypes.byref(msg))
        u.DispatchMessageW(ctypes.byref(msg))
    time.sleep(0.001)
print('baseline WM_INPUT =', stats['count'])

# 注入 200 个相对移动
for i in range(200):
    inp = INPUT()
    inp.type = 0
    inp.union.mi.dx = 2
    inp.union.mi.dy = 1
    inp.union.mi.dwFlags = 1
    u.SendInput(1, ctypes.byref(inp), ctypes.sizeof(INPUT))
    time.sleep(0.002)

deadline = time.time() + 0.5
while time.time() < deadline:
    while u.PeekMessageW(ctypes.byref(msg), None, 0, 0, 1):
        u.TranslateMessage(ctypes.byref(msg))
        u.DispatchMessageW(ctypes.byref(msg))
    time.sleep(0.001)

print(f'after inject: WM_INPUT={stats["count"]}  move-events={stats["move"]}  '
      f'hDevices={stats["hdev"]}  usFlags={stats["flags0"]}')
