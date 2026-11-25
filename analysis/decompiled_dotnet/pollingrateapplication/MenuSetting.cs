using System;
using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Markup;
using RawInput;

namespace pollingrateapplication;

public class MenuSetting : Window, IComponentConnector
{
	private int HidHandle = -1;

	public const uint GENERIC_READ = 2147483648u;

	public const uint GENERIC_WRITE = 1073741824u;

	public const uint FILE_SHARE_READ = 1u;

	public const uint FILE_SHARE_WRITE = 2u;

	public const int OPEN_EXISTING = 3;

	private RawMouse mouse;

	internal Label label;

	internal ComboBox comboBoxdev;

	internal Button buttonscan;

	internal Label label_Copy2;

	internal ComboBox comboBoxpollingrate;

	internal Button buttonok;

	internal Button buttoncancel;

	private bool _contentLoaded;

	public MenuSetting()
	{
		InitializeComponent();
	}

	public MenuSetting(RawMouse _mouse)
	{
		mouse = _mouse;
		InitializeComponent();
	}

	private void Window_Loaded(object sender, RoutedEventArgs e)
	{
		string text = "";
		_ = IntPtr.Zero;
		for (int i = 0; i < mouse._deviceList.Count; i++)
		{
			text = mouse._deviceList.ElementAt(i).Key.ToUpper();
			string devProductName = mouse.GetDevProductName(text);
			text.IndexOf("PID");
			if (devProductName != "")
			{
				comboBoxdev.Items.Add(devProductName);
				if (text == Common.testdevpath.ToUpper())
				{
					comboBoxdev.SelectedIndex = i;
				}
			}
		}
		if (comboBoxdev.SelectedIndex < 0)
		{
			comboBoxdev.SelectedIndex = 0;
		}
		comboBoxpollingrate.Items.Add("125");
		comboBoxpollingrate.Items.Add("250");
		comboBoxpollingrate.Items.Add("500");
		comboBoxpollingrate.Items.Add("1000");
		comboBoxpollingrate.Items.Add("2000");
		comboBoxpollingrate.Items.Add("4000");
		comboBoxpollingrate.Items.Add("8000");
		comboBoxpollingrate.SelectedIndex = 3;
		for (int j = 0; j < comboBoxpollingrate.Items.Count; j++)
		{
			if (comboBoxpollingrate.Items[j].ToString().Contains(Common.targetpollingrate.ToString()))
			{
				comboBoxpollingrate.SelectedIndex = j;
			}
		}
	}

	private void buttonok_Click(object sender, RoutedEventArgs e)
	{
		Common.testdevpath = mouse._deviceList.ElementAt(comboBoxdev.SelectedIndex).Key;
		string text = mouse._deviceList.ElementAt(comboBoxdev.SelectedIndex).Key.ToUpper();
		int num = text.IndexOf("VID");
		if (text.Substring(num + 4, 4) == "1532")
		{
			Common.isRazerDev = true;
		}
		else
		{
			Common.isRazerDev = false;
		}
		Common.targetpollingrate = Convert.ToInt32(comboBoxpollingrate.SelectedItem.ToString());
		Close();
	}

	private void buttoncancel_Click(object sender, RoutedEventArgs e)
	{
		Close();
	}

	private void buttonscan_Click(object sender, RoutedEventArgs e)
	{
		string text = "";
		_ = IntPtr.Zero;
		comboBoxdev.Items.Clear();
		for (int i = 0; i < mouse._deviceList.Count; i++)
		{
			text = mouse._deviceList.ElementAt(i).Key.ToUpper();
			string devProductName = mouse.GetDevProductName(text);
			text.IndexOf("PID");
			if (devProductName != "")
			{
				comboBoxdev.Items.Add(devProductName);
				if (text == Common.testdevpath.ToUpper())
				{
					comboBoxdev.SelectedIndex = i;
				}
			}
		}
		if (comboBoxdev.SelectedIndex < 0)
		{
			comboBoxdev.SelectedIndex = 0;
		}
	}

	[DebuggerNonUserCode]
	[GeneratedCode("PresentationBuildTasks", "4.0.0.0")]
	public void InitializeComponent()
	{
		if (!_contentLoaded)
		{
			_contentLoaded = true;
			Uri resourceLocator = new Uri("/PollingRateTesterApp;component/menusetting.xaml", UriKind.Relative);
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
			((MenuSetting)target).Loaded += Window_Loaded;
			break;
		case 2:
			label = (Label)target;
			break;
		case 3:
			comboBoxdev = (ComboBox)target;
			break;
		case 4:
			buttonscan = (Button)target;
			buttonscan.Click += buttonscan_Click;
			break;
		case 5:
			label_Copy2 = (Label)target;
			break;
		case 6:
			comboBoxpollingrate = (ComboBox)target;
			break;
		case 7:
			buttonok = (Button)target;
			buttonok.Click += buttonok_Click;
			break;
		case 8:
			buttoncancel = (Button)target;
			buttoncancel.Click += buttoncancel_Click;
			break;
		default:
			_contentLoaded = true;
			break;
		}
	}
}
