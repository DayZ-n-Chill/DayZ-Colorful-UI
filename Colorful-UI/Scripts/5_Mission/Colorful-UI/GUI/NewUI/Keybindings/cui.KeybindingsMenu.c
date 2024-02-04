modded class KeybindingsMenu extends UIScriptedMenu
{
	private Widget m_TopShader;
	private Widget m_BottomShader;
	private Widget m_MenuDivider;
		
	override Widget Init()
	{
		Input input = GetGame().GetInput();
		layoutRoot			= GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/new_ui/options/pc/cui.keybinding_menu.layout", null);
		
		m_Version			= TextWidget.Cast(layoutRoot.FindAnyWidget("version"));
		m_Apply				= ButtonWidget.Cast(layoutRoot.FindAnyWidget("apply"));
		m_Back				= ButtonWidget.Cast(layoutRoot.FindAnyWidget("back"));
		m_Undo				= ButtonWidget.Cast(layoutRoot.FindAnyWidget("undo"));
		m_Defaults			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("reset"));
		m_HardReset			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("reset_all"));

		m_TopShader 			    = layoutRoot.FindAnyWidget( "TopShader" );
		m_BottomShader 			    = layoutRoot.FindAnyWidget( "BottomShader" );
		m_MenuDivider				= layoutRoot.FindAnyWidget( "MenuDivider" );
		

		m_TopShader.SetColor(colorScheme.TopShader());
		m_BottomShader.SetColor(colorScheme.BottomShader());
		m_MenuDivider.SetColor(colorScheme.Separator());

		
		layoutRoot.FindAnyWidget("Tabber").GetScript(m_Tabber);
		
		string version;
		GetGame().GetVersion(version);
		#ifdef PLATFORM_CONSOLE
		version = "#main_menu_version" + " " + version + " (" + g_Game.GetDatabaseID() + ")";
		#else
		version = "#main_menu_version" + " " + version;
		#endif
		m_Version.SetText(version);

		#ifdef PLATFORM_PS4
		string back = "circle";
		if (GetGame().GetInput().GetEnterButton() != GamepadButton.A)
			back = "cross";

		ImageWidget toolbar_b = ImageWidget.Cast(layoutRoot.FindAnyWidget("BackIcon"));
		toolbar_b.LoadImageFile(0, "set:playstation_buttons image:" + back);
		#endif
		
		InitInputSortingMap();
		CreateTabs();
		CreateGroupContainer();
		
		InitPresets(-1, layoutRoot.FindAnyWidget("group_header"), input);
		m_Tabber.m_OnTabSwitch.Insert(UpdateTabContent);
		m_Tabber.SelectTabControl(0);
		m_Tabber.SelectTabPanel(0);
		g_Game.SetKeyboardHandle(this);
		m_Tabber.RefreshTab(true);
		
		ColorDisabled(m_Apply);
		m_Apply.SetFlags(WidgetFlags.IGNOREPOINTER);
		ColorDisabled(m_Undo);
		m_Undo.SetFlags(WidgetFlags.IGNOREPOINTER);
		ColorWhite(m_Defaults, null);
		m_Defaults.ClearFlags(WidgetFlags.IGNOREPOINTER);
		
		return layoutRoot;
	}
	
	override void ClearKeybind(int key_index)
	{
		ColorWhite(m_Apply, null);
		m_Apply.ClearFlags(WidgetFlags.IGNOREPOINTER);
		ColorWhite(m_Undo, null);
		m_Undo.ClearFlags(WidgetFlags.IGNOREPOINTER);
	}
	
	override void ClearAlternativeKeybind(int key_index)
	{
		ColorWhite(m_Apply, null);
		m_Apply.ClearFlags(WidgetFlags.IGNOREPOINTER);
		ColorWhite(m_Undo, null);
		m_Undo.ClearFlags(WidgetFlags.IGNOREPOINTER);
	}
	
	//Coloring functions (Until WidgetStyles are useful)
	override void ColorRed(Widget w)
	{
		SetFocus(w);
		
		ButtonWidget button = ButtonWidget.Cast(w);
		if (m_Apply)
		{
			button.SetTextColor(colorScheme.ButtonHover());
		}
	}
	
	override void ColorWhite(Widget w, Widget enterW)
	{
		#ifdef PLATFORM_WINDOWS
		SetFocus(null);
		#endif
		
		ButtonWidget button = ButtonWidget.Cast(w);
		if (button)
		{
			if (button.GetFlags() & WidgetFlags.DISABLED)
			{
				button.SetTextColor(ColorManager.COLOR_DISABLED_TEXT);
			}
			else
			{
				button.SetTextColor(ColorManager.COLOR_NORMAL_TEXT);
			}
		}
	}
	
	override void ColorDisabled(Widget w)
	{
		#ifdef PLATFORM_WINDOWS
		SetFocus(null);
		#endif
		
		ButtonWidget button = ButtonWidget.Cast(w);
		if (button)
		{
			// These will be reset in the next update with the new theme manager.
			button.SetTextColor(ColorManager.COLOR_DISABLED_TEXT);
		}
	}
}