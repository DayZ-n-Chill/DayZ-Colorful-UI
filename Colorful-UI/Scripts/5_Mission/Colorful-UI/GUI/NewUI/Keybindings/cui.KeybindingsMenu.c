modded class KeybindingsMenu extends UIScriptedMenu
{
	protected Widget m_Separator
	private	Widget m_shader
	override Widget Init()
	{
		Input input = GetGame().GetInput();
		layoutRoot			= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/options/pc/cui.keybinding_menu.layout", null );
		
		m_Version			= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		m_Apply				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "apply" ) );
		m_Back				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "back" ) );
		m_Undo				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "reset" ) );
		m_Defaults			= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "defaults" ) );
		
		layoutRoot.FindAnyWidget( "Tabber" ).GetScript( m_Tabber );
		
		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));
		// m_shader.SetColor(colorScheme.ShaderColor());

		InitInputSortingMap();
		CreateTabs();
		CreateGroupContainer();
		
		InitPresets( -1, layoutRoot.FindAnyWidget( "group_header" ), input );
		m_Tabber.m_OnTabSwitch.Insert(UpdateTabContent);
		m_Tabber.SelectTabControl( 0 );
		m_Tabber.SelectTabPanel( 0 );
		g_Game.SetKeyboardHandle( this );
		m_Tabber.RefreshTab(true);
		
		ColorDisabled( m_Apply );
		m_Apply.SetFlags( WidgetFlags.IGNOREPOINTER );
		ColorDisabled( m_Undo );
		m_Undo.SetFlags( WidgetFlags.IGNOREPOINTER );
		ColorWhite( m_Defaults, null );
		m_Defaults.ClearFlags( WidgetFlags.IGNOREPOINTER );
		
		m_Separator 	= layoutRoot.FindAnyWidget( "separator_red" );
		// m_Separator.SetColor(colorScheme.SeparatorColor());

		return layoutRoot;
	}
	
	override void CreateTabs()
	{
		int sort_count = InputUtils.GetInputActionSortingMap().Count();
		for (int i = 0; i < sort_count; i++)
		{
			if (InputUtils.GetInputActionSortingMap().GetElement(i) && InputUtils.GetInputActionSortingMap().GetElement(i).Count() > 0)
			{
				string group_name = GetUApi().SortingLocalization(InputUtils.GetInputActionSortingMap().GetKey(i));
				group_name = Widget.TranslateString("#" + group_name); //oof
				m_Tabber.AddTab( group_name );
			}
		}
		
		if (InputUtils.GetUnsortedInputActions() && InputUtils.GetUnsortedInputActions().Count() > 0)
		{
			m_Tabber.AddTab( Widget.TranslateString("#layout_pc_keybinding_unsorted") );
		}
		m_Tabber.DisableTabs(true);
	}
	
	override void CreateGroupContainer()
	{
		m_GroupsContainer = new KeybindingsContainer(-1,GetGame().GetInput(),layoutRoot.FindAnyWidget("TabContentsHolder"),this);
	}
	
	override void UpdateTabContent( int tab_index )
	{
		m_GroupsContainer.SwitchSubgroup(tab_index);
	}
	
	override void ClearKeybind( int key_index )
	{
		ColorWhite( m_Apply, null );
		m_Apply.ClearFlags( WidgetFlags.IGNOREPOINTER );
		ColorWhite( m_Undo, null );
		m_Undo.ClearFlags( WidgetFlags.IGNOREPOINTER );
	}
	
	override void ClearAlternativeKeybind( int key_index )
	{
		ColorWhite( m_Apply, null );
		m_Apply.ClearFlags( WidgetFlags.IGNOREPOINTER );
		ColorWhite( m_Undo, null );
		m_Undo.ClearFlags( WidgetFlags.IGNOREPOINTER );
	}
	
	override void StartEnteringKeybind( int key_index )
	{
		m_CurrentSettingAlternateKeyIndex	= -1;
		m_CurrentSettingKeyIndex			= key_index;
	}
	
	override void CancelEnteringKeybind()
	{
		m_GroupsContainer.CancelEnteringKeybind();
		m_CurrentSettingKeyIndex = -1;
	}
	
	override void StartEnteringAlternateKeybind( int key_index )
	{
		m_CurrentSettingKeyIndex			= -1;
		m_CurrentSettingAlternateKeyIndex	= key_index;
	}
	
	override void CancelEnteringAlternateKeybind()
	{
		m_GroupsContainer.CancelEnteringAlternateKeybind();
		m_CurrentSettingAlternateKeyIndex = -1;
	}
	
	override void ConfirmKeybindEntry( TIntArray new_keys )
	{
		m_CurrentSettingKeyIndex = -1;
		ColorWhite( m_Apply, null );
		m_Apply.ClearFlags( WidgetFlags.IGNOREPOINTER );
		ColorWhite( m_Undo, null );
		m_Undo.ClearFlags( WidgetFlags.IGNOREPOINTER );
	}
	
	override void ConfirmAlternateKeybindEntry( TIntArray new_keys )
	{
		m_CurrentSettingAlternateKeyIndex = -1;
		ColorWhite( m_Apply, null );
		m_Apply.ClearFlags( WidgetFlags.IGNOREPOINTER );
		ColorWhite( m_Undo, null );
		m_Undo.ClearFlags( WidgetFlags.IGNOREPOINTER );
	}
	
	override void Update(float timeslice)
	{
		if( GetGame().GetInput().LocalPress("UAUIBack",false) )
		{
			Back();
		}
		
		if( m_GroupsContainer )
		{
			m_GroupsContainer.Update( timeslice );
		}
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_Apply )
			{
				Apply();
				return true;
			}
			else if( w == m_Back )
			{
				Back();
				return true;
			}
			else if( w == m_Undo )
			{
				Reset();
				return true;
			}
			else if( w == m_Defaults )
			{
				SetToDefaults();
				return true;
			}
		}
		return false;
	}
	
	override void Apply()
	{
		ColorDisabled( m_Apply );
		m_Apply.SetFlags( WidgetFlags.IGNOREPOINTER );
		ColorDisabled( m_Undo );
		m_Undo.SetFlags( WidgetFlags.IGNOREPOINTER );
		ColorWhite( m_Defaults, null );
		m_Defaults.ClearFlags( WidgetFlags.IGNOREPOINTER );
		
		m_GroupsContainer.Apply();
		
		// save input configuration
		GetUApi().Export();
	}
	
	override void Back()
	{
		if( m_CurrentSettingKeyIndex != -1 )
		{
			CancelEnteringKeybind();
			return;
		}
		
		if( m_CurrentSettingAlternateKeyIndex != -1 )
		{
			CancelEnteringAlternateKeybind();
			return;
		}
		
		bool changed = m_GroupsContainer.IsChanged();

		if ( changed )
		{
			EnterScriptedMenu( COLORFUL_CONFIGURE );
			//g_Game.GetUIManager().ShowDialog("#main_menu_configure", "#main_menu_configure_desc", MODAL_ID_BACK, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
		}
		else
		{
			GetGame().GetUIManager().Back();
		}
	}
	
	// ! Undoes the unsaved changes and reverts to previous state. Does not reset to defaults!
	override void Reset()
	{
		ColorDisabled( m_Apply );
		m_Apply.SetFlags( WidgetFlags.IGNOREPOINTER );
		ColorDisabled( m_Undo );
		m_Undo.SetFlags( WidgetFlags.IGNOREPOINTER );
		
		m_GroupsContainer.Reset();
	}
	
	override void SetToDefaults()
	{
		EnterScriptedMenu( COLORFUL_DEFAULTS );
		//g_Game.GetUIManager().ShowDialog("#menu_default_cap", "#menu_default_desc", MODAL_ID_DEFAULT, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
	}
	
	override void PerformSetToDefaults()
	{
		ColorDisabled( m_Apply );
		m_Apply.SetFlags( WidgetFlags.IGNOREPOINTER );
		ColorDisabled( m_Undo );
		m_Undo.SetFlags( WidgetFlags.IGNOREPOINTER );
		ColorDisabled( m_Defaults );
		m_Defaults.SetFlags( WidgetFlags.IGNOREPOINTER );
		
		GetUApi().Revert();
		
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().GetMission().RefreshExcludes);
		
		m_GroupsContainer.Reset(true);
	}
	
	override void DeferredDefaultsInit()
	{
		//GetGame().GetMission().RefreshExcludes();
	}
	
	override bool OnModalResult( Widget w, int x, int y, int code, int result )
	{
		if( code == MODAL_ID_BACK )
		{
			if( result == 2 )
			{
				Reset();
				GetGame().GetUIManager().Back();
			}
			return true;
		}
		else if (code == MODAL_ID_DEFAULT)
		{
			if( result == 2 )
			{
				PerformSetToDefaults();
			}
			return true;
		}
		else if (code == MODAL_ID_PRESET_CHANGE)
		{
			if( result == 2 )
			{
				Reset();
				m_PresetSelector.PerformSetOption(m_TargetPresetIndex);
			}
			return true;
		}
		
		return false;
	}
	
	override void Refresh()
	{
		string version;
		GetGame().GetVersion( version );
		#ifdef PLATFORM_CONSOLE
			version = "#main_menu_version" + " " + version + " (" + g_Game.GetDatabaseID() + ")";
		#else
			version = "#main_menu_version" + " " + version;
		#endif
		m_Version.SetText( version );
	}
	

	override bool OnMouseWheel(Widget w, int x, int y, int wheel)
	{
		return super.OnMouseWheel(w, x, y, wheel);
	}
	
	override bool OnFocus( Widget w, int x, int y )
	{
		if( w && IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}
	
	override bool OnFocusLost( Widget w, int x, int y )
	{
		if( w && IsFocusable( w ) )
		{
			if ( (w.GetFlags() & WidgetFlags.DISABLED) || (w.GetFlags() & WidgetFlags.IGNOREPOINTER) )
			{
				ColorDisabled(w);
			}
			else
			{
				ColorWhite( w, null );
			}
			return true;
		}
		return false;
	}
	
	override bool IsFocusable( Widget w )
	{
		if( w )
		{
			return ( w == m_Apply || w == m_Back || w == m_Undo || w == m_Defaults );
		}
		return false;
	}


	//Coloring functions (Until WidgetStyles are useful)
 	override void ColorRed( Widget w )
	{
		SetFocus( w );
		
		ButtonWidget button = ButtonWidget.Cast( w );
		if( button && button != m_Apply )
		{
			button.SetTextColor(colorScheme.OptionInputColors());
		}
	}
	

	override bool OnMouseEnter( Widget w, int x, int y )
	{
		ColorHighlight( w );
		return true;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		ColorNormal( w );
		return true;
	}
	

	protected void ButtonSetColor( Widget w, int color )
	{
		if( !w )
			return;
		
		Widget panel = w.FindWidget( w.GetName() + "_panel" );
		
		if( panel )
		{
			panel.SetColor( color );
		}
	}

	protected void ButtonSetTextColor( Widget w, int color )
	{
		if( !w )
			return;

		TextWidget label	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
				
		if( label )
		{
			label.SetColor( color );
		}
	}
	
	protected void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.OptionInputColors());
	};

	protected void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.PrimaryText());
	}



	override void ColorWhite( Widget w, Widget enterW )
	{
		#ifdef PLATFORM_WINDOWS
		SetFocus( null );
		#endif
		
		ButtonWidget button = ButtonWidget.Cast( w );
		if ( button )
		{
			if ( button.GetFlags() & WidgetFlags.DISABLED )
			{
				button.SetTextColor(ColorManager.COLOR_DISABLED_TEXT);
			}
			else
			{
				button.SetTextColor(ColorManager.COLOR_NORMAL_TEXT);
			}
		}
	}
	
	override void ColorDisabled( Widget w )
	{
		#ifdef PLATFORM_WINDOWS
		SetFocus( null );
		#endif
		
		ButtonWidget button = ButtonWidget.Cast(w);
		if ( button )
		{
			button.SetTextColor(ColorManager.COLOR_DISABLED_TEXT);
		}
	}
	
	override void InitInputSortingMap()
	{
		InputUtils.InitInputMetadata();
	}
	
	override void InitPresets( int index, Widget parent, Input input )
	{
		Widget kb_root = parent.FindAnyWidget( "keyboard_dropown" );
		if (kb_root)
		{
			kb_root.Show(false);
		}
		
		array<string> opt1			= new array<string>;
		string profile_text;
		
		for (int i = 0; i < input.GetProfilesCount(); i++)
		{
			input.GetProfileName( i, profile_text );
			opt1.Insert( profile_text );
		}
		
		int current_idx = input.GetCurrentProfile();
		m_OriginalPresetIndex = current_idx;
		m_PresetSelector = new OptionSelectorMultistate( layoutRoot.FindAnyWidget( "profile_setting_option" ), current_idx, null, false, opt1 );
		m_PresetSelector.m_AttemptOptionChange.Insert( OnAttemptSelectPreset );
		m_PresetSelector.m_OptionChanged.Insert( OnSelectKBPreset );
	}
	
	override void OnAttemptSelectPreset( int index )
	{
		bool changed = m_GroupsContainer.IsChanged() && m_OriginalPresetIndex != index;
		m_TargetPresetIndex = index;
		
		if (changed)
		{
			g_Game.GetUIManager().ShowDialog("#main_menu_configure", "#main_menu_configure_desc", MODAL_ID_PRESET_CHANGE, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
		}
		
		m_PresetSelector.SetCanSwitch(!changed);
	}
	
	override void OnSelectKBPreset( int index )
	{
		m_OriginalPresetIndex = index;
		m_GroupsContainer.OnSelectKBPreset(index);
		string profile_text;
		GetGame().GetInput().GetProfileName( index, profile_text );
	}
	
	//////////////////////////////////////////////////
	// 				OBSOLETE METHODS 				//
	//////////////////////////////////////////////////
	override KeybindingsContainer GetCurrentTab()
	{
		return m_GroupsContainer;
	}
	
	override void AddGroup( int index, Input input )
	{
	}
}		