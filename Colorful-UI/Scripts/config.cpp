
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
		dir = "Colorful-UI";
		name = "DayZ n' Chill's: Colorful-UI";
		version = "3.0";
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
				files[] = {	"Colorful-UI/scripts/3_Game" };
			};
			class worldScriptModule
			{
				files[] = {	"Colorful-UI/scripts/4_World" };
			};
			class missionScriptModule 
			{
				files[] = {	"Colorful-UI/scripts/5_Mission"	};
			};
		};
	};	
};

class CfgSoundSets
{
	class Music_Menu_SoundSet
	{
		soundShaders[]= { "DZNC_Music_Menu_SoundShader" };
		volumeFactor=1;
		frequencyFactor=1;
		spatial=0;
	};
};	

class CfgSoundShaders
{
	class DZNC_Music_Menu_SoundShader
	{
		samples[] = 
		{
			{"\Colorful-UI\GUI\sounds\MainMenu.ogg", 1}
			// If you want to use more than one song to override the new vanilla main menu music that is based on time of day, 
			// you can add more lines like the one above. But using just one song will override all of them
			// {"\Colorful-UI\GUI\sounds\MainMenu_1.ogg", 1},
			// {"\Colorful-UI\GUI\sounds\MainMenu_2.ogg", 1},
			// {"\Colorful-UI\GUI\sounds\MainMenu_3.ogg", 1},
			// {"\Colorful-UI\GUI\sounds\MainMenu_4.ogg", 1},
			// {"\Colorful-UI\GUI\sounds\MainMenu_5.ogg", 1},
			// {"\Colorful-UI\GUI\sounds\MainMenu_6.ogg", 1}
		};
		volume = 0.5;
	};
};
