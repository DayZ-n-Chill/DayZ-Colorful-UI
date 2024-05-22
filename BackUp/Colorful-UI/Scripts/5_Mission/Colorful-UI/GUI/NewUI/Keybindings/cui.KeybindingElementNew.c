modded class KeybindingElementNew extends ScriptedWidgetEventHandler
{
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		if( w == m_PrimaryClear )
		{
			m_IsEdited				= true;
			m_CustomBind			= new array<int>;
			m_PrimaryBindButton.SetText( "" );
			m_Container.ClearKeybind( m_ElementIndex );
		}
		if( w == m_AlternativeClear )
		{
			m_IsAlternateEdited		= true;
			m_CustomAlternateBind	= new array<int>;
			m_AlternativeBindButton.SetText( "" );
			m_Container.ClearAlternativeKeybind( m_ElementIndex );
		}
		return false;
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( w == m_PrimaryBindButton || w == m_PrimaryClear )
		{
			m_PrimaryBindButton.SetColor( colorScheme.ButtonHover() );
			m_PrimaryClear.Show( true );
			m_PrimaryClear.Update();
			m_AlternativeClear.Show( false );
			return true;
		}
		else if( w == m_AlternativeBindButton || w == m_AlternativeClear )
		{
			m_AlternativeBindButton.SetColor( colorScheme.ButtonHover() );
			m_PrimaryClear.Show( false );
			m_AlternativeClear.Show( true );
			m_AlternativeClear.Update();
			return true;
		}
		else
		{
			m_PrimaryBindButton.SetColor( ARGBF( 0, 0, 0, 0 ) );
			m_AlternativeBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
			m_PrimaryClear.Show( false );
			m_AlternativeClear.Show( false );
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( w == m_PrimaryClear || w == m_PrimaryBindButton )
		{
			if( enterW != m_PrimaryClear && enterW != m_PrimaryBindButton )
			{
				m_PrimaryClear.Show( false );
				m_PrimaryBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
			}
		}
		if( w == m_AlternativeClear || w == m_AlternativeBindButton )
		{
			if( enterW != m_AlternativeClear && enterW != m_AlternativeBindButton )
			{
				m_AlternativeClear.Show( false );
				m_AlternativeBindButton.SetColor( ARGBF( 1, 0, 0, 0 ) );
			}
		}
		return false;
	}
}