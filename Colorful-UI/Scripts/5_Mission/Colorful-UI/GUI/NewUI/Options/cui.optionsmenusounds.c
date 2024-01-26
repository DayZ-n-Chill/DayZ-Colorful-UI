modded class OptionsMenuSounds extends ScriptedWidgetEventHandler
{
	override string GetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
		return "gui/layouts/new_ui/options/xbox/sound_tab.layout";
		#else
		#ifdef PLATFORM_WINDOWS
		return "Colorful-UI/gui/layouts/new_ui/options/pc/sound_tab.layout";
		#endif
		#endif
	}
}