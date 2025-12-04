// UI THEME ---------------------------------------------------------------
// Adjust these settings to align with your desired theme and aesthetics.
class colorScheme 
{
	// Brand Specific 
	static int BrandColor()          { return ARGB(255, 255, 204, 102); }   
	static int AccentColor()         { return ARGB(255, 100, 35, 35); }  
	static int TertiaryColor()       { return ARGB(255, 204, 255, 204); }

	// Base Typography 
	static int PrimaryText()         { return UIColor.White(); }            // Primary text color
	static int SecondaryText()       { return UIColor.Grey(); }         	// Color for secondary text, e.g., subtitles or info
	static int TextHover()           { return BrandColor(); }           	// Text color for hover effects
	static int DisabledText()        { return ARGB(180, 130, 130, 130); };  // Color for secondary text, e.g., subtitles or info

	// Global UI Elements 
	static int ButtonHover()         { return BrandColor(); }           	// Button color on hover
	static int Icons()         		 { return BrandColor(); }           	// Primary Color for all icons
	static int LogOutTimer()         { return BrandColor(); }           	// Timer color for logout on logout Screen
	static int Separator()           { return BrandColor(); }           	// Divider color to segment UI sections
	static int Loadingbar()          { return BrandColor(); }           	// Loading bar color
	
	// Buttons
	static int BtnText()          { return PrimaryText(); }
	static int BtnHoverText()     { return TextHover(); }
	static int BtnSolidBG()       { return BrandColor(); }
	static int BtnSolidHoverBG()  { return AccentColor(); }
	static int BtnIcon()          { return Icons(); }

	// Tabs
	static int TabIdle()           { return PrimaryText(); }
	static int TabHoverColor()     { return BrandColor(); }
	static int TabSelectedColor()  { return BrandColor(); }
	static int TabBackground()     { return UIColor.Black(); }

	// Shader Colors 
	static int TopShader()           {return UIColor.Black();}  			// Top shader on layouts
	static int BottomShader()        {return UIColor.Black();}  			// Bottom shader on layouts

	// Loading Screen
	static int TipText()             { return PrimaryText(); }          	// Main text color for tips
	static int LoadingMsg()          { return TertiaryColor(); }        	// Color for loading messages
	static int TipHeader()           { return BrandColor(); }           	// Header color for tips
	static int TipLine()             { return BrandColor(); }           	// Divider line color in tips

	// Main Menu
	static int NavIcon()             { return BrandColor(); }           	// Navigation icon color
	static int SurvivorBox()         { return UIColor.cuiDarkBlue(); }		// Background color for "Survivor" box
	static int StatsBox()            { return UIColor.cuiDarkBlue(); }  	// Background color for "Stats" box

	// Options Page 
	static int OptionHeaders()       { return BrandColor(); }           	// Header color in options
	static int OptionLine()          { return AccentColor(); }          	// Header color in options
	static int OptionInputColors()   { return BrandColor(); }           	// Input fields color
	static int OptionSliderColors()  { return BrandColor(); }           	// Slider color in options
	static int OptionCaretColors()   { return BrandColor(); }           	// Caret color for dropdowns
	static int OptionBGHover()       { return UIColor.cuiDarkBlue(); }  	// Background color for hovered options



}
