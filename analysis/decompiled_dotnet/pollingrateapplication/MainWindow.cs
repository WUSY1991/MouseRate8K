using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Threading;
using RawInput;

namespace pollingrateapplication;

public class MainWindow : Window, IComponentConnector
{
	private static readonly int LOGPIXELSX = 88;

	private static readonly int LOGPIXELSY = 90;

	private DispatcherTimer timer = new DispatcherTimer();

	private int curangle = 225;

	private RawMouse mouse;

	private IntPtr DevHandle = IntPtr.Zero;

	public Queue<int> pollingratelist = new Queue<int>();

	private bool Testing;

	private bool pause;

	public static long sampleno = 0L;

	private long samplestartclock;

	private BackgroundWorker bgWorker_PollingRate;

	internal Grid mainlayout;

	internal Image razermeter;

	internal Image razerhand;

	internal Canvas draw;

	internal Image razergraph;

	internal Label labelpollingrate;

	internal Label labeltitle;

	internal Label israzerdev;

	internal TextBlock UserTip1;

	internal TextBlock UserTip;

	internal Hyperlink linkHelp;

	internal Label pollingratelow;

	internal Label pollingratemid;

	internal Label pollingratehig;

	internal Label transmissionstability;

	private bool _contentLoaded;

	public static Point GetSystemDpi()
	{
		Point result = default(Point);
		IntPtr dC = GetDC(IntPtr.Zero);
		result.X = GetDeviceCaps(dC, LOGPIXELSX);
		result.Y = GetDeviceCaps(dC, LOGPIXELSY);
		ReleaseDC(IntPtr.Zero, dC);
		return result;
	}

	[DllImport("gdi32.dll")]
	private static extern int GetDeviceCaps(IntPtr hdc, int nIndex);

	[DllImport("user32.dll")]
	private static extern IntPtr GetDC(IntPtr hWnd);

	[DllImport("user32.dll")]
	private static extern int ReleaseDC(IntPtr hWnd, IntPtr hDC);

	[DllImport("Kernel32.dll")]
	private static extern bool QueryPerformanceFrequency(out long lpm_Frequency);

	[DllImport("Kernel32.dll")]
	private static extern bool QueryPerformanceCounter(out long lpPerformanceCount);

	public MainWindow()
	{
		InitializeComponent();
	}

