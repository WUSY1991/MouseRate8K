// chart.cpp — 全屏覆盖层渲染（Areson 式满屏）
// 窗口 = WS_POPUP 覆盖整个虚拟屏幕，WS_EX_LAYERED + 颜色键(纯黑=全透明) + 全局 alpha。
// 轨迹按真实屏幕光标坐标绘制（线画在鼠标实际所在处），面板（大数字/曲线/按键）浮动其上。
#include "chart.h"
#include "rawinput_engine.h"
#include "csvlog.h"
#include <vector>
#include <cmath>
#include <cwchar>

LayoutInfo g_layout;

// ---- 配色（纯黑满屏背景，Areson 式）----
static constexpr COLORREF C_BK      = RGB(0, 0, 0);      // 背景（不透明纯黑）
static constexpr COLORREF C_PANEL   = RGB(16, 20, 26);   // 面板底（经全局 alpha 呈半透明）
static constexpr COLORREF C_PANEL2  = RGB(20, 25, 32);
static constexpr COLORREF C_GRID    = RGB(40, 46, 56);
static constexpr COLORREF C_TEXT    = RGB(198, 205, 213);
static constexpr COLORREF C_DIM     = RGB(122, 130, 140);
static constexpr COLORREF C_ACCENT  = RGB(0, 230, 118);
static constexpr COLORREF C_TRAJ    = RGB(0, 230, 118);   // 左键绿
static constexpr COLORREF C_TRAJOLD = RGB(1, 60, 32);
static constexpr COLORREF C_TRAJNEW = RGB(0, 200, 100);
static constexpr COLORREF C_TRAJR   = RGB(255, 70, 70);   // 右键红
static constexpr COLORREF C_TRAJROLD= RGB(70, 16, 16);
static constexpr COLORREF C_TRAJRNEW= RGB(220, 60, 60);
static constexpr COLORREF C_BTN     = RGB(52, 58, 66);
static constexpr COLORREF C_CHIP    = RGB(20, 26, 34);

static const int kScales[7] = { 125, 250, 500, 1000, 2000, 4000, 8000 };

static HWND g_chartHwnd = nullptr;   // 轨迹屏幕坐标 → 客户区坐标换算用

const wchar_t* ScaleName(int idx) {
    static wchar_t names[8][12];
    if (idx >= 0 && idx < 7) { swprintf(names[idx], 12, L"%d", kScales[idx]); return names[idx]; }
    return L"自动";
}
int ScaleValue(int idx) { return (idx >= 0 && idx < 7) ? kScales[idx] : 0; }

// ---- 内存 DC / 字体 ----
static HDC     g_mem = nullptr;
static HBITMAP g_bmp = nullptr, g_oldBmp = nullptr;
static int     g_mw = 0, g_mh = 0;
static HFONT   g_fBig = nullptr, g_fNum = nullptr, g_fUI = nullptr,
               g_fSmall = nullptr, g_fTiny = nullptr;

static void KillFonts() {
    if (g_fBig)   { DeleteObject(g_fBig);   g_fBig = nullptr; }
    if (g_fNum)   { DeleteObject(g_fNum);   g_fNum = nullptr; }
    if (g_fUI)    { DeleteObject(g_fUI);    g_fUI = nullptr; }
    if (g_fSmall) { DeleteObject(g_fSmall); g_fSmall = nullptr; }
    if (g_fTiny)  { DeleteObject(g_fTiny);  g_fTiny = nullptr; }
}
static HFONT MkFont(const wchar_t* face, int pt, bool bold, UINT dpi) {
    return CreateFontW(-MulDiv(pt, (int)dpi, 72), 0, 0, 0,
                       bold ? FW_BOLD : FW_NORMAL, 0, 0, 0,
                       DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                       CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, face);
}

