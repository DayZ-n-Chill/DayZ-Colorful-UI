
class CfgPatches
{
	class Mod-Name_Scripts
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
	class Mod-Name
	{
		name = "Project-Mod-Name";
		dir = "Mod-Name";
		creditsJson = "Mod-Name/Scripts/Credits.json";
		inputs = "Mod-Name/Scripts/Inputs.xml";
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
					"Mod-Name/scripts/1_core"
				};
			};

			class gameScriptModule
			{
				files[] = 
				{
					"Mod-Name/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				files[] = 
				{
					"Mod-Name/scripts/4_World"
				};
			};

			class missionScriptModule 
			{
				files[] = 
				{
					"Mod-Name/scripts/5_Mission"
				};
			};
		};
	};	
};
