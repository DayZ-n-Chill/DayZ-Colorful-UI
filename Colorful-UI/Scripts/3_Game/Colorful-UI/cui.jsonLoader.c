class ColorfulConfig
{
	static const string CONFIG_VERSION = "1";
	private const static string ProfileFolder = "$profile:\\CUI\\";
	private const static string fileName = "CUIconfig.json";
	
	string ConfigVersion = "";
	
	void Load()
	{
		if (FileExist(ProfileFolder + fileName))
		{	
			JsonFileLoader<ColorfulConfig>.JsonLoadFile(ProfileFolder + fileName, this);
			if (ConfigVersion != CONFIG_VERSION)
			{
				JsonFileLoader<ColorfulConfig>.JsonSaveFile(ProfileFolder + fileName + "_old", this);
			}
			else
			{
				return;
			}
		}

		ConfigVersion = CONFIG_VERSION;
		Save();
	};

	void Save()
	{
		if (!FileExist(ProfileFolder))
		{	
			MakeDirectory(ProfileFolder);
		}

		JsonFileLoader<ColorfulConfig>.JsonSaveFile(ProfileFolder + fileName, this);
	}
}

ref ColorfulConfig m_ColorfulConfig;

static ColorfulConfig GetColorfulConfig()
{
	if (!m_ColorfulConfig)
	{
		Print("[ColorfulConfig] Init");
		m_ColorfulConfig = new ColorfulConfig;

		if (GetGame().IsDedicatedServer())
		{
			m_ColorfulConfig.Load();
		}
	}

	return m_ColorfulConfig;
};