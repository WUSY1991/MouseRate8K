// csvlog.h — 逐事件 CSV 日志（Razer X,Y,Delta(ms) 的超集，微秒精度）
#pragma once
#include "common.h"

bool     Csv_Start();                                   // 建文件写表头
void     Csv_Stop();                                    // 刷盘关闭
void     Csv_Append(uint64_t qpc, uint64_t dtQpc, int dx, int dy, double instHz);
void     Csv_Tick();                                    // 100ms 定时刷盘
uint64_t Csv_Rows();
bool     Csv_IsOpen();
