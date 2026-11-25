using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;
using pollingrateapplication;

namespace RawInput;

[StructLayout(LayoutKind.Explicit)]
internal struct Rawmouse
{
	[FieldOffset(0)]
	public ushort usFlags;

	[FieldOffset(4)]
	public uint ulButtons;

	[FieldOffset(4)]
	public ushort usButtonFlags;

	[FieldOffset(6)]
	public ushort usButtonData;

	[FieldOffset(8)]
	public uint ulRawButtons;

	[FieldOffset(12)]
	public int lLastX;

	[FieldOffset(16)]
	public int lLastY;

	[FieldOffset(20)]
	public uint ulExtraInformation;
}
public sealed class RawMouse
{
	protected const int DIGCF_PRESENT = 2;

	protected const int DIGCF_DEVICEINTERFACE = 16;

	public const uint GENERIC_READ = 2147483648u;

	public const uint GENERIC_WRITE = 1073741824u;

	public const uint FILE_SHARE_WRITE = 2u;

	public const uint FILE_SHARE_READ = 1u;

	public const uint FILE_FLAG_OVERLAPPED = 1073741824u;

	protected const uint OPEN_EXISTING = 3u;

	public Queue<long> Pktlist = new Queue<long>();

	public readonly Dictionary<string, IntPtr> _deviceList = new Dictionary<string, IntPtr>();

	private readonly object _padLock = new object();

	private static InputData _rawBuffer;

	[DllImport("Kernel32.dll")]
	private static extern bool QueryPerformanceCounter(out long lpPerformanceCount);

	[DllImport("kernel32.dll", SetLastError = true)]
	public static extern int CloseHandle(IntPtr hFile);

	[DllImport("kernel32.dll", SetLastError = true)]
	public static extern IntPtr CreateFile([MarshalAs(UnmanagedType.LPStr)] string strName, uint nAccess, uint nShareMode, IntPtr lpSecurity, uint nCreationFlags, uint nAttributes, IntPtr lpTemplate);

	[DllImport("HID.dll", CallingConvention = CallingConvention.StdCall, SetLastError = true)]
	public static extern bool HidD_GetProductString(IntPtr HidDeviceObject, [Out][MarshalAs(UnmanagedType.LPWStr)] StringBuilder Buffer, int BufferLength);

	public RawMouse(IntPtr hwnd, bool captureOnlyInForeground)
	{
		RawInputDevice[] array = new RawInputDevice[1];
		array[0].UsagePage = HidUsagePage.GENERIC;
		array[0].Usage = HidUsage.Mouse;
		array[0].Flags = ((!captureOnlyInForeground) ? RawInputDeviceFlags.INPUTSINK : RawInputDeviceFlags.NONE) | RawInputDeviceFlags.DEVNOTIFY;
		array[0].Target = hwnd;
		if (!Win32.RegisterRawInputDevices(array, (uint)array.Length, (uint)Marshal.SizeOf((object)array[0])))
		{
			throw new ApplicationException("Failed to register raw input device(s).");
		}
	}

	public void EnumerateDevices()
	{
		lock (_padLock)
		{
			_deviceList.Clear();
			uint numberDevices = 0u;
			int num = Marshal.SizeOf(typeof(Rawinputdevicelist));
			if (Win32.GetRawInputDeviceList(IntPtr.Zero, ref numberDevices, (uint)num) == 0)
			{
				IntPtr intPtr = Marshal.AllocHGlobal((int)(num * numberDevices));
				Win32.GetRawInputDeviceList(intPtr, ref numberDevices, (uint)num);
				for (int i = 0; i < numberDevices; i++)
				{
					uint size = 0u;
					Rawinputdevicelist rawinputdevicelist = (Rawinputdevicelist)Marshal.PtrToStructure(new IntPtr(intPtr.ToInt64() + num * i), typeof(Rawinputdevicelist));
					Win32.GetRawInputDeviceInfo(rawinputdevicelist.hDevice, RawInputDeviceInfo.RIDI_DEVICENAME, IntPtr.Zero, ref size);
					if (size != 0)
					{
						IntPtr intPtr2 = Marshal.AllocHGlobal((int)size);
						Win32.GetRawInputDeviceInfo(rawinputdevicelist.hDevice, RawInputDeviceInfo.RIDI_DEVICENAME, intPtr2, ref size);
						string key = Marshal.PtrToStringAnsi(intPtr2);
						if (rawinputdevicelist.dwType == 0)
						{
							_deviceList.Add(key, rawinputdevicelist.hDevice);
						}
						Marshal.FreeHGlobal(intPtr2);
					}
				}
				Marshal.FreeHGlobal(intPtr);
				return;
			}
		}
		throw new Win32Exception(Marshal.GetLastWin32Error());
	}

	public void ProcessRawInput(IntPtr lparam, IntPtr hdevice, bool Testing)
	{
		if (!Testing)
		{
			return;
		}
		long lpPerformanceCount = 0L;
		int size = 0;
		Win32.GetRawInputData(lparam, DataCommand.RID_INPUT, IntPtr.Zero, ref size, Marshal.SizeOf(typeof(Rawinputheader)));
		if (Win32.GetRawInputData(lparam, DataCommand.RID_INPUT, out _rawBuffer, ref size, Marshal.SizeOf(typeof(Rawinputheader))) == 0 || !(_rawBuffer.header.hDevice == hdevice))
		{
			return;
		}
		QueryPerformanceCounter(out lpPerformanceCount);
		Common.total++;
		Pktlist.Enqueue(lpPerformanceCount);
		if (Common.logfile)
		{
			if (Pktlist.Count > 1)
			{
				double num = (double)(lpPerformanceCount - Common.lastclock) / (double)Common.freq;
				Common.logstream.WriteLine(_rawBuffer.data.mouse.lLastX + "," + _rawBuffer.data.mouse.lLastY + "," + num * 1000.0);
			}
			else
			{
				Common.logstream.WriteLine(_rawBuffer.data.mouse.lLastX + "," + _rawBuffer.data.mouse.lLastY + ",0");
			}
		}
		Common.lastclock = lpPerformanceCount;
	}

	public string GetDevProductName(string devpath)
	{
		string result = "";
		IntPtr intPtr = CreateFile(devpath, 0u, 3u, IntPtr.Zero, 3u, 0u, IntPtr.Zero);
		if (intPtr.ToInt32() != -1 && intPtr != IntPtr.Zero)
		{
			StringBuilder stringBuilder = new StringBuilder(256);
			HidD_GetProductString(intPtr, stringBuilder, stringBuilder.Capacity);
			result = stringBuilder.ToString();
			CloseHandle(intPtr);
		}
		return result;
	}
}
