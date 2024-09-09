modded class LogoutMenu extends UIScriptedMenu
{	
	protected Widget m_restartbtn
	protected Widget m_optionsbtn
	private Widget m_Discord;
	private Widget m_Twitter;
	private Widget m_Youtube;
	private Widget m_Reddit;
	private Widget m_Facebook;
	private Widget m_Separator
	private	Widget m_shader

	private	Widget m_timerText

	private Widget m_DiscordImg;
	private Widget m_TwitterImg;
	private Widget m_YoutubeImg;
	private Widget m_RedditImg;
	private Widget m_FacebookImg;
	private Widget m_MetaImg;

	private Widget m_MenuDivider;
	private Widget m_TopShader;
	private Widget m_BottomShader;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-ui/gui/layouts/cui.day_z_logout_dialog.layout");
	
		// Custom Buttons  
		// NOTE: THe "NameBtn" is the name of the widget in the layout file.
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
		m_timerText 				= layoutRoot.FindAnyWidget( "txtLogoutTime" );

		m_restartbtn		= ButtonWidget.Cast(layoutRoot.FindAnyWidget("restartbtn"));
		m_optionsbtn        = ButtonWidget.Cast(layoutRoot.FindAnyWidget("optionsbtn"));

		m_LogoutTimeText 	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtLogoutTime"));
		m_DescriptionText 	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtDescription"));
		m_bLogoutNow 		= ButtonWidget.Cast(layoutRoot.FindAnyWidget("bLogoutNow"));
		m_bCancel 			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("bCancel"));
		
		// player should sit down if possible
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player.GetEmoteManager() && !player.IsRestrained() && !player.IsUnconscious()) 
		{
			player.GetEmoteManager().CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_LYINGDOWN);
			player.GetEmoteManager().GetEmoteLauncher().SetForced(EmoteLauncher.FORCE_DIFFERENT);
		}

		m_TopShader.SetColor(colorScheme.TopShader());
		m_BottomShader.SetColor(colorScheme.BottomShader());
		m_MenuDivider.SetColor(colorScheme.Separator());
		m_timerText.SetColor(colorScheme.LogOutTimer());
		
		// Social Icons
		m_DiscordImg.SetColor(UIColor.discord());
		m_TwitterImg.SetColor(UIColor.twitter());
		m_YoutubeImg.SetColor(UIColor.youtube());
		m_RedditImg.SetColor(UIColor.reddit());
		m_FacebookImg.SetColor(UIColor.meta());
		m_MetaImg.SetColor(UIColor.meta());

		m_Separator = layoutRoot.FindAnyWidget( "actionItems_separator" );

		return layoutRoot;
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
		else if (w == m_restartbtn)
		{
			GetGame().GetMission().AbortMission();
			
			return true;
		}
		else if (w == m_optionsbtn)
		{
			Hide();
			Cancel();
			return true;
		}

		return super.OnClick(w, x, y, button);
	};
	
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

	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		ColorNormal( w );
		return true;
	}

	protected void ColorHighlight( Widget w )
	{
		if( !w )
			return;

		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.ButtonHover());
	};

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

	protected void ColorNormal( Widget w )
	{
		if( !w )
			return;		
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.PrimaryText() );
	}	


}
