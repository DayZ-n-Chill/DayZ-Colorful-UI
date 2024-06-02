void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();
	/*
	  [Takistan] Weather init
	   Warning: DO NOT ALTER following values as they are interconnected with Takistan weather system!
	   To ensure correct functionality, it is necessary to include weaher init AFTER the hive init.
	*/
	Weather weather = GetGame().GetWeather();
	weather.MissionWeather( true );
	weather.GetOvercast().SetLimits( 0.0, 0.30 );
	weather.GetRain().SetLimits( 0.0, 0.0 );
	weather.GetFog().SetLimits( 0.0, 0.0 );
	weather.GetOvercast().SetForecastChangeLimits( 0.1, 0.3 );
	weather.GetOvercast().SetForecastTimeLimits( 1600, 2100 );
	weather.GetOvercast().Set( 0.0, 0, 0 );
	weather.GetRain().Set( 0, 0, 0 );
	weather.GetFog().Set( 0, 0, 0 );
	weather.SetWindMaximumSpeed( 30 );
	weather.SetWindFunctionParams( 0.1, 1.0, 42 );
	weather.SetStorm( 1, 0.7, 30 );
	weather.SetRainThresholds( 0.0, 1.0, 0 );
	/*
	  [Takistan] Mission time init
	   after CE init to determine if storage mission type is outside of the required time-frame
	*/
	int year, month, day, hour, minute;
	GetGame().GetWorld().GetDate( year, month, day, hour, minute );
    if ( ( month > 9 ) || ( month <= 6 ) )
    {
    	year = 2011;
        month = 7;
        day = 1;
		
		GetGame().GetWorld().SetDate( year, month, day, hour, minute );
	}
}