void Chart_OnDpiChange(HWND, UINT dpi) {
    g_layout.dpi = dpi;
    KillFonts();
    g_fBig   = MkFont(L"Consolas", 64, true, dpi);
    g_fNum   = MkFont(L"Consolas", 15, false, dpi);
    g_fUI    = MkFont(L"Microsoft YaHei UI", 10, false, dpi);
    g_fSmall = MkFont(L"Microsoft YaHei UI", 9, false, dpi);
    g_fTiny  = MkFont(L"Consolas", 8, false, dpi);
}

void Chart_Destroy() {
    KillFonts();
    if (g_mem) { SelectObject(g_mem, g_oldBmp); DeleteDC(g_mem); g_mem = nullptr; }
    if (g_bmp) { DeleteObject(g_bmp); g_bmp = nullptr; }
    g_mw = g_mh = 0;
}

static void EnsureMem(HDC winDC, int w, int h) {
    if (g_mem && g_mw == w && g_mh == h) return;
    if (g_mem) { SelectObject(g_mem, g_oldBmp); DeleteDC(g_mem); g_mem = nullptr; }
    if (g_bmp) { DeleteObject(g_bmp); g_bmp = nullptr; }
    g_mem = CreateCompatibleDC(winDC);
    g_bmp = CreateCompatibleBitmap(winDC, w, h);
    g_oldBmp = (HBITMAP)SelectObject(g_mem, g_bmp);
    g_mw = w; g_mh = h;
}

// ---- 布局：全屏 + 浮动面板 ----
void ComputeLayout(int w, int h, UINT dpi) {
    g_layout.dpi = dpi;
    LayoutInfo& L = g_layout;
    int m = L.S(16);                                    // 屏幕边距
    // 顶中：提示条
    int hw = L.S(860), hh = L.S(30);
    L.rcHint = { (w - hw) / 2, m, (w + hw) / 2, m + hh };
    // 左上：大数字面板
    L.rcBig = { m, m + hh + L.S(8), m + L.S(400), m + hh + L.S(8) + L.S(170) };
    // 右上：设备/量程下拉框位置（子窗口由 main.cpp 摆放）
    int cw = L.S(320), ch = L.S(28);
    L.rcChipDev   = { w - m - cw, m, w - m, m + ch };
    L.rcChipScale = { w - m - cw, m + ch + L.S(6), w - m, m + 2 * ch + L.S(6) };
    L.rcChipSpan  = { w - m - cw, m + 2 * ch + 2 * L.S(6), w - m, m + 3 * ch + 2 * L.S(6) };
    // 左下：曲线面板（缩小版）
    int kw = L.S(420), kh = L.S(220);
    L.rcCurve = { m, h - m - kh, m + kw, h - m };
    // 右下：按键 + X/Y
    int bw = L.S(330), bh2 = L.S(110);
    L.rcBtns = { w - m - bw, h - m - bh2, w - m, h - m };
}

void Chart_OnSize(HWND hwnd, int w, int h, UINT dpi) {
    g_chartHwnd = hwnd;
    ComputeLayout(w, h, dpi);
}

static UINT g_paintInterval = 33;
void Chart_SetPaintInterval(HWND hwnd, UINT ms) {
    if (ms == g_paintInterval) return;
    g_paintInterval = ms;
    SetTimer(hwnd, 1, ms, nullptr);
}

