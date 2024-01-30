modded class OptionSelectorSliderSetup extends OptionSelectorBase
{
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		if ( m_Slider )
		{
			SetFocus( m_Slider );
			m_Slider.SetColor( colorScheme.PrimaryText() );
		}
		
		super.ColorHighlight( w );
	}
	
	override void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		if ( m_Slider )
		{
			m_Slider.SetColor( colorScheme.OptionSliderColors()  );
		}
		super.ColorNormal( w );
	}

	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( m_ParentClass )
		{
			OnFocus( w, x, y );
			m_ParentClass.OnFocus( m_Root.GetParent(), -1, m_SelectorType );
			#ifdef PLATFORM_WINDOWS
			m_ParentClass.OnMouseEnter( m_Root.GetParent().GetParent(), x, y );
			m_Slider.SetColor(colorScheme.OptionSliderColors());
			#endif
		}
		
		return true;
	}

	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( m_ParentClass )
		{
			#ifdef PLATFORM_WINDOWS
			m_ParentClass.OnMouseLeave( m_Root.GetParent().GetParent(), enterW, x, y );
			m_Slider.SetColor(colorScheme.PrimaryText());
			#endif
			OnFocusLost( w, x, y );
			SetFocus( null );
		}
			
		return true;
	}
}		