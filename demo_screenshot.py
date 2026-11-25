# demo_screenshot.py — 启动 MouseRate8K，注入演示输入（移动+按键+滚轮），截图保存
import ctypes, math, os, subprocess, time
from ctypes import wintypes

u = ctypes.windll.user32
k = ctypes.windll.kernel32
g = ctypes.windll.gdi32

class MI(ctypes.Structure):
    _fields_ = [('dx', ctypes.c_long), ('dy', ctypes.c_long), ('md', ctypes.c_ulong),
                ('fl', ctypes.c_ulong), ('t', ctypes.c_ulong),
                ('ex', ctypes.POINTER(ctypes.c_ulong))]
class U(ctypes.Union):
    _fields_ = [('mi', MI)]
class INP(ctypes.Structure):
    _fields_ = [('ty', ctypes.c_ulong), ('un', U)]

def send(inp):
    u.SendInput(1, ctypes.byref(inp), ctypes.sizeof(INP))

def move(dx, dy):
    i = INP(); i.ty = 0; i.un.mi.dx = dx; i.un.mi.dy = dy; i.un.mi.fl = 1
    send(i)

def click(btn=0):     # 0=L 1=R 2=M
    d, up = ((2, 4), (8, 16), (32, 64))[btn]
    i = INP(); i.ty = 0; i.un.mi.fl = d; send(i)
    i = INP(); i.ty = 0; i.un.mi.fl = up; send(i)

def wheel(d):
    i = INP(); i.ty = 0; i.un.mi.fl = 0x800; i.un.mi.md = d & 0xFFFF
    send(i)

def hwheel(d):
    i = INP(); i.ty = 0; i.un.mi.fl = 0x1000; i.un.mi.md = d & 0xFFFF
    send(i)

# 1) 2 秒 8K 圆周运动（小圈，不动用户光标太多）
freq = ctypes.c_longlong(); k.QueryPerformanceFrequency(ctypes.byref(freq))
F = freq.value
c = ctypes.c_longlong()
def now():
    k.QueryPerformanceCounter(ctypes.byref(c)); return c.value

N = 8000 * 2
t0 = now()
period = F / 8000
for i in range(N):
    ang = i * (2 * math.pi / 400)
    move(int(6 * math.cos(ang)), int(6 * math.sin(ang)))
    if i % 40 == 20: click(0)                       # 点亮 L
    if i == 8000: click(1)                          # 点亮 R
    if i == 12000: click(2)                         # 点亮 M
    if i == 16000: hwheel(1)                        # 点亮 TR
    if i == 20000: wheel(-1)                        # 点亮 滚轮
    tgt = t0 + int(period * (i + 1))
    while now() < tgt:
        pass
print('injection done')

# 2) 截图窗口
hwnd = u.FindWindowW('MouseRate8KWnd', None)
rc = wintypes.RECT()
u.GetWindowRect(hwnd, ctypes.byref(rc))
w, h = rc.right - rc.left, rc.bottom - rc.top
time.sleep(0.15)
hdc = u.GetWindowDC(hwnd)
mdc = g.CreateCompatibleDC(hdc)
bmp = g.CreateCompatibleBitmap(hdc, w, h)
g.SelectObject(mdc, bmp)
g.PrintWindow(hwnd, mdc, 2)      # PW_RENDERFULLCONTENT
out = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'screenshot.png')
class BMIH(ctypes.Structure):
    _fields_ = [('biSize', ctypes.c_ulong), ('biWidth', ctypes.c_long),
                ('biHeight', ctypes.c_long), ('biPlanes', ctypes.c_ushort),
                ('biBitCount', ctypes.c_ushort), ('biCompression', ctypes.c_ulong),
                ('biSizeImage', ctypes.c_ulong), ('biXPelsPerMeter', ctypes.c_long),
                ('biYPelsPerMeter', ctypes.c_long), ('biClrUsed', ctypes.c_ulong),
                ('biClrImportant', ctypes.c_ulong)]
class BMI(ctypes.Structure):
    _fields_ = [('bmiHeader', BMIH), ('biColors', ctypes.c_ulong * 3)]
bmi = BMI()
bmi.bmiHeader.biSize = ctypes.sizeof(BMIH)
bmi.bmiHeader.biWidth = w
bmi.bmiHeader.biHeight = -h
bmi.bmiHeader.biPlanes = 1
bmi.bmiHeader.biBitCount = 32
bmi.bmiHeader.biCompression = 0
buf = ctypes.create_string_buffer(w * h * 4)
g.GetDIBits(mdc, bmp, 0, h, buf, ctypes.byref(bmi), 0)
open(out, 'wb').write(buf.raw)
g.DeleteObject(bmp); g.DeleteDC(mdc); u.ReleaseDC(hwnd, hdc)
print('saved', out, w, 'x', h)
