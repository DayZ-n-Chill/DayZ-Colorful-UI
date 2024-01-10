
// Prioity Queue ----------------------------------
modded class LoginQueueBase extends LoginScreenBase
{
	override Widget Init()
	{	
		// Use CUI Layout	
		layoutRoot 		= GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/cui.dialog_queue_position.layout");
		// Vanillia Casting
		m_HintPanel	= new UiHintPanelLoading(layoutRoot.FindAnyWidget("hint_frame0"));
		m_txtPosition	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtPosition"));
		m_txtNote 		= TextWidget.Cast(layoutRoot.FindAnyWidget("txtNote"));
		m_btnLeave 		= ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
		m_txtNote.Show(true);
		layoutRoot.FindAnyWidget("notification_root").Show(false);
		return layoutRoot;
	}
};

// Loging In Screen ------------------------------
modded class LoginTimeBase extends LoginScreenBase
{
	override Widget Init()
 	{
 		// Use CUI Layout
		layoutRoot 			= GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/cui.dialog_login_time.layout");
		// Vanillia Casting
		m_txtDescription 	= TextWidget.Cast(layoutRoot.FindAnyWidget("txtDescription"));
		m_txtLabel 			= TextWidget.Cast(layoutRoot.FindAnyWidget("txtLabel"));
		m_btnLeave 			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
		m_txtDescription.Show(true);
		layoutRoot.FindAnyWidget("notification_root").Show(false);
		return layoutRoot;
	}		
 };

 // Loading Screen (UH DUH!) --------------------
modded class LoadingScreen
{
	protected ImageWidget m_Background;
	protected ImageWidget m_tShader;
	protected ImageWidget m_bShader;
	protected ImageWidget m_tipIcon;
	protected TextWidget m_tipHeader;
	protected ImageWidget m_tipLineL;
	protected ImageWidget m_tipLineR;
	protected TextWidget m_tipText;
	protected TextWidget m_loadingMsg;

	void LoadingScreen(DayZGame game)
	{
		m_DayZGame = game;
		// Use the CUI 2.0 custom layout 
		m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("Colorful-UI/gui/layouts/cui.loading.layout");
		// CUI 2.0 Elements
		Class.CastTo(m_tShader, m_WidgetRoot.FindAnyWidget("TopShader"));
		Class.CastTo(m_bShader, m_WidgetRoot.FindAnyWidget("BottomShader"));
		Class.CastTo(m_tipIcon, m_WidgetRoot.FindAnyWidget("hintIcon"));
		Class.CastTo(m_tipHeader, m_WidgetRoot.FindAnyWidget("TipHeader"));
		Class.CastTo(m_tipLineL, m_WidgetRoot.FindAnyWidget("LinesImageLeft"));
		Class.CastTo(m_tipLineR, m_WidgetRoot.FindAnyWidget("LinesImageRight"));
		Class.CastTo(m_tipText, m_WidgetRoot.FindAnyWidget("Hints"));
		Class.CastTo(m_loadingMsg, m_WidgetRoot.FindAnyWidget("LoadingMsg"));
		// Load BG and Progress Bar
		m_ImageBackground = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("ImageBackground"));
		m_ProgressLoading = ProgressBarWidget.Cast(m_WidgetRoot.FindAnyWidget("LoadingBar"));
		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
		m_ImageWidgetBackground.Show(true);
		// Theme the elements. 
		// To edit these colors see the "Constant.c" file
		m_ProgressLoading.SetColor(colorScheme.Loadingbar());
		m_tShader.SetColor(colorScheme.TopShader());
		m_bShader.SetColor(colorScheme.BottomShader());
		m_tipIcon.SetColor(colorScheme.TipIcon());
		m_tipHeader.SetColor(colorScheme.TipHeader());
		m_tipLineL.SetColor(colorScheme.TipLine());
		m_tipLineR.SetColor(colorScheme.TipLine());
		m_tipText.SetColor(colorScheme.TipText());
		m_loadingMsg.SetColor(colorScheme.LoadingMsg());
	}

	override void Show()
	{
		// Set default Tip Data
		m_tipHeader.SetText("Tip Header.");
		m_tipText.SetText("The tips will show up hear.");
		m_loadingMsg.SetText("Load Screen Messages.");

		// Use Random Background Images
		Widget lIcon = m_Background;
		ImageWidget m_Background = ImageWidget.Cast( m_WidgetRoot.FindAnyWidget("ImageBackground"));		
		m_Background.LoadImageFile(0, GetRandomBackground()); 
	}
};
