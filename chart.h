// chart.h — GDI 双缓冲渲染（曲线 / 大数字 / 轨迹 / 按键 / 状态栏）
#pragma once
#include "common.h"

void Chart_OnSize(HWND hwnd, int w, int h, UINT dpi);   // 布局 + 重建内存位图
void Chart_OnDpiChange(HWND hwnd, UINT dpi);            // 重建字体
void Chart_Paint(HWND hwnd, HDC hdc);
void Chart_Destroy();
void ComputeLayout(int w, int h, UINT dpi);
void Chart_SetPaintInterval(HWND hwnd, UINT ms);        // 自适应重绘节奏
const wchar_t* ScaleName(int idx);                      // 量程显示名
int  ScaleValue(int idx);                               // 量程 Hz 值（自动返回 0）
