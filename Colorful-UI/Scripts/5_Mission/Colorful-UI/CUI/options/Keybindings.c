// modded class KeybindingsMenu extends UIScriptedMenu
// {
// 	private Widget m_TopShader, m_BottomShader, m_MenuDivider;
//     private TextWidget m_ApplyBtn_Label;
// 	protected ProgressBarWidget m_LoadingBar;

// 	override Widget Init()
// 	{
// 		Input input = GetGame().GetInput();
// 		layoutRoot			= GetGame().GetWorkspace().CreateWidgets("Colorful-UI/GUI/layouts/options/cui.keybindings.layout", null);
		
// 		m_Apply     = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ApplyBtn"));
// 		m_Back      = ButtonWidget.Cast(layoutRoot.FindAnyWidget("BackBtn"));
// 		m_Undo      = ButtonWidget.Cast(layoutRoot.FindAnyWidget("UndoBtn"));
// 		m_Defaults  = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ResetBtn"));
// 		m_HardReset = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ResetAllBtn"));

// 		cuiElmnt.proBtnCB(m_Apply,     "Apply",      colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "Apply");
// 		cuiElmnt.proBtnCB(m_Back,      "Back",       colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "Back");
// 		cuiElmnt.proBtnCB(m_Undo,      "Undo",       colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "Reset");
// 		cuiElmnt.proBtnCB(m_Defaults,  "Defaults",   colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "SetToDefaults");
// 		cuiElmnt.proBtnCB(m_HardReset, "Hard Reset", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "HardReset");

// 		m_TopShader    = layoutRoot.FindAnyWidget( "TopShader" );
// 		m_BottomShader = layoutRoot.FindAnyWidget( "BottomShader" );
// 		m_MenuDivider  = layoutRoot.FindAnyWidget( "MenuDivider" );

// 		// Note that this is just used as a visual trim, not a real loading bar.
// 		m_LoadingBar      = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("LoadingBar"));
// 		if (m_LoadingBar) m_LoadingBar.SetColor(colorScheme.Loadingbar());

// 		m_TopShader.SetColor(colorScheme.TopShader());
// 		m_BottomShader.SetColor(colorScheme.BottomShader());
// 		m_MenuDivider.SetColor(colorScheme.Separator());
		
// 		layoutRoot.FindAnyWidget("Tabber").GetScript(m_Tabber);		
		
// 		InitInputSortingMap();
// 		CreateTabs();
// 		CreateGroupContainer();
		
// 		InitPresets(-1, layoutRoot.FindAnyWidget("group_header"), input);
// 		m_Tabber.m_OnTabSwitch.Insert(UpdateTabContent);
// 		m_Tabber.SelectTabControl(0);
// 		m_Tabber.SelectTabPanel(0);
// 		g_Game.SetKeyboardHandle(this);
// 		m_Tabber.RefreshTab(true);
		
// 		return layoutRoot;
// 	}
// }

// modded class KeybindingElementNew extends ScriptedWidgetEventHandler
// {
// 	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
// 	{
// 		if( w == m_PrimaryClear )
// 		{
// 			m_IsEdited				= true;
// 			m_CustomBind			= new array<int>;
// 			m_PrimaryBindButton.SetText( "" );
// 			m_Container.ClearKeybind( m_ElementIndex );
// 		}
// 		if( w == m_AlternativeClear )
// 		{
// 			m_IsAlternateEdited		= true;
// 			m_CustomAlternateBind	= new array<int>;
// 			m_AlternativeBindButton.SetText( "" );
// 			m_Container.ClearAlternativeKeybind( m_ElementIndex );
// 		}
// 		return false;
// 	}
	
// 	override bool OnMouseEnter( Widget w, int x, int y )
// 	{
// 		if( w == m_PrimaryBindButton || w == m_PrimaryClear )
// 		{
// 			m_PrimaryBindButton.SetColor( colorScheme.ButtonHover() );
// 			m_PrimaryClear.Show( true );
// 			m_PrimaryClear.Update();
// 			m_AlternativeClear.Show( false );
// 			return true;
// 		}
// 		else if( w == m_AlternativeBindButton || w == m_AlternativeClear )
// 		{
// 			m_AlternativeBindButton.SetColor( colorScheme.ButtonHover() );
// 			m_PrimaryClear.Show( false );
// 			m_AlternativeClear.Show( true );
// 			m_AlternativeClear.Update();
// 			return true;
// 		}
// 		else
// 		{
// 			m_PrimaryBindButton.SetColor( ARGBF( 0, 0, 0, 0 ) );
// 			m_AlternativeBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
// 			m_PrimaryClear.Show( false );
// 			m_AlternativeClear.Show( false );
// 		}
// 		return false;
// 	}
	
// 	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
// 	{
// 		if( w == m_PrimaryClear || w == m_PrimaryBindButton )
// 		{
// 			if( enterW != m_PrimaryClear && enterW != m_PrimaryBindButton )
// 			{
// 				m_PrimaryClear.Show( false );
// 				m_PrimaryBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
// 			}
// 		}
// 		if( w == m_AlternativeClear || w == m_AlternativeBindButton )
// 		{
// 			if( enterW != m_AlternativeClear && enterW != m_AlternativeBindButton )
// 			{
// 				m_AlternativeClear.Show( false );
// 				m_AlternativeBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
// 			}
// 		}
// 		return false;
// 	}
// }
