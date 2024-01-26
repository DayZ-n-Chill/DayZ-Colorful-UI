modded class OptionsMenuGame extends ScriptedWidgetEventHandler
{
	override string GetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
		return "gui/layouts/new_ui/options/xbox/game_tab.layout";
		#else
		return "Colorful-UI/gui/layouts/new_ui/options/pc/game_tab.layout";
		#endif
	}
}