// ---- 绘制辅助 ----
static void Fill(HDC dc, const RECT& rc, COLORREF c) {
    HBRUSH b = CreateSolidBrush(c);
    FillRect(dc, &rc, b);
    DeleteObject(b);
}
static void Panel(HDC dc, const RECT& rc) {           // 圆角面板
    Fill(dc, rc, C_PANEL);
    HPEN p = CreatePen(PS_SOLID, 1, C_GRID);
    HBRUSH nb = (HBRUSH)GetStockObject(NULL_BRUSH);
    HPEN op = (HPEN)SelectObject(dc, p);
    HBRUSH ob = (HBRUSH)SelectObject(dc, nb);
    RoundRect(dc, rc.left, rc.top, rc.right, rc.bottom, g_layout.S(10), g_layout.S(10));
    SelectObject(dc, op);
    SelectObject(dc, ob);
    DeleteObject(p);
}
static void Txt(HDC dc, int x, int y, const wchar_t* s, HFONT f, COLORREF c) {
    HFONT of = (HFONT)SelectObject(dc, f);
    SetTextColor(dc, c);
    SetBkMode(dc, TRANSPARENT);
    TextOutW(dc, x, y, s, (int)wcslen(s));
    SelectObject(dc, of);
}
static void TxtR(HDC dc, const RECT& rc, const wchar_t* s, HFONT f, COLORREF c, UINT align = DT_LEFT) {
    HFONT of = (HFONT)SelectObject(dc, f);
    SetTextColor(dc, c);
    SetBkMode(dc, TRANSPARENT);
    RECT t = rc;
    DrawTextW(dc, s, -1, &t, align | DT_VCENTER | DT_SINGLELINE | DT_NOPREFIX | DT_END_ELLIPSIS);
    SelectObject(dc, of);
}

// ---- 帧快照（持共享锁填充；绘制段无锁）----
struct ColStat { uint32_t n = 0; double sum = 0, mx = 0, mn = 1e18; };
struct FrameSnap {
    bool     hasSel = false;
    uint32_t winN = 0;
    double   avg = 0, mn = 0, mx = 0;
    uint64_t totalEvents = 0;
    int32_t  lastDx = 0, lastDy = 0;
    wchar_t  devname[160] = L"(未检测到设备)";
    uint32_t buttonBits = 0;
    uint64_t flashQpc[3] = {0, 0, 0};
    double   yMax = 0;
    std::vector<ColStat> cols;
    std::vector<TrajPoint> traw;
};

static double NiceAuto(double v) {
    static const int cands[] = { 125, 250, 500, 1000, 1500, 2000, 4000, 8000,
                                 12000, 16000, 24000, 32000, 48000, 64000 };
    for (int c : cands) if (v <= c) return c;
    return 128000;
}

