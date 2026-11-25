using System;
using System.Runtime.InteropServices;

namespace RawInput;

public static class Win32
{
	public const int KEYBOARD_OVERRUN_MAKE_CODE = 255;

	public const int WM_APPCOMMAND = 793;

	private const int FAPPCOMMANDMASK = 61440;

	internal const int FAPPCOMMANDMOUSE = 32768;

	internal const int FAPPCOMMANDOEM = 4096;

	public const int WM_KEYDOWN = 256;

	public const int WM_KEYUP = 257;

	internal const int WM_SYSKEYDOWN = 260;

	internal const int WM_INPUT = 255;

	internal const int WM_USB_DEVICECHANGE = 537;

	internal const int VK_SHIFT = 16;

	internal const int RI_KEY_MAKE = 0;

	internal const int RI_KEY_BREAK = 1;

	internal const int RI_KEY_E0 = 2;

	internal const int RI_KEY_E1 = 4;

	internal const int VK_CONTROL = 17;

	internal const int VK_MENU = 18;

	internal const int VK_ZOOM = 251;

	internal const int VK_LSHIFT = 160;

	internal const int VK_RSHIFT = 161;

	internal const int VK_LCONTROL = 162;

	internal const int VK_RCONTROL = 163;

	internal const int VK_LMENU = 164;

	internal const int VK_RMENU = 165;

	internal const int SC_SHIFT_R = 54;

	internal const int SC_SHIFT_L = 42;

	internal const int RIM_INPUT = 0;

	public static int LoWord(int dwValue)
	{
		return dwValue & 0xFFFF;
	}

	public static int HiWord(long dwValue)
	{
		return (int)(dwValue >> 16) & -61441;
	}

	public static ushort LowWord(uint val)
	{
		return (ushort)val;
	}

	public static ushort HighWord(uint val)
	{
		return (ushort)(val >> 16);
	}

	public static uint BuildWParam(ushort low, ushort high)
	{
		return (uint)((high << 16) | low);
	}

	[DllImport("User32.dll", SetLastError = true)]
	internal static extern int GetRawInputData(IntPtr hRawInput, DataCommand command, out InputData buffer, [In][Out] ref int size, int cbSizeHeader);

	[DllImport("User32.dll", SetLastError = true)]
	internal static extern int GetRawInputData(IntPtr hRawInput, DataCommand command, [Out] IntPtr pData, [In][Out] ref int size, int sizeHeader);

	[DllImport("User32.dll", SetLastError = true)]
	internal static extern uint GetRawInputDeviceInfo(IntPtr hDevice, RawInputDeviceInfo command, IntPtr pData, ref uint size);

	[DllImport("user32.dll")]
	private static extern uint GetRawInputDeviceInfo(IntPtr hDevice, uint command, ref DeviceInfo data, ref uint dataSize);

	[DllImport("User32.dll", SetLastError = true)]
	internal static extern uint GetRawInputDeviceList(IntPtr pRawInputDeviceList, ref uint numberDevices, uint size);

	[DllImport("User32.dll", SetLastError = true)]
	internal static extern bool RegisterRawInputDevices(RawInputDevice[] pRawInputDevice, uint numberDevices, uint size);

	[DllImport("user32.dll", SetLastError = true)]
	internal static extern IntPtr RegisterDeviceNotification(IntPtr hRecipient, IntPtr notificationFilter, DeviceNotification flags);

	[DllImport("user32.dll", SetLastError = true)]
	internal static extern bool UnregisterDeviceNotification(IntPtr handle);

	public static string GetDeviceType(uint device)
	{
		return device switch
		{
			0u => "MOUSE", 
			1u => "KEYBOARD", 
			2u => "HID", 
			_ => "UNKNOWN", 
		};
	}
}
