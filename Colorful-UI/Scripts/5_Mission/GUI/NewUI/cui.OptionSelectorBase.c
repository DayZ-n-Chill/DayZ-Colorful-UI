modded class OptionSelectorBase extends ScriptedWidgetEventHandler
{	
	
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
				
		ButtonSetColor(w, colorScheme.ButtonHover());
	}
	
	override void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = colorScheme.PrimaryText();
		int color_lbl = colorScheme.PrimaryText();
		
		ButtonSetColor(w, color_pnl);
		
		Widget title_label = w.FindAnyWidget( w.GetName() + "_label" );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if ( title_label )
		{
			title_label.SetColor( color_lbl );
		}
		
		if ( option_label )
		{
			option_label.SetColor( color_lbl );
		}
	}
	
	override void ColorDisabled( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = colorScheme.PrimaryText();
		
		ButtonSetColor(w, color_pnl);
		
		Widget title_label = w.FindAnyWidget( w.GetName() + "_label" );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if ( title_label )
		{
			title_label.SetColor( color_lbl );
		}
		
		if ( option_label )
		{
			option_label.SetColor( color_lbl );
		}		
	}
	
	override void ButtonSetColor( Widget w, int color )
	{
		Widget option = w.FindAnyWidget( w.GetName() + "_image" );
		
		if ( option )
		{
			option.SetColor( color );
		}
	}
	
	override void ColorHighlightConsole( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = colorScheme.ButtonHover();
		int color_lbl = colorScheme.PrimaryText();
		
		ButtonSetColorConsole(w, color_pnl);
		ButtonSetAlphaAnimConsole( null );
		ButtonSetTextColorConsole(w, color_lbl);
	}
	
	override void ColorNormalConsole( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = colorScheme.PrimaryText();
		
		ButtonSetColorConsole(w, color_pnl);
		ButtonSetAlphaAnimConsole( null );
		ButtonSetTextColorConsole(w, color_lbl);
	}
	
	override void ColorDisabledConsole( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.SemiTransparentWhite();
		
		ButtonSetColorConsole(w, color_pnl);
		ButtonSetAlphaAnimConsole( null );
		ButtonSetTextColorConsole(w, color_lbl);
	}
}