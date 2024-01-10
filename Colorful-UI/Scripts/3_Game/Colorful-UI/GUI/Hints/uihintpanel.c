modded class UiHintPanel extends ScriptedWidgetEventHandler
{	
	protected const string m_DataPath = "Colorful-UX/Scripts/data/hints.json";
}


modded class UiHintPanelLoading extends UiHintPanel
{
	// override void Init(DayZGame game)
	// {
	// 	m_RootPath = "Colorful-UX/gui/layouts/new_ui/hints/cui.in_game_hints_load.layout";
	// 	super.Init(game);
	// }

    override void Init(DayZGame game)
    {
        m_RootPath = "Colorful-UX/gui/layouts/new_ui/hints/cui.in_game_hints_load.layout";

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
	override protected void PopulateLayout()
    {
        if (m_RootFrame)
        {
            SetHintHeadline();
            SetHintDescription();
            SetHintPaging();
        }
    }
}
