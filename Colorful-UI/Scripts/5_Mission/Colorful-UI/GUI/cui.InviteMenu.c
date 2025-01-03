modded class InviteMenu extends UIScriptedMenu
{	
	private TextWidget		m_LogoutTimetext;
	private TextWidget		m_Info;
	private int m_iTime;
    private Widget m_Separator1
	private	Widget m_shader

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("colorful-ui/gui/layouts/cui.day_z_invite_dialog.layout");
		
		m_LogoutTimetext = TextWidget.Cast( layoutRoot.FindAnyWidget("logoutTimeText") );
		m_Info = TextWidget.Cast( layoutRoot.FindAnyWidget("txtInfo") );
		m_LogoutTimetext.SetText(m_iTime.ToString());
		
		layoutRoot.FindAnyWidget("toolbar_bg").Show(true);
		RichTextWidget toolbar_b = RichTextWidget.Cast(layoutRoot.FindAnyWidget("BackIcon"));
		toolbar_b.SetText(InputUtils.GetRichtextButtonIconFromInputAction("UAUIBack", "", EUAINPUT_DEVICE_CONTROLLER, InputUtils.ICON_SCALE_TOOLBAR));
		
		// player should sit down if possible
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player && player.GetEmoteManager() && !player.IsRestrained() && !player.IsUnconscious()) 
		{
			player.GetEmoteManager().CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_SITA);
			player.GetEmoteManager().GetEmoteLauncher().SetForced(EmoteLauncher.FORCE_DIFFERENT);
		}
		
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( UpdateTime, 1000, true ); 
		return layoutRoot;
	}
}