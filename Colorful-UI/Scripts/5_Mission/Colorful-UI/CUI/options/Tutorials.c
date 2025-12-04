// modded class TutorialsMenu extends UIScriptedMenu
// {
// 	private	Widget m_shader, m_TopShader, m_BottomShader;
// 	private ButtonWidget m_Back;
// 	protected ProgressBarWidget m_LoadingBar;

// 	override Widget Init()
// 	{
// 		layoutRoot	= GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/options/cui.tutorials.layout");
	
// 		m_InfoTextLeft	= layoutRoot.FindAnyWidget("InfoTextLeft");
// 		m_InfoTextRight	= layoutRoot.FindAnyWidget("InfoTextRight");
		
// 		m_Back			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("BackBtn"));
//         cuiElmnt.proBtnCB(ButtonWidget.Cast(m_Back), "Back", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "Back");
		
// 		layoutRoot.FindAnyWidget("Tabber").GetScript(m_TabScript);
// 		m_TabScript.m_OnTabSwitch.Insert(DrawConnectingLines);
			
// 		m_tab_images[0] = ImageWidget.Cast(layoutRoot.FindAnyWidget("MovementTabBackdropImageWidget"));
// 		m_tab_images[1] = ImageWidget.Cast(layoutRoot.FindAnyWidget("WeaponsAndActionsBackdropImageWidget"));
// 		m_tab_images[2] = ImageWidget.Cast(layoutRoot.FindAnyWidget("InventoryTabBackdropImageWidget"));
// 		m_tab_images[3] = ImageWidget.Cast(layoutRoot.FindAnyWidget("MenusTabBackdropImageWidget"));
		
// 		// Note that this is just used as a visual trim, not a real loading bar.
// 		m_LoadingBar        = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("LoadingBar"));
// 		if (m_LoadingBar) m_LoadingBar.SetColor(colorScheme.Loadingbar());

// 		m_TopShader     = layoutRoot.FindAnyWidget( "TopShader" );
// 		m_BottomShader  = layoutRoot.FindAnyWidget( "BottomShader" );
		
// 		m_TopShader.SetColor(colorScheme.TopShader());
// 		m_BottomShader.SetColor(colorScheme.BottomShader());

// 		PPERequesterBank.GetRequester(PPERequester_TutorialMenu).Start(new Param1<float>(0.6));
// 		DrawConnectingLines(0);

// 		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));

// 		return layoutRoot;
// 	}
// }
