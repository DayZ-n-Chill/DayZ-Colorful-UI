// Constants.c v2.0

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

// SOCIALS & LINKS ---------------------------------------------------------------
// Set your links Here
class MenuURLS {
	static string urlDiscord   = "https://discord.gg/dayznchill";
	static string urlFacebook  = "https://www.facebook.com/DayZnChill/";
	static string urlTwitter   = "https://twitter.com/dayznchill";
	static string urlReddit    = "https://www.reddit.com/r/DayZnChill/";
	static string urlYoutube   = "https://youtube.com/@dayznchill";
	static string urlWebsite   = "http://dayznchill.com"; 
	static string urlPriorityQ = "http://dayznchill.com/prioQ";
	static string urlCustom    = "http://dayznchill.com/promo";
}


// DIALOGS ------------------------------------------------------------------------
// There is No Need to mess with anything below this line. 
const int COLORFUL_EXIT				= 666;
const int COLORFUL_CONFIGURE 		= 667;
const int COLORFUL_DEFAULTS 		= 668;
