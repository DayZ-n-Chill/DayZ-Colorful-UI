modded class RespawnDialogue extends UIScriptedMenu
{
	// const int 					ID_RESPAWN_CUSTOM = 101;
	// const int 					ID_RESPAWN_RANDOM = 102;
	
	// //tooltips
	// protected Widget			m_DetailsRoot;
	// protected TextWidget		m_DetailsLabel;
	// protected RichTextWidget	m_DetailsText;
	
	// protected Widget 			m_CustomRespawn;
	
	// //helper
	// protected Widget 			m_CurrentlyHighlighted;
	
	// void RespawnDialogue();
	// void ~RespawnDialogue()
	private Widget m_Separator
	private	Widget m_shader
	private Widget m_Discord;
	private Widget m_Twitter;
	private Widget m_Youtube;
	private Widget m_Reddit;
	private Widget m_Facebook;

	
	override Widget Init()
	{
		layoutRoot 					= GetGame().GetWorkspace().CreateWidgets("colorful-ui/gui/layouts/cui.2.day_z_respawn_dialogue.layout");
		m_DetailsRoot 				= layoutRoot.FindAnyWidget("menu_details_tooltip");
		m_DetailsLabel				= TextWidget.Cast(m_DetailsRoot.FindAnyWidget("menu_details_label"));
		m_DetailsText				= RichTextWidget.Cast(m_DetailsRoot.FindAnyWidget("menu_details_tooltip_content"));
		
		m_CustomRespawn 			= layoutRoot.FindAnyWidget("respawn_button_custom");
		SetFocus(m_CustomRespawn);

		m_Separator 				= layoutRoot.FindAnyWidget( "actionItems_separator" );
		m_Discord 					= layoutRoot.FindAnyWidget( "DiscordBtn" );
		m_Twitter 					= layoutRoot.FindAnyWidget( "TwitterBtn" );
		m_Youtube 					= layoutRoot.FindAnyWidget( "YoutubeBtn" );
		m_Reddit 					= layoutRoot.FindAnyWidget( "RedditBtn" );
		m_Facebook 					= layoutRoot.FindAnyWidget( "FacebookBtn" );
		

		return layoutRoot;
	}
	
	// override void Update(float timeslice)
	// {
	// 	super.Update(timeslice);
		
	// 	if (GetUApi().GetInputByID(UAUIBack).LocalPress() || GetUApi().GetInputByID(UAUIMenu).LocalPress())
	// 		Close();
	// }

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		switch (w.GetUserID())
		{
			case IDC_CANCEL:
				Close();
				return true;

			case ID_RESPAWN_CUSTOM:
				return RequestRespawn(false);

			case ID_RESPAWN_RANDOM:
				return RequestRespawn(true);
		}

		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL(MenuURLS.urlDiscord);
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Twitter)
		{
			GetGame().OpenURL(MenuURLS.urlTwitter);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Reddit)
		{
			GetGame().OpenURL(MenuURLS.urlReddit);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Youtube)
		{
			GetGame().OpenURL(MenuURLS.urlYoutube);
			return false;
		}	
		else if (button == MouseState.LEFT && w == m_Facebook)
		{
			GetGame().OpenURL(MenuURLS.urlFacebook);
			return false;
		}

		return false;
	}
	
	override bool OnMouseEnter(Widget w, int x, int y)
	{
		if( w == m_Twitter )
		{
			TwitterHighlight( w );
			return true;
		}

		if( w == m_Facebook )
		{
			MetaHighlight( w );
			return true;
		}

		if( w == m_Discord )
		{
			DiscordHighlight( w );
			return true;
		}

		if( w == m_Youtube )
		{
			YoutubeHighlight( w );
			return true;
		}

		if( w == m_Reddit )
		{
			RedditHighlight( w );
			return true;
		}
		// string tooltip_header = "";
		// string tooltip_text = "";
		ColorHighlight(w);
		// switch (w.GetUserID())
		// {
		// 	case ID_RESPAWN_RANDOM:
		// 		tooltip_header = "#main_menu_respawn_random";
		// 		tooltip_text = "#main_menu_respawn_random_tooltip";
		// 		break;
			
		// 	case ID_RESPAWN_CUSTOM:
		// 		tooltip_header = "#main_menu_respawn_custom";
		// 		tooltip_text = "#main_menu_respawn_custom_tooltip";
		// 		break;
		// }

		// SetTooltipTexts(w, tooltip_header, tooltip_text);
		return true;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		ColorNormal(w);
		return true;
	}
	
	// override void OnShow()
	// {
	// 	super.OnShow();
		
	// 	SetFocus(m_CustomRespawn);
	// }
	
	// override bool OnFocus(Widget w, int x, int y)
	// {
	// 	string tooltip_header = "";
	// 	string tooltip_text = "";
	// 	if (IsFocusable(w))
	// 	{
	// 		ColorHighlight(w);
	// 		switch (w.GetUserID())
	// 		{
	// 			case ID_RESPAWN_RANDOM:
	// 				tooltip_header = "#main_menu_respawn_random";
	// 				tooltip_text = "#main_menu_respawn_random_tooltip";
	// 				break;
				
	// 			case ID_RESPAWN_CUSTOM:
	// 				tooltip_header = "#main_menu_respawn_custom";
	// 				tooltip_text = "#main_menu_respawn_custom_tooltip";
	// 				break;
	// 		}

	// 		SetTooltipTexts(w, tooltip_header, tooltip_text);
	// 		return true;
	// 	}

	// 	SetTooltipTexts(w, tooltip_header, tooltip_text);
	// 	return false;
	// }
	
	// override bool OnFocusLost(Widget w, int x, int y)
	// {
	// 	if (IsFocusable(w))
	// 	{
	// 		ColorNormal(w);
	// 		return true;
	// 	}

	// 	return false;
	// }
	
	// bool IsFocusable(Widget w)
	// {
	// 	if (w)
	// 	{
	// 		if (w.GetUserID() == IDC_CANCEL || w.GetUserID() == ID_RESPAWN_CUSTOM || w.GetUserID() == ID_RESPAWN_RANDOM);
	// 			return true;
	// 	}

	// 	return false;
	// }
	
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.ButtonHover());
		
	};

	override void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, UIColor.White());
	}

	protected void TwitterHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.twitter();
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	protected void DiscordHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.discord();
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	protected void YoutubeHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.youtube();
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	protected void RedditHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.reddit();
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	protected void MetaHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.meta();
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}
	
	// protected void ButtonSetColor(Widget w, int color)
	// {
	// 	Widget panel = w.FindWidget(w.GetName() + "_panel");
	// 	if (panel)
	// 		panel.SetColor(color);
	// }
	
	// protected void ButtonSetTextColor(Widget w, int color)
	// {
	// 	TextWidget label = TextWidget.Cast(w.FindAnyWidget(w.GetName() + "_label"));
	// 	if (label)
	// 		label.SetColor(color);
	// }
	
	// void SetTooltipTexts(Widget w, string header = "", string desc = "")
	// {
	// 	bool show = header != "" && desc != "";
	// 	m_DetailsRoot.Show(show);
	// 	m_DetailsLabel.SetText(header);
	// 	m_DetailsText.SetText(desc);
		
	// 	m_DetailsText.Update();
	// 	m_DetailsLabel.Update();
	// 	m_DetailsRoot.Update();
	// }
	
	bool RequestRespawn(bool random)
	{
		IngameHud.Cast(GetGame().GetMission().GetHud()).InitBadgesAndNotifiers();
		Man player = GetGame().GetPlayer();
		if (player && (player.GetPlayerState() == EPlayerStates.ALIVE && !player.IsUnconscious()))
			return false;
		
		#ifdef PLATFORM_CONSOLE
		InGameMenuXbox menu_ingame = InGameMenuXbox.Cast(GetGame().GetUIManager().FindMenu(MENU_INGAME));
		#else
		InGameMenu menu_ingame = InGameMenu.Cast(GetGame().GetUIManager().FindMenu(MENU_INGAME));
		#endif
		
		if (!menu_ingame)
			return false;
		
		menu_ingame.MenuRequestRespawn(this, random);
		return true;
	}
}
