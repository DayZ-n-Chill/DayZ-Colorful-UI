
class CfgPatches
{
	class ColorfulUI_Scripts
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
			list[] = {"DZ_Data","DZ_Scripts","DZ_UI","DZ_UIFonts","DZ_Sounds_Effects","COLORFUL_HUD"};
		};
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
				files[]= {"Colorful-UI/GUI/imagesets/CUI.imageset"};
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

class CfgSoundSets
{
	class Music_Menu_SoundSet
	{
		soundShaders[]=
		{
			"DZNC_Music_Menu_SoundShader"
		};
		volumeFactor=1;
		frequencyFactor=1;
		spatial=0;
	};
};	

class CfgSoundShaders
{
	class DZNC_Music_Menu_SoundShader
	{
		samples[] = {{"\Colorful-UI\GUI\sounds\MainMenu.ogg", 1}};
		volume = 0.5;
	};
};
