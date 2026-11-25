// csvlog.cpp — 缓冲 CSV 写入
// 铁律：磁盘 I/O 只发生在 UI 线程（100ms tick / stop），输入线程只 snprintf 进内存。
// 双缓冲交换：UI 在短临界区内换走待写缓冲，WriteFile 在锁外执行。
#include "csvlog.h"
#include <cstdio>
#include <vector>
#include <cstring>

static SRWLOCK     g_csvLock = SRWLOCK_INIT;
static std::vector<char> g_buf;          // 输入线程追加（持 g_csvLock）
static std::vector<char> g_out;          // UI 线程换出后写盘（无锁）
static size_t        g_len = 0;
static uint64_t      g_rows = 0;
static HANDLE        g_file = nullptr;

uint64_t Csv_Rows() { return g_rows; }
bool     Csv_IsOpen() { return g_file != nullptr; }

// 仅 UI 线程调用；把待写数据换到 g_out 后在锁外 WriteFile
static void Csv_SwapAndWrite(bool force) {
    if (!g_file) return;
    bool needWrite = false;
    AcquireSRWLockExclusive(&g_csvLock);
    if (g_len > 0 && (force || g_len > 64 * 1024)) {
        g_out.assign(g_buf.begin(), g_buf.begin() + g_len);
        g_len = 0;
        needWrite = true;
    }
    ReleaseSRWLockExclusive(&g_csvLock);
    if (!needWrite) return;
    DWORD written = 0;
    WriteFile(g_file, g_out.data(), (DWORD)g_out.size(), &written, nullptr);
}

bool Csv_Start() {
    if (g_file) return true;
    wchar_t dir[MAX_PATH];
    GetModuleFileNameW(nullptr, dir, MAX_PATH);
    wchar_t* p = wcsrchr(dir, L'\\');
    if (p) *p = L'\0'; else wcscpy(dir, L".");
    SYSTEMTIME st;
    GetLocalTime(&st);
    wchar_t path[MAX_PATH];
    swprintf(path, MAX_PATH,
             L"%s\\PollingRate_Log_%04u%02u%02u%02u%02u%02u.csv",
             dir, st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    g_file = CreateFileW(path, GENERIC_WRITE, 0, nullptr,
                         CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
                         nullptr);
    if (g_file == INVALID_HANDLE_VALUE) { g_file = nullptr; return false; }
    AcquireSRWLockExclusive(&g_csvLock);
    if (g_buf.empty()) g_buf.resize(2u << 20);    // 2 MiB
    g_len = 0;
    g_rows = 0;
    const char hdr[] = "Seq,Time_s,dt_us,X,Y,InstHz\r\n";
    g_buf.resize(g_buf.size());
    memcpy(g_buf.data(), hdr, sizeof(hdr) - 1);
    g_len += sizeof(hdr) - 1;
    ReleaseSRWLockExclusive(&g_csvLock);
    Csv_SwapAndWrite(true);
    return true;
}

void Csv_Stop() {
    if (!g_file) return;
    Csv_SwapAndWrite(true);
    CloseHandle(g_file);
    g_file = nullptr;
}

void Csv_Append(uint64_t qpc, uint64_t dtQpc, int dx, int dy, double instHz) {
    if (!g_file) return;
    // 会话边界（上一轮测试遗留的 dt）记 0
    if (dtQpc > (uint64_t)g_qpcFreq) dtQpc = 0;
    double tSec = (double)(int64_t)(qpc - g_startQpc) / (double)g_qpcFreq;
    double dtUs = (double)(int64_t)dtQpc * 1e6 / (double)g_qpcFreq;
    char line[160];
    int n = snprintf(line, sizeof(line), "%llu,%.6f,%.3f,%d,%d,%.2f\r\n",
                     (unsigned long long)(g_rows + 1), tSec, dtUs, dx, dy, instHz);
    if (n <= 0) return;
    AcquireSRWLockExclusive(&g_csvLock);   // 仅内存操作（~百 ns）
    if (g_len + (size_t)n + 16 > g_buf.size()) {
        ReleaseSRWLockExclusive(&g_csvLock);
        return;                             // 缓冲满：丢行（UI tick 会很快换出）
    }
    memcpy(g_buf.data() + g_len, line, (size_t)n);
    g_len += (size_t)n;
    g_rows++;
    ReleaseSRWLockExclusive(&g_csvLock);
}

void Csv_Tick() {
    Csv_SwapAndWrite(false);
}