static void Snapshot(FrameSnap& sn, int pw) {
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    uint64_t nowQ = (uint64_t)now.QuadPart;

    AcquireSRWLockShared(&g_lock);
    sn.buttonBits = g_buttonBits;
    for (int i = 0; i < 3; i++) sn.flashQpc[i] = g_flashQpc[i];
    if (g_selIdx >= 0) {
        const Channel& ch = g_ch[g_selIdx];
        sn.hasSel = true;
        // 当前值：最近 250ms 内全部报文数 ×4（零位移报文也计入 = Razer 语义）
        sn.winN = (uint32_t)RawInput_CountIn(g_selIdx, nowQ,
                                             (uint64_t)g_qpcFreq / 4);
        // 平均：1 秒滚动计数平均（计数语义，抗成批发报/dt 排除偏差）
        sn.avg = RawInput_CountIn(g_selIdx, nowQ, (uint64_t)g_qpcFreq) * 1.0;
        // 最大/最小：读保持寄存器（UI tick 刷新；停止后维持最后值，C 清零）
        sn.mx = ch.hzMaxHold;
        sn.mn = ch.hzMinHold;
        sn.totalEvents = ch.totalEvents;
        sn.lastDx = ch.lastDx;
        sn.lastDy = ch.lastDy;
        swprintf(sn.devname, 160, L"%s  [%04X/%04X]", ch.name, ch.vid, ch.pid);

        // 曲线列分桶（计数口径，与 max/min 同语义，抗抖动尖峰）：
        // 列值 = 尾随窗口 W 内报文数 ÷ W；W = max(列宽, 4×平均间隔)。
        // 抖动链路（蓝牙 7.5ms±抖动）下逐对 1/dt 会窜出 500~2400Hz 假尖峰，计数不会。
        sn.cols.assign((size_t)pw, ColStat{});
        double xSec = g_set.xSeconds;
        uint64_t t1 = nowQ;
        uint64_t t0 = t1 - (uint64_t)(xSec * (double)g_qpcFreq);
        if (ch.buf && ch.count > 1) {
            uint64_t lo = ch.count > kRingCap ? ch.count - kRingCap : 0;
            uint64_t a = lo, b = ch.count;
            while (a < b) {
                uint64_t mid = a + (b - a) / 2;
                if (ch.buf[mid % kRingCap].qpc < t0) a = mid + 1; else b = mid;
            }
            uint64_t nEv = ch.count - a;
            double colDur = xSec / (double)pw;
            double meanIv = nEv > 0 ? xSec / (double)nEv : colDur;
            double Wd = (4.0 * meanIv > colDur) ? 4.0 * meanIv : colDur;
            if (Wd > xSec) Wd = xSec;
            uint64_t colDurT = (uint64_t)(colDur * (double)g_qpcFreq);
            uint64_t Wt = (uint64_t)(Wd * (double)g_qpcFreq);
            if (Wt == 0) Wt = 1;
            uint64_t sp = a, ep = a;               // 双指针：sp≥winStart, ep≥winEnd
            for (int c = 0; c < pw; c++) {
                uint64_t winEnd = t0 + (uint64_t)(c + 1) * colDurT;
                uint64_t winStart = winEnd > Wt ? winEnd - Wt : 0;
                if (winStart < t0) winStart = t0;
                while (sp < ch.count && ch.buf[sp % kRingCap].qpc < winStart) sp++;
                while (ep < ch.count && ch.buf[ep % kRingCap].qpc < winEnd) ep++;
                uint64_t len = winEnd - winStart;
                if (len > 0 && ep > sp) {
                    double hz = (double)(ep - sp) * (double)g_qpcFreq / (double)len;
                    ColStat& s = sn.cols[(size_t)c];
                    s.n = 1; s.sum = hz;
                    if (hz > sn.yMax) sn.yMax = hz;
                }
            }
        }
    }
    // 轨迹：真实屏幕坐标点（最多拷 8192）；点数不足时必须清空，否则残留上一帧
    uint64_t n = g_trajCount < kTrajCap ? g_trajCount : kTrajCap;
    if (n >= 2) {
        uint64_t start = g_trajCount - n;
        sn.traw.resize((size_t)n);
        for (uint64_t i = start; i < g_trajCount; i++)
            sn.traw[(size_t)(i - start)] = g_traj[i % kTrajCap];
    } else {
        sn.traw.clear();
    }
    ReleaseSRWLockShared(&g_lock);

    int sv = ScaleValue(g_set.scaleIdx);
    sn.yMax = sv > 0 ? (double)sv : NiceAuto(sn.yMax * 1.05);
    if (sn.yMax < 1) sn.yMax = 1000;
}

