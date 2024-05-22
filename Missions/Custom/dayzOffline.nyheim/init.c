void main()
{
	Weather weather = g_Game.GetWeather();
	weather.MissionWeather(false);
	weather.GetOvercast().Set( 0, 0, 0);
	weather.GetRain().Set( 0, 0, 0);
	weather.GetFog().Set( 0, 0, 0);

	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;

		itemClothing = player.FindAttachmentBySlotName( "Body" );
		if ( itemClothing )
		{
			SetRandomHealth( itemClothing );
			
			itemEnt = itemClothing.GetInventory().CreateInInventory( "Rag" );
			if ( Class.CastTo( itemBs, itemEnt ) )
				itemBs.SetQuantity( 4 );

			SetRandomHealth( itemEnt );
			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
			int rndIndex = Math.RandomInt( 0, 4 );
			itemEnt = itemClothing.GetInventory().CreateInInventory( chemlightArray[rndIndex] );
			SetRandomHealth( itemEnt );
			rand = Math.RandomFloatInclusive( 0.0, 1.0 );
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory( "Apple" );
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory( "Pear" );
			else
				itemEnt = player.GetInventory().CreateInInventory( "Plum" );

			SetRandomHealth( itemEnt );
			itemEnt = player.GetInventory().CreateInInventory("PersonalRadio");
			itemEnt.GetInventory().CreateAttachment("Battery9V");
			SetRandomHealth(itemEnt);
			rand = Math.RandomFloatInclusive(0.0, 1.0);
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory("Apple");
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory("Pear");
			else
				itemEnt = player.GetInventory().CreateInInventory("Plum");
			SetRandomHealth(itemEnt);
			rand = Math.RandomFloatInclusive(0.0, 1.0);
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory("SodaCan_Cola");
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory("SodaCan_Spite");
			else
				itemEnt = player.GetInventory().CreateInInventory("SodaCan_Pipsi");
			SetRandomHealth(itemEnt);
			player.GetInventory().CreateInInventory("StoneKnife");
            itemEnt = player.GetInventory().CreateInInventory("Matchbox");
            rndIndex = Math.RandomInt( 1, 4 );
            ItemBase base;
            if(Class.CastTo(base, itemEnt))
                base.SetQuantity(rndIndex);
		}
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		if ( itemClothing )
			SetRandomHealth( itemClothing );
		itemClothing = player.FindAttachmentBySlotName( "Feet" );
		player.GetStatEnergy().Set(900);
		player.GetStatWater().Set(900);
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