	private void Window_Loaded(object sender, RoutedEventArgs e)
	{
		double primaryScreenHeight = SystemParameters.PrimaryScreenHeight;
		double primaryScreenWidth = SystemParameters.PrimaryScreenWidth;
		double num = ((primaryScreenWidth / 1920.0 > primaryScreenHeight / 1080.0) ? (primaryScreenWidth / 1920.0) : (primaryScreenHeight / 1080.0));
		Point systemDpi = GetSystemDpi();
		mainlayout.LayoutTransform = new ScaleTransform(num * systemDpi.X / 96.0, num * systemDpi.Y / 96.0);
		razerhand.RenderTransform = new RotateTransform(225.0);
		if (!QueryPerformanceFrequency(out Common.freq))
		{
			MessageBox.Show("QueryPerformanceFrequency Fail!");
			return;
		}
		mouse = new RawMouse(new WindowInteropHelper(Application.Current.MainWindow).Handle, captureOnlyInForeground: false);
		mouse.EnumerateDevices();
		DevHandle = mouse._deviceList.ElementAt(0).Value;
		labeltitle.Content = mouse.GetDevProductName(mouse._deviceList.ElementAt(0).Key);
		string text = mouse._deviceList.ElementAt(0).Key.ToUpper();
		int num2 = text.IndexOf("PID");
		Common.testdevpath = text;
		num2 = text.IndexOf("VID");
		if (text.Substring(num2 + 4, 4) == "1532")
		{
			Common.isRazerDev = true;
		}
		else
		{
			Common.isRazerDev = false;
		}
		if (Common.isRazerDev)
		{
			labeltitle.Foreground = Brushes.Lime;
			razermeter.Source = new BitmapImage(new Uri("/razer_device.png", UriKind.Relative));
			razerhand.Source = new BitmapImage(new Uri("/hand.png", UriKind.Relative));
			razergraph.Source = new BitmapImage(new Uri("/razer_graph.png", UriKind.Relative));
			israzerdev.Content = "RAZER";
			israzerdev.Foreground = Brushes.Lime;
			transmissionstability.Foreground = Brushes.Lime;
			pollingratehig.Content = Common.targetpollingrate + " Hz";
			pollingratehig.Foreground = Brushes.Lime;
			Common.pollingratelow = Common.targetpollingrate * 150 / 1000;
			pollingratemid.Content = Common.targetpollingrate - Common.pollingratelow / 2 + " Hz";
			pollingratemid.Foreground = Brushes.Lime;
			pollingratelow.Content = Common.targetpollingrate - Common.pollingratelow + " Hz";
			pollingratelow.Foreground = Brushes.Lime;
		}
		else
		{
			labeltitle.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
			razermeter.Source = new BitmapImage(new Uri("/other_device.png", UriKind.Relative));
			razerhand.Source = new BitmapImage(new Uri("/other_hand.png", UriKind.Relative));
			razergraph.Source = new BitmapImage(new Uri("/other_graph.png", UriKind.Relative));
			israzerdev.Content = "COMPETITOR";
			israzerdev.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
			transmissionstability.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
			pollingratehig.Content = Common.targetpollingrate + " Hz";
			pollingratehig.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
			Common.pollingratelow = Common.targetpollingrate * 150 / 1000;
			pollingratemid.Content = Common.targetpollingrate - Common.pollingratelow / 2 + " Hz";
			pollingratemid.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
			pollingratelow.Content = Common.targetpollingrate - Common.pollingratelow + " Hz";
			pollingratelow.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
		}
		labeltitle.FontWeight = FontWeights.Bold;
		labeltitle.FontSize = 40.0;
		labeltitle.HorizontalContentAlignment = HorizontalAlignment.Center;
		labeltitle.VerticalContentAlignment = VerticalAlignment.Center;
		bgWorker_PollingRate = new BackgroundWorker();
		bgWorker_PollingRate.WorkerReportsProgress = true;
		bgWorker_PollingRate.WorkerSupportsCancellation = true;
		bgWorker_PollingRate.DoWork += BgWorker_DoWork;
		bgWorker_PollingRate.ProgressChanged += BgWorker_ProgressChanged;
		bgWorker_PollingRate.RunWorkerCompleted += BgWorker_RunWorkerCompleted;
	}

	private void BgWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
	{
	}

	private void BgWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
	{
		Common.samplecount = 0;
		while (mouse.Pktlist.Count > 0 && mouse.Pktlist.First() <= samplestartclock)
		{
			Common.samplecount++;
			mouse.Pktlist.Dequeue();
		}
		if (Common.samplecount > Common.targetpollingrate)
		{
			Common.samplecount = Common.targetpollingrate;
		}
		pollingratelist.Enqueue(Common.samplecount);
		labelpollingrate.Content = Common.samplecount.ToString();
		labelpollingrate.FontWeight = FontWeights.Bold;
		if (Common.isRazerDev)
		{
			labelpollingrate.Foreground = Brushes.Lime;
		}
		else
		{
			labelpollingrate.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
		}
		byte b = (byte)(Common.samplecount * 100 / Common.targetpollingrate);
		if (b < 50)
		{
			curangle = 225 + b * 270 / 100;
		}
		if (b >= 50)
		{
			curangle = (b - 50) * 270 / 100;
		}
		razerhand.RenderTransform = new RotateTransform(curangle);
		int num = ((pollingratelist.Count > 91) ? 91 : pollingratelist.Count);
		PointCollection pointCollection = new PointCollection();
		int num2 = 0;
		for (int i = 0; i < num; i++)
		{
			Point value = default(Point);
			value.X = i * 5;
			if (pollingratelist.Count > 91)
			{
				draw.Children.Clear();
				num2 = pollingratelist.ElementAt(pollingratelist.Count - 91 + i);
			}
			else
			{
				num2 = pollingratelist.ElementAt(i);
			}
			if (num2 <= Common.targetpollingrate - Common.pollingratelow)
			{
				value.Y = 450.0;
			}
			else if (num2 > Common.targetpollingrate)
			{
				value.Y = 0.0;
			}
			else
			{
				value.Y = 450 - (num2 - (Common.targetpollingrate - Common.pollingratelow)) * 450 / Common.pollingratelow;
			}
			if (value.Y > 450.0 || value.Y < 0.0)
			{
				break;
			}
			pointCollection.Add(value);
		}
		Polyline polyline = new Polyline();
		polyline.StrokeThickness = 2.0;
		if (Common.isRazerDev)
		{
			polyline.Stroke = Brushes.Lime;
		}
		else
		{
			polyline.Stroke = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
		}
		polyline.Points = pointCollection;
		draw.Children.Add(polyline);
		razerhand.UpdateLayout();
	}

