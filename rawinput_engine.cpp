// rawinput_engine.cpp — Raw Input 采集引擎
// 设计规则（8K 热路径）：WndProc 入口先取 QPC（全精度）→ GetRawInputData 栈缓冲
// → hDevice 分通道 → 环形缓冲 O(1) 写入 + 双指针 250ms 滑窗 O(1) 摊还。
// 零堆分配、零文本输出、零 GDI。CSV 仅 memcpy 进预分配缓冲。
#include "rawinput_engine.h"
#include "csvlog.h"
#include <hidsdi.h>
#include <dbt.h>
#include <cstdio>
#include <cwchar>

int64_t   g_qpcFreq = 0;
Channel   g_ch[kMaxChannels];
int       g_selIdx = -1;
Settings  g_set;
uint32_t  g_buttonBits = 0;
uint64_t  g_flashQpc[3] = {0, 0, 0};
TrajPoint g_traj[kTrajCap];
uint64_t  g_trajCount = 0;
double    g_trajX = 0, g_trajY = 0;
uint64_t  g_startQpc = 0;
uint32_t  g_comboDirtyGen = 1;
bool      g_devDirty = false;
SRWLOCK   g_lock = SRWLOCK_INIT;

// ---- 输入线程：专用 message-only 窗口，只做收报文+时间戳，绝不绘制 ----
static HWND     g_inputHwnd = nullptr;
static volatile LONG g_inputRunning = 0;

static LRESULT CALLBACK InputWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_INPUT:
        RawInput_OnInput(wp, lp);
        return DefWindowProc(hwnd, msg, wp, lp);   // WM_INPUT 清理必需
    case WM_DEVICECHANGE:
        if (wp == DBT_DEVNODES_CHANGED) g_devDirty = true;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

static DWORD WINAPI InputThread(void*) {
    WNDCLASSEXW wc{};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = InputWndProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpszClassName = L"MouseRate8KInput";
    RegisterClassExW(&wc);
    g_inputHwnd = CreateWindowExW(0, L"MouseRate8KInput", L"", 0,
                                  0, 0, 0, 0, HWND_MESSAGE, nullptr,
                                  wc.hInstance, nullptr);
    if (!g_inputHwnd) { PostQuitMessage(0); return 1; }
    RAWINPUTDEVICE rid;
    rid.usUsagePage = 0x01;                 // Generic Desktop
    rid.usUsage     = 0x02;                 // Mouse（修正 Areson 的 usage=0 错误）
    rid.dwFlags     = RIDEV_INPUTSINK | RIDEV_DEVNOTIFY;  // 后台收 + 设备变更通知
    rid.hwndTarget  = g_inputHwnd;
    if (!RegisterRawInputDevices(&rid, 1, sizeof(rid))) { PostQuitMessage(0); return 1; }
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL);
    InterlockedIncrement(&g_inputRunning);
    MSG m;
    while (GetMessageW(&m, nullptr, 0, 0) > 0) {
        TranslateMessage(&m);
        DispatchMessageW(&m);
    }
    InterlockedDecrement(&g_inputRunning);
    return 0;
}

bool RawInput_Start() {
    HANDLE t = CreateThread(nullptr, 0, InputThread, nullptr, 0, nullptr);
    if (!t) return false;
    CloseHandle(t);
    // 等输入线程就绪（注册完成）
    for (int i = 0; i < 100 && !g_inputRunning; i++) Sleep(10);
    return g_inputRunning != 0;
}

void RawInput_Stop() {
    if (g_inputHwnd) PostMessageW(g_inputHwnd, WM_CLOSE, 0, 0);
}

int RawInput_FindChannel(HANDLE h) {
    for (int i = 0; i < (int)kMaxChannels; i++)
        if (g_ch[i].occupied && g_ch[i].hDevice == h) return i;
    return -1;
}

