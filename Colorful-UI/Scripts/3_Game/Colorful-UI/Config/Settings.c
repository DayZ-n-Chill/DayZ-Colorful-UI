// Constants.c v3.0.0
static bool StartMainMenu      = true; // If set to true, the main menu will be forced to show on startup.
static bool NoHints			   = false; // If set to true, the hints will not be shown during load screens.
static bool LoadVideo          = true;  // If set to true, a video will be shown during load screens along with tips.
static bool ShowDeadScreen     = false; // If set to true, a custom game over screen will be shown when the player dies. if false, the default game over screen will be shown.
static bool CuiDebug           = true;  // Turn on Colorful UI Debugging. This will show debug information in the console and log file.

// The below two settings are not yet implemented.
static bool EnableMenuVideo    = true;  // If set to true, a video will be shown during Main Menu Screens along with tips.
static bool EnableOptionsVideo = true;  // If set to true, a video will be shown during Main Menu Screens along with tips.
static bool VideoDeathScreens  = false; // If set to true, a random game over screen will be shown when the player dies.
static bool RandomDeathScreens = false; // If set to true, a random game over video that will be shown when the player dies.

// Server Information 
// THESE SETTINGS ARE NOT YET IMPLEMENTED but will be available in future updates.
static const string SERVER_IP = "127.0.0.1";
static const int SERVER_PORT = 2302;

// Video Settings (Change them up)
static const string m_LoadingVideo     = "CUI_Video.mov";  // Video file name for loading screen video. 
static const string m_MainMenuVideo    = "CUI_Video.mov";  // Video file name for Main Menu screen video. 
static const string m_OptionsMenuVideo = "CUI_Video.mov";  // Video file name for Options screen video. 

// Loading Screens
ref TStringArray loadscreens = {
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG1.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG2.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG3.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG4.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG5.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG6.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG7.edds"
};

// Gameover Screens (Array Not yet implemented)
ref TStringArray GameOverScreens = {
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG1.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG2.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG3.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG4.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG5.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG6.edds",
    "Colorful-UI/GUI/textures/LoadScreens/Cui3-BG7.edds"
};

// Set Single Game Over Screen ( Death Screen )
class GameOverScreen
{
    static string GameOverScreenImage() { return "Colorful-UI/GUI/textures/DeathScreens/DeathScreen.edds"; };
};

// Set Your Servers Logo
// NOTE:  Width and High Settings are not yet implemented here.
//        Recommended size is 512x512 But you can set the size manually in the layout file for the moment.
class Branding
{
    static string Logo() { return "Colorful-UI/GUI/textures/Shared/CuiPro_Logo.edds"; }; 
    static void ApplyLogo(ImageWidget widget)
    {
        if (!widget) return;
        widget.LoadImageFile(0, Logo());
        widget.SetFlags(WidgetFlags.STRETCH);
    }
};

// Link URLs (Add your own links here)
// NOTE:  If you do not want to use a button, set the URL to "#" or "".
//        If you do not set them they will not show up in the layout when compiled.
//        This way it shows only the buttons you want to use.

class CustomURL {
	static string Website    = "http://www.example.com"; 
	static string PriorityQ  = "http://www.example.com";
	static string Custom     = "http://www.example.com";
}

class SocialURL {
	static string Discord    = "http://www.example.com";
	static string Facebook   = "http://www.example.com";
	static string Twitter    = "http://www.example.com";
	static string Reddit     = "http://www.example.com";
	static string Youtube    = "http://www.example.com";
}

// Menu IDs
const int COLORFUL_EXIT		    = 666;
const int COLORFUL_CONFIGURE    = 667;
const int COLORFUL_DEFAULTS     = 668;
