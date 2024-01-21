// Constants.c 
// Ver 2.0

string GetRandomBackground()
{
	const string images[] = {
		"Colorful-UI/gui/textures/loading_screens/CUI2-BG1.edds", 
		"Colorful-UI/gui/textures/loading_screens/CUI2-BG2.edds",
		"Colorful-UI/gui/textures/loading_screens/CUI2-BG3.edds"
	};
	// If you add more images be sure to change the image count
	const int IMAGES_COUNT = 3;
	int bgIndex = Math.RandomInt(0, IMAGES_COUNT - 1);
	return images[bgIndex];
}

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

// COLOR PALETTES ---------------------------------------------------------
// Use these coloring functions to mix and match the theme of your choice.
class UIColor
{
	// Note: ------------------------------------------------------------------
	// Many of these colors are included for convenience and may not be necessary 
	// for your current use. Please feel free to omit any that you don't need.
	
	// GreyScale
	static int White()                { return ARGB(255, 255, 255, 255); };
	static int Grey()                 { return ARGB(255, 130, 130, 130); };
	static int Black()                { return ARGB(255, 0, 0, 0); };
	static int Transparent()          { return ARGB(1, 0, 0, 0); };
	static int SemiTransparentWhite() { return ARGB(120, 255, 255, 255); };
	
	// R.O.Y.G.B.I.V
	static int Red()    			  { return ARGB(255, 173, 35, 35); };
	static int Orange() 			  { return ARGB(255, 215, 153, 19); };
	static int Yellow() 			  { return ARGB(255, 255, 204, 102); };
	static int Green()  			  { return ARGB(255, 51, 204, 51); };
	static int Blue()   			  { return ARGB(255, 51, 102, 102); };
	static int Indigo() 			  { return ARGB(255, 102, 51, 204); };
	static int Violet() 			  { return ARGB(255, 204, 51, 204); };
	
	// Social Network Colors 
	static int discord() 			  { return ARGB(255, 88, 101, 242); };
	static int twitter() 			  { return ARGB(255, 29, 161, 242); };
	static int youtube() 			  { return ARGB(255, 255, 0, 0); };
	static int reddit()               { return ARGB(255, 255, 69, 0); };
	static int meta()                 { return ARGB(255, 24, 119, 242); };
	
	// Custom Colors (Use to add your own branding colors)
	static int CUI2Teal()             { return ARGB(255, 102, 153, 153); };
	static int CUI2Blue()             { return ARGB(255, 1, 5, 74); };
	static int CUI2Red()              { return ARGB(255, 100, 35, 35); };
}

// UI THEME ---------------------------------------------------------------
// Adjust these settings to align with your desired theme and aesthetics.
class colorScheme 
{
	// Brand Specific (Set your primary & secondary colors)
	static int BrandColor() 		  { return UIColor.CUI2Red(); };
	static int AccentColor()  		  { return UIColor.CUI2Teal(); };

	// Base Typography 
	static int PrimaryText()          { return UIColor.White(); }; 	
	static int TextHover()            { return UIColor.Yellow(); }; 	
	static int SecondaryText()        { return UIColor.Grey(); }; 

	// Shader Colors 
	static int TopShader()       	  { return AccentColor(); };
	static int BottomShader()    	  { return UIColor.CUI2Blue(); };

	// Global UI Elements 
	static int ButtonHover()     	  { return UIColor.Yellow(); };	
	static int Separator()       	  { return BrandColor(); };
	static int TabHover()        	  { return BrandColor(); };
	static int Loadingbar()      	  { return BrandColor(); };
	

	// Loading Screen
	static int TipIcon()         	  { return UIColor.Yellow(); };
	static int TipHeader()       	  { return UIColor.Yellow(); };
	static int TipLine()         	  { return UIColor.Yellow(); };
	static int TipText()       	 	  { return PrimaryText(); };
	static int LoadingMsg()       	  { return ARGB(255, 204, 255, 204);};
	
 	// Priority Queue Screen
		
	// Main Menu
	
	// Options Page 
	static int OptionInputColors()    { return BrandColor(); };
	static int OptionSliderColors()   { return BrandColor(); };
	static int OptionCaretColors()    { return BrandColor(); };
}

// DIALOGS ---------------------------------------------------------------
// There is No Need to mess with anything below this line. 
const int COLORFUL_EXIT				= 666;
const int COLORFUL_CONFIGURE 		= 667;
const int COLORFUL_DEFAULTS 		= 668;