// UI 100ms tick：统计的会话语义。
// 活动中 → 刷新最大/最小保持寄存器；空闲 ≥600ms → 平均/最大/最小/事件数全部复位
// （当前值 250ms 已先归零，统计在半拍后跟上，下次移动从干净状态重新累计）。
void RawInput_RefreshHolds() {
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    AcquireSRWLockExclusive(&g_lock);
    if (g_selIdx >= 0) {
        Channel& ch = g_ch[g_selIdx];
        if (RawInput_CountIn(g_selIdx, (uint64_t)now.QuadPart,
                              (uint64_t)g_qpcFreq * 3 / 5) == 0) {
            // 空闲 → 复位统计（含保持寄存器与计数桶）
            if (ch.hzMaxHold || ch.totalEvents) {
                ch.hzMaxHold = 0; ch.hzMinHold = 0;
                ch.totalEvents = 0;
                for (uint32_t k = 0; k < kBktN; k++) { ch.bkt[k] = 0; ch.bktEpoch[k] = 0; }
            }
        } else {
            uint64_t curEpoch = (uint64_t)now.QuadPart / ((uint64_t)g_qpcFreq / 10);
            uint64_t epoch0 = curEpoch > kBktN ? curEpoch - kBktN : 0;
            uint32_t mx = 0, mn = 0xFFFFFFFF;
            for (uint32_t k = 0; k < kBktN; k++) {
                if (ch.bktEpoch[k] < epoch0 || ch.bktEpoch[k] >= curEpoch) continue;
                if (ch.bkt[k] > mx) mx = ch.bkt[k];
                if (ch.bkt[k] < mn) mn = ch.bkt[k];
            }
            if (mx > 0) {                    // 窗口内有活动 → 刷新保持值
                ch.hzMaxHold = mx * 10.0;
                ch.hzMinHold = (mn == 0xFFFFFFFF) ? ch.hzMinHold : mn * 10.0;
            }
        }
    }
    ReleaseSRWLockExclusive(&g_lock);
}

static void RawInput_OnInputLocked(WPARAM, LPARAM, const RAWINPUT* prIn, uint64_t nowQpc);

void RawInput_OnInput(WPARAM wParam, LPARAM lParam) {
    // (1) 时间戳最先取：GetRawInputData 的拷贝耗时不进入间隔测量
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);

    // (2) 取报文（栈缓冲；鼠标报文恒小于 sizeof(RAWINPUT)）
    RAWINPUT rin;
    UINT sz = (UINT)sizeof(rin);
    UINT got = GetRawInputData((HRAWINPUT)lParam, RID_INPUT, &rin, &sz,
                               (UINT)sizeof(RAWINPUTHEADER));
    if (got == (UINT)-1 || got == 0) return;
    if (rin.header.dwType != RIM_TYPEMOUSE) return;

    // (3) 此后触及共享状态 → 持锁（UI 仅在短快照期间持共享锁）
    AcquireSRWLockExclusive(&g_lock);
    RawInput_OnInputLocked(wParam, lParam, &rin, (uint64_t)now.QuadPart);
    ReleaseSRWLockExclusive(&g_lock);
}

