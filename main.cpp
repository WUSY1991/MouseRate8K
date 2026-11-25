// main.cpp — WinMain / WndProc / 定时器 / 快捷键
// 全屏覆盖层：WS_POPUP 覆盖虚拟屏幕 + WS_EX_LAYERED（颜色键纯黑=透明 + 全局 alpha），
// 轨迹按真实光标位置画在屏幕上，面板浮动半透明（Areson 式满屏）。
#include "common.h"
#include "rawinput_engine.h"
#include "chart.h"
#include "csvlog.h"
#include <commctrl.h>
#include <windowsx.h>
#include <cstdio>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "hid.lib")

static HWND g_hwnd = nullptr;
static HWND g_comboDev = nullptr, g_comboScale = nullptr;
static UINT g_comboGen = 0;
static bool g_rebuilding = false;

static void PositionControls() {
    LayoutInfo& L = g_layout;
    if (g_comboDev)
        MoveWindow(g_comboDev, L.rcChipDev.left, L.rcChipDev.top,
                   L.rcChipDev.right - L.rcChipDev.left, L.S(400), TRUE);
    if (g_comboScale)
        MoveWindow(g_comboScale, L.rcChipScale.left, L.rcChipScale.top,
                   L.rcChipScale.right - L.rcChipScale.left, L.S(400), TRUE);
}

static void RebuildComboDev() {
    if (!g_comboDev) return;
    g_rebuilding = true;
    wchar_t cur[192] = L"";
    int k0 = (int)SendMessageW(g_comboDev, CB_GETCURSEL, 0, 0);
    if (k0 != CB_ERR) SendMessageW(g_comboDev, CB_GETLBTEXT, k0, (LPARAM)cur);
    SendMessageW(g_comboDev, CB_RESETCONTENT, 0, 0);
    SendMessageW(g_comboDev, CB_ADDSTRING, 0, (LPARAM)L"(自动) 选择活动设备");
    SendMessageW(g_comboDev, CB_SETITEMDATA, 0, 0);
    int storeSel = 0;
    for (int i = 0; i < (int)kMaxChannels; i++) {
        if (!g_ch[i].occupied || !g_ch[i].named) continue;
        wchar_t s[192];
        swprintf(s, 192, L"%s%s  [%04X/%04X]", g_ch[i].name,
                 g_ch[i].present ? L"" : L" (离线)", g_ch[i].vid, g_ch[i].pid);
        int kk = (int)SendMessageW(g_comboDev, CB_ADDSTRING, 0, (LPARAM)s);
        SendMessageW(g_comboDev, CB_SETITEMDATA, kk, (LPARAM)(i + 1));
        if (cur[0] && wcscmp(cur, s) == 0) storeSel = kk;
    }
    SendMessageW(g_comboDev, CB_SETCURSEL, (WPARAM)storeSel, 0);
    g_rebuilding = false;
    g_comboGen = g_comboDirtyGen;
}

static UINT GetDpi(HWND h) {
    HDC dc = GetDC(h);
    UINT dpi = (UINT)GetDeviceCaps(dc, LOGPIXELSX);
    ReleaseDC(h, dc);
    return dpi ? dpi : 96;
}

static void LogicTick() {
    RawInput_ResolveNamesStep();
    if (g_devDirty) {              // 输入线程 WM_DEVICECHANGE 置位
        RawInput_UpdatePresence();
        g_comboDirtyGen++;
        g_devDirty = false;
    }
    AutoSelect();
    RawInput_RefreshHolds();       // 统计会话语义（保持/复位）
    if (g_comboDev && g_comboGen != g_comboDirtyGen) RebuildComboDev();
    Csv_Tick();
}

