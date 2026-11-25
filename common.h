// common.h — 共享类型与全局声明
// 鼠标回报率测试仪 8K（合并 Areson 免配置 + Razer 8K 曲线）
#pragma once

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif

#include <windows.h>
#include <cstdint>

// ---- 常量 ----
constexpr uint32_t kRingSec     = 30;               // 环形缓冲覆盖秒数
constexpr uint32_t kRingCap     = kRingSec * 8192;  // 条目上限（30s @ 8K）≈ 24.6 万条
constexpr uint32_t kMaxChannels = 16;               // 最多同时跟踪设备数
constexpr uint32_t kTrajCap     = 8192;             // 轨迹点环形缓冲
constexpr uint32_t kBktN        = 16;               // 最大/最小统计的 100ms 桶数（1.6s 滚动）

// 按键位标志（L R M 4 5 为闩锁；TL TR W 为闪烁型，存 g_flashQpc）
enum MouseBtnBits : uint32_t {
    MB_L = 1u << 0, MB_R = 1u << 1, MB_M = 1u << 2,
    MB_4 = 1u << 3, MB_5 = 1u << 4,
    MBX_TL = 0, MBX_TR = 1, MBX_W = 2   // 闪烁位在 g_flashQpc 中的下标
};

struct MouseEvent {
    uint64_t qpc;      // WndProc 入口取的 QPC（全精度，不截断）
    int32_t  dx, dy;   // 本报文位移增量
};

struct TrajPoint {          // 屏幕轨迹点（按住按键才记录）
    double   x, y;          // 真实屏幕光标坐标
    uint8_t  col;           // 0=无 1=绿(左键) 2=红(右键)
};

struct Channel {
    HANDLE    hDevice = nullptr;      // SendInput 注入的事件为 NULL
    bool      occupied = false;       // 槽位占用标记（与 hDevice 区分）
    wchar_t   name[128] = L"";
    uint32_t  vid = 0, pid = 0;
    bool      named = false;
    bool      present = true;          // 热插拔在线标记
    bool      absolute = false;        // MOUSE_MOVE_ABSOLUTE 设备（RDP/数位板）
    long      lastAbsX = 0, lastAbsY = 0;
    MouseEvent* buf = nullptr;         // 懒分配 kRingCap 条（VirtualAlloc）
    uint64_t  count = 0;               // 累计写入数；新事件在 (count-1)%cap
    uint64_t  lastQpc = 0;             // 上一事件 QPC（0 = 无基准）
    uint32_t  bkt[kBktN] = {};         // 100ms 计数桶（最大/最小统计，抗出队抖动）
    uint64_t  bktEpoch[kBktN] = {};
    double    hzMaxHold = 0, hzMinHold = 0;  // 保持寄存器：停止后 max/min 维持最后值
    int32_t   lastDx = 0, lastDy = 0;
    uint64_t  totalEvents = 0;
};

struct Settings {
    bool   countAll = true;   // true=全部报文（Razer 语义，默认）；false=仅位移（Areson 语义，D 键切换）
    bool   paused = false;
    bool   logging = false;
    bool   showBand = false;      // 曲线 min-max 带
    HANDLE manualPin = nullptr;   // nullptr = 自动选设备
    int    scaleIdx = 6;          // 预设 {125,250,500,1000,2000,4000,8000}，7=自动
    double xSeconds = 10.0;       // 曲线 X 窗口秒数
};

// ---- 布局（全屏覆盖 + 浮动半透明面板）----
struct LayoutInfo {
    UINT dpi = 96;
    RECT rcHint{};        // 顶中：快捷键提示条
    RECT rcBig{};         // 左上：大数字 + 统计
    RECT rcCurve{};       // 左下：回报率曲线
    RECT rcBtns{};        // 右下：按键图标 + X/Y
    RECT rcChipDev{};     // 右上：设备切换 chip（点击循环）
    RECT rcChipScale{};   // 右上：量程 chip（点击循环）
    int  S(int v) const { return (int)((int64_t)v * dpi / 96); }
};

// ---- 全局（rawinput_engine.cpp / main.cpp 定义）----
extern int64_t     g_qpcFreq;
extern Channel     g_ch[kMaxChannels];
extern int         g_selIdx;            // 当前选中通道，-1 = 无
extern Settings    g_set;
extern uint32_t    g_buttonBits;
extern uint64_t    g_flashQpc[3];       // TL/TR/W 闪烁时间戳
extern TrajPoint   g_traj[kTrajCap];
extern uint64_t    g_trajCount;
extern double      g_trajX, g_trajY;
extern uint64_t    g_startQpc;
extern LayoutInfo  g_layout;
extern uint32_t    g_comboDirtyGen;     // 递增 → 需要重建设备下拉
extern bool        g_devDirty;          // 设备变更置位（输入线程 → UI 轮询）
extern SRWLOCK     g_lock;              // 输入线程(写) ↔ UI(读快照) 单锁
