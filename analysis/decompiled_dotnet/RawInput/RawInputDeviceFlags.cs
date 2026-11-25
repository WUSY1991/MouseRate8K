using System;

namespace RawInput;

[Flags]
internal enum RawInputDeviceFlags
{
	NONE = 0,
	REMOVE = 1,
	EXCLUDE = 0x10,
	PAGEONLY = 0x20,
	NOLEGACY = 0x30,
	INPUTSINK = 0x100,
	CAPTUREMOUSE = 0x200,
	NOHOTKEYS = 0x200,
	APPKEYS = 0x400,
	EXINPUTSINK = 0x1000,
	DEVNOTIFY = 0x2000
}