class CustomMission: MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		if ( m_EventManager )
		{
			m_EventManager.Run( 1500, 2700, 1 );
			m_EventManager.RegisterEvent( Sandstorm, 1.0 );
		}
	}

	override void RegisterNoBuildZones(array<ref NoBuildZoneData> no_build_zones) 
	{
		super.RegisterNoBuildZones(no_build_zones);

		no_build_zones.Insert(new NoBuildZoneData("5751.000000 0.0 11491.000000", 1000.0, "You cannot build near Rasman Airbase!"));
		no_build_zones.Insert(new NoBuildZoneData("6042.000000 0.0 10443.000000", 500.0, "You cannot build near the Mahahwit Military Base!"));
		no_build_zones.Insert(new NoBuildZoneData("5655.000000 0.0 8893.000000", 1000.0, "You cannot build near the Safezone Extract!"));
		no_build_zones.Insert(new NoBuildZoneData("6577.000000 0.0 6967.000000", 550.0, "You cannot build near the Falar Outpost!"));
		no_build_zones.Insert(new NoBuildZoneData("4125.000000 0.0 6729.000000", 1000.0, "You cannot build near the FeeruzAbad RadioTower!"));
		no_build_zones.Insert(new NoBuildZoneData("5205.000000 0.0 5960.000000", 1000.0, "You cannot build near FeeruzAbad Military Bases!"));
		no_build_zones.Insert(new NoBuildZoneData("8055.000000 0.0 9497.000000", 900.0, "You cannot build near Garmsar Military Base!"));
		no_build_zones.Insert(new NoBuildZoneData("8229.000000 0.0 1960.000000", 1000.0, "You cannot build near LoyManara AirBase!"));
		no_build_zones.Insert(new NoBuildZoneData("7107.000000 0.0 1010.000000", 1000.0, "You cannot build near LoyManara Refinery!"));
		no_build_zones.Insert(new NoBuildZoneData("2627.000000 0.0 5098.000000", 750.0, "You cannot build near Rustaq Military base!"));
		no_build_zones.Insert(new NoBuildZoneData("1396.000000 0.0 3546.000000", 1000.0, "You cannot build near Bandit Camp!"));
		no_build_zones.Insert(new NoBuildZoneData("9415.000000 0.0 4662.000000", 1000.0, "You cannot build near Black Market!"));
		no_build_zones.Insert(new NoBuildZoneData("5279.000000 0.0 4701.000000", 1000.0, "You cannot build near the Safezone Extract!"));
		no_build_zones.Insert(new NoBuildZoneData("11232.000000 0.0 9107.000000", 750.0, "You cannot build near Laschkar Radarbase!"));
		no_build_zones.Insert(new NoBuildZoneData("8229.000000 0.0 1960.000000", 1000.0, "You cannot build near LoyManara AirBase!"));
		no_build_zones.Insert(new NoBuildZoneData("5644.000000 0.0 9893.000000", 50.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("5967.000000 0.0 7336.000000", 50.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("9159.000000 0.0 6810.000000", 50.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("8629.000000 0.0 3859.000000", 150.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("8897.000000 0.0 5292.000000", 50.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("10050.000000 0.0 2260.000000", 50.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("4692.000000 0.0 671.000000", 50.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("3072.000000 0.0 9837.000000", 120.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("1549.000000 0.0 5677.000000", 50.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("6786.000000 0.0 4826.000000", 50.0, "You cannot build near a keyroom!"));
		no_build_zones.Insert(new NoBuildZoneData("1841.000000 0.0 7567.000000", 50.0, "You cannot build near a keyroom!"));
		
			
	}


	override void RegisterStaticBoxPositions(array<ref StaticBoxPosition> static_box_positions) 
	{
		super.RegisterStaticBoxPositions(static_box_positions);

		//DO NOT ADJUST CONTAINERS INDIVIDUAL 
		//Adjust the entire military base by the same increments 
      	//Rustaq Military Base
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "2652.772705 196.882004 5132.997559", "151.746994 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "2657.530029 196.092133 5088.236328", "-27.999998 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "2613.709961 199.272003 5069.819824", "-24.500000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "2604.311279 197.749390 5145.635254", "-35.999989 3.266281 2.944387",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "2683.600098 196.894516 5146.240234", "139.500000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "2572.053223 197.672913 5104.892578", "80.999969 2.268933 -1.472219",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "2633.782471 196.669907 5116.579590", "-26.999985 -0.688747 1.071174",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "2647.239990 197.171646 5162.970215", "-80.838486 5.499689 1.500000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "2569.100098 197.931000 5115.830078", "-27.000000 0.000000 -0.500000",0.2,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "2650.979980 196.936996 5118.169922", "-103.351990 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "2609.820068 198.511993 5099.470215", "147.499985 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "2673.323242 196.925461 5142.188477", "44.999939 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "2676.766113 197.592224 5155.084961", "125.499992 0.999998 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "2634.443115 197.605392 5079.023926", "44.999981 -2.197218 -4.141425",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "2598.030029 198.794006 5144.740234", "-90.000000 0.000000 -2.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "2674.138916 197.448761 5158.482910", "-152.999908 1.169980 2.344476",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "2683.845947 199.674759 5146.074707", "-54.335667 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "2696.990479 195.970917 5166.143066", "-72.000015 -0.243846 2.232867",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "2632.899902 197.251007 5126.740234", "-98.999985 0.000000 2.000000",0.2,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "2608.260010 198.125656 5148.750000", "-161.999985 0.580193 -2.565619",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "2588.581787 199.125870 5098.498047", "-18.000000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "2662.745850 196.247971 5145.375000", "-144.000000 -2.137412 4.150340",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "2669.669189 196.950272 5127.979980", "152.999908 1.035200 1.426587",0.1,0));
      	//FeeruzAbad Radio Tower
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4283.689941 489.426000 6590.740234", "54.999992 0.420517 0.600632",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4275.330078 490.537079 6637.459961", "26.999992 -0.319440 -2.131470",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4248.209961 486.781250 6589.419922", "-5.500000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4231.890137 495.151672 6657.649902", "-67.500000 0.000000 0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4152.677734 495.636871 6631.736816", "35.999992 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4148.278809 505.051422 6706.987793", "-27.000000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4125.609375 505.257935 6754.728516", "41.500000 0.798616 1.057918",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4106.040039 505.479523 6732.465332", "-16.999998 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "4020.756348 536.141846 6929.208008", "170.999863 0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4031.007080 537.059998 6937.451660", "-170.999863 0.000000 -0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4024.209229 533.876282 6882.721680", "-34.795853 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4109.386719 505.079712 6748.621094", "80.146477 1.928926 1.325596",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4135.347168 505.571960 6743.726563", "179.999893 1.671647 -1.844413",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4124.336426 507.103577 6693.461914", "-64.530754 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4178.388184 502.844757 6676.054688", "-26.999990 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4236.398438 495.955078 6653.194336", "-62.999973 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4223.273926 486.859436 6594.041016", "179.999878 0.000000 0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4129.680664 508.066986 6647.084961", "-178.185562 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "4279.321289 489.751648 6600.829102", "107.999962 0.061203 0.405526",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "4301.272461 489.728271 6617.019043", "170.999863 0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "4257.680176 492.747375 6641.744629", "125.999924 0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "4207.123535 488.614777 6598.282715", "-123.719666 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "4137.473145 497.817566 6639.423828", "-127.470818 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "4149.981445 505.407928 6725.997070", "0.000000 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "4109.660156 505.246857 6753.009766", "161.999878 -0.883524 2.147458",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "3997.440156 535.415000 6896.950000", "-81.000078 0.686524 2.147458",0.05,0));
		//Garmsar Military Base
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10440.299805 260.087616 6459.799805", "-49.000000 -3.038138 -2.644429",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "10402.803711 257.824158 6389.041016", "40.017883 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "10465.632813 257.956970 6400.103516", "35.999966 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10367.877930 258.833832 6447.547852", "89.999954 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10379.868164 258.900940 6455.729004", "179.999878 0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10368.747070 258.008270 6437.414063", "-8.999986 0.000000 0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "10354.000000 257.528168 6430.100098", "-18.000004 -0.406810 -2.734410",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "10375.658203 258.138611 6456.506836", "-53.999985 0.000000 0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "10325.299805 255.216003 6442.040039", "-168.999985 -1.413549 3.921021",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "10406.096680 258.023010 6451.987793", "-170.500000 -2.470032 2.002072",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "10391.187500 256.675476 6400.575684", "-155.277969 0.081789 0.041658",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "10331.070313 255.928543 6409.725098", "9.000000 0.144096 -2.666826",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10333.000000 256.482788 6446.240234", "-45.000000 -2.245891 -3.189928",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "10292.484375 253.938202 6422.750000", "-156.957977 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10520.198242 262.533905 6451.534668", "-44.999992 0.388918 -1.814423",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "10533.400391 262.628815 6447.419922", "-36.499992 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "10487.099609 260.021881 6420.359863", "140.999985 0.000000 0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "10514.183594 264.315186 6476.361816", "-35.999992 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "10478.125000 261.897003 6458.933105", "53.999985 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "10453.900391 258.255005 6424.270020", "-43.499996 0.724183 -3.834780",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "10372.166992 256.630280 6398.652344", "-125.999893 0.242113 0.957192",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "10491.669922 262.504333 6472.728516", "-44.999981 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10432.946289 260.391754 6460.462891", "-168.829010 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10346.099609 257.775482 6434.279785", "0.624363 5.499057 1.999999",0.2,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10427.854492 262.145325 6363.809570", "-29.424242 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "10374.382813 256.619843 6400.979004", "-53.499996 -0.330229 -0.016053",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "10467.519531 258.249023 6403.026855", "143.999893 0.000000 -0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "10532.161133 263.515900 6455.794434", "-116.999916 0.000000 -0.000000",0.05,0));
		//FeeruzAbad Military Base
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5196.859863 145.409668 6103.685547", "-167.499969 0.248625 0.149110",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5200.579590 145.396896 6073.240723", "-42.000004 0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5205.779785 145.330750 6046.819824", "74.499992 0.269432 0.971642",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5166.319824 145.779190 6101.540039", "76.499977 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5178.631348 145.388641 6042.366699", "143.999893 -0.148248 0.107709",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5147.310059 145.441299 6032.419922", "90.999977 -0.541999 -0.467894",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5104.823242 145.657257 6030.549805", "-13.500000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5099.259766 145.950790 6079.279785", "-14.499994 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5142.093750 145.597214 6077.628418", "74.999985 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "5182.855469 146.182724 6043.229980", "-152.999908 -0.081636 -0.041596",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "5196.897461 145.514053 6078.612793", "170.999863 0.000000 -0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "5175.939941 145.781494 6110.830078", "-27.000000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "5157.665039 146.211548 6034.458496", "152.999893 0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "5111.740234 145.634811 6048.160156", "144.000000 -0.999991 3.499999",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "5136.640137 145.621445 6067.959961", "53.999996 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "5129.430176 146.417007 6095.323730", "3.499999 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "5207.473145 145.385880 6053.137695", "53.999969 -0.074124 0.053855",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "5169.514160 145.375198 6086.312988", "0.000039 0.366748 -0.458384",0.2,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "5141.967285 145.241837 6094.402832", "171.000107 -2.513152 -1.828177",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5125.119629 145.398941 6038.676758", "-107.999962 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5100.509766 146.413513 6075.569824", "-152.999924 -1.344650 -0.994168",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5121.376953 145.521378 6086.007324", "153.000061 -0.534872 -0.241921",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5149.518555 145.612503 6034.519043", "0.000000 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5190.205078 146.023392 6047.886230", "-98.999962 0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5216.429688 146.355759 6084.775391", "-35.999992 0.000000 0.000000",0.2,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5173.475098 145.395264 6105.844727", "-35.999969 0.000000 0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5191.671387 145.396072 6072.658203", "-80.999977 0.000000 0.000000",0.15,0));
		//FeeruzAbad Fob 
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5261.751465 244.354218 5828.362305", "-152.999908 6.323487 0.663139",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5214.045898 244.614716 5817.753418", "-89.999954 0.000000 0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5254.260742 245.736481 5790.662109", "-24.000000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5223.867188 246.153580 5783.948730", "134.999878 -0.000002 -1.166601",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "5291.209961 245.568939 5798.870117", "151.500000 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5275.366211 245.578781 5803.682617", "-44.999992 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5270.242188 245.915329 5791.983887", "-8.999853 -0.429732 -2.714334",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5269.339844 244.366806 5829.229980", "9.000000 -5.309067 3.836840",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5238.898926 245.154953 5822.107422", "-71.999977 0.000000 -0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5218.473145 246.013763 5801.688965", "-62.999973 -2.887515 3.254491",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5224.897461 246.940338 5796.272949", "9.000000 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "5222.427734 247.094849 5763.931641", "-98.999931 0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "5284.149902 246.501877 5790.278809", "143.999893 0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "5262.871094 246.126526 5795.566406", "-116.999962 0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "5238.099609 246.664001 5770.640137", "63.999996 0.000000 0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "5219.935059 245.314346 5809.200195", "161.999878 0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "5240.099609 245.149765 5821.382813", "-89.999954 0.000000 -0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticToolbox", "5228.209961 246.218048 5785.189941", "158.500000 1.730964 0.894294",0.2,0));
		//Falar Outpost
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6587.580078 294.636108 6976.319824", "9.499999 -1.000000 -2.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticFileCabinet_Grey", "6592.025391 298.350525 7030.518555", "-23.832121 -0.000000 -0.000000",0.5,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticFileCabinet_Grey", "6584.450195 298.354797 7027.350098", "64.922409 0.000000 0.000000",0.5,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "6595.296387 295.518005 7019.523438", "-75.479332 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "6600.758789 294.763794 7030.465332", "-139.155334 -0.000000 -0.000000",0.10,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "6589.834961 295.861115 7028.969727", "110.734200 -0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "6583.234375 295.226868 7026.634766", "56.163555 -0.000000 -0.000000",0.2,0)); //armory room
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6579.872559 295.279724 7027.692871", "63.090523 -0.000000 -0.000000",0.2,0)); //armory room
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Green", "6580.720215 296.128998 7023.149902", "-131.714981 0.000000 1.000000",0.2,0)); //armory room
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "6618.095703 295.257782 7013.064941", "74.393471 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "6605.874023 298.346191 7018.113770", "-133.483215 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "6578.564941 298.348816 7025.124512", "-99.947937 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "6592.978516 298.339111 7020.000488", "56.082767 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "6613.711426 294.614532 7045.777832", "0.000000 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "6580.768555 301.813385 7025.175293", "81.971397 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "6613.361328 301.837219 7024.326660", "-115.514542 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Red", "6564.254883 294.490234 6979.335449", "-89.999954 -4.206465 2.107631",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticDuffleBag_Blue", "6598.802246 294.716522 6998.142578", "162.000092 0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6594.466309 306.885040 6907.660645", "-153.000061 0.000000 -0.000000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6594.729980 306.473602 6886.229980", "-107.999992 3.499928 -2.500000",0.05,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6572.229004 293.602081 7009.782227", "-26.999987 -2.021830 -1.951864",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6587.140137 312.066345 6768.950195", "-174.999985 0.000000 0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6615.216309 294.420410 6994.774902", "-71.999947 0.000000 0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6601.736816 293.657745 7045.631348", "26.999987 -2.316116 -2.312392",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6577.546387 301.816498 7027.189453", "-51.451435 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6603.493652 298.341309 7016.187988", "-170.702789 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6591.540039 299.292999 7033.129883", "165.826981 0.000000 0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6607.917969 298.353760 7023.936523", "144.339996 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6580.390137 296.109009 7025.509766", "-14.040999 0.000000 -1.500000",0.2,0)); //armory room
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6582.189941 295.276398 7028.500000", "177.988266 -0.000000 -0.000000",0.2,0)); //armory room
		static_box_positions.Insert(new StaticBoxPosition("StaticMetalBoxStash", "6603.727051 295.729950 7018.338379", "-26.238827 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6606.970703 294.770691 7028.665527", "-67.342743 -0.000000 -0.000000",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6582.068848 301.817719 7031.879883", "66.691307 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6614.600098 301.843689 7007.571289", "-113.397995 0.000000 0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6591.283203 298.348053 7023.725098", "-68.560966 -0.000000 -0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6601.640137 293.908173 6991.640137", "0.000000 -1.873852 2.107629",0.15,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6603.700195 301.828003 7032.330078", "-68.765091 -0.499988 0.000000",0.1,0));
		static_box_positions.Insert(new StaticBoxPosition("StaticWoodCrate", "6579.549805 306.091827 6887.279785", "0.000000 -0.049803 0.874780",0.05,0));
	}

	override void RegisterSafeZoneLocations(array<ref SafeZoneLocation> safe_zones) 
	{
		super.RegisterSafeZoneLocations(safe_zones);

		safe_zones.Insert(new SafeZoneLocation("12616.584277 881.263210 266.863953", 100, 150));
	}

	override void RegisterPlayerTeleportLocations(array<ref PlayerTeleportLocationData> teleport_zones) 
	{
		super.RegisterPlayerTeleportLocations(teleport_zones);

		//SOUTH
		teleport_zones.Insert(new SafezoneTeleportLocationData(
		"5267.630117 245.684006 4679.889824", // source
		"12641.800957 901.825196 324.718906", // destination
		"4 8 4", // size
		{ 
			"5269.967773 306.757446 4319.241699",
			"5636.573242 310.550568 4544.794922",
			"5385.632813 395.764771 4019.251221",
			"5184.550293 217.628113 5146.398926",
			"6048.724609 335.796204 4777.431641",
			"5373.861328 265.459503 4498.460449",
			"5093.929199 283.009460 4443.362793",
			"4930.556152 265.372162 4521.492676",
			"5010.091309 244.336838 4718.900879",
			"5161.037109 244.296570 4594.853516",
			"5168.474121 239.602661 4775.065918",
			"5258.086914 228.480927 4918.823242",
			"5419.848633 224.986771 4850.873047",
			"5526.210938 259.244659 4674.863281",
			"5595.080078 246.510483 4773.956543",
			"5432.536133 247.390732 4710.446777",
			"4589.724121 284.428661 4454.865918"
		}));
		
		//NORTH
		teleport_zones.Insert(new SafezoneTeleportLocationData(
		"5656.260058 82.656363 8894.070469", // source
		"12641.800957 901.825196 324.718906", // destination
		"4 8 4", // size
		{
			"5572.544922 84.201401 8852.309570",
			"5563.680176 82.418633 8960.466797",
			"5695.697266 78.966789 9018.805664",
			"5747.847656 89.494850 8812.134766",
			"5858.333984 101.486275 8962.507813",
			"6055.659668 102.306076 8910.400391",
			"5620.189941 91.890236 8775.787109",
			"5736.293945 99.003326 8660.396484",
			"5714.682129 97.362541 8537.783203",
			"5774.821777 98.921227 8462.286133",
			"5876.108398 115.310844 8515.708008",
			"6003.734375 110.773483 9029.541992",
			"6257.770508 105.809204 9001.104492",
			"6349.371094 113.543068 8841.466797",
			"5554.669434 78.637459 9079.358398",
			"5678.490234 78.791885 9148.112305",
			"5551.144043 78.601830 9188.440430",
			"5621.666016 78.655334 9270.858398"
		}));
	}

	override void RegisterSafeZoneExits(array<vector> safe_zone_exits) 
	{
		super.RegisterSafeZoneExits(safe_zone_exits);

		safe_zone_exits.Insert("12603.400000 881.153 260.129000");
		safe_zone_exits.Insert("5588.81 347.032 3713.09");

	}

	override void RegisterGunRanges(array<ref GunRangeLocation> gun_ranges) 
	{
		super.RegisterGunRanges(gun_ranges);
		
		gun_ranges.Insert(new GunRangeLocation("12621.60 882.264 282.78", 0.75, "-1 0 0"));
        gun_ranges.Insert(new GunRangeLocation("12621.60 882.264 284.38", 0.75, "-1 0 0"));
        gun_ranges.Insert(new GunRangeLocation("12621.60 882.264 286.08", 0.75, "-1 0 0"));
        gun_ranges.Insert(new GunRangeLocation("12621.60 882.264 287.68", 0.75, "-1 0 0"));
        gun_ranges.Insert(new GunRangeLocation("12621.60 882.264 289.38", 0.75, "-1 0 0"));
        gun_ranges.Insert(new GunRangeLocation("12621.60 882.264 291.08", 0.75, "-1 0 0"));
        gun_ranges.Insert(new GunRangeLocation("12621.60 882.264 292.68", 0.75, "-1 0 0"));
        gun_ranges.Insert(new GunRangeLocation("12621.60 882.264 294.38", 0.75, "-1 0 0"));
	}
}