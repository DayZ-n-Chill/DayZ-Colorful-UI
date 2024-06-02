modded class InGameMenu extends UIScriptedMenu
{
	private Widget m_Separator;
	private	Widget m_shader;
	private Widget m_Discord;
	private Widget m_Twitter;
	private Widget m_Youtube;
	private Widget m_Reddit;
	private Widget m_Facebook;
	
	private Widget m_DiscordImg;
	private Widget m_TwitterImg;
	private Widget m_YoutubeImg;
	private Widget m_RedditImg;
	private Widget m_FacebookImg;
	private Widget m_MetaImg;
	private Widget m_MenuDivider;
	
	private Widget m_TopShader;
	private Widget m_BottomShader;

	private Widget m_GameOverScreen;
	private ImageWidget m_GameOverScreenImage;
	float m_TimerSlice;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/cui.day_z_ingamemenu.layout");
			
		m_ContinueButton			= layoutRoot.FindAnyWidget( "ContinueBtn" );
		m_ExitButton				= layoutRoot.FindAnyWidget( "ExitBtn" );
		m_MenuDivider				= layoutRoot.FindAnyWidget( "MenuDivider" );
		m_RestartButton				= layoutRoot.FindAnyWidget( "RestartBtn" );
		m_RespawnButton 			= layoutRoot.FindAnyWidget( "respawn_button" );
		m_RestartDeadRandomButton	= layoutRoot.FindAnyWidget( "respawn_button_random" );
		m_RestartDeadCustomButton	= layoutRoot.FindAnyWidget( "respawn_button_custom" );
		m_OptionsButton				= layoutRoot.FindAnyWidget( "OptionsBtn" );
		m_ModdedWarning				= TextWidget.Cast( layoutRoot.FindAnyWidget( "ModdedWarning" ) );
		m_HintPanel					= new UiHintPanel(layoutRoot.FindAnyWidget( "hint_frame" ));
		m_ServerInfoPanel 			= layoutRoot.FindAnyWidget( "server_info" );
		m_ServerIP 					= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_ip" ) );
		m_ServerPort 				= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_port" ) );
		m_ServerName 				= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_name" ) );
		m_FavoriteImage 			= layoutRoot.FindAnyWidget( "favorite_image" );
		m_UnfavoriteImage 			= layoutRoot.FindAnyWidget( "unfavorite_image" );
		m_CopyInfoButton 			= layoutRoot.FindAnyWidget( "copy_button" );
		m_Separator 				= layoutRoot.FindAnyWidget( "actionItems_separator" );
		m_Discord 					= layoutRoot.FindAnyWidget( "DiscordBtn" );
		m_Twitter 					= layoutRoot.FindAnyWidget( "TwitterBtn" );
		m_Youtube 					= layoutRoot.FindAnyWidget( "YoutubeBtn" );
		m_Reddit 					= layoutRoot.FindAnyWidget( "RedditBtn" );
		m_Facebook 					= layoutRoot.FindAnyWidget( "FacebookBtn" );
		m_DiscordImg 				= layoutRoot.FindAnyWidget( "DiscordBtn_img" );
	    m_TwitterImg 				= layoutRoot.FindAnyWidget( "TwitterBtn_img" );
		m_YoutubeImg 				= layoutRoot.FindAnyWidget( "YoutubeBtn_img" );
		m_RedditImg 				= layoutRoot.FindAnyWidget( "RedditBtn_img" );
		m_FacebookImg 				= layoutRoot.FindAnyWidget( "FacebookBtn_img" );
		m_MetaImg 					= layoutRoot.FindAnyWidget( "MetaBtn_img" );
		m_TopShader 			    = layoutRoot.FindAnyWidget( "TopShader" );
		m_BottomShader 			    = layoutRoot.FindAnyWidget( "BottomShader" );
		
		// Social Icons
		m_DiscordImg.SetColor(UIColor.discord());
		m_TwitterImg.SetColor(UIColor.twitter());
		m_YoutubeImg.SetColor(UIColor.youtube());
		m_RedditImg.SetColor(UIColor.reddit());
		m_FacebookImg.SetColor(UIColor.meta());
		m_MetaImg.SetColor(UIColor.meta());

   		m_MenuDivider.SetColor(colorScheme.Separator());
		m_TopShader.SetColor(colorScheme.TopShader());
		m_BottomShader.SetColor(colorScheme.BottomShader());

		HudShow( false );
		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));

		m_GameOverScreen = Widget.Cast(layoutRoot.FindAnyWidget("GameOverScreen"));
		m_GameOverScreen.SetAlpha(0);
		m_GameOverScreen.Show(false);
		m_GameOverScreenImage = ImageWidget.Cast(m_GameOverScreen.FindAnyWidget("GameOverScreenImage"));
		m_GameOverScreenImage.LoadImageFile(0, GameOverScreen.GameOverScreenImage());
		m_GameOverScreenImage.SetAlpha(0);

		return layoutRoot;
	}

	override void Update(float timeslice)
	{
		if (ShowDeadScreen)
		{
			m_TimerSlice += timeslice;
			if (m_TimerSlice >= 0.01)
			{
				GameOverMan(timeslice);
				m_TimerSlice = 0;
			}
		}
		super.Update(timeslice);
	};

	void GameOverMan(float timeslice)
	{
		if (m_GameOverScreenImage.GetAlpha() < 1)
		{
			m_GameOverScreen.Show(true);

			float newAlpha = Math.Min(m_GameOverScreen.GetAlpha() + (1.5 * timeslice), 1);
			m_GameOverScreen.SetAlpha(newAlpha);

			if (newAlpha > 0.5)
			{
				m_GameOverScreenImage.SetAlpha(Math.Min(m_GameOverScreenImage.GetAlpha() + (1.25 * timeslice), 1));
			}
		}
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if ( w == m_ContinueButton )
		{
			OnClick_Continue();
			return true;
		}
		else if ( w == m_RestartButton )
		{
			OnClick_Restart();
			return true;
		}
		else if ( w == m_RespawnButton )
		{
			OnClick_Respawn();
			return true;
		}
		else if ( w == m_OptionsButton )
		{
			OnClick_Options();
			return true;
		}
		else if ( w == m_ExitButton )
		{
			OnClick_Exit();
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Discord)
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

	// If you want to change the way the buttons work.  
	// Visit the Colorful.MainMenu.c file. It has notes.
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
		int color_img = UIColor.twitter();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	protected void DiscordHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.discord();
		int color_img = UIColor.discord();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	protected void YoutubeHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.youtube();
		int color_img = UIColor.youtube();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	protected void RedditHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.reddit();
		int color_img = UIColor.reddit();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	protected void MetaHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.meta();
		int color_img = UIColor.meta();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	override bool OnMouseEnter( Widget w, int x, int y )
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

		ColorHighlight( w );
		return true;
	}
	
	override void OnShow() {
	    super.OnShow();
	}
}
