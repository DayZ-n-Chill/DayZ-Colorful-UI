// modded class LogoutMenu extends UIScriptedMenu
// {	
// 	protected ImageWidget m_TopShader, m_BottomShader, m_MenuDivider, m_Logo;
// 	protected ButtonWidget m_LogoutNow, m_Cancel, m_PrioQ, m_Website, m_Discord, m_Twitter, m_Youtube, m_Reddit, m_Facebook;
// 	protected Widget m_TopSpacer, m_BottomSpacer;
// 	private	Widget m_timerText;
// 	protected TextWidget m_LogoutTimeText;

//         override Widget Init()
//         {
//                 layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-ui/gui/layouts/menus/inGame/cui.logout.layout");

//                 CuiLogger.Log("LogoutMenu Init");
	
// 		m_Logo 				= ImageWidget.Cast(layoutRoot.FindAnyWidget("Logo"));
// 		m_LogoutTimeText 	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtLogoutTime"));

// 		m_LogoutNow			= layoutRoot.FindAnyWidget("ExitBtn");
// 		m_Cancel			= layoutRoot.FindAnyWidget("CancelBtn");

// 		m_PrioQ				= layoutRoot.FindAnyWidget("QueueBtn");
// 		m_Website			= layoutRoot.FindAnyWidget("WebsiteBtn");
// 		m_Discord 			= layoutRoot.FindAnyWidget("DiscordBtn");
// 		m_Twitter 			= layoutRoot.FindAnyWidget("TwitterBtn");
// 		m_Youtube 			= layoutRoot.FindAnyWidget("YoutubeBtn");
// 		m_Reddit 			= layoutRoot.FindAnyWidget("RedditBtn");
// 		m_Facebook 			= layoutRoot.FindAnyWidget("FacebookBtn");

// 		m_TopShader 		= layoutRoot.FindAnyWidget("TopShader");
// 		m_BottomShader 		= layoutRoot.FindAnyWidget("BottomShader");
		
// 		m_TopSpacer         = layoutRoot.FindAnyWidget("TopSpacer");
//         m_MenuDivider       = ImageWidget.Cast(layoutRoot.FindAnyWidget("MenuDivider"));
//         m_BottomSpacer      = layoutRoot.FindAnyWidget("BottomSpacer");
		
// 		// Set the colors of Shader, Divider, and Logout Timer
//         m_TopShader.SetColor(colorScheme.TopShader());
//         m_BottomShader.SetColor(colorScheme.BottomShader());
//         m_MenuDivider.SetColor(colorScheme.Separator());
// 		m_LogoutTimeText.SetColor(colorScheme.LogOutTimer());

// 		// Set Button color, and type. 
// 		// COLOR  CONTROLS:: Colorful-UI-Pro\Colorful-UI\Scripts\3_Game\UIConfig\Color.c
// 		// GLOBAL CONTROLS:: Colorful-UI-Pro\Colorful-UI\Scripts\3_Game\UIConfig\Scheme.c
// 		// You can even be specific and set the color directly. ie. argb(255, 255, 255, 255);
		
// 		// Example of a button with a callback
//         cuiElmnt.proBtnCB(m_LogoutNow,"#main_menu_exit",colorScheme.PrimaryText(),colorScheme.ButtonHover(),this,"abortMission");
// 		cuiElmnt.proBtnCB(m_Cancel,"Cancel",colorScheme.PrimaryText(),colorScheme.ButtonHover(),this,"canelExit");

// 		// Custom Links
//         cuiElmnt.proBtnURL(m_PrioQ,"Priority Queue",colorScheme.PrimaryText(),colorScheme.ButtonHover(),CustomURL.PriorityQ);           
//         cuiElmnt.proBtnURL(m_Website,"Visit Website",colorScheme.PrimaryText(),colorScheme.ButtonHover(),CustomURL.Website);

// 		// Social Links
//         cuiElmnt.proBtnURL(m_Discord,"Discord",colorScheme.PrimaryText(),UIColor.Discord(),SocialURL.Discord);
//         cuiElmnt.proBtnURL(m_Twitter,"Twitter",colorScheme.PrimaryText(),UIColor.Twitter(),SocialURL.Twitter);  
//         cuiElmnt.proBtnURL(m_Youtube,"Youtube",colorScheme.PrimaryText(),UIColor.YouTube(),SocialURL.Youtube);
//         cuiElmnt.proBtnURL(m_Reddit,"Reddit",colorScheme.PrimaryText(),UIColor.Reddit(),SocialURL.Reddit);
//         cuiElmnt.proBtnURL(m_Facebook,"Facebook",colorScheme.PrimaryText(),UIColor.Facebook(),SocialURL.Facebook);

// 		// These checks show/hide what buttons that are invalid or null
//         CheckURL(m_PrioQ,    	 CustomURL.PriorityQ);
//         CheckURL(m_Website,  	 CustomURL.Website);
//         CheckSocials(m_Discord,  SocialURL.Discord);
//         CheckSocials(m_Twitter,  SocialURL.Twitter);
//         CheckSocials(m_Youtube,  SocialURL.Youtube);
//         CheckSocials(m_Reddit,   SocialURL.Reddit);
//         CheckSocials(m_Facebook, SocialURL.Facebook);

//         if (allInvalid && m_MenuDivider)
//         {
//             m_TopSpacer.Show(false);
//             m_MenuDivider.Show(false);
//             m_BottomSpacer.Show(false);
//         }

// 		// Make the player lay down. Change with what ever emote you want to use. 
// 		// Emotes:: scripts\5_mission\gui\gesturesmenu.c
// 		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
// 		if (player.GetEmoteManager() && !player.IsRestrained() && !player.IsUnconscious()) 
// 		{
// 			player.GetEmoteManager().CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_LYINGDOWN);
// 			player.GetEmoteManager().GetEmoteLauncher().SetForced(EmoteLauncher.FORCE_DIFFERENT);
// 		}
		
// 		Branding.ApplyLogo(m_Logo);
// 		return layoutRoot;
// 	}

//         void abortMission()
//         {
//                 CuiLogger.Log("LogoutMenu abortMission");
//                 GetGame().GetMission().AbortMission();
//         }

//         void canelExit()
//         {
//                 CuiLogger.Log("LogoutMenu cancelExit");
//                 Hide();
//                 Cancel();
//         }
// }