// ---- 屏幕轨迹：左键=绿线 / 右键=红线，只滑动不画；Space 清除 ----
static void DrawTrail(HDC dc, const FrameSnap& sn) {
    size_t n = sn.traw.size();
    if (n < 2) return;
    POINT org{ 0, 0 };
    if (g_chartHwnd) ScreenToClient(g_chartHwnd, &org);
    static std::vector<POINT> run;
    // 每种颜色两支画笔（暗/亮），按 col 分段绘制，颜色切换处断开折线
    struct PenPair { HPEN dim, hot; };
    PenPair green{ CreatePen(PS_SOLID, g_layout.S(2), C_TRAJOLD),
                   CreatePen(PS_SOLID, g_layout.S(3), C_TRAJ) };
    PenPair red{ CreatePen(PS_SOLID, g_layout.S(2), C_TRAJROLD),
                 CreatePen(PS_SOLID, g_layout.S(3), C_TRAJR) };
    HPEN op = (HPEN)GetCurrentObject(dc, OBJ_PEN);
    auto flushRun = [&](uint8_t col) {
        if (run.size() < 2) { run.clear(); return; }
        size_t h1 = run.size() / 2;
        const PenPair& pp = (col == 2) ? red : green;
        SelectObject(dc, pp.dim);
        Polyline(dc, run.data(), (int)(h1 > 1 ? h1 : 1));
        SelectObject(dc, pp.hot);
        Polyline(dc, run.data() + (h1 ? h1 - 1 : 0),
                 (int)(run.size() - (h1 ? h1 - 1 : 0)));
        run.clear();
    };
    uint8_t curCol = sn.traw[0].col;
    for (size_t i = 0; i < n; i++) {
        if (sn.traw[i].col != curCol) { flushRun(curCol); curCol = sn.traw[i].col; }
        run.push_back({ (LONG)sn.traw[i].x + org.x, (LONG)sn.traw[i].y + org.y });
    }
    flushRun(curCol);
    // 线段末端（最后画点）亮点，颜色跟随
    const TrajPoint& last = sn.traw[n - 1];
    POINT hd = { (LONG)last.x + org.x, (LONG)last.y + org.y };
    COLORREF hc = (last.col == 2) ? C_TRAJR : C_TRAJ;
    HBRUSH b = CreateSolidBrush(hc);
    HPEN np = CreatePen(PS_SOLID, 1, hc);
    HPEN op2 = (HPEN)SelectObject(dc, np);
    HBRUSH ob2 = (HBRUSH)SelectObject(dc, b);
    int r = g_layout.S(5);
    Ellipse(dc, hd.x - r, hd.y - r, hd.x + r, hd.y + r);
    SelectObject(dc, op2);
    SelectObject(dc, ob2);
    DeleteObject(np);
    DeleteObject(b);
    SelectObject(dc, op);
    DeleteObject(green.dim); DeleteObject(green.hot);
    DeleteObject(red.dim); DeleteObject(red.hot);
}

// ---- 左上：大数字 + 统计 ----
static void DrawBig(HDC dc, const FrameSnap& sn) {
    const RECT& rc = g_layout.rcBig;
    Panel(dc, rc);
    Txt(dc, rc.left + g_layout.S(18), rc.top + g_layout.S(12),
        L"当前回报率", g_fUI, C_DIM);
    wchar_t num[32];
    if (g_set.paused) wcscpy(num, L"暂停");
    else if (!sn.hasSel || sn.winN == 0) wcscpy(num, L"--");
    else swprintf(num, 32, L"%u", sn.winN * 4);
    bool hot = sn.winN * 4 >= 7800;
    Txt(dc, rc.left + g_layout.S(18), rc.top + g_layout.S(38), num, g_fBig,
        hot ? C_ACCENT : C_TEXT);
    Txt(dc, rc.left + g_layout.S(330), rc.top + g_layout.S(112), L"Hz", g_fUI, C_DIM);
    wchar_t s[160];
    swprintf(s, 160, L"平均 %.0f    最大 %.0f    最小 %.0f",
             sn.avg, sn.mx, sn.mn);
    Txt(dc, rc.left + g_layout.S(18), rc.top + g_layout.S(142), s, g_fNum, C_TEXT);
}

