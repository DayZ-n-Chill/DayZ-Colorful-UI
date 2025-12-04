// modded class MainMenu extends UIScriptedMenu
// {
// 	protected ImageWidget m_TopShader, m_BottomShader, m_MenuDivider, m_StatisticsBoxBG, m_SurvivorBox, m_Logo;
// 	protected ButtonWidget m_Play, m_Exit, m_SettingsBtn, m_TutorialBtn, m_MessageBtn, m_PrioQ, m_Website, m_Discord, m_Twitter, m_Youtube, m_Reddit, m_Facebook, m_CharacterBtn;

// 	protected ButtonWidget m_TestBtn0, m_TestBtn1, m_TestBtn2, m_TestBtn3, m_TestBtn4;

// 	protected Widget m_TopSpacer, m_BottomSpacer;
// 	protected ProgressBarWidget m_LoadingBar;
// 	protected VideoWidget m_MenuVid;

// 	// Stats support (from vanilla)
// 	protected ref MainMenuStats m_Stats;

// 	override Widget Init()
// 	{
// 		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/GUI/layouts/menus/cui.mainMenu.layout");

// 		m_Play              = ButtonWidget.Cast(layoutRoot.FindAnyWidget("PlayBtn"));
// 		m_Exit              = ButtonWidget.Cast(layoutRoot.FindAnyWidget("ExitBtn"));
// 		m_SettingsBtn       = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SettingsBtn"));
// 		m_TutorialBtn       = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TutorialBtn"));
// 		m_MessageBtn        = ButtonWidget.Cast(layoutRoot.FindAnyWidget("MessageBtn"));
// 		m_CharacterBtn      = ButtonWidget.Cast(layoutRoot.FindAnyWidget("CharacterBtn"));

// 		m_PrioQ             = ButtonWidget.Cast(layoutRoot.FindAnyWidget("QueueBtn"));
// 		m_Website           = ButtonWidget.Cast(layoutRoot.FindAnyWidget("WebsiteBtn"));
// 		m_Discord           = ButtonWidget.Cast(layoutRoot.FindAnyWidget("DiscordBtn"));
// 		m_Twitter           = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TwitterBtn"));
// 		m_Youtube           = ButtonWidget.Cast(layoutRoot.FindAnyWidget("YoutubeBtn"));
// 		m_Reddit            = ButtonWidget.Cast(layoutRoot.FindAnyWidget("RedditBtn"));
// 		m_Facebook          = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FacebookBtn"));

// 		m_TestBtn0          = ButtonWidget.Cast(layoutRoot.FindAnyWidget("testBtn0"));
// 		m_TestBtn1          = ButtonWidget.Cast(layoutRoot.FindAnyWidget("testBtn1"));
// 		m_TestBtn2          = ButtonWidget.Cast(layoutRoot.FindAnyWidget("testBtn2"));
// 		m_TestBtn3          = ButtonWidget.Cast(layoutRoot.FindAnyWidget("testBtn3"));
// 		m_TestBtn4          = ButtonWidget.Cast(layoutRoot.FindAnyWidget("testBtn4"));

// 		m_TopShader         = ImageWidget.Cast(layoutRoot.FindAnyWidget("TopShader"));
// 		m_BottomShader      = ImageWidget.Cast(layoutRoot.FindAnyWidget("BottomShader"));
// 		m_StatisticsBoxBG   = layoutRoot.FindAnyWidget("StatisticsBoxBG");
// 		m_SurvivorBox       = layoutRoot.FindAnyWidget("SurvivorBox");
// 		m_TopSpacer         = layoutRoot.FindAnyWidget("TopSpacer");
// 		m_MenuDivider       = ImageWidget.Cast(layoutRoot.FindAnyWidget("MenuDivider"));
// 		m_BottomSpacer      = layoutRoot.FindAnyWidget("BottomSpacer");

// 		m_LoadingBar        = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("LoadingBar"));
// 		m_Logo              = ImageWidget.Cast(layoutRoot.FindAnyWidget("Logo"));

// 		if (m_StatisticsBoxBG) m_StatisticsBoxBG.SetColor(UIColor.cuiDarkBlue());
// 		if (m_SurvivorBox) m_SurvivorBox.SetColor(UIColor.cuiDarkBlue());
// 		if (m_TopShader) m_TopShader.SetColor(colorScheme.TopShader());
// 		if (m_BottomShader) m_BottomShader.SetColor(colorScheme.BottomShader());
// 		if (m_MenuDivider) m_MenuDivider.SetColor(colorScheme.Separator());
// 		if (m_LoadingBar) m_LoadingBar.SetColor(colorScheme.Loadingbar());

// 		cuiElmnt.proBtnCB(m_Play, "#main_menu_play", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "");
// 		cuiElmnt.proBtnCB(m_Exit, "#main_menu_exit", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "Exit");
// 		cuiElmnt.proBtnCB(m_SettingsBtn, "Settings", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "OpenSettings");
// 		cuiElmnt.proBtnCB(m_TutorialBtn, "Tutorial", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "OpenTutorials");
// 		cuiElmnt.proBtnCB(m_MessageBtn, "Credits", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "OpenCredits");
// 		cuiElmnt.proBtnCB(m_CharacterBtn, "", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "OpenMenuCustomizeCharacter");

