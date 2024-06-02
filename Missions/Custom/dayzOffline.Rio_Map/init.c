//Spawn helper function
void SpawnObject( string type, vector position, vector orientation )
{
    auto obj = GetGame().CreateObject( type, position );
    obj.SetPosition( position );
    obj.SetOrientation( orientation ); //Collision fix
}
void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
    GetGame().GetWorld().SetDate(2017, 6, 17, 9, 45);
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	// economy init
	CreateHive();
	GetHive().InitOffline();

//GetCEApi().ExportProxyData( "7500 0 7500", 18000 );  

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if ((month == reset_month) && (day < reset_day))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
    else
    {
        if ((month == reset_month + 1) && (day > reset_day))
        {
            GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
        }
        else
        {
            if ((month < reset_month) || (month > reset_month + 1))
            {
                GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
            }
        }
    }
//EditorLoaderModule.ExportLootData = true;
}

class CustomMission : MissionServer
{
    private const static string m_SpawnLoadoutDirectory = "$profile:SpawnLoadout/"; // root directory for SpawnLoadout
    private const static string m_DonatorDirectory = m_SpawnLoadoutDirectory + "Donators/"; // directory for donator loadout text files

    private const static string m_RegularLoadout = m_SpawnLoadoutDirectory + "Regular.txt"; // file for regular loadout
    private const static string m_CommonItems = m_SpawnLoadoutDirectory + "CommonItems.txt"; // file for in common items for both regular and donator

    void CustomMission()
    {
        FileHandle templateFile;

        if (!FileExist(m_SpawnLoadoutDirectory))
        {
            MakeDirectory(m_SpawnLoadoutDirectory)

            // create default CommonItems.txt
            templateFile = OpenFile(m_CommonItems, FileMode.WRITE);
            FPrintln(templateFile, "Rag 4\nHuntingKnife\nMatchbox\nHatchet\nFlashlight\nBattery9V\nSodaCan_Cola\nBakedBeansCan");
            CloseFile(templateFile);

            // create default Regular.txt
            templateFile = OpenFile(m_RegularLoadout, FileMode.WRITE);
            FPrintln(templateFile, "TShirt_Brazil\nJeans_Black\nTaloonBag_Blue\nAthleticShoes_Grey");
            CloseFile(templateFile);
        }

        if (!FileExist(m_DonatorDirectory))
        {
            string template = GetDonatorFile("76561198135264603");

            MakeDirectory(m_DonatorDirectory);

            // create template donator file
            templateFile = OpenFile(template, FileMode.WRITE);
            FPrintln(templateFile, "BomberJacket_Blue\nJeans_Grey\nTaloonBag_Orange\nAthleticShoes_Brown");
            CloseFile(templateFile);
        }
    }

    //!!! REPLACES EXISTING METHOD
    override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
    {
        player.RemoveAllItems(); // clear all default spawning items

        FileHandle donatorFile;
        string line;

        TStringArray contents = new TStringArray();
        string file = GetDonatorFile(player.GetIdentity().GetPlainId());

        if (FileExist(file))
        {
            SpawnLoadout(player, ReadFileLines(file)); // spawn donator loadout
            //player.SetPosition("4658.65 0 10317.65");
            return;
        }

        SpawnLoadout(player, ReadFileLines(m_RegularLoadout)); // spawn regular player loadout
    }

    private void SpawnLoadout(PlayerBase player, ref TStringArray loadout)
    {
        FileHandle loadoutFile;
        string line;

        // creates clothes loadout
        foreach (string clothes : loadout)
            player.GetInventory().CreateInInventory(clothes);


        // creates common items
        TStringArray items = ReadFileLines(m_CommonItems);
        foreach (string item : items)
        {
            if (item.Contains(" ")) // check for space, which signifies a quantity item
            {
                CreateQuantityItem(player, item);
                continue;
            }

            player.GetInventory().CreateInInventory(item);
        }
    }

    private void CreateQuantityItem(PlayerBase player, string item)
    {
        TStringArray quantity = new TStringArray();
        item.Split(" ", quantity);

        ItemBase quantityItem = player.GetInventory().CreateInInventory(quantity[0]);
        quantityItem.SetQuantity(quantity[1].ToFloat());
    }

    private string GetDonatorFile(string id)
    {
        return string.Format("%1%2.txt", m_DonatorDirectory, id);
    }

    private TStringArray ReadFileLines(string path)
    {
        FileHandle file;
        string line;

        TStringArray contents = new TStringArray();

        file = OpenFile(path, FileMode.READ);
        while (FGets(file, line) > 0)
        {
            line.Trim();
            if (line != string.Empty)
            {
                contents.Insert(line);
                line = string.Empty;
            }
        }

        CloseFile(file);
        return contents;
    }
}

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
//MissionServer.ExportLootData = true;
