modded class MissionBase
{	
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = super.CreateScriptedMenu(id);

		switch (id)
		{
			case COLORFUL_EXIT:
				menu = new colorfulExitDialog;
				break;

			case COLORFUL_CONFIGURE:
				menu = new colorfulConfigureDialog;
				break;

			#ifdef CodeLock
				case CLMENU.SET_CODE_MENU:
					menu = new SetCodeMenu();
					break;
				case CLMENU.GUEST_CODE_MENU:
					menu = new GuestCodeMenu();
					break;
				case CLMENU.ENTER_CODE_MENU:
					menu = new EnterCodeMenu();
					break;
				case CLMENU.ADMIN_CODE_MENU:
					menu = new AdminCodeMenu();
					break;
				case CLMENU.CLAIM_CODE_MENU:
					menu = new ClaimCodeMenu();
					break;
			#endif

			#ifdef VPPADMINTOOLS
				case VPP_ADMIN_HUD:
					menu = new VPPAdminHud;
					break;
			#endif
		
			#ifdef VanillaPPMap
				case VPP_MENU_MAP:
					menu = new VPPMapMenu;
					break;
			#endif

			case MENU_GESTURES:
				menu = new GesturesMenu;
				break;

			case MENU_LOGOUT:
				menu = new LogoutMenu;
				break;

			#ifdef SERVERPANEL
				case SERVER_PANEL:
					menu = GetServerPanelMenu();
					break;
			#endif
		
			#ifdef DayZInformationPanel
				case DIP_PANEL:
					menu = new DayZInformationPanelUI;
					break;
			#endif
			
			#ifdef SchanaModParty
				case SCHANA_PARTY_MENU:
					menu = new SchanaPartyMenu;
					break;
			#endif	
	
			#ifdef Trader
				case TRADERMENU_UI:
					menu = new TraderMenu;
					break;
			#endif
			
			#ifdef BasicSpawnSelect		
				case BASIC_SPAWNSELECTMENU:
					menu = new BasicSpawnSelectMenu;
					break;
			#endif

			#ifdef KTQuestClient		
				case KTQuestMenuHandler.MENU_QUEST:
					menu = new KTQuestMenu();
					break;
				case KTQuestAdditionalInfoMenuHandler.MENU_QUEST_ADDITIONAL_INFO_TARGET:
					menu = new KTQuestAdditionalInfoMenuTarget();
					break;
				case KTQuestAdditionalInfoMenuHandler.MENU_QUEST_ADDITIONAL_INFO_REWARD:
					menu = new KTQuestAdditionalInfoMenuReward();
					break;
			#endif
		}

		if (!menu)
		{
			menu = super.CreateScriptedMenu(id);
		}

		if (menu)
		{
			menu.SetID(id);
		}

		return menu;
	}
};
