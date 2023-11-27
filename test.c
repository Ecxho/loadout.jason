void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

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
}

class CustomMission: MissionServer

{
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);
		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}

		player.SetQuickBarEntityShortcut(mag, 1, true);
	}

	EntityAI srsClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_SRSA2");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_SRSA2_10Rnd");
		addMags(player, "Rev_Mag_SRSA2_10Rnd", 4);

		return gun;
	}

	EntityAI m2010Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_M2010_Blue");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_M2010_10Rnd");
		addMags(player, "Rev_Mag_M2010_10Rnd", 4);

		return gun;
	}

	EntityAI sakoClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("PITSTOP_M10_Tan");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("PITSTOP_M10_Magazine");
		addMags(player, "PITSTOP_M10_Magazine", 4);

		return gun;
	}

	EntityAI m200Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_M200");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_M200_Suppressor");
		gun.GetInventory().CreateAttachment("Rev_Mag_M200_7Rnd");
		addMags(player, "Rev_Mag_M200_7Rnd", 4);

		return gun;
	}

	EntityAI m300Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_M300");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("BO_Mag_M300_7rnd");
		addMags(player, "BO_Mag_M300_7rnd", 4);

		return gun;
	}

	EntityAI msrClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("PITSTOP_MSR");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("PITSTOP_MSR_Magazine");
		addMags(player, "PITSTOP_MSR_Magazine", 4);

		return gun;
	}

	EntityAI m96Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_M96");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_M96_5rnd");
		addMags(player, "Rev_Mag_M96_5rnd", 4);

		return gun;
	}

	EntityAI cdxClass(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("Rev_CDX50");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_CDX50_5Rnd");
		addMags(player, "Rev_Mag_CDX50_5Rnd", 4);

		return gun;
	}

	EntityAI ax50Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("SNAFUAX50_GUN");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("SNAFUAX50_Mag");
		gun.GetInventory().CreateAttachment("SNAFU_50bmg_Suppressor_BK");
		addMags(player, "SNAFUAX50_Mag", 4);

		return gun;
	}

	EntityAI m82a1Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("BO_M82A1");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("BO_Mag_M82A1_10rnd");
		addMags(player, "BO_Mag_M82A1_10rnd", 4);

		return gun;
	}

	EntityAI m107Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("A2M107");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("A2M107_Magazine");
		addMags(player, "A2M107_Magazine", 4);

		return gun;
	}

	EntityAI as50Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("A2AS50");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("Rev_Mag_SRSA2_10Rnd");
		addMags(player, "A2AS50_Magazine", 4);

		return gun;
	}

	EntityAI asr12Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("LF_ASR12_White");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		gun.GetInventory().CreateAttachment("LF_ASR12_Mag");
		addMags(player, "LF_ASR12_Mag", 4);

		return gun;
	}

	EntityAI a2m200Class(PlayerBase player)
	{
		EntityAI gun = player.GetHumanInventory().CreateInHands("ussr_m200");
		gun.GetInventory().CreateAttachment("HuntingOptic");
        gun.GetInventory().CreateAttachment("M200Suppressor");
		gun.GetInventory().CreateAttachment("Mag_ussrm200_7Rnd");
		addMags(player, "Mag_ussrm200_7Rnd", 4);

		return gun;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		
		player.GetInventory().CreateInInventory("Echo_6B43_Black");
		player.GetInventory().CreateInInventory("MVS_Assault_Pack_Black");
		player.GetInventory().CreateInInventory("MVS_CombatPants_Black");
		player.GetInventory().CreateInInventory("MVS_CombatShirt_Black");
		player.GetInventory().CreateInInventory("MilitaryBoots_Black");
		player.GetInventory().CreateInInventory("MVS_Balaclava_Wraith");
		player.GetInventory().CreateInInventory("TacticalGloves_Black");
		player.GetInventory().CreateInInventory("BandageDressing");
        
        EntityAI helmet = player.GetInventory().CreateInInventory("MVS_Altyn_Black");
        helmet.GetInventory().CreateAttachment("MVS_Altyn_Visor_Black");

		EntityAI primary;

		switch (Math.RandomInt(0, 13)) {
			case 0: primary = srsClass(player); break;
			case 1: primary = m2010Class(player); break;
			case 2: primary = sakoClass(player); break;
			case 3: primary = m200Class(player); break;
			case 4: primary = m300Class(player); break;
			case 5: primary = msrClass(player); break;
			case 6: primary = m96Class(player); break;
			case 7: primary = cdxClass(player); break;
			case 8: primary = ax50Class(player); break;
			case 9: primary = m82a1Class(player); break;
			case 10: primary = m107Class(player); break;
			case 11: primary = as50Class(player); break;
			case 12: primary = asr12Class(player); break;
			case 13: primary = a2m200Class(player); break;
            
		}
        
        player.LocalTakeEntityToHands(primary);
		player.SetQuickBarEntityShortcut(primary, 0, true);
        
		player.GetStatWater().Add(4400);
        player.GetStatEnergy().Add(19400);
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