// 		cuiElmnt.proBtnURL(m_PrioQ, "Priority Queue", colorScheme.PrimaryText(), colorScheme.ButtonHover(), CustomURL.PriorityQ);
// 		cuiElmnt.proBtnURL(m_Website, "Visit Website", colorScheme.PrimaryText(), colorScheme.ButtonHover(), CustomURL.Website);

// 		cuiElmnt.proBtnURL(m_Discord, "Discord", colorScheme.PrimaryText(), UIColor.Discord(), SocialURL.Discord);
// 		cuiElmnt.proBtnURL(m_Twitter, "Twitter", colorScheme.PrimaryText(), UIColor.Twitter(), SocialURL.Twitter);
// 		cuiElmnt.proBtnURL(m_Youtube, "Youtube", colorScheme.PrimaryText(), UIColor.YouTube(), SocialURL.Youtube);
// 		cuiElmnt.proBtnURL(m_Reddit, "Reddit", colorScheme.PrimaryText(), UIColor.Reddit(), SocialURL.Reddit);
// 		cuiElmnt.proBtnURL(m_Facebook, "Facebook", colorScheme.PrimaryText(), UIColor.Facebook(), SocialURL.Facebook);
		
// 		// Test button hookups (Only used in Proto.Layout but was left here for refrence)
// 		if (m_TestBtn0) cuiElmnt.proSolidBtn(m_TestBtn0, "Icon Button", colorScheme.BrandColor(), colorScheme.ButtonHover(), "https://example.com");
// 		if (m_TestBtn1) cuiElmnt.proSolidBtn(m_TestBtn1, "Solid Button", colorScheme.BrandColor(), colorScheme.ButtonHover(), "https://example.com");
// 		if (m_TestBtn2) cuiElmnt.proBtnURL(m_TestBtn2, "Test Btn with URL", colorScheme.PrimaryText(), colorScheme.ButtonHover(), "https://example.com");
// 		if (m_TestBtn3) cuiElmnt.proBtnDC(m_TestBtn3, "Test Button", colorScheme.PrimaryText(), colorScheme.ButtonHover(), SERVER_IP, SERVER_PORT);
// 		if (m_TestBtn4) cuiElmnt.proIconBtn(m_TestBtn4, 1, colorScheme.PrimaryText(), colorScheme.ButtonHover(), "https://example.com");

// 		CheckURL(m_PrioQ, CustomURL.PriorityQ);
// 		CheckURL(m_Website, CustomURL.Website);
// 		CheckSocials(m_Discord, SocialURL.Discord);
// 		CheckSocials(m_Twitter, SocialURL.Twitter);
// 		CheckSocials(m_Youtube, SocialURL.Youtube);
// 		CheckSocials(m_Reddit, SocialURL.Reddit);
// 		CheckSocials(m_Facebook, SocialURL.Facebook);

// 		if (allInvalid && m_MenuDivider)
// 		{
// 			if (m_TopSpacer) m_TopSpacer.Show(false);
// 			m_MenuDivider.Show(false);
// 			if (m_BottomSpacer) m_BottomSpacer.Show(false);
// 		}

// 		Branding.ApplyLogo(m_Logo);

// 		#ifdef WORKBENCH
// 		CuiLogger.Log("Skipping video in Workbench mode");
// 		#else
// 		if (EnableMenuVideo)
// 		{
// 			Class.CastTo(m_MenuVid, layoutRoot.FindAnyWidget("MenuVideo"));
// 			if (m_MenuVid)
// 			{
// 				if (!FileExist("$saves:" + m_MainMenuVideo))
// 					CopyFile("Colorful-UI/GUI/video/" + m_MainMenuVideo, "$saves:" + m_MainMenuVideo);

// 				m_MenuVid.Load("$saves:" + m_MainMenuVideo, true);
// 				m_MenuVid.Play();
// 			}
// 		}
// 		#endif

// 		// Stats initialization (from vanilla)
// 		m_Stats = new MainMenuStats(layoutRoot.FindAnyWidget("character_stats_root"));
// 		return layoutRoot;
// 	}

// 	override void OnShow()
// 	{
// 		CuiLogger.Log("MainMenu.OnShow() - Validating UI elements");
// 		if (!m_LoadingBar) m_LoadingBar = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("LoadingBar"));
// 		if (!m_Logo) m_Logo = ImageWidget.Cast(layoutRoot.FindAnyWidget("Logo"));
// 		if (!m_TopShader) m_TopShader = ImageWidget.Cast(layoutRoot.FindAnyWidget("TopShader"));
// 		if (!m_BottomShader) m_BottomShader = ImageWidget.Cast(layoutRoot.FindAnyWidget("BottomShader"));
// 		// Update stats (from vanilla)
// 		if (m_Stats) m_Stats.UpdateStats();
// 	}

// 	override bool OnClick(Widget w, int x, int y, int button)
// 	{
// 		if (button == MouseState.LEFT && w == m_Play)
// 		{
// 			g_Game.ConnectFromServerBrowser( "192.168.146.1", 2302, "" );
// 			return true;
// 		}
// 		return false;
// 	}

// }
