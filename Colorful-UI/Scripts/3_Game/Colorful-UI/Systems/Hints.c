modded class UiHintPanel extends ScriptedWidgetEventHandler
{	
	protected const string m_DataPath = "Colorful-UI/Scripts/data/hints.json";
	protected string m_RootPath       = "Colorful-UI/Gui/layouts/loading/hints/cui.ingamehints.layout";	
}

modded class UiHintPanelLoading extends UiHintPanel
{
	protected ImageWidget m_TipLineL;
	protected ImageWidget m_TipLineR;
	protected VideoWidget m_Video;

	void ~UiHintPanelLoading()
	{
		CuiLogger.Log("UiHintPanelLoading.~UiHintPanelLoading() - Cleaning up video resources");
		
		if (m_Video)
		{
			m_Video.Stop();
			m_Video.Unload();
	
			CuiLogger.Log("UiHintPanelLoading.~UiHintPanelLoading() - Video stopped and unloaded");
		}
	}

	override void Init(DayZGame game)
    {
        CuiLogger.Log("UiHintPanelLoading.Init() - Starting hint panel init");

        m_RootPath = "Colorful-UI/gui/layouts/loading/hints/cui.loadinghints.layout";
        
        if (!game)
        {
            CuiLogger.Log("UiHintPanelLoading.Init() - Game context not found, aborting init");
            return;
        }

        m_Game = game;
        LoadContentList();
        if (m_ContentList)    
        {
            CuiLogger.Log("UiHintPanelLoading.Init() - Content list loaded, building layout...");
            BuildLayout(m_ParentWidget);
            RandomizePageIndex();
            PopulateLayout();
            StartSlideshow();            
        }
        else 
        {
            CuiLogger.Log("ERROR: UiHintPanelLoading.Init() - Could not create the hint panel. The data are missing!");
        }
    }

	override protected void BuildLayout(Widget parent_widget)
	{
        CuiLogger.Log("UiHintPanelLoading.BuildLayout() - Creating layout");

        protected ImageWidget m_TopShader;
	    protected ImageWidget m_BottomShader;
        protected ImageWidget m_Icon;

		m_RootFrame = m_Game.GetWorkspace().CreateWidgets(m_RootPath, parent_widget);

        #ifdef WORKBENCH
            CuiLogger.Log("UiHintPanelLoading.BuildLayout() - Skipping video in Workbench mode");
        #else
            if (LoadVideo) {
                CuiLogger.Log("UiHintPanelLoading.BuildLayout() - Loading and playing video");

                Class.CastTo(m_Video, m_RootFrame.FindAnyWidget("LoadingVid"));
                if (!FileExist("$saves:" + m_LoadingVideo))
                    CopyFile("Colorful-UI/GUI/video/" + m_LoadingVideo, "$saves:" + m_LoadingVideo);
                m_Video.Load("$saves:" + m_LoadingVideo, true);
                m_Video.Play();
            }
        #endif

		if (m_RootFrame)
		{
            CuiLogger.Log("UiHintPanelLoading.BuildLayout() - Root frame created, finding widgets");

            m_Icon              = ImageWidget.Cast(m_RootFrame.FindAnyWidget("hintIcon"));	
		    m_TipLineL          = ImageWidget.Cast(m_RootFrame.FindAnyWidget("LinesImageLeft"));
            m_TipLineR          = ImageWidget.Cast(m_RootFrame.FindAnyWidget("LinesImageRight"));
            m_TopShader         = ImageWidget.Cast(m_RootFrame.FindAnyWidget("TopShader"));
		    m_BottomShader      = ImageWidget.Cast(m_RootFrame.FindAnyWidget("BottomShader"));
            m_SpacerFrame		= m_RootFrame.FindAnyWidget("Hints");	
			m_UiLeftButton		= ButtonWidget.Cast(m_RootFrame.FindAnyWidget("LeftButton"));		
			m_UiRightButton		= ButtonWidget.Cast(m_RootFrame.FindAnyWidget("RightButton"));
			m_UiHeadlineLabel	= TextWidget.Cast(m_RootFrame.FindAnyWidget("HeadlineLabel"));	
			m_UiDescLabel		= RichTextWidget.Cast(m_RootFrame.FindAnyWidget("HintDescLabel"));
			m_UiHintImage		= ImageWidget.Cast(m_RootFrame.FindAnyWidget("HintImage"));
			m_UiPageingLabel	= TextWidget.Cast(m_RootFrame.FindAnyWidget("PageInfoLabel"));
            
		    m_BottomShader.SetColor(colorScheme.BottomShader());
            m_TopShader.SetColor(colorScheme.TopShader());
            m_Icon.SetColor(colorScheme.Icons());
            m_TipLineL.SetColor(colorScheme.TipLine());
            m_TipLineR.SetColor(colorScheme.TipLine());
            m_UiHeadlineLabel.SetColor(colorScheme.TipHeader());
            m_UiDescLabel.SetColor(colorScheme.TipText());
			
            m_RootFrame.SetHandler(this);

            if (NoHints)
            {
                CuiLogger.Log("UiHintPanelLoading.BuildLayout() - NoHints flag set, hiding spacer frame");
                m_SpacerFrame.Show(false);
            }

            
            CuiLogger.Log("UiHintPanelLoading.BuildLayout() - Layout successfully built");
		}
        else
        {
            CuiLogger.Log("ERROR: UiHintPanelLoading.BuildLayout() - Failed to create root frame");
        }
	}
}