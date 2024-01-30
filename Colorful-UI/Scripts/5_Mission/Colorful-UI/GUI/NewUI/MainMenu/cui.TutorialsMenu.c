modded class TutorialsMenu extends UIScriptedMenu
{
	private	Widget m_shader
	private Widget m_TopShader;
	private Widget m_BottomShader;
	override Widget Init()
	{
		layoutRoot	= GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/new_ui/tutorials/pc/cui.tutorials.layout");
	
		m_InfoTextLeft	= layoutRoot.FindAnyWidget("InfoTextLeft");
		m_InfoTextRight	= layoutRoot.FindAnyWidget("InfoTextRight");
		
		m_Back			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("back"));
		
		layoutRoot.FindAnyWidget("Tabber").GetScript(m_TabScript);
		m_TabScript.m_OnTabSwitch.Insert(DrawConnectingLines);
			
		m_tab_images[0] = ImageWidget.Cast(layoutRoot.FindAnyWidget("MovementTabBackdropImageWidget"));
		m_tab_images[1] = ImageWidget.Cast(layoutRoot.FindAnyWidget("WeaponsAndActionsBackdropImageWidget"));
		m_tab_images[2] = ImageWidget.Cast(layoutRoot.FindAnyWidget("InventoryTabBackdropImageWidget"));
		m_tab_images[3] = ImageWidget.Cast(layoutRoot.FindAnyWidget("MenusTabBackdropImageWidget"));
		
		m_TopShader 			    = layoutRoot.FindAnyWidget( "TopShader" );
		m_BottomShader 			    = layoutRoot.FindAnyWidget( "BottomShader" );
		
		m_TopShader.SetColor(colorScheme.TopShader());
		m_BottomShader.SetColor(colorScheme.BottomShader());

		PPERequesterBank.GetRequester(PPERequester_TutorialMenu).Start(new Param1<float>(0.6));
		DrawConnectingLines(0);

		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));
		// m_shader.SetColor(colorScheme.ShaderColor());

		return layoutRoot;
	}
		
	//Coloring functions (Until WidgetStyles are useful)
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;

		int color_pnl = UIColor.Transparent();
		int color_lbl = colorScheme.ButtonHover();
		int color_img = UIColor.Transparent();
			
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	}
	
	override void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = colorScheme.PrimaryText(); 
		int color_img = colorScheme.PrimaryText(); 
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	}
}