static void OnHotkey(WPARAM vk) {
    switch (vk) {
    case 'S': g_set.paused = false; break;
    case 'P': g_set.paused = true; break;
    case 'C':
        if (g_selIdx >= 0) RawInput_ClearChannel(g_selIdx);
        break;
    case VK_SPACE:     // 只清轨迹（左绿/右红线），统计保留
        AcquireSRWLockExclusive(&g_lock);
        g_trajCount = 0;
        ReleaseSRWLockExclusive(&g_lock);
        break;
    case 'L':
        if (!Csv_IsOpen()) {
            if (Csv_Start()) g_set.logging = true;
        } else {
            Csv_Stop();
            g_set.logging = false;
        }
        break;
    case 'B': g_set.showBand = !g_set.showBand; break;
    case 'T': {  // 曲线时间窗循环：2s → 5s → 10s → 30s
        static const double spans[4] = { 2.0, 5.0, 10.0, 30.0 };
        int i = 0;
        for (; i < 4; i++) if (g_set.xSeconds == spans[i]) break;
        g_set.xSeconds = spans[(i + 1) % 4];
        break;
    }
    case 'D':   // 计数模式：全部报文（默认）/ 仅位移；切换后统计清零重测
        g_set.countAll = !g_set.countAll;
        if (g_selIdx >= 0) {
            AcquireSRWLockExclusive(&g_lock);
            Channel& ch = g_ch[g_selIdx];
            ch.count = 0; ch.lastQpc = 0;
            ch.hzMaxHold = 0; ch.hzMinHold = 0; ch.totalEvents = 0;
            for (uint32_t k = 0; k < kBktN; k++) { ch.bkt[k] = 0; ch.bktEpoch[k] = 0; }
            ReleaseSRWLockExclusive(&g_lock);
        }
        break;
    case 'X':   // 隐藏功能：锁定/解锁 SendInput 注入通道（自动化测试用）
        g_set.manualPin = (g_set.manualPin == INVALID_HANDLE_VALUE)
                              ? nullptr : INVALID_HANDLE_VALUE;
        break;
    case 'Z': { // 隐藏功能：状态转储到 debug_state.txt
        AcquireSRWLockShared(&g_lock);
        FILE* f = _wfopen(L"debug_state.txt", L"w");
        if (f) {
            fwprintf(f, L"selIdx=%d manualPin=%p paused=%d logging=%d\n",
                     g_selIdx, g_set.manualPin, g_set.paused, g_set.logging);
            for (int i = 0; i < (int)kMaxChannels; i++) {
                if (!g_ch[i].occupied) continue;
                fwprintf(f, L"ch[%d] hDev=%p name=%s count=%llu "
                         L"total=%llu lastQpc=%llu hold[max=%.0f min=%.0f]\n",
                         i, g_ch[i].hDevice, g_ch[i].name,
                         (unsigned long long)g_ch[i].count,
                         (unsigned long long)g_ch[i].totalEvents,
                         (unsigned long long)g_ch[i].lastQpc,
                         g_ch[i].hzMaxHold, g_ch[i].hzMinHold);
            }
            fwprintf(f, L"trajCount=%llu\n", (unsigned long long)g_trajCount);
            fclose(f);
        }
        ReleaseSRWLockShared(&g_lock);
        break;
    }
    case 'M': ShowWindow(g_hwnd, SW_MINIMIZE); break;
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
        g_set.scaleIdx = (vk == '0') ? 7 : (int)(vk - '1');
        break;
    case VK_ESCAPE: DestroyWindow(g_hwnd); break;
    default: break;
    }
}

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_TIMER:
        if (wParam == 1) {
            if (!IsIconic(hwnd)) InvalidateRect(hwnd, nullptr, FALSE);
        } else if (wParam == 2) {
            LogicTick();
        }
        break;
    case WM_KEYDOWN:
        OnHotkey(wParam);
        break;
    case WM_SETCURSOR:       // 覆盖层上仍显示标准箭头光标
        SetCursor(LoadCursor(nullptr, IDC_ARROW));
        return TRUE;
    case WM_SIZE: {
        UINT dpi = GetDpi(hwnd);
        Chart_OnSize(hwnd, LOWORD(lParam), HIWORD(lParam), dpi);
        PositionControls();
        InvalidateRect(hwnd, nullptr, FALSE);
        break;
    }
    case WM_DPICHANGED: {
        UINT dpi = HIWORD(wParam);
        RECT* sug = (RECT*)lParam;
        SetWindowPos(hwnd, nullptr, sug->left, sug->top,
                     sug->right - sug->left, sug->bottom - sug->top,
                     SWP_NOZORDER | SWP_NOACTIVATE);
        RECT rc;
        GetClientRect(hwnd, &rc);
        Chart_OnDpiChange(hwnd, dpi);
        Chart_OnSize(hwnd, rc.right, rc.bottom, dpi);
        PositionControls();
        InvalidateRect(hwnd, nullptr, FALSE);
        break;
    }
    case WM_EXITSIZEMOVE:
        RawInput_ResetAllDt();
        break;
    case WM_ERASEBKGND:
        return 1;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC dc = BeginPaint(hwnd, &ps);
        Chart_Paint(hwnd, dc);
        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_COMMAND:
        if ((HWND)lParam == g_comboDev || (HWND)lParam == g_comboScale) {
            WORD code = HIWORD(wParam);
            if (code == CBN_CLOSEUP || code == CBN_SELENDCANCEL) {
                // 下拉列表关闭后把键盘焦点还给主窗口，恢复快捷键（否则 D/ESC 等会被下拉框吃掉）
                SetFocus(hwnd);
                break;
            }
            if (code == CBN_SELCHANGE && !g_rebuilding) {
                if ((HWND)lParam == g_comboDev) {
                    int kk = (int)SendMessageW(g_comboDev, CB_GETCURSEL, 0, 0);
                    if (kk != CB_ERR) {
                        int idx = (int)SendMessageW(g_comboDev, CB_GETITEMDATA, kk, 0);
                        if (idx > 0) {
                            AcquireSRWLockExclusive(&g_lock);
                            g_set.manualPin = g_ch[idx - 1].hDevice;
                            g_selIdx = idx - 1;
                            g_trajCount = 0;
                            ReleaseSRWLockExclusive(&g_lock);
                        } else {
                            g_set.manualPin = nullptr;   // 回到自动
                        }
                    }
                } else {
                    int kk = (int)SendMessageW(g_comboScale, CB_GETCURSEL, 0, 0);
                    if (kk != CB_ERR) g_set.scaleIdx = kk;
                }
                SetFocus(hwnd);    // 选择完成即归还焦点
            }
        }
        break;
    case WM_DESTROY:
        Csv_Stop();
        RawInput_Stop();
        Chart_Destroy();
        PostQuitMessage(0);
        return 0;
    default:
        break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, PWSTR, int nCmdShow) {
    INITCOMMONCONTROLSEX icc{ sizeof(icc), ICC_STANDARD_CLASSES | ICC_WIN95_CLASSES };
    InitCommonControlsEx(&icc);

    QueryPerformanceFrequency((LARGE_INTEGER*)&g_qpcFreq);
    QueryPerformanceCounter((LARGE_INTEGER*)&g_startQpc);
    if (g_qpcFreq <= 0) g_qpcFreq = 10000000;

    WNDCLASSEXW wc{};
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hIcon = LoadIconW(hInst, MAKEINTRESOURCEW(1));
    wc.hIconSm = wc.hIcon;
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = L"MouseRate8KWnd";
    RegisterClassExW(&wc);

    // 只铺满主屏（不跨多显示器）
    int vx = 0, vy = 0;
    int vw = GetSystemMetrics(SM_CXSCREEN);
    int vh = GetSystemMetrics(SM_CYSCREEN);

    g_hwnd = CreateWindowExW(
        WS_EX_TOPMOST | WS_EX_APPWINDOW,
        L"MouseRate8KWnd",
        L"鼠标回报率测试仪 8K — 满屏覆盖 · 8K 精测 · 轨迹/曲线",
        WS_POPUP,
        vx, vy, vw, vh,
        nullptr, nullptr, hInst, nullptr);
    if (!g_hwnd) return 1;

    UINT wdpi = GetDpi(g_hwnd);
    Chart_OnDpiChange(g_hwnd, wdpi);
    Chart_OnSize(g_hwnd, vw, vh, wdpi);

    g_comboDev = CreateWindowExW(0, L"COMBOBOX", nullptr,
        WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL,
        0, 0, 100, 400, g_hwnd, (HMENU)1001, hInst, nullptr);
    g_comboScale = CreateWindowExW(0, L"COMBOBOX", nullptr,
        WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
        0, 0, 80, 400, g_hwnd, (HMENU)1002, hInst, nullptr);
    HFONT comboFont = CreateFontW(-MulDiv(9, (int)wdpi, 72), 0, 0, 0, FW_NORMAL,
        0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Microsoft YaHei UI");
    static const wchar_t* scaleItems[8] = { L"125", L"250", L"500", L"1000",
                                            L"2000", L"4000", L"8000", L"自动" };
    for (int i = 0; i < 8; i++)
        SendMessageW(g_comboScale, CB_ADDSTRING, 0, (LPARAM)scaleItems[i]);
    SendMessageW(g_comboScale, CB_SETCURSEL, (WPARAM)g_set.scaleIdx, 0);
    SendMessageW(g_comboDev, WM_SETFONT, (WPARAM)comboFont, TRUE);
    SendMessageW(g_comboScale, WM_SETFONT, (WPARAM)comboFont, TRUE);
    PositionControls();
    RebuildComboDev();

    if (!RawInput_Start()) {
        MessageBoxW(g_hwnd, L"输入线程/原始输入注册失败", L"错误", MB_ICONERROR);
        return 1;
    }

    SetTimer(g_hwnd, 1, 33, nullptr);    // 30fps 重绘
    SetTimer(g_hwnd, 2, 100, nullptr);   // 逻辑心跳

    ShowWindow(g_hwnd, nCmdShow);
    UpdateWindow(g_hwnd);

    MSG m;
    while (GetMessageW(&m, nullptr, 0, 0) > 0) {
        TranslateMessage(&m);
        DispatchMessageW(&m);
    }
    return (int)m.wParam;
}