// ---- 左下：回报率曲线 ----
static void DrawCurve(HDC dc, const FrameSnap& sn) {
    const RECT& rc = g_layout.rcCurve;
    Panel(dc, rc);
    int padL = g_layout.S(50), padB = g_layout.S(22),
        padT = g_layout.S(12), padR = g_layout.S(14);
    RECT plot = { rc.left + padL, rc.top + padT, rc.right - padR, rc.bottom - padB };
    int pw = plot.right - plot.left, ph = plot.bottom - plot.top;
    if (pw < 10 || ph < 10) return;
    double yMax = sn.yMax, xSec = g_set.xSeconds;

    HPEN grid = CreatePen(PS_SOLID, 1, C_GRID);
    HPEN oldp = (HPEN)SelectObject(dc, grid);
    for (int i = 0; i <= 8; i++) {
        int y = plot.bottom - ph * i / 8;
        MoveToEx(dc, plot.left, y, nullptr);
        LineTo(dc, plot.right, y);
    }
    {   // X 轴刻度：nice 步长，支持亚秒窗口（100ms~30s）
        static const double steps[] = { 0.01, 0.02, 0.05, 0.1, 0.2, 0.5,
                                        1, 2, 5, 10, 15, 30 };
        double step = steps[sizeof(steps) / sizeof(steps[0]) - 1];
        for (double st : steps)
            if (st <= xSec / 4.0) { step = st; break; }
        for (double v = step; v < xSec * 0.999; v += step) {
            int x = plot.right - (int)(v / xSec * pw);
            MoveToEx(dc, x, plot.top, nullptr);
            LineTo(dc, x, plot.bottom);
            wchar_t lb[20];
            if (step < 1.0) swprintf(lb, 20, L"-%.0fms", v * 1000.0);
            else            swprintf(lb, 20, L"-%.0fs", v);
            Txt(dc, x - g_layout.S(18), plot.bottom + g_layout.S(3), lb, g_fTiny, C_DIM);
        }
    }
    SelectObject(dc, oldp);
    DeleteObject(grid);
    for (int i = 0; i <= 8; i += 2) {
        wchar_t lb[16];
        swprintf(lb, 16, L"%d", (int)(yMax * i / 8));
        RECT lr = { rc.left + g_layout.S(2), plot.bottom - ph * i / 8 - g_layout.S(7),
                    plot.left - g_layout.S(2), plot.bottom - ph * i / 8 + g_layout.S(7) };
        TxtR(dc, lr, lb, g_fTiny, C_DIM, DT_RIGHT);
    }
    wchar_t cap[64];
    wchar_t spanTxt[20];
    if (xSec < 1.0) swprintf(spanTxt, 20, L"%.0fms", xSec * 1000.0);
    else            swprintf(spanTxt, 20, L"%.0fs", xSec);
    swprintf(cap, 64, L"回报率曲线  %s Hz  |  窗口 %s",
             g_set.scaleIdx == 7 ? L"自动" : ScaleName(g_set.scaleIdx), spanTxt);
    Txt(dc, plot.left + g_layout.S(4), rc.top + g_layout.S(1), cap, g_fSmall, C_DIM);

    auto yOf = [&](double hz) -> int {
        double t = hz / yMax; if (t < 0) t = 0; if (t > 1) t = 1;
        return plot.bottom - (int)(t * ph + 0.5);
    };
    HPEN line = CreatePen(PS_SOLID, g_layout.S(2) < 1 ? 1 : g_layout.S(2), C_ACCENT);
    HPEN op = (HPEN)SelectObject(dc, line);
    bool down = false;
    int lastY = 0;
    for (int c = 0; c < pw && c < (int)sn.cols.size(); c++) {
        const ColStat& s = sn.cols[(size_t)c];
        if (!s.n) { down = false; continue; }
        int y = yOf(s.sum / s.n);
        if (!down) { MoveToEx(dc, plot.left + c, y, nullptr); down = true; }
        else LineTo(dc, plot.left + c, y);
        lastY = y;
    }
    SelectObject(dc, op);
    DeleteObject(line);
    if (down) {
        HBRUSH b = CreateSolidBrush(C_ACCENT);
        RECT dot = { plot.right - g_layout.S(4), lastY - g_layout.S(3),
                     plot.right + g_layout.S(2), lastY + g_layout.S(3) };
        FillRect(dc, &dot, b);
        DeleteObject(b);
    }
}

