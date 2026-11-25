// rawinput_engine.h — Raw Input 采集引擎（热路径 + 枚举 + 自动选设备）
#pragma once
#include "common.h"

bool RawInput_Start();                                   // 启动输入线程（message-only 窗口 + 注册）
void RawInput_Stop();
void RawInput_OnInput(WPARAM wParam, LPARAM lParam);     // WM_INPUT 热路径（输入线程内，持锁）
int  RawInput_CountIn(int idx, uint64_t nowQpc, uint64_t spanQpc); // 窗口内全部报文数（速率显示）
int  RawInput_MovedIn(int idx, uint64_t nowQpc, uint64_t spanQpc); // 窗口内有位移报文数（自动选择）
void RawInput_ResolveNamesStep();                        // 100ms：给未命名通道取名（每 tick ≤1 个）
void RawInput_ClearChannel(int idx);                     // C 键清零（UI 持独占锁调用）
void RawInput_ResetAllDt();                              // 消除 dt 尖峰（UI 持独占锁调用）
void RawInput_UpdatePresence();                          // 设备在线状态刷新
void RawInput_RefreshHolds();                            // UI tick：max/min 保持寄存器刷新
int  RawInput_FindChannel(HANDLE h);
void AutoSelect();                                       // 带迟滞的自动设备选择（UI tick）
