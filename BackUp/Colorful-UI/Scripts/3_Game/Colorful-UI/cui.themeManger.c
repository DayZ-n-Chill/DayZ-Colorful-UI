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
	static int CUI2DarkBlue()         { return ARGB(155, 0, 0, 32); };
	static int CUI2SubtleRed()        { return ARGB(255, 100, 35, 35); };
	static int CUI2BrightRed()        { return ARGB(255, 152, 0, 0); };
}

// UI THEME ---------------------------------------------------------------
// Adjust these settings to align with your desired theme and aesthetics.
class colorScheme 
{
	// Brand Specific (Set your primary & secondary colors)
	static int BrandColor() 		  { return UIColor.Yellow(); };
	static int AccentColor()  		  { return UIColor.CUI2SubtleRed(); };
	static int TertiaryColor()  	  { return ARGB(255, 204, 255, 204); };

	// Base Typography 
	static int PrimaryText()          { return UIColor.White(); }; 	
	static int TextHover()            { return BrandColor(); }; 	
	static int SecondaryText()        { return UIColor.Grey(); }; 

	// Shader Colors 
	static int TopShader()       	  { return UIColor.CUI2Teal(); };
	static int BottomShader()    	  { return UIColor.CUI2Blue(); };

	// Global UI Elements 
	static int ButtonHover()     	  { return BrandColor(); };	
	static int LogOutTimer()     	  { return BrandColor(); };	
	static int Separator()       	  { return AccentColor(); };
	static int TabHover()        	  { return BrandColor(); };
	static int Loadingbar()      	  { return AccentColor(); };

	// Loading Screen
	static int TipIcon()         	  { return BrandColor(); };
	static int TipHeader()       	  { return BrandColor(); };
	static int TipLine()         	  { return BrandColor(); };
	static int TipText()       	 	  { return PrimaryText(); };
	static int LoadingMsg()       	  { return TertiaryColor(); };
	
	// Main Menu
	static int NavIcon()         	  { return BrandColor(); };
	static int SurvivorBox()       	  { return UIColor.CUI2DarkBlue(); };
	static int StatsBox()     	 	  { return UIColor.CUI2DarkBlue(); };
	
	// Options Page 
	static int OptionHeaders()		  { return TextHover(); };
	static int OptionInputColors()    { return TextHover(); };
	static int OptionSliderColors()   { return TextHover(); };
	static int OptionCaretColors()    { return TextHover(); };
	static int OptionBGHover()		  { return TextHover(); };
}
