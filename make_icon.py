# make_icon.py — 生成简单的 32x32 图标（荧光绿折线 + 暗底）
import struct, sys

W = H = 32
def px(x, y, c):
    return c

# 像素缓冲（自底向上）
base = (14, 16, 20)
accent = (0, 230, 118)
dim = (0, 92, 48)
rows = []
for y in range(H):
    row = []
    for x in range(W):
        c = base
        # 曲线：正弦折线
        cy = 22 - int(14 * (x / 31.0) ** 2)          # 上升曲线
        if y == cy or (y == cy + 1 and x % 3 == 0):
            c = accent
        if y < cy and y > cy - 4 and (x + y) % 5 == 0:
            c = dim
        if x < 2 or x >= W - 2 or y < 2 or y >= H - 2:
            c = (30, 34, 40)
        row.append(c)
    rows.append(row)

bmp = b''
for y in range(H - 1, -1, -1):                        # bottom-up
    for x in range(W):
        r, g, b = rows[y][x]
        bmp += bytes((b, g, r, 255))
and_mask = bytes(W // 8 * H)                          # 全不透明掩码占位

ico = struct.pack('<HHH', 0, 1, 1)
ico += struct.pack('<BBBBHHII', W, H, 0, 0, 1, 32,
                   40 + len(bmp) + len(and_mask), 22)
ico += struct.pack('<IiiHHIIiiII', 40, W, H * 2, 1, 32, 0,
                   len(bmp) + len(and_mask), 0, 0, 0, 0)
ico += bmp + and_mask

open('app.ico', 'wb').write(ico)
print('app.ico written', len(ico), 'bytes')
