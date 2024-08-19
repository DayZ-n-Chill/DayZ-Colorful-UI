modded class MissionBase
{	
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = super.CreateScriptedMenu(id);

		switch (id)
		{
		case MENU_MAIN:
		#ifdef PLATFORM_CONSOLE			
					menu = new MainMenuConsole;
		#else
					menu = new MainMenu;
		#endif
					break;
				case MENU_INGAME:
		#ifdef PLATFORM_CONSOLE
					menu = new InGameMenuXbox;
		#else
					menu = new InGameMenu;
		#endif
		break;

		case MENU_CHARACTER:
			menu = new CharacterCreationMenu;
			break;
		case MENU_OPTIONS:
			menu = new OptionsMenu;
			break;

		case COLORFUL_EXIT:
			menu = new colorfulExitDialog;
			break;

		case COLORFUL_CONFIGURE:
			menu = new colorfulConfigureDialog;
			break;

		#ifdef CodeLock
        case CLMENU.SET_CODE_MENU:
        	{
        	    menu = new SetCodeMenu();
        	    break;
        	}
        case CLMENU.GUEST_CODE_MENU:
        	{
        	    menu = new GuestCodeMenu();
        	    break;
        	}
        case CLMENU.ENTER_CODE_MENU:
        	{
        	    menu = new EnterCodeMenu();
        	    break;
        	}
        case CLMENU.ADMIN_CODE_MENU:
        	{
        	    menu = new AdminCodeMenu();
        	    break;
        	}
        case CLMENU.CLAIM_CODE_MENU:
        	{
        	    menu = new ClaimCodeMenu();
        	    break;
        	}
		#endif

		#ifdef VPPADMINTOOLS
			case VPP_ADMIN_HUD:
			menu = new VPPAdminHud;
			break;
		#endif
		
		// #ifdef VanillaPPMap
		// case VPP_MENU_MAP:
		// 	menu = new VPPMapMenu;
		// 	break;
		// #endif
			
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
			
		#ifdef 	BasicSpawnSelect		
			case BASIC_SPAWNSELECTMENU:
            menu = new BasicSpawnSelectMenu;
            break;
		#endif

		#ifdef 	KTQuestClient		
			case KTQuestMenuHandler.MENU_QUEST:
				menu = new KTQuestMenu;
			break;
			case KTQuestAdditionalInfoMenuHandler.MENU_QUEST_ADDITIONAL_INFO_TARGET:
				menu = new KTQuestAdditionalInfoMenuTarget;
			break;
			case KTQuestAdditionalInfoMenuHandler.MENU_QUEST_ADDITIONAL_INFO_REWARD:
				menu = new KTQuestAdditionalInfoMenuReward;
			break;
			default:
				menu = super.CreateScriptedMenu(id);
		#endif

		case MENU_STARTUP:
			menu = new StartupMenu;
			break;
		case MENU_LOADING:
			menu = new LoadingMenu;
			break;
		case MENU_INVENTORY:
			menu = new InventoryMenu;
			break;
		case MENU_INSPECT:
			menu = new InspectMenuNew;
			break;
		case MENU_EARLYACCESS:
			menu = new EarlyAccessMenu;
			break;
		case MENU_SCRIPTCONSOLE:
			menu = new ScriptConsole;
			break;
		case MENU_SCRIPTCONSOLE_DIALOG_PRESET_NAME:
			menu = new ScriptConsoleNewPresetDialog;
			break;
		case MENU_SCRIPTCONSOLE_DIALOG_PRESET_RENAME:
			menu = new ScriptConsoleRenamePresetDialog;
			break;
		case MENU_CHAT_INPUT:
			menu = new ChatInputMenu;
			break;
		case MENU_CONTROLS_PRESET:
			menu = new PresetsMenu;
			break;
		case MENU_NOTE:
			menu = new NoteMenu;
			break;
		case MENU_MAP:
			menu = new MapMenu;
			break;
		case MENU_BOOK:
			menu = new BookMenu;
			break;
		case MENU_SCENE_EDITOR:
			menu = new SceneEditorMenu;
			break;
		case MENU_HELP_SCREEN:
			menu = new HelpScreen;
			break;
		// case MENU_GESTURES:
		// 	menu = new GesturesMenu;
		// 	break;
		// case MENU_LOGOUT:
		//	menu = new LogoutMenu;
		//	break;
		case MENU_TITLE_SCREEN:
			menu = new TitleScreenMenu;
			break;
		case MENU_XBOX_CONTROLS:
			menu = new ControlsXboxNew;
			break;
		case MENU_RADIAL_QUICKBAR:
			menu = new RadialQuickbarMenu;
			break;
		case MENU_SERVER_BROWSER:
			menu = new ServerBrowserMenuNew;
			break;
		case MENU_LOGIN_QUEUE:
			menu = new LoginQueueBase;
			break;
		case MENU_LOGIN_TIME:
			menu = new LoginTimeBase;
			break;
		case MENU_CAMERA_TOOLS:
			menu = new CameraToolsMenu;
			break;
		case MENU_VIDEO:
			menu = new MainMenuVideo;
			break;
		case MENU_KEYBINDINGS:
			menu = new KeybindingsMenu;
			break;
		case MENU_TUTORIAL:
			menu = new TutorialsMenu;
			break;
		case MENU_CREDITS:
			menu = new CreditsMenu;
			break;
		case MENU_INVITE_TIMER:
			menu = new InviteMenu;
			break;
		case MENU_WARNING_ITEMDROP:
			menu = new ItemDropWarningMenu;
			break;
		case MENU_WARNING_TELEPORT:
			menu = new PlayerRepositionWarningMenu;
			break;
		case MENU_RESPAWN_DIALOGUE:
			menu = new RespawnDialogue;
			break;
		case MENU_CONNECT_ERROR:
			menu = new ConnectErrorScriptModuleUI;
			break;

		}

		if (menu)
		{
			menu.SetID(id);
		}

		return menu;
	}
};