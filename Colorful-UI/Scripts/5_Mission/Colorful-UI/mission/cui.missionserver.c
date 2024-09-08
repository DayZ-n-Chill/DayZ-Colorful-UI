modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		Print("[Colorful UI] OnInit");
    
    	GetColorfulConfig();
        Print("[Colorful UI] Loading config");
	}
}