static void RawInput_OnInputLocked(WPARAM, LPARAM, const RAWINPUT* prIn, uint64_t nowQpc) {

    // (3) 通道查找/创建（线性扫 ≤16；注入事件 hDevice 为 NULL，用 occupied 区分空槽）
    int idx = -1, freeSlot = -1;
    for (int i = 0; i < (int)kMaxChannels; i++) {
        if (g_ch[i].occupied && g_ch[i].hDevice == prIn->header.hDevice) { idx = i; break; }
        if (!g_ch[i].occupied && freeSlot < 0) freeSlot = i;
    }
    if (idx < 0) {
        if (freeSlot < 0) return;             // 表满，忽略新设备
        idx = freeSlot;
        g_ch[idx] = Channel{};                 // 清零后接管
        g_ch[idx].hDevice = prIn->header.hDevice;
        g_ch[idx].occupied = true;
        if (!prIn->header.hDevice) {
            wcscpy(g_ch[idx].name, L"SendInput 注入");
            g_ch[idx].named = true;            // 无实体设备可查询
        }
        g_comboDirtyGen++;
    }
    Channel* ch = &g_ch[idx];

    const RAWMOUSE& m = prIn->data.mouse;

    // (4) 绝对坐标 → 增量
    int32_t dx, dy;
    if (m.usFlags & MOUSE_MOVE_ABSOLUTE) {
        dx = (int32_t)m.lLastX - ch->lastAbsX;
        dy = (int32_t)m.lLastY - ch->lastAbsY;
        ch->lastAbsX = m.lLastX;
        ch->lastAbsY = m.lLastY;
        ch->absolute = true;
    } else {
        dx = m.lLastX;
        dy = m.lLastY;
        ch->absolute = false;
    }
    bool hasMove = (dx != 0 || dy != 0);

    // (5) 按键状态（图标实时更新，与是否计入速率无关）
    USHORT bf = m.usButtonFlags;
    if (bf) {
        if (bf & RI_MOUSE_LEFT_BUTTON_DOWN)  g_buttonBits |= MB_L;
        if (bf & RI_MOUSE_LEFT_BUTTON_UP)    g_buttonBits &= ~MB_L;
        if (bf & RI_MOUSE_RIGHT_BUTTON_DOWN) g_buttonBits |= MB_R;
        if (bf & RI_MOUSE_RIGHT_BUTTON_UP)   g_buttonBits &= ~MB_R;
        if (bf & RI_MOUSE_MIDDLE_BUTTON_DOWN) g_buttonBits |= MB_M;
        if (bf & RI_MOUSE_MIDDLE_BUTTON_UP)   g_buttonBits &= ~MB_M;
        if (bf & RI_MOUSE_BUTTON_4_DOWN)     g_buttonBits |= MB_4;
        if (bf & RI_MOUSE_BUTTON_4_UP)       g_buttonBits &= ~MB_4;
        if (bf & RI_MOUSE_BUTTON_5_DOWN)     g_buttonBits |= MB_5;
        if (bf & RI_MOUSE_BUTTON_5_UP)       g_buttonBits &= ~MB_5;
        if (bf & RI_MOUSE_HWHEEL) {          // 倾轮：正=右，负=左，闪烁 150ms
            SHORT hd = (SHORT)m.usButtonData;
            if (hd < 0)      g_flashQpc[MBX_TL] = nowQpc;
            else if (hd > 0) g_flashQpc[MBX_TR] = nowQpc;
        }
        if (bf & RI_MOUSE_WHEEL)
            g_flashQpc[MBX_W] = nowQpc;
    }

    if (g_set.paused) { ch->lastQpc = 0; return; }
    // 计数模式（D 键切换，默认全部报文/Razer 语义）：零位移报文也是真实报文；
    // 仅位移模式（Areson 语义）下滤掉零位移报文。
    // 自动选设备的"活跃度"两种模式下都按有位移报文统计（MovedIn），防触摸板劫持。
    if (!g_set.countAll && !hasMove) return;

    // (6) 瞬时速率 + 双守卫：
    //     dt > 100ms → 空闲间隙；dt < 20µs → 消息积压后的连发伪影（非真实报文间隔）
    uint64_t dt = 0;
    double   instHz = 0.0;
    bool     gap = true;
    if (ch->lastQpc) {
        dt = nowQpc - ch->lastQpc;
        uint64_t dtFloor = (uint64_t)g_qpcFreq / 50000;          // 20 µs
        if (dt >= dtFloor && dt < (uint64_t)g_qpcFreq / 10) {
            instHz = (double)g_qpcFreq / (double)dt;   // 全精度，无 ms 截断
            gap = false;
        }
    }
    ch->lastQpc = nowQpc;
    if (hasMove) {              // X/Y 面板显示最近一次非零位移（零位移报文不刷掉）
        ch->lastDx = dx;
        ch->lastDy = dy;
    }
    ch->totalEvents++;

    // (7) 环形缓冲写入（懒分配一次）
    if (!ch->buf) {
        ch->buf = (MouseEvent*)VirtualAlloc(nullptr,
                    sizeof(MouseEvent) * kRingCap,
                    MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
        if (!ch->buf) { ch->count = 0; return; }
    }
    ch->buf[ch->count % kRingCap] = MouseEvent{ nowQpc, dx, dy };
    ch->count++;

    // (9b) 100ms 计数桶（最大/最小显示值的数据源，抗出队抖动）
    {
        uint64_t epoch = nowQpc / ((uint64_t)g_qpcFreq / 10);
        uint32_t slot = (uint32_t)(epoch % kBktN);
        if (ch->bktEpoch[slot] != epoch) {
            ch->bktEpoch[slot] = epoch;
            ch->bkt[slot] = 0;
        }
        ch->bkt[slot]++;
    }

    // (10) 轨迹（仅选中通道）：按住左键画绿线 / 按住右键画红线，只滑动不画
    if (idx == g_selIdx) {
        uint8_t col = 0;
        if (g_buttonBits & MB_L)      col = 1;
        else if (g_buttonBits & MB_R) col = 2;
        if (col) {
            POINT pt;
            if (GetCursorPos(&pt)) {
                uint64_t last = g_trajCount % kTrajCap;
                bool dup = g_trajCount > 0 &&
                    g_traj[(last + kTrajCap - 1) % kTrajCap].x == (double)pt.x &&
                    g_traj[(last + kTrajCap - 1) % kTrajCap].y == (double)pt.y;
                if (!dup) {
                    g_traj[g_trajCount % kTrajCap] =
                        TrajPoint{ (double)pt.x, (double)pt.y, col };
                    g_trajCount++;
                }
            }
        }
    }

    // (11) CSV（仅内存缓冲；刷盘在 100ms 定时器）
    if (g_set.logging && idx == g_selIdx)
        Csv_Append(nowQpc, dt, dx, dy, instHz);
}

// 环上二分定位窗口起点（内部共用）
static uint64_t RingLowerBound(Channel& ch, uint64_t cutoff) {
    uint64_t lo = ch.count > kRingCap ? ch.count - kRingCap : 0;
    uint64_t a = lo, b = ch.count;          // [a, b) 找第一个 >= cutoff
    while (a < b) {
        uint64_t mid = a + (b - a) / 2;
        if (ch.buf[mid % kRingCap].qpc < cutoff) a = mid + 1;
        else b = mid;
    }
    return a;
}

// 窗口内全部报文数（回报率显示用）
int RawInput_CountIn(int idx, uint64_t nowQpc, uint64_t spanQpc) {
    Channel& ch = g_ch[idx];
    if (!ch.buf || ch.count == 0) return 0;
    return (int)(ch.count - RingLowerBound(ch, nowQpc - spanQpc));
}

// 窗口内有位移的报文数（自动选设备活跃度用，防零位移流式设备劫持）
int RawInput_MovedIn(int idx, uint64_t nowQpc, uint64_t spanQpc) {
    Channel& ch = g_ch[idx];
    if (!ch.buf || ch.count == 0) return 0;
    uint64_t a = RingLowerBound(ch, nowQpc - spanQpc);
    int n = 0;
    for (uint64_t i = a; i < ch.count; i++) {
        const MouseEvent& e = ch.buf[i % kRingCap];
        if (e.dx != 0 || e.dy != 0) n++;
    }
    return n;
}

void RawInput_ClearChannel(int idx) {
    if (idx < 0 || idx >= (int)kMaxChannels) return;
    AcquireSRWLockExclusive(&g_lock);
    Channel& ch = g_ch[idx];
    ch.count = 0;
    ch.lastQpc = 0;
    for (uint32_t k = 0; k < kBktN; k++) { ch.bkt[k] = 0; ch.bktEpoch[k] = 0; }
    ch.hzMaxHold = 0; ch.hzMinHold = 0;
    ch.totalEvents = 0;
    g_trajCount = 0; g_trajX = 0; g_trajY = 0;
    ReleaseSRWLockExclusive(&g_lock);
}

void RawInput_ResetAllDt() {
    AcquireSRWLockExclusive(&g_lock);
    for (uint32_t i = 0; i < kMaxChannels; i++)
        g_ch[i].lastQpc = 0;                 // 强制下一事件为基准，不产生 dt 尖峰
    ReleaseSRWLockExclusive(&g_lock);
}

// ---- 设备命名（冷路径，100ms 定时器，每 tick 最多 1 个；I/O 无锁，写回持锁）----
static void ResolveName(int idx) {
    wchar_t devName[512];
    UINT sz = (UINT)(sizeof(devName) / sizeof(wchar_t));
    HANDLE hDev;
    {
        AcquireSRWLockShared(&g_lock);
        hDev = g_ch[idx].hDevice;
        ReleaseSRWLockShared(&g_lock);
    }
    uint32_t vid = 0, pid = 0;
    wchar_t prod[128] = L"";
    UINT r = GetRawInputDeviceInfoW(hDev, RIDI_DEVICENAME, devName, &sz);
    if (r != 0 && r != (UINT)-1) {
        devName[511] = L'\0';
        // 解析 VID/PID（路径形如 \\?\hid#vid_1532&pid_00ab&mi_00#...）
        wchar_t up[512];
        wcsncpy(up, devName, 511); up[511] = L'\0';
        _wcsupr(up);
        wchar_t* pv = wcsstr(up, L"VID_");
        if (pv) swscanf(pv + 4, L"%4X", &vid);
        wchar_t* pp = wcsstr(up, L"PID_");
        if (pp) swscanf(pp + 4, L"%4X", &pid);
        // 产品名：CreateFile(GENERIC_READ) + HidD_GetProductString；失败退化
        HANDLE h = CreateFileW(devName, GENERIC_READ,
                               FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr,
                               OPEN_EXISTING, 0, nullptr);
        if (h == INVALID_HANDLE_VALUE)
            h = CreateFileW(devName, 0, FILE_SHARE_READ | FILE_SHARE_WRITE,
                            nullptr, OPEN_EXISTING, 0, nullptr);
        if (h != INVALID_HANDLE_VALUE) {
            HidD_GetProductString(h, prod,
                                  (int)(sizeof(prod) - sizeof(wchar_t)));
            CloseHandle(h);
        }
    }
    AcquireSRWLockExclusive(&g_lock);
    Channel& ch = g_ch[idx];
    if (prod[0]) {
        wcsncpy(ch.name, prod, 127);
        ch.name[127] = L'\0';
    } else if (vid || pid) {
        swprintf(ch.name, 128, L"HID 鼠标 (VID_%04X PID_%04X)", vid, pid);
    } else {
        swprintf(ch.name, 128, L"鼠标设备 #%d", idx + 1);
    }
    ch.vid = vid; ch.pid = pid;
    ch.named = true;
    ReleaseSRWLockExclusive(&g_lock);
    g_comboDirtyGen++;
}

void RawInput_ResolveNamesStep() {
    for (uint32_t i = 0; i < kMaxChannels; i++) {
        if (g_ch[i].occupied && !g_ch[i].named) { ResolveName((int)i); return; }
    }
}

void RawInput_UpdatePresence() {
    UINT n = 0;
    if (GetRawInputDeviceList(nullptr, &n, sizeof(RAWINPUTDEVICELIST)) != 0 ||
        n == 0)
        return;
    RAWINPUTDEVICELIST* lst = new RAWINPUTDEVICELIST[n];
    UINT n2 = n;
    if (GetRawInputDeviceList(lst, &n2, sizeof(RAWINPUTDEVICELIST)) == (UINT)-1) {
        delete[] lst;
        return;
    }
    AcquireSRWLockExclusive(&g_lock);
    for (uint32_t i = 0; i < kMaxChannels; i++) {
        if (!g_ch[i].occupied) continue;
        if (!g_ch[i].hDevice) { g_ch[i].present = true; continue; }  // 注入通道
        bool present = false;
        for (UINT k = 0; k < n2; k++) {
            if (lst[k].hDevice == g_ch[i].hDevice &&
                lst[k].dwType == RIM_TYPEMOUSE) { present = true; break; }
        }
        g_ch[i].present = present;
    }
    ReleaseSRWLockExclusive(&g_lock);
    delete[] lst;
}

// ---- 自动选设备（带迟滞：挑战者需 2× 优势且持续 200ms；当前闲置 1s 才让位）----
void AutoSelect() {
    AcquireSRWLockExclusive(&g_lock);
    if (g_set.manualPin == INVALID_HANDLE_VALUE) {      // X 键：锁定注入通道
        int idx = RawInput_FindChannel(nullptr);
        if (idx >= 0 && idx != g_selIdx) { g_selIdx = idx; g_trajCount = 0; }
        ReleaseSRWLockExclusive(&g_lock);
        return;
    }
    if (g_set.manualPin) {
        int idx = RawInput_FindChannel(g_set.manualPin);
        if (idx >= 0 && idx != g_selIdx) { g_selIdx = idx; g_trajCount = 0; g_trajX = g_trajY = 0; }
        ReleaseSRWLockExclusive(&g_lock);
        return;
    }
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    const uint64_t span300 = (uint64_t)g_qpcFreq * 3 / 10;

    static int idleTicks = 0, challTicks = 0;
    int act[kMaxChannels];
    int best = -1, bestA = 0;
    for (int i = 0; i < (int)kMaxChannels; i++) {
        act[i] = g_ch[i].occupied ? RawInput_MovedIn(i, (uint64_t)now.QuadPart, span300) : 0;
        if (best < 0 || act[i] > bestA) { best = i; bestA = act[i]; }
    }
    if (g_selIdx < 0) {                       // 尚无选择：够活跃即锁定
        if (bestA >= 10) {
            g_selIdx = best;
            g_trajCount = 0; g_trajX = g_trajY = 0;
            idleTicks = challTicks = 0;
        }
        ReleaseSRWLockExclusive(&g_lock);
        return;
    }
    int aSel = act[g_selIdx];
    if (aSel < 5) idleTicks++; else idleTicks = 0;
    bool challenger = (best != g_selIdx) && bestA >= 50 &&
                      bestA >= 2 * (aSel > 1 ? aSel : 1);
    if (idleTicks >= 10 && bestA >= 20) {     // 当前设备闲置 1s
        g_selIdx = best;
        g_trajCount = 0; g_trajX = g_trajY = 0;
        idleTicks = challTicks = 0;
    } else if (challenger && ++challTicks >= 2) {  // 持续 200ms 的 2× 优势
        g_selIdx = best;
        g_trajCount = 0; g_trajX = g_trajY = 0;
        idleTicks = challTicks = 0;
    } else if (!challenger) {
        challTicks = 0;
    }
    ReleaseSRWLockExclusive(&g_lock);
}