	private void BgWorker_DoWork(object sender, DoWorkEventArgs e)
	{
		while (Testing)
		{
			QueryPerformanceCounter(out var lpPerformanceCount);
			if ((double)(lpPerformanceCount - samplestartclock) / (double)Common.freq * 1000.0 >= (double)Common.sampletime)
			{
				QueryPerformanceCounter(out samplestartclock);
				bgWorker_PollingRate.ReportProgress(0, sampleno++);
			}
		}
	}

	private void Window_KeyDown(object sender, KeyEventArgs e)
	{
		switch (e.Key)
		{
		case Key.Escape:
			Testing = false;
			Close();
			break;
		case Key.M:
			Testing = false;
			new MenuSetting(mouse).ShowDialog();
			labeltitle.Content = mouse.GetDevProductName(Common.testdevpath);
			if (Common.isRazerDev)
			{
				labeltitle.Foreground = Brushes.Lime;
				razermeter.Source = new BitmapImage(new Uri("/razer_device.png", UriKind.Relative));
				razerhand.Source = new BitmapImage(new Uri("/hand.png", UriKind.Relative));
				razergraph.Source = new BitmapImage(new Uri("/razer_graph.png", UriKind.Relative));
				israzerdev.Content = "RAZER";
				israzerdev.Foreground = Brushes.Lime;
				transmissionstability.Foreground = Brushes.Lime;
				pollingratehig.Content = Common.targetpollingrate + " Hz";
				pollingratehig.Foreground = Brushes.Lime;
				Common.pollingratelow = Common.targetpollingrate * 150 / 1000;
				pollingratemid.Content = Common.targetpollingrate - Common.pollingratelow / 2 + " Hz";
				pollingratemid.Foreground = Brushes.Lime;
				pollingratelow.Content = Common.targetpollingrate - Common.pollingratelow + " Hz";
				pollingratelow.Foreground = Brushes.Lime;
				labelpollingrate.Foreground = Brushes.Lime;
			}
			else
			{
				labeltitle.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
				razermeter.Source = new BitmapImage(new Uri("/other_device.png", UriKind.Relative));
				razerhand.Source = new BitmapImage(new Uri("/other_hand.png", UriKind.Relative));
				razergraph.Source = new BitmapImage(new Uri("/other_graph.png", UriKind.Relative));
				israzerdev.Content = "COMPETITOR";
				israzerdev.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
				transmissionstability.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
				pollingratehig.Content = Common.targetpollingrate + " Hz";
				pollingratehig.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
				Common.pollingratelow = Common.targetpollingrate * 150 / 1000;
				pollingratemid.Content = Common.targetpollingrate - Common.pollingratelow / 2 + " Hz";
				pollingratemid.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
				pollingratelow.Content = Common.targetpollingrate - Common.pollingratelow + " Hz";
				pollingratelow.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
				labelpollingrate.Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString("#047EDC"));
			}
			labelpollingrate.Content = "0";
			labelpollingrate.FontWeight = FontWeights.Bold;
			razerhand.RenderTransform = new RotateTransform(225.0);
			pollingratelist.Clear();
			draw.Children.Clear();
			UpdateLayout();
			break;
		case Key.S:
		{
			Common.logfilepath = System.IO.Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName) + "\\PollingRate_Log_" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".csv";
			if (Common.logfile)
			{
				Common.logstream = File.CreateText(Common.logfilepath);
				Common.logstream.WriteLine("X,Y,Delta(ms)");
			}
			Testing = true;
			if (pause)
			{
				pause = false;
			}
			else
			{
				pollingratelist.Clear();
				draw.Children.Clear();
			}
			for (int i = 0; i < mouse._deviceList.Count; i++)
			{
				if (mouse._deviceList.ElementAt(i).Key.ToUpper() == Common.testdevpath.ToUpper())
				{
					DevHandle = mouse._deviceList.ElementAt(i).Value;
					break;
				}
			}
			if (!bgWorker_PollingRate.IsBusy)
			{
				bgWorker_PollingRate.RunWorkerAsync();
			}
			break;
		}
		case Key.P:
			pause = true;
			Testing = false;
			break;
		case Key.C:
			pollingratelist.Clear();
			draw.Children.Clear();
			break;
		}
	}

	protected override void OnSourceInitialized(EventArgs e)
	{
		base.OnSourceInitialized(e);
		(PresentationSource.FromVisual(this) as HwndSource).AddHook(WndProc);
	}

	private IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
	{
		switch (msg)
		{
		case 255:
			if (Testing)
			{
				mouse.ProcessRawInput(lParam, DevHandle, Testing);
			}
			break;
		case 537:
			mouse.EnumerateDevices();
			break;
		}
		return IntPtr.Zero;
	}

	private void Window_Closed(object sender, EventArgs e)
	{
		if (Common.logfile && Common.logstream != null)
		{
			Common.logstream.Close();
		}
		foreach (Window window in Application.Current.Windows)
		{
			if (window != this)
			{
				window.Close();
			}
		}
	}

	private void linkDmsite_Click(object sender, RoutedEventArgs e)
	{
		Process.Start(new ProcessStartInfo((sender as Hyperlink).NavigateUri.AbsoluteUri));
	}

	private void HLink_MouseMove(object sender, MouseEventArgs e)
	{
		linkHelp.Foreground = new SolidColorBrush(Colors.Lime);
	}

	private void HLink_MouseLeave(object sender, MouseEventArgs e)
	{
		linkHelp.Foreground = new SolidColorBrush(Colors.White);
	}

	[DebuggerNonUserCode]
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	public void InitializeComponent()
	{
		if (!_contentLoaded)
		{
			_contentLoaded = true;
			Uri resourceLocator = new Uri("/PollingRateTesterApp;component/mainwindow.xaml", UriKind.Relative);
			Application.LoadComponent(this, resourceLocator);
		}
	}

	[DebuggerNonUserCode]
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	[EditorBrowsable(EditorBrowsableState.Never)]
	void IComponentConnector.Connect(int connectionId, object target)
	{
		switch (connectionId)
		{
		case 1:
			((MainWindow)target).Loaded += Window_Loaded;
			((MainWindow)target).KeyDown += Window_KeyDown;
			((MainWindow)target).Closed += Window_Closed;
			break;
		case 2:
			mainlayout = (Grid)target;
			break;
		case 3:
			razermeter = (Image)target;
			break;
		case 4:
			razerhand = (Image)target;
			break;
		case 5:
			draw = (Canvas)target;
			break;
		case 6:
			razergraph = (Image)target;
			break;
		case 7:
			labelpollingrate = (Label)target;
			break;
		case 8:
			labeltitle = (Label)target;
			break;
		case 9:
			israzerdev = (Label)target;
			break;
		case 10:
			UserTip1 = (TextBlock)target;
			break;
		case 11:
			UserTip = (TextBlock)target;
			break;
		case 12:
			linkHelp = (Hyperlink)target;
			linkHelp.Click += linkDmsite_Click;
			linkHelp.MouseMove += HLink_MouseMove;
			linkHelp.MouseLeave += HLink_MouseLeave;
			break;
		case 13:
			pollingratelow = (Label)target;
			break;
		case 14:
			pollingratemid = (Label)target;
			break;
		case 15:
			pollingratehig = (Label)target;
			break;
		case 16:
			transmissionstability = (Label)target;
			break;
		default:
			_contentLoaded = true;
			break;
		}
	}
}
