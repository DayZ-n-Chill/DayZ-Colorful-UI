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

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-ui/gui/layouts/cui.day_z_logout_dialog.layout");
	
		// Custom Buttons  
		// NOTE: THe "NameBtn" is the name of the widget in the layout file.
		m_Discord 			= layoutRoot.FindAnyWidget( "DiscordBtn" );
		m_Twitter 			= layoutRoot.FindAnyWidget( "TwitterBtn" );
		m_Youtube 			= layoutRoot.FindAnyWidget( "YoutubeBtn" );
		m_Reddit 			= layoutRoot.FindAnyWidget( "RedditBtn" );
		m_Facebook 			= layoutRoot.FindAnyWidget( "FacebookBtn" );
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

		m_Separator 				= layoutRoot.FindAnyWidget( "actionItems_separator" );
		// m_Separator.SetColor(colorScheme.SeparatorColor());
		// Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));
		// m_shader.SetColor(colorScheme.ShaderColor());

		return layoutRoot;
	}
	
	// Button Hover Functions
	// These type of buttons are not normally in this file 
	// So we borrow some code from the vanillia mainmenu.c
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

	protected void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.ButtonHover());
	};

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

	protected void ColorNormal( Widget w )
	{
		if( !w )
			return;		
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.PrimaryText() );
	}	
}
