modded class OptionsMenuVideo extends ScriptedWidgetEventHandler
{
	override string GetLayoutName()
	{
		#ifdef PLATFORM_PS4
		return "gui/layouts/new_ui/options/ps/video_tab.layout";
		#else
		#ifdef PLATFORM_WINDOWS
		return "Colorful-UI/gui/layouts/new_ui/options/pc/video_tab.layout";
		#endif
		#endif		
	}
}
