# 两款鼠标回报率测试软件逆向分析报告

> 分析对象（位于 `d:\12-AI\0-rea\exe2c\`）：
> - `Polling Rate Tester App_v1.02.00.exe`（用户称 "Pollxxx"）
> - `Areson Mouse Test  2.023.exe`
>
> 分析方法（REA 流程）：objdump/strings/pefile 静态 triage → Explore agent 反汇编追踪
> → Ghidra 11.2.1 headless 全量反编译（DecompAll.py，产物在 `analysis/decompiled/`）
> → ilspycmd 8.2 反编译 .NET（产物在 `analysis/decompiled_dotnet/`）。
> 本报告所有结论均有二进制级证据（地址/指令/反编译代码）。

---

## 一、总结论（一句话版）

**两款软件用同一条主干测量回报率：Raw Input（WM_INPUT）+ QueryPerformanceCounter 时间戳，
回报率 = 事件间隔的倒数（或窗口计数）。差异全在实现细节：**
Razer（Pollxxx）逐事件全精度时间戳 + 按 `hDevice` 手动过滤设备 → 能测 8K；
Areson 用"1.5 秒滑窗事件计数 × 2/3"且时间戳截断为整毫秒、环形缓冲只有 2000 格
→ **数学上限 1333 Hz，物理上永远测不到 1K 以上**。

---

## 二、Pollxxx = Razer 官方 "Polling Rate Tester App"

### 2.1 身份
- .NET Framework 4.5 **WPF** 程序，Authenticode 签名 **Razer USA Ltd.**，
  产品链接 `razer.com/gaming-mice/razer-viper-8khz`，PDB 路径 `E:\2017_fwu\...\`，
  图标 `Firmware_Updater_2018.ico`（固件更新器代码库复用）。
- 根命名空间 `pollingrateapplication`，核心类 `MainWindow` / `MenuSetting` / `RawInput.RawMouse`。

### 2.2 测量算法（反编译自 `MainWindow.cs` + `RawInput/Rawmouse.cs`，逐行核实）

1. **注册**：`RawMouse(hwnd, captureOnlyInForeground:false)` →
   `RegisterRawInputDevices({GenericDesktop/Mouse, INPUTSINK|DEVNOTIFY, hwnd})`
   （DEVNOTIFY 让 WM_DEVICECHANGE 直达，实现热插拔重枚举）
2. **逐事件**（`WndProc` case 255 → `ProcessRawInput(lParam, DevHandle, Testing)`）：
   ```csharp
   GetRawInputData(RID_INPUT, ...)                       // 查长 + 取数两次调用
   if (返回0 || header.hDevice != hdevice) return;       // ★ 按 hDevice 过滤（手选设备的真相）
   QueryPerformanceCounter(out qpc);
   Pktlist.Enqueue(qpc);                                 // 只入队时间戳
   if (logfile) logstream.WriteLine(X + "," + Y + "," + delta_ms);  // CSV: X,Y,Delta(ms)
   ```
   **没有位移过滤**——零位移报文也计数（依赖 8K 鼠标"动才发报"的特性）。
3. **显示**（`BgWorker_DoWork` 每 `sampletime=1000ms` 触发一次 `ProgressChanged`）：
   ```csharp
   samplecount = Pktlist 中 ≤ 上一秒起点的时间戳个数（即 1 秒内事件数）
   if (samplecount > targetpollingrate) samplecount = targetpollingrate;  // ★ 钳制到量程
   大数字 = samplecount；表盘指针角度 = samplecount*100/target
   ```
4. **曲线**：`pollingratelist` 队列存每秒的 samplecount，保留 **91 个点 × 5px**；
   Y 轴映射区间 **[target−15%, target] → [450px, 0px]**，区间外钳到顶/底；
   WPF Canvas + 代码构造荧光绿 Polyline（非 XAML）。Razer 设备（VID 1532）用 lime，
   其他厂商（"COMPETITOR"皮肤）用蓝 #047EDC。

### 2.3 为什么"必须手选设备才能测 8K"
Raw Input **只能按 usage 类注册（整类鼠标），不能按单个设备注册** → 应用收到
所有指向设备的 WM_INPUT。Razer 的解法是让用户在 MenuSetting 里选中一个设备，
然后用 `header.hDevice == DevHandle` 过滤。不选（或选错）时多设备事件交织
（触摸板/接收器/第二鼠标），125µs 量级的间隔完全失真。
**手选不是 8K 的必要条件，只是它把"按设备归因"做成了手动步骤。**

### 2.4 交互
快捷键 S 开始 / P 暂停 / C 清零 / M 设置 / ESC 退出；量程下拉
125/250/500/1000/2000/4000/8000；满屏 1920×1080 无边框 + ScaleTransform 适配。

---

## 三、Areson Mouse Test 2.023

### 3.1 身份
MFC42（VC6 时代）原生 C++，2010-01-11 链接，内部名 "Mouse Test 2008"，
窗口标题 `"Mouse Test by Areson - %s"`。厂商产测工具（HID Feature 配置 + 串口功率计 +
EEPROM 产测 + 固件升级 + 传感器数据库 Nova231G/FD8 系列…）。

### 3.2 测量算法（objdump 反汇编 + Ghidra 反编译双重核实）

1. **注册**（OnInitDialog `0x404ad0`，调用点 `0x404d97`）：**一次注册 2 个设备**
   - dev[0] = {page 1, **usUsage=0**, flags **0x20(未公开)**} —— 异常组合，疑似 bug
   - dev[1] = {**page 0xFF03**（厂商定义页）, usage 1, RIDEV_INPUTSINK} —— 收 DPI/模式按键
   - 整体成功与否存 `0x41efb4`；**失败则回退用 WM_MOUSEMOVE 喂时间戳**
     （`0x40654d`，legacy 消息被系统合并 → 天然 ~1K）
2. **时间戳**：`PreTranslateMessage (0x406000)` 里对每条泵出的消息：
   `(QPC × 1000) / QPF` → **整数毫秒**（`__allmul`+`__alldiv`）—— 8K 间隔 125µs
   在这里直接不可分辨
3. **WM_INPUT 处理**（`0x4125b0`）：GetRawInputData ×2（查长+取数）→
   RIM_TYPEMOUSE 分支 **只记录有位移事件**（`X==0 && Y==0` 跳过）→
   写入 **固定 2000 格时间戳环形缓冲**（`0x41a228`，`(idx+1) % 2000`）
4. **回报率计算**（`0x407430`，OnTimer 65ms 调用）：
   ```
   N = 环内时间戳距今 < 1500ms 的个数
   rate = 2N/3        （魔数 0x55555556 = 除以 3）
   显示 "Report Rate : %-3d"（100ms 定时器，值不变不重绘）
   ```

### 3.3 1K 上限的三重根因
| # | 根因 | 证据 |
|---|---|---|
| 1 | **2000 格环 × 1500ms 窗 → rate ≤ 2×2000/3 = 1333 Hz**；≥1334Hz 的鼠标自己覆盖自己的历史 | `0x41280a: div ebx(0x7D0=2000)`；`0x407460: mov eax,0x55555556; imul ecx` |
| 2 | 时间戳取自消息泵 + **整毫秒截断**，125µs 间隔不可分辨 | `0x406057: push 0x3E8`（×1000） |
| 3 | usUsage=0 异常注册失败 → WM_MOUSEMOVE 回退（系统合并 ≈1K） | `0x406571: cmp …,0x200` + `DAT_0041efb4==0` 守卫（Ghidra 反编译确认同构代码） |

时代佐证：内置模式表字面写着 `" - Gaming Test (1000 report rate)"`。

### 3.4 其他能力（本次不合并，已逆向存档）
- HID Feature 协议：`{00 01 02 00 … 12}` / `{00 03 02 0C 12}`，应答 bit：byte[1]&0x40，
  全程临界区 `0x419e98`；厂商输入报文 8 字节（byte[0x0A]=DPI 事件携带 16 位值）
- 串口 115200-8N1 连**外部功率计**（"Power : %-0.4f µW"），非鼠标
- SetTimer 表：100ms 显示 / 100ms 绘图 / **1ms 光标锁定** / 65ms 扫描 / 600ms / 100ms / 80ms

---

## 四、对比总表

| | Razer Polling Rate Tester | Areson Mouse Test | **本软件 MouseRate8K** |
|---|---|---|---|
| 框架 | .NET 4.5 WPF | MFC42 原生 C++ | 纯 Win32 C++（MSVC /MT 单 exe）|
| 时间戳 | 逐事件 QPC 全精度 | 消息泵 + 整 ms 截断 | 专用输入线程入口 QPC 全精度 |
| 算法 | 1s 窗口计数（钳到量程）| 1.5s 窗计数 ×2/3 | 250ms 窗计数（大数字）+ 逐事件 1/Δt（曲线）|
| 上限 | 8000（量程表）| **1333（数学硬上限）** | 无上限（环 30s×8192 格/秒）|
| 设备选择 | **手动必选**（hDevice 过滤）| 无需选择 | **自动锁定活动设备**（300ms 活跃度 + 2× 迟滞）+ 可手选 |
| 曲线 | 每秒 1 点 × 91 点，[85%,100%] 钳制 | 无 | 逐事件瞬时 Hz，按像素列分桶，30fps |
| 轨迹 | 无 | Auto Plot（小画布）| **满屏、画在光标真实位置** |
| 按键指示 | 无 | L R M 4 5 TL TR（图标）| L R M 4 5 TL TR 滚轮（浮层面板）|
| CSV | X,Y,Delta(ms) | 无 | Seq,Time_s,dt_us,X,Y,InstHz（微秒级）|
| 多设备抗交织 | 手选规避 | 无处理 | **按 hDevice 分通道**（Razer 的教训 + 免手选）|

## 五、原版 Areson 直接补丁 → "Areson Mouse Test Pro 8K"

除自研 MouseRate8K 外，还按用户要求**直接给原版 exe 打了二进制补丁**
（`areson_patch.py` → `Areson Mouse Test Pro 8K.exe`），4 处等长字节替换：

| # | 位置(file) | 原指令 | 补丁 | 作用 |
|---|---|---|---|---|
| P1 | 0x6058 | `push 0x3E8` | `push 0xF4240` | 时间戳乘数 ×1000→×1000000：ms→µs（修根因②）|
| P2 | 0x7449 | `cmp edi,0x5DC` | `cmp edi,0x30D40` | 速率窗 1500ms→200ms（修根因①a）|
| P3 | 0x745d | `lea ecx,[edx+edx]; mov eax,0x55555556; imul ecx` | `lea edx,[edx+edx*4]+nop×7` | 换算 ×2/3→×5（修根因①b）|
| P5 | 0x1859c | 标题串 | "Areson Mouse Test Pro %s" | Pro 化 |

数学：200ms 窗 × 2000 格环 → 上限 2000/0.2 = **10000 Hz**（8K 有 25% 余量）；
µs 存 32 位 71 分钟回绕，无符号减法对 <200ms 差值天然安全。
**注册代码未动**：实测 Win11 接受原版 `{page1,usage0,flags0x20}` 注册（运行时
`0x41efb4=1` 证实），根因③（WM_MOUSEMOVE 回退）不活跃。

### 实测对照（ReadProcessMemory 直读 0x41f034 速率全局）
| 注入 | 原版读数 | Pro 补丁版读数 |
|---|---|---|
| 1000 Hz | ~1000（本来就对）| **1000（+0.0%）** |
| 4000 Hz（实际 3999.6）| **1333 死锁**（=2000×2/3 硬上限，逆向预测精确命中）| **4005（+0.1%）** |
| 8000 Hz（环境限速实际 ~4742）| **1333 死锁** | **4815（忠实反映实际送达）** |

## 六、本软件的防伪影设计（Razer/Areson 都没有的）

实测发现（合成注入验证）：UI 线程任何毫秒级停顿都会造成 WM_INPUT 积压，
恢复后连发事件的出队时间戳间隔失真（±50µs 抖动、假高峰）。对策：
1. **输入线程隔离**：专用 message-only 窗口线程只做收报文+时间戳，绝不绘制
2. **快照-绘制两段式**：UI 持共享锁只做 ~百 µs 级数据快照，绘制无锁
3. **CSV 磁盘 I/O 只在 UI 线程**，双缓冲交换（输入线程只 snprintf 进内存）
4. **20µs dt 下限**（连发伪影守卫）+ 100ms 上限（空闲间隙守卫）
5. **最大/最小统计用 100ms 计数桶 ×10**（计数语义天然抗出队抖动，均值仍用 Σdt 精确值）

另注：SendInput 合成注入的吞吐受系统环境影响（Defender/VM 活动时会被合并到 ~125Hz，
与监听者无关——已用无 GUI 探针对照证实）；**物理鼠标走 USB 中断路径，不受此影响**。
