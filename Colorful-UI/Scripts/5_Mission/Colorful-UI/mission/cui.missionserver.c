modded class MissionServer
{
	// Called when server initializes
	override void OnInit()
	{
		super.OnInit();
		Print("[Colorful UI] OnInit");

		// Load config
		GetColorfulConfig();
        Print("[Colorful UI] Loading config");
	}

}

