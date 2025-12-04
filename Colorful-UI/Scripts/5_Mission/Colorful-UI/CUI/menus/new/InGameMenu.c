// modded class InGameMenu extends UIScriptedMenu
// {
//     protected ImageWidget m_TopShader, m_BottomShader, m_MenuDivider, m_GameOverScreenImage, m_Logo;
//     protected ButtonWidget m_PrioQ, m_Website, m_Discord, m_Twitter, m_Youtube, m_Reddit, m_Facebook;
//     protected ButtonWidget m_ExitButton, m_ContinueButton, m_OptionsButton, m_RestartButton, m_RespawnButton;
//     protected Widget m_TopSpacer, m_BottomSpacer, m_GameOverScreen;
//     protected UiHintPanel m_HintPanel;
//     float m_TimerSlice;

//     override Widget Init()
//     {
//         layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/GUI/layouts/menus/inGame/cui.ingame.layout");
//         m_Logo                  = ImageWidget.Cast(layoutRoot.FindAnyWidget("Logo"));
//         m_GameOverScreen        = Widget.Cast(layoutRoot.FindAnyWidget("GameOverScreen"));
//         m_GameOverScreenImage   = ImageWidget.Cast(m_GameOverScreen.FindAnyWidget("GameOverScreenImage"));
//         m_HintPanel             = new UiHintPanel(layoutRoot.FindAnyWidget("hint_frame"));

//         m_ExitButton        = layoutRoot.FindAnyWidget("ExitBtn");
//         m_ContinueButton    = layoutRoot.FindAnyWidget("ContinueBtn");
//         m_OptionsButton     = layoutRoot.FindAnyWidget("OptionsBtn");
//         m_RestartButton     = layoutRoot.FindAnyWidget("RestartBtn");
//         m_RespawnButton     = layoutRoot.FindAnyWidget("respawn_button");
                
// 		m_PrioQ             = layoutRoot.FindAnyWidget("QueueBtn");
//         m_Website           = layoutRoot.FindAnyWidget("WebsiteBtn");
//         m_Discord           = layoutRoot.FindAnyWidget("DiscordBtn");
//         m_Twitter           = layoutRoot.FindAnyWidget("TwitterBtn");
//         m_Youtube           = layoutRoot.FindAnyWidget("YoutubeBtn");
//         m_Reddit            = layoutRoot.FindAnyWidget("RedditBtn");
//         m_Facebook          = layoutRoot.FindAnyWidget("FacebookBtn");

//         m_TopShader         = ImageWidget.Cast(layoutRoot.FindAnyWidget("TopShader"));
//         m_BottomShader      = ImageWidget.Cast(layoutRoot.FindAnyWidget("BottomShader"));
        
//         m_TopSpacer         = layoutRoot.FindAnyWidget("TopSpacer");
//         m_MenuDivider       = ImageWidget.Cast(layoutRoot.FindAnyWidget("MenuDivider"));
//         m_BottomSpacer      = layoutRoot.FindAnyWidget("BottomSpacer");

//         // Set the colors of Shader, Divider
//         m_TopShader.SetColor(colorScheme.TopShader());
//         m_BottomShader.SetColor(colorScheme.BottomShader());
//         m_MenuDivider.SetColor(colorScheme.Separator());

//         // Example of a button with a callbacks
//         cuiElmnt.proBtnCB(m_ExitButton,"#main_menu_exit",colorScheme.PrimaryText(),colorScheme.ButtonHover(),this,"OnClick_Exit");
//         cuiElmnt.proBtnCB(m_ContinueButton,"#main_menu_continue",colorScheme.PrimaryText(),colorScheme.ButtonHover(),this,"OnClick_Continue");
//         cuiElmnt.proBtnCB(m_OptionsButton,"#layout_xbox_ingame_menu_options",colorScheme.PrimaryText(),colorScheme.ButtonHover(),this,"OnClick_Options");
//         cuiElmnt.proBtnCB(m_RestartButton,"#main_menu_restart",colorScheme.PrimaryText(),colorScheme.ButtonHover(),this,"OnClick_Restart");
//         cuiElmnt.proBtnCB(m_RespawnButton,"#main_menu_respawn",colorScheme.PrimaryText(),colorScheme.ButtonHover(),this,"OnClick_Respawn");

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

// 		HudShow(false);       
        
//         Branding.ApplyLogo(m_Logo);
// 		m_GameOverScreen.SetAlpha(0);
// 		m_GameOverScreenImage.SetAlpha(0);
// 		m_GameOverScreenImage.LoadImageFile(0, GameOverScreen.GameOverScreenImage());

// 		return layoutRoot;
//     }

//    	override void Update(float timeslice)
// 	{
// 		if (ShowDeadScreen)
// 		{
// 			m_TimerSlice += timeslice;
// 			if (m_TimerSlice >= 0.01)
// 			{
// 				GameOverMan(timeslice);
// 				m_TimerSlice = 0;
// 			}
// 		}
// 		super.Update(timeslice);
// 	};

// 	void GameOverMan(float timeslice)
// 	{
// 		if (m_GameOverScreenImage.GetAlpha() < 1)
// 		{
// 			m_GameOverScreen.Show(true);

// 			float newAlpha = Math.Min(m_GameOverScreen.GetAlpha() + (1.5 * timeslice), 1);
// 			m_GameOverScreen.SetAlpha(newAlpha);

// 			if (newAlpha > 0.5)
// 			{
// 				m_GameOverScreenImage.SetAlpha(Math.Min(m_GameOverScreenImage.GetAlpha() + (1.25 * timeslice), 1));
// 			}
// 		}
// 	}
// }
