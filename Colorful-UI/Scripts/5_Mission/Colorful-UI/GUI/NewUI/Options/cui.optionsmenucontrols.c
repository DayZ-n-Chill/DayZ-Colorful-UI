modded class OptionsMenuControls extends ScriptedWidgetEventHandler
{
	override string GetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
		return "gui/layouts/new_ui/options/xbox/controls_tab.layout";
		#else
		return "Colorful-UI/gui/layouts/new_ui/options/pc/controls_tab.layout";
		#endif
	}
}