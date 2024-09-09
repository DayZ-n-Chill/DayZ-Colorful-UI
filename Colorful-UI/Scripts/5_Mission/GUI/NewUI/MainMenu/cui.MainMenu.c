modded class MainMenu extends UIScriptedMenu
{
// Social Buttons
	private Widget m_Discord;
	private Widget m_Twitter;
	private Widget m_Youtube;
	private Widget m_Reddit;
	private Widget m_Facebook;
	private Widget m_Meta;

	// Social Icons
	private Widget m_DiscordImg;
	private Widget m_TwitterImg;
	private Widget m_YoutubeImg;
	private Widget m_RedditImg;
	private Widget m_FacebookImg;
	private Widget m_MetaImg;
	
	// Top Nav Buttons
	private Widget m_ExitBtn;
	private Widget m_SettingsBtn;
	private Widget m_TutorialBtn;
	private Widget m_MessageBtn;

	// Top Nav Icons
	private Widget m_ExitBtnImg;
	private Widget m_SettingsBtnImg;
	private Widget m_TutorialBtnImg;
	private Widget m_MessageBtnImg;
	
	// Custom Buttons (No Icons)
	private Widget m_Website;
	private Widget m_PriorityQueue;
	private Widget m_CharacterBtn;

	// CUI Shaders
	private Widget m_TopShader;
	private Widget m_BottomShader;
	
	// Visual Elements
	private	Widget m_welcomeBack;
	private Widget m_SurvivorBox;
	private Widget m_StatsBox;
	private Widget m_SurvivorDivider;
	private Widget m_MenuDivider;
	private Widget m_ProgressLoading;
	
	override Widget Init()
	{
		// Load the layout file
		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/cui.main_menu.layout" );

		// Social Buttons  
		m_Discord 					= layoutRoot.FindAnyWidget( "DiscordBtn" );
		m_DiscordImg 				= layoutRoot.FindAnyWidget( "DiscordBtn_img" );
		m_Twitter 					= layoutRoot.FindAnyWidget( "TwitterBtn" );
		m_TwitterImg 				= layoutRoot.FindAnyWidget( "TwitterBtn_img" );
		m_Youtube 					= layoutRoot.FindAnyWidget( "YoutubeBtn" );
		m_YoutubeImg 				= layoutRoot.FindAnyWidget( "YoutubeBtn_img" );
		m_Reddit 					= layoutRoot.FindAnyWidget( "RedditBtn" );
		m_RedditImg 				= layoutRoot.FindAnyWidget( "RedditBtn_img" );
		m_Facebook 					= layoutRoot.FindAnyWidget( "FacebookBtn" );
		m_FacebookImg 				= layoutRoot.FindAnyWidget( "FacebookBtn_img" );
		m_Meta 						= layoutRoot.FindAnyWidget( "MetaBtn" );
		m_MetaImg 					= layoutRoot.FindAnyWidget( "MetaBtn_img" );
		
		// Shaders
		m_TopShader 			    = layoutRoot.FindAnyWidget( "TopShader" );
		m_BottomShader 			    = layoutRoot.FindAnyWidget( "BottomShader" );

		// Call to action Buttons
		m_Play						= layoutRoot.FindAnyWidget( "play" );
		m_ChooseServer				= layoutRoot.FindAnyWidget( "choose_server" );
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "customize_character" );
		m_CharacterBtn 				= layoutRoot.FindAnyWidget( "character_button" );
		m_PrevCharacter				= layoutRoot.FindAnyWidget( "prev_character" );
		m_NextCharacter				= layoutRoot.FindAnyWidget( "next_character" );

		// Custom C2A Buttons
		m_PriorityQueue				= layoutRoot.FindAnyWidget( "QueueBtn" );
		m_Website					= layoutRoot.FindAnyWidget( "WebsiteBtn" );

		// Top Naviagtion Buttons
		m_ExitBtn		 		    = layoutRoot.FindAnyWidget( "ExitBtn" );
		m_ExitBtnImg		 		= layoutRoot.FindAnyWidget( "ExitBtn_img" );
		m_SettingsBtn				= layoutRoot.FindAnyWidget( "SettingsBtn" );
		m_SettingsBtnImg		 	= layoutRoot.FindAnyWidget( "SettingsBtn_img" );
		m_TutorialBtn				= layoutRoot.FindAnyWidget( "TutorialBtn" );
		m_TutorialBtnImg		 	= layoutRoot.FindAnyWidget( "TutorialBtn_img" );
		m_MessageBtn				= layoutRoot.FindAnyWidget( "MessageBtn" );
		m_MessageBtnImg		 		= layoutRoot.FindAnyWidget( "MessageBtn_img" );

		// Misc Elements
		m_welcomeBack				= layoutRoot.FindAnyWidget( "WelcomeBack" );
		m_SurvivorDivider			= layoutRoot.FindAnyWidget( "SurvivorDivider" );
		m_SurvivorBox				= layoutRoot.FindAnyWidget( "SurvivorBox" );
		m_StatsBox					= layoutRoot.FindAnyWidget( "StatisticsBoxBG" );
		m_MenuDivider				= layoutRoot.FindAnyWidget( "MenuDivider" );
		
		// Vanilla 
		m_Play						= layoutRoot.FindAnyWidget( "play" );
		m_ChooseServer				= layoutRoot.FindAnyWidget( "choose_server" );
		m_Stats						= new MainMenuStats( layoutRoot.FindAnyWidget("StatsBox"));
		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );
		m_ScenePC					= m_Mission.GetIntroScenePC();
		m_PlayerName				= TextWidget.Cast(layoutRoot.FindAnyWidget("character_name_text"));
		string version;
		
		GetGame().GetVersion( version );
		GetGame().GetUIManager().ScreenFadeOut(0);
		SetFocus( null );
		GetDayZGame().GetBacklit().MainMenu_OnShow();
		
		// Colorful UI Theming -----------------------------------------
		// Visual Elements
		m_welcomeBack.SetColor(UIColor.Yellow());
		m_SurvivorBox.SetColor(colorScheme.SurvivorBox());
		m_StatsBox.SetColor(colorScheme.StatsBox());
		m_TopShader.SetColor(colorScheme.TopShader());
		m_BottomShader.SetColor(colorScheme.BottomShader());
		m_MenuDivider.SetColor(colorScheme.Separator());
		m_SurvivorDivider.SetColor(colorScheme.Separator());

		// Top Nav Icons
		m_SettingsBtnImg.SetColor(colorScheme.NavIcon());
		m_TutorialBtnImg.SetColor(colorScheme.NavIcon());
		m_MessageBtnImg.SetColor(colorScheme.NavIcon());
		m_ExitBtnImg.SetColor(colorScheme.NavIcon());
		
		// Social Icons
		m_DiscordImg.SetColor(UIColor.discord());
		m_TwitterImg.SetColor(UIColor.twitter());
		m_YoutubeImg.SetColor(UIColor.youtube());
		m_RedditImg.SetColor(UIColor.reddit());
		m_FacebookImg.SetColor(UIColor.meta());
		m_MetaImg.SetColor(UIColor.meta());

		// This progress bar is just used as trim. 
		m_ProgressLoading = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		m_ProgressLoading.SetColor(colorScheme.Loadingbar());

		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );
		return layoutRoot;
	}	

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		if (IsFocusable(w))
		{
			ColorNormal(w);
			return true;
		}
		return false;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
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
		else if (button == MouseState.LEFT && w == m_Website)
		{
			GetGame().OpenURL(MenuURLS.urlWebsite);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_PriorityQueue)
		{
			GetGame().OpenURL(MenuURLS.urlPriorityQ);
			return false;
		}
		else if ( w == m_CharacterBtn )
		{
			OpenMenuCustomizeCharacter();
			return true;
		}
		else if (w == m_TutorialBtn)
		{
			OpenTutorials();
			return true;
		}	
		else if ( w == m_SettingsBtn )
		{
			OpenSettings();
			return true;
		}
		else if ( w == m_MessageBtn )
		{
			OpenCredits();
			return true;
		}	
		else if ( w == m_ExitBtn )
		{
			Exit();
			return true;
		}		
		return super.OnClick(w, x, y, button);
	};

	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = colorScheme.ButtonHover();
		int color_img = colorScheme.ButtonHover();	

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

	void TwitterHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.twitter();
		int color_img = UIColor.twitter();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void DiscordHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.discord();
		int color_img = UIColor.discord();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void YoutubeHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.youtube();
		int color_img = UIColor.youtube();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void RedditHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.reddit();
		int color_img = UIColor.reddit();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void MetaHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.meta();
		int color_img = UIColor.meta();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}
	
	override void LoadMods()
	{
		// Kill this annoying shit
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		
		if( w == m_CharacterBtn )
		{
			TwitterHighlight( w );
			return true;
		}
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
		if( w == m_Meta )
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
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}

	override void Exit()
	{
		EnterScriptedMenu( COLORFUL_EXIT );
	}
}