modded class MainMenu extends UIScriptedMenu
{
	protected ButtonWidget m_ExitBtn, m_SettingsBtn, m_TutorialBtn, m_MessageBtn, m_Website, m_PriorityQueue, m_CharacterBtn,m_Discord, m_Twitter, m_Youtube, m_Reddit, m_Facebook, m_Meta;
	protected ImageWidget m_TopShader, m_BottomShader, m_SurvivorDivider,m_MenuDivider, m_StatsBox, m_SurvivorBox, m_Logo, m_ExitBtnImg, m_SettingsBtnImg, m_TutorialBtnImg, m_MessageBtnImg, m_DiscordImg, m_TwitterImg, m_YoutubeImg, m_RedditImg, m_FacebookImg, m_MetaImg, m_welcomeBack;
	protected Widget m_TopSpacer, m_BottomSpacer;
	protected ProgressBarWidget m_LoadingBar;
	protected ref MainMenuStats m_Stats;
	protected VideoWidget m_MenuVid;
	
	override Widget Init()
	{
		// Load the layout file
		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/GUI/layouts/menus/cui.mainMenu.layout" );

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
		m_Logo                      = ImageWidget.Cast(layoutRoot.FindAnyWidget("Logo"))
		
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
		
		CheckURL(m_PriorityQueue, CustomURL.PriorityQ);
		CheckURL(m_Website, CustomURL.Website);
		CheckSocials(m_Discord, SocialURL.Discord);
		CheckSocials(m_Twitter, SocialURL.Twitter);
		CheckSocials(m_Youtube, SocialURL.Youtube);
		CheckSocials(m_Reddit, SocialURL.Reddit);
		CheckSocials(m_Facebook, SocialURL.Facebook);

		if (allInvalid && m_MenuDivider)
		{
			if (m_TopSpacer) m_TopSpacer.Show(false);
			m_MenuDivider.Show(false);
			if (m_BottomSpacer) m_BottomSpacer.Show(false);
		}

		#ifdef WORKBENCH
		CuiLogger.Log("Skipping video in Workbench mode");
		#else
		if (EnableMenuVideo)
		{
			Class.CastTo(m_MenuVid, layoutRoot.FindAnyWidget("MenuVideo"));
			if (m_MenuVid)
			{
				if (!FileExist("$saves:" + m_MainMenuVideo))
					CopyFile("Colorful-UI/GUI/video/" + m_MainMenuVideo, "$saves:" + m_MainMenuVideo);

				m_MenuVid.Load("$saves:" + m_MainMenuVideo, true);
				m_MenuVid.Play();
			}
		}
		#endif

		Branding.ApplyLogo(m_Logo);

		// Colorful UI Theming -----------------------------------------
		// // Visual Elements
		m_welcomeBack.SetColor(UIColor.Yellow());
		m_SurvivorBox.SetColor(colorScheme.SurvivorBox());
		m_StatsBox.SetColor(colorScheme.StatsBox());
		m_TopShader.SetColor(colorScheme.TopShader());
		m_BottomShader.SetColor(colorScheme.BottomShader());
		m_MenuDivider.SetColor(colorScheme.Separator());
		m_SurvivorDivider.SetColor(colorScheme.Separator());

		// // Top Nav Icons
		m_SettingsBtnImg.SetColor(colorScheme.NavIcon());
		m_TutorialBtnImg.SetColor(colorScheme.NavIcon());
		m_MessageBtnImg.SetColor(colorScheme.NavIcon());
		m_ExitBtnImg.SetColor(colorScheme.NavIcon());
		
		// Social Icons
		m_DiscordImg.SetColor(UIColor.Discord());
		m_TwitterImg.SetColor(UIColor.Twitter());
		m_YoutubeImg.SetColor(UIColor.YouTube());
		m_RedditImg.SetColor(UIColor.Reddit());
		m_FacebookImg.SetColor(UIColor.Meta());
		m_MetaImg.SetColor(UIColor.Meta());

		// This progress bar is just used as trim. 
		m_LoadingBar = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		m_LoadingBar.SetColor(colorScheme.Loadingbar());

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
			GetGame().OpenURL(SocialURL.Discord);
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Twitter)
		{
			GetGame().OpenURL(SocialURL.Twitter);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Reddit)
		{
			GetGame().OpenURL(SocialURL.Reddit);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Youtube)
		{
			GetGame().OpenURL(SocialURL.Youtube);
			return false;
		}	
		else if (button == MouseState.LEFT && w == m_Facebook)
		{
			GetGame().OpenURL(SocialURL.Facebook);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Website)
		{
			GetGame().OpenURL(CustomURL.Website);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_PriorityQueue)
		{
			GetGame().OpenURL(CustomURL.PriorityQ);
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
		int color_lbl = UIColor.Twitter();
		int color_img = UIColor.Twitter();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void DiscordHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.Discord();
		int color_img = UIColor.Discord();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void YoutubeHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.YouTube();
		int color_img = UIColor.YouTube();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void RedditHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.Reddit();
		int color_img = UIColor.Reddit();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void MetaHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.Meta();
		int color_img = UIColor.Meta();	

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
