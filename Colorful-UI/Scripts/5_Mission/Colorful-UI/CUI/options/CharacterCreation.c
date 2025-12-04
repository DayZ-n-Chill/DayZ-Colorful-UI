
// modded class CharacterCreationMenu extends UIScriptedMenu
// {
// 	protected Widget m_Apply, m_Save, m_RandomizeCharacter, m_BackButton;
// 	protected ImageWidget m_MenuDivider, m_TopShader, m_BottomShader;
// 	protected ProgressBarWidget m_LoadingBar;

// 	override Widget Init()
// 	{
// 		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/options/cui.characters.layout" );
		
// 		m_CharacterRotationFrame	= layoutRoot.FindAnyWidget("character_rotation_frame");
// 		m_Apply						= layoutRoot.FindAnyWidget("ApplyBtn");
// 		m_Save 						= layoutRoot.FindAnyWidget("SaveBtn");
// 		m_RandomizeCharacter		= layoutRoot.FindAnyWidget("RandoBtn");
// 		m_BackButton				= layoutRoot.FindAnyWidget("BackBtn");
//         m_MenuDivider               = ImageWidget.Cast(layoutRoot.FindAnyWidget("MenuDivider"));
// 		m_TopShader                 = ImageWidget.Cast(layoutRoot.FindAnyWidget("TopShader"));
// 		m_BottomShader              = ImageWidget.Cast(layoutRoot.FindAnyWidget("BottomShader"));
		
// 		m_TopShader.SetColor(colorScheme.TopShader());
// 		m_BottomShader.SetColor(colorScheme.BottomShader());

// 		// Note that this is just used as a visual trim, not a real loading bar.
// 		m_LoadingBar        = ProgressBarWidget.Cast(layoutRoot.FindAnyWidget("LoadingBar"));
// 		if (m_LoadingBar) m_LoadingBar.SetColor(colorScheme.Loadingbar());

//         cuiElmnt.proBtnCB(ButtonWidget.Cast(m_Apply), "Apply", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "Apply");
//         cuiElmnt.proBtnCB(m_Save, "Save", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "Saveback");
//         cuiElmnt.proBtnCB(ButtonWidget.Cast(m_RandomizeCharacter), "",     colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "RandomizeCharacter");
//         cuiElmnt.proBtnCB(ButtonWidget.Cast(m_BackButton), "Back", colorScheme.PrimaryText(), colorScheme.ButtonHover(), this, "Back");
//         if (m_MenuDivider) m_MenuDivider.SetColor(colorScheme.Separator());
	
// 		if (m_Scene && m_Scene.GetIntroCharacter())
// 		{
// 			m_OriginalCharacterID = m_Scene.GetIntroCharacter().GetCharacterID();
// 		}
		
// 		m_NameSelector		= new OptionSelectorEditbox(layoutRoot.FindAnyWidget("character_name_setting_option"), m_Scene.GetIntroCharacter().GetCharacterName(), null, false);
// 		m_GenderSelector	= new OptionSelectorMultistateCharacterMenu(layoutRoot.FindAnyWidget("character_gender_setting_option"), 0, null, false, m_Scene.GetIntroCharacter().GetCharGenderList());
// 		if (m_Scene.GetIntroCharacter().IsCharacterFemale())
// 		{
// 			m_GenderSelector.SetValue("Female");
// 			m_SkinSelector	= new OptionSelectorMultistateCharacterMenu(layoutRoot.FindAnyWidget("character_head_setting_option"), 0, null, false, m_Scene.GetIntroCharacter().GetCharList(ECharGender.Female));
// 		}
// 		else
// 		{
// 			m_GenderSelector.SetValue("Male");
// 			m_SkinSelector	= new OptionSelectorMultistateCharacterMenu(layoutRoot.FindAnyWidget("character_head_setting_option"), 0, null, false, m_Scene.GetIntroCharacter().GetCharList(ECharGender.Male));
// 		}
		
// 		m_TopSelector		= new OptionSelectorMultistateCharacterMenu(layoutRoot.FindAnyWidget("character_top_setting_option"), 0, null, false, DefaultCharacterCreationMethods.GetConfigAttachmentTypes(InventorySlots.BODY));
// 		m_BottomSelector	= new OptionSelectorMultistateCharacterMenu(layoutRoot.FindAnyWidget("character_bottom_setting_option"), 0, null, false, DefaultCharacterCreationMethods.GetConfigAttachmentTypes(InventorySlots.LEGS));
// 		m_ShoesSelector		= new OptionSelectorMultistateCharacterMenu(layoutRoot.FindAnyWidget("character_shoes_setting_option"), 0, null, false, DefaultCharacterCreationMethods.GetConfigAttachmentTypes(InventorySlots.FEET));
		
// 		m_GenderSelector.ShowNavigationButtons(true);
// 		m_SkinSelector.ShowNavigationButtons(true);
// 		m_TopSelector.ShowNavigationButtons(true);
// 		m_BottomSelector.ShowNavigationButtons(true);
// 		m_ShoesSelector.ShowNavigationButtons(true);
		
// 		if (!m_MultiOptionSelectors)
// 		{
// 			m_MultiOptionSelectors = new map<Widget, OptionSelectorMultistateCharacterMenu>;
// 			m_MultiOptionSelectors.Insert(layoutRoot.FindAnyWidget("character_gender_button"), m_GenderSelector);
// 			m_MultiOptionSelectors.Insert(layoutRoot.FindAnyWidget("character_head_button"), m_SkinSelector);
// 			m_MultiOptionSelectors.Insert(layoutRoot.FindAnyWidget("character_top_button"), m_TopSelector);
// 			m_MultiOptionSelectors.Insert(layoutRoot.FindAnyWidget("character_bottom_button"), m_BottomSelector);
// 			m_MultiOptionSelectors.Insert(layoutRoot.FindAnyWidget("character_shoes_button"), m_ShoesSelector);
// 		}
		
// 		PlayerBase scene_char = GetPlayerObj();
// 		if (scene_char)
// 		{
// 			Object obj = scene_char.GetInventory().FindAttachment(InventorySlots.BODY);
// 			if (obj)
// 				m_TopSelector.SetValue(obj.GetType(), false);
			
// 			obj = scene_char.GetInventory().FindAttachment(InventorySlots.LEGS);
// 			if (obj)
// 				m_BottomSelector.SetValue(obj.GetType(), false);
			
// 			obj = scene_char.GetInventory().FindAttachment(InventorySlots.FEET);
// 			if (obj)
// 				m_ShoesSelector.SetValue(obj.GetType(), false);
			
// 			m_SkinSelector.SetValue(scene_char.GetType());
// 		}
		
// 		m_GenderSelector.m_OptionChanged.Insert(GenderChanged);
// 		m_SkinSelector.m_OptionChanged.Insert(SkinChanged);
// 		m_TopSelector.m_OptionChanged.Insert(TopChanged);
// 		m_BottomSelector.m_OptionChanged.Insert(BottomChanged);
// 		m_ShoesSelector.m_OptionChanged.Insert(ShoesChanged);
		
// 		Refresh();
// 		SetCharacter();
// 		CheckNewOptions();
		
// 		GetGame().GetMission().GetOnInputDeviceChanged().Insert(OnInputDeviceChanged);

// 		return layoutRoot;
// 	}

//     void Saveback()
//     {
//         Save();
//         GetGame().GetUIManager().Back();
//     }
// }
