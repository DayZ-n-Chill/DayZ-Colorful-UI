class colorfulExitDialog extends UIScriptedMenu
{
	protected Widget				m_Separator;
	protected Widget		 		m_bYes;
	protected Widget				m_bNo;
	protected Widget 				m_LastFocusedButton;
	protected Widget 				m_Text;
	protected Widget 				m_Caption;

	private Widget m_TopShader;
	private Widget m_BottomShader;
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/new_ui/dialogs/cui.Exit.dialog.layout" );
		
		m_Separator					= layoutRoot.FindAnyWidget( "SeparatorPanel" );
		m_bYes						= layoutRoot.FindAnyWidget( "bYes" );
		m_bNo						= layoutRoot.FindAnyWidget( "bNo" );
		m_Text						= layoutRoot.FindAnyWidget( "Text" );
		m_Caption					= layoutRoot.FindAnyWidget( "Caption" );

		m_TopShader 			    = layoutRoot.FindAnyWidget( "TopShader" );
		m_BottomShader 			    = layoutRoot.FindAnyWidget( "BottomShader" );
		
   		m_Separator.SetColor( colorScheme.Separator() );
		m_TopShader.SetColor(colorScheme.TopShader());
		m_BottomShader.SetColor(colorScheme.BottomShader());
		
		m_LastFocusedButton = m_bYes;
		
		return layoutRoot;
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_bYes )
			{
				m_LastFocusedButton = m_bYes;
				Exit();
				return true;
			}
			else if ( w == m_bNo )
			{
				m_LastFocusedButton = m_bNo;
				Cancel();
				return true;
			}
		}
		return false;
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{		
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}

	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorNormal( w );
			return true;
		}
		return false;
	}

	override bool OnFocus( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}

	override bool OnFocusLost( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorNormal( w );
			return true;
		}
		return false;
	}

	bool IsFocusable( Widget w )
	{
		if( w )
		{
			if( w == m_bYes || w == m_bNo )
			{
				return true;
			}
		}
		return false;
	}

	void Exit()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
	}

	void Cancel()
	{
		GetGame().GetUIManager().Back();
	}

	void ColorHighlight( Widget w )
	{
		if( !w )
			return;

		w.SetColor( colorScheme.ButtonHover() );
	}

	void ColorNormal( Widget w )
	{
		if( !w )
			return;

		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.White();

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}

	void ButtonSetColor( Widget w, int color )
	{
		if( !w )
			return;

		Widget panel = w.FindWidget( w.GetName() + "_panel" );

		if( panel )
		{
			panel.SetColor( color );
		}
	}

	void ButtonSetTextColor( Widget w, int color )
	{
		if( !w )
			return;

		TextWidget label	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		TextWidget text		= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );

		if( label )
		{
			label.SetColor( color );
		}

		if( text )
		{
			text.SetColor( color );
		}

		if( text2 )
		{
			text2.SetColor( color );
		}
	}
};
