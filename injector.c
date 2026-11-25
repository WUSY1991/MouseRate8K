// injector.c — C 注入器：以精确 QPC 节拍注入鼠标移动（验证 8K 测量）
// 用法: injector.exe <hz> <seconds>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    if (argc < 3) { printf("usage: injector.exe <hz> <seconds>\n"); return 1; }
    int hz = atoi(argv[1]);
    double secs = atof(argv[2]);
    if (hz < 1 || hz > 64000) { printf("bad hz\n"); return 1; }

    HWND hwnd = FindWindowW(L"MouseRate8KWnd", NULL);
    if (!hwnd) printf("(note: MouseRate8K not running, injecting anyway)\n");

    // 提升定时器分辨率与优先级，降低调度抖动（保证注入节拍精确）
    TIMECAPS tc;
    if (timeGetDevCaps(&tc, sizeof(tc)) == TIMERR_NOERROR)
        timeBeginPeriod(1);
    SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);

    LARGE_INTEGER freq, t0;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&t0);

    printf("injecting %d Hz for %.2fs ... ", hz, secs);

    long long N = (long long)(hz * secs);
    double period = (double)freq.QuadPart / hz;
    long long rejected = 0;

    for (long long i = 1; i <= N; i++) {
        double ang = i * (2.0 * 3.14159265358979 / 256.0);
        INPUT inp;
        memset(&inp, 0, sizeof(inp));
        inp.type = INPUT_MOUSE;
        inp.mi.dx = (LONG)lround(3.0 * cos(ang));
        inp.mi.dy = (LONG)lround(3.0 * sin(ang));
        inp.mi.dwFlags = MOUSEEVENTF_MOVE;

        LARGE_INTEGER now;
        long long tgt = t0.QuadPart + (long long)(period * i);
        for (;;) {
            QueryPerformanceCounter(&now);
            if (now.QuadPart >= tgt) break;
            if (tgt - now.QuadPart > 20000) Sleep(0);   // 等待时让出
        }
        if (SendInput(1, &inp, sizeof(INPUT)) != 1) rejected++;
    }

    LARGE_INTEGER te;
    QueryPerformanceCounter(&te);
    double el = (double)(te.QuadPart - t0.QuadPart) / freq.QuadPart;
    printf("done: %lld moves (rejected %lld) in %.1f ms -> %.1f Hz actual\n",
           N, rejected, el * 1000.0, (N - rejected) / el);

    timeEndPeriod(1);
    return 0;
}
