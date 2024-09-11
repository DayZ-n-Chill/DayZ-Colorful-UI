// Constants.c v2.5.0

// RANDO IMAGES ----------------------------------------------------------------
// If you dont want to use the UiHintPanel you can use these instead.
string GetRandomBackground()
{
	const string images[] = {
		"Colorful-UI/gui/textures/loading_screens/CUI2-BG1.edds", 
		"Colorful-UI/gui/textures/loading_screens/CUI2-BG2.edds",
		"Colorful-UI/gui/textures/loading_screens/CUI2-BG3.edds"
	};
	// If you add more images be sure to change the image count. 
	const int IMAGES_COUNT = 3;
	int bgIndex = Math.RandomInt(0, IMAGES_COUNT - 1);
	return images[bgIndex];
}

static bool ShowDeadScreen = false;

string GetRandomGameOverScreen()
{
	const string images[] = {
		"Colorful-UI/gui/textures/globals/DeathScreen-BG1.edds", 
		"Colorful-UI/gui/textures/globals/DeathScreen-BG2.edds",
		"Colorful-UI/gui/textures/globals/DeathScreen-BG3.edds"
	};
	// If you add more images be sure to change the image count. 
	const int IMAGES_COUNT = 3;
	int bgIndex = Math.RandomInt(0, IMAGES_COUNT - 1);
	return images[bgIndex];
}

class GameOverScreen
{
    static string GameOverScreenImage() { return "Colorful-UI/gui/textures/globals/DeathScreen.edds"; };
};

// SOCIALS & LINKS ---------------------------------------------------------------
// Set your links Here
class MenuURLS {
	static string urlDiscord   = "discord.gg/7QMVZUR6yx";
	static string urlFacebook  = "#";
	static string urlTwitter   = "#";
	static string urlReddit    = "#";
	static string urlYoutube   = "https://www.youtube.com/@ByXaRiKUA";
	static string urlWebsite   = "#"; 
	static string urlPriorityQ = "#";
	static string urlCustom    = "#";
}

// DIALOGS ------------------------------------------------------------------------
// There is No Need to mess with anything below this line. 
const int COLORFUL_EXIT				= 666;
const int COLORFUL_CONFIGURE 		= 667;
const int COLORFUL_DEFAULTS 		= 668;