// ---- 右下：按键图标 + X/Y ----
static void DrawButtons(HDC dc, const FrameSnap& sn) {
    const RECT& rc = g_layout.rcBtns;
    Panel(dc, rc);
    static const wchar_t* labels[8] = { L"L", L"R", L"M", L"4", L"5", L"TL", L"TR", L"滚轮" };
    int bw = g_layout.S(34), bh = g_layout.S(28), gap = g_layout.S(6);
    int total = 8 * bw + 7 * gap;
    int x0 = rc.left + ((rc.right - rc.left) - total) / 2;
    int y0 = rc.top + g_layout.S(10);
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    for (int i = 0; i < 8; i++) {
        bool active;
        if (i < 5) active = (sn.buttonBits & (1u << i)) != 0;
        else {
            uint64_t dt = (uint64_t)now.QuadPart - sn.flashQpc[i - 5];
            active = sn.flashQpc[i - 5] != 0 &&
                     dt < (uint64_t)g_qpcFreq * 150 / 1000;
        }
        RECT br = { x0 + i * (bw + gap), y0, x0 + i * (bw + gap) + bw, y0 + bh };
        HBRUSH b = CreateSolidBrush(active ? C_ACCENT : C_BTN);
        FillRect(dc, &br, b);
        DeleteObject(b);
        TxtR(dc, br, labels[i], g_fSmall, active ? RGB(8, 12, 10) : C_TEXT, DT_CENTER);
    }
    wchar_t s[96];
    if (sn.hasSel)
        swprintf(s, 96, L"X: %-5d  Y: %-5d    报文: %llu",
                 sn.lastDx, sn.lastDy, (unsigned long long)sn.totalEvents);
    else
        wcscpy(s, L"X: --   Y: --");
    Txt(dc, rc.left + g_layout.S(12), rc.bottom - g_layout.S(34), s, g_fNum, C_TEXT);
    wchar_t st[220];
    swprintf(st, 220, L"%s   模式:%s   日志:%s(%llu行)   报文:%llu%s",
             sn.devname,
             g_set.countAll ? L"全部报文" : L"仅位移",
             Csv_IsOpen() ? L"开" : L"关",
             (unsigned long long)Csv_Rows(),
             (unsigned long long)sn.totalEvents,
             g_set.paused ? L"   [已暂停]" : L"");
    Txt(dc, rc.left + g_layout.S(12), rc.bottom - g_layout.S(20), st, g_fTiny, C_DIM);
}

// ---- 顶中提示 + 右上 chips ----
static void DrawHint(HDC dc) {
    Panel(dc, g_layout.rcHint);
    TxtR(dc, g_layout.rcHint,
         L"S 开始  P 暂停  C 清零  L 日志  D 模式  T 时间窗  0-7 量程  M 最小化  ESC 退出"
         L"   |   点击右上角切换 设备/量程",
         g_fSmall, C_DIM, DT_CENTER);
}


void Chart_Paint(HWND hwnd, HDC hdc) {
    RECT rc;
    GetClientRect(hwnd, &rc);
    int w = rc.right - rc.left, h = rc.bottom - rc.top;
    if (w <= 0 || h <= 0) return;
    LARGE_INTEGER t0, t1, f;
    QueryPerformanceCounter(&t0);

    static FrameSnap sn;
    int plotW = (g_layout.rcCurve.right - g_layout.rcCurve.left) -
                g_layout.S(50) - g_layout.S(14);
    if (plotW < 10) plotW = 10;
    Snapshot(sn, plotW);

    EnsureMem(hdc, w, h);
    SetBkMode(g_mem, TRANSPARENT);
    Fill(g_mem, rc, C_BK);               // 纯黑满屏背景（不透明，Areson 式）
    DrawHint(g_mem);
    DrawBig(g_mem, sn);
    DrawCurve(g_mem, sn);
    DrawButtons(g_mem, sn);
    DrawTrail(g_mem, sn);                // 轨迹叠加在所有面板之上（鼠标划过控件可见）
    BitBlt(hdc, 0, 0, w, h, g_mem, 0, 0, SRCCOPY);

    QueryPerformanceCounter(&t1);
    QueryPerformanceFrequency(&f);
    double ms = (double)(t1.QuadPart - t0.QuadPart) * 1000.0 / (double)f.QuadPart;
    if (ms > 3.0) Chart_SetPaintInterval(hwnd, 50);
    else if (ms < 1.5) Chart_SetPaintInterval(hwnd, 33);
}
