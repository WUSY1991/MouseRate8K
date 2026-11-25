namespace RawInput;

internal struct Rawkeyboard
{
	public ushort Makecode;

	public ushort Flags;

	private readonly ushort Reserved;

	public ushort VKey;

	public uint Message;

	public uint ExtraInformation;

	public override string ToString()
	{
		return string.Format("Rawkeyboard\n Makecode: {0}\n Makecode(hex) : {0:X}\n Flags: {1}\n Reserved: {2}\n VKeyName: {3}\n Message: {4}\n ExtraInformation {5}\n", Makecode, Flags, Reserved, VKey, Message, ExtraInformation);
	}
}
