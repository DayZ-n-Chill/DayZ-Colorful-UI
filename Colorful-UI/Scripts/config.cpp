
class CfgPatches
{
	class ColorfulUI_Scripts
	{
        requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Scripts"};
	};
};

class CfgMods 
{
	class ColorfulUI
	{
		name = "DayZ-Mod-Template";
		dir = "Colorful-UI";
		creditsJson = "Colorful-UI/Scripts/Credits.json";
		inputs = "Colorful-UI/Scripts/Inputs.xml";
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
					"Colorful-UI/scripts/1_core"
				};
			};

			class gameScriptModule
			{
				files[] = 
				{
					"Colorful-UI/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				files[] = 
				{
					"Colorful-UI/scripts/4_World"
				};
			};

			class missionScriptModule 
			{
				files[] = 
				{
					"Colorful-UI/scripts/5_Mission"
				};
			};
		};
	};
};
