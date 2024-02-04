modded class UiHintPanel extends ScriptedWidgetEventHandler
{	
	protected const string m_DataPath = "Colorful-UI/Scripts/data/hints.json";
	protected string m_RootPath       = "Colorful-UI/Gui/layouts/new_ui/hints/cui.in_game_hints.layout";	
}


modded class UiHintPanelLoading extends UiHintPanel
{
 	protected ImageWidget m_tipLineL;
	protected ImageWidget m_tipLineR;

	override void Init(DayZGame game)
    {
        m_RootPath = "Colorful-UI/gui/layouts/new_ui/hints/cui.in_game_hints_load.layout";
        
        if (!game)
            return;

        m_Game = game;
        LoadContentList();
        if (m_ContentList)    
        {
            BuildLayout(m_ParentWidget);
            RandomizePageIndex();
            PopulateLayout();
            StartSlideshow();            
        }
        else 
        {
            Print("ERROR: UiHintPanel - Could not create the hint panel. The data are missing!");
        }
    }

	override protected void BuildLayout(Widget parent_widget)
	{
        protected ImageWidget m_tShader;
	    protected ImageWidget m_bShader;
        protected ImageWidget m_tipIcon;

		m_RootFrame = m_Game.GetWorkspace().CreateWidgets( m_RootPath, parent_widget );
		
		if (m_RootFrame)
		{
		    m_tipLineL          = ImageWidget.Cast(m_RootFrame.FindAnyWidget("LinesImageLeft"));
            m_tipLineR          = ImageWidget.Cast(m_RootFrame.FindAnyWidget("LinesImageRight"));
            m_SpacerFrame		= m_RootFrame.FindAnyWidget("Hints");	
            m_tipIcon           = ImageWidget.Cast(m_RootFrame.FindAnyWidget("hintIcon"));	
            m_tShader           = ImageWidget.Cast(m_RootFrame.FindAnyWidget("TopShader"));
		    m_bShader           = ImageWidget.Cast(m_RootFrame.FindAnyWidget("BottomShader"));
			m_UiLeftButton		= ButtonWidget.Cast(m_RootFrame.FindAnyWidget("LeftButton"));		
			m_UiRightButton		= ButtonWidget.Cast(m_RootFrame.FindAnyWidget("RightButton"));
			m_UiHeadlineLabel	= TextWidget.Cast(m_RootFrame.FindAnyWidget("HeadlineLabel"));	
			m_UiDescLabel		= RichTextWidget.Cast(m_RootFrame.FindAnyWidget("HintDescLabel"));
			m_UiHintImage		= ImageWidget.Cast(m_RootFrame.FindAnyWidget("HintImage"));
			m_UiPageingLabel	= TextWidget.Cast(m_RootFrame.FindAnyWidget("PageInfoLabel"));
            
            m_tipIcon.SetColor(colorScheme.TipIcon());
            m_tipLineL.SetColor(colorScheme.TipLine());
            m_tipLineR.SetColor(colorScheme.TipLine());
            m_UiHeadlineLabel.SetColor(colorScheme.TipHeader());
            m_UiDescLabel.SetColor(colorScheme.TipText());
            m_tShader.SetColor(colorScheme.TopShader());
		    m_bShader.SetColor(colorScheme.BottomShader());
			
            m_RootFrame.SetHandler(this);
		}
	}
}
