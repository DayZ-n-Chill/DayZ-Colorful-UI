
class CfgPatches
{
	class Colorful_UI_Scripts
	{
        requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Sounds_Effects"};
	};
};

class CfgAddons
{
	class PreloadBanks{};
	class PreloadAddons
	{
		class DayZ
		{
			list[] = {"DZ_Data","DZ_Scripts"};
		};
	};
};

class CfgMods 
{
	class Colorful_UI
	{
		name = "Project-Colorful-UI";
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

