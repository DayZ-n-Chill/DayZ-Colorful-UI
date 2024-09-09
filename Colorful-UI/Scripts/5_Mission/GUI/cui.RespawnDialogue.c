modded class RespawnDialogue extends UIScriptedMenu
{

	private Widget m_Discord;
	private Widget m_Twitter;
	private Widget m_Youtube;
	private Widget m_Reddit;
	private Widget m_Facebook;
	private Widget m_Separator
	private	Widget m_shader

	private Widget m_DiscordImg;
	private Widget m_TwitterImg;
	private Widget m_YoutubeImg;
	private Widget m_RedditImg;
	private Widget m_FacebookImg;
	private Widget m_MetaImg;

	private Widget m_TopShader;
	private Widget m_BottomShader;
	private Widget m_MenuDivider;

	private Widget m_GameOverScreen;
	private ImageWidget m_GameOverScreenImage;


	override Widget Init()
	{
		layoutRoot 					= GetGame().GetWorkspace().CreateWidgets("colorful-ui/gui/layouts/cui.day_z_respawn_dialogue.layout");
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
		m_DiscordImg 				= layoutRoot.FindAnyWidget( "DiscordBtn_img" );
	    m_TwitterImg 				= layoutRoot.FindAnyWidget( "TwitterBtn_img" );
		m_YoutubeImg 				= layoutRoot.FindAnyWidget( "YoutubeBtn_img" );
		m_RedditImg 				= layoutRoot.FindAnyWidget( "RedditBtn_img" );
		m_FacebookImg 				= layoutRoot.FindAnyWidget( "FacebookBtn_img" );
		m_MetaImg 					= layoutRoot.FindAnyWidget( "MetaBtn_img" );
		m_TopShader 			    = layoutRoot.FindAnyWidget( "TopShader" );
		m_BottomShader 			    = layoutRoot.FindAnyWidget( "BottomShader" );
		m_MenuDivider				= layoutRoot.FindAnyWidget( "MenuDivider" );

		m_TopShader.SetColor(colorScheme.TopShader());
		m_BottomShader.SetColor(colorScheme.BottomShader());
		m_MenuDivider.SetColor(colorScheme.Separator());
		// Social Icons
		m_DiscordImg.SetColor(UIColor.discord());
		m_TwitterImg.SetColor(UIColor.twitter());
		m_YoutubeImg.SetColor(UIColor.youtube());
		m_RedditImg.SetColor(UIColor.reddit());
		m_FacebookImg.SetColor(UIColor.meta());
		m_MetaImg.SetColor(UIColor.meta());

		m_GameOverScreen = Widget.Cast(layoutRoot.FindAnyWidget("GameOverScreen"));
		m_GameOverScreen.SetAlpha(0);
		m_GameOverScreen.Show(false);
		m_GameOverScreenImage = ImageWidget.Cast(m_GameOverScreen.FindAnyWidget("GameOverScreenImage"));
		m_GameOverScreenImage.LoadImageFile(0, GameOverScreen.GameOverScreenImage());
		m_GameOverScreenImage.SetAlpha(0);

		return layoutRoot;
	}
	
	void Update(float timeslice)
	{
		if (ShowDeadScreen)
		{
			ShowGameOverScreen();
		}
		super.Update(timeslice);
	};

	void ShowGameOverScreen()
	{
		m_GameOverScreen.SetAlpha(1);
		m_GameOverScreenImage.SetAlpha(1);
		m_GameOverScreen.Show(true);
	}

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

		ColorHighlight(w);

		return true;
	}
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		ColorNormal(w);
		return true;
	}
	
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
}

