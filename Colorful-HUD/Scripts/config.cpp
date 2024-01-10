
class CfgPatches
{
	class ColorfulHUD_Scripts
	{
        requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Scripts"};
	};
};

class CfgMods 
{
	class ColorfulHUD
	{
		name = "DayZ-Mod-Template";
		dir = "Colorful-HUD";
		creditsJson = "Colorful-HUD/Scripts/Credits.json";
		inputs = "Colorful-HUD/Scripts/Inputs.xml";
		type = "mod";

		dependencies[] =
		{
			"Game", "World", "Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]= {};
			};
			class engineScriptModule
			{
				files[] =
				{
					"Colorful-HUD/scripts/1_core"
				};
			};

			class gameScriptModule
			{
				files[] = 
				{
					"Colorful-HUD/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				files[] = 
				{
					"Colorful-HUD/scripts/4_World"
				};
			};

			class missionScriptModule 
			{
				files[] = 
				{
					"Colorful-HUD/scripts/5_Mission"
				};
			};
		};
	};
};
