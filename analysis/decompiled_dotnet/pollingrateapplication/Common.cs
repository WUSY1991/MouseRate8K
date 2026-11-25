using System.IO;

namespace pollingrateapplication;

internal class Common
{
	public static StreamWriter logstream;

	public static string logfilepath = "";

	public static bool logfile = false;

	public static string testdevpath = "";

	public static int testtime = 0;

	public static int targetpollingrate = 1000;

	public static long total = 0L;

	public static int samplecount = 0;

	public static int sampletime = 1000;

	public static int avgpollingrate = 0;

	public static long lastclock = 0L;

	public static bool isRazerDev = true;

	public static long freq = 0L;

	public static bool normal = false;

	public static int pollingratelow = 150;
}
