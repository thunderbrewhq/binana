-- #include "cgunit.lua"

local QuestLog = Struct("QuestLog")
    :int32("QuestId")
    :int32("ObjectiveDone")
    :int32("ObjectiveCounterFlag")
    :int32("UnkField4")
    :int32("UnkField5")

local PlayerSkill = Struct("PlayerSkill")
    :uint16("ID")
    :uint16("Unk")
    :uint16("Skill")
    :uint16("SkillMax")
    :int32("UnkPad")

local ExploredZones = Struct("ExploredZonesBitflied")
    :flag64("flag")

local ArenaTeam = Struct("ArenaTeam")
    :int32("ID")
    :int32("TypeID")
    :int32("MemberID")
    :int32("GamesWeekID")
    :int32("GamesSeasonID")
    :int32("WinsSeasonID")
    :int32("PersonalRateID")

local PlayerFields = Struct("PlayerFields")
    :int32("DuelArbiter") -- 0x1BB0
    :int32("GuildID") -- 0x1BB4
    :int32("GuildRank") -- 0x1BB8
    :flag32("bytes1") -- 0x1BBC
    :flag32("bytes2") -- 0x1BC0
    :flag32("bytes3") -- 0x1BC4
    :int32("DueldTeam") -- 0x1BC8
    :int32("GuildTimestamp") -- 0x1BCC

    :QuestLog_array("m_questLog", 25)

    :int32("HeadItemId") -- 0x1DC4
    :int32("HeadEnchantment") -- 0x1DC8
    :int32("NeckItemId") -- 0x1DCC
    :int32("NeckEnchantment") -- 0x1DD0
    :int32("ShoulderItemId") -- 0x1DD4
    :int32("ShoulderEnchantment") -- 0x1DD8
    :int32("ShirtItemId") -- 0x1DDC
    :int32("ShirtEnchantment") -- 0x1DE0
    :int32("ChestItemId") -- 0x1DE4
    :int32("ChestEnchantment") -- 0x1DE8
    :int32("BeltItemId") -- 0x1DEC
    :int32("BeltEnchantment") -- 0x1DF0
    :int32("LegsItemId") -- 0x1DF4
    :int32("LegsEnchantment") -- 0x1DF8
    :int32("FootItemId") -- 0x1DFC
    :int32("FootEnchantment") -- 0x1E00
    :int32("WristItemId") -- 0x1E04
    :int32("WristEnchantment") -- 0x1E08
    :int32("HandsItemId") -- 0x1E0C
    :int32("HandsEnchantment") -- 0x1E10
    :int32("Finger1ItemId") -- 0x1E14
    :int32("Finger1Enchantment") -- 0x1E18
    :int32("Finger2ItemId") -- 0x1E1C
    :int32("Finger2Enchantment") -- 0x1E20
    :int32("Trinket1ItemId") -- 0x1E24
    :int32("Trinket1Enchantment") -- 0x1E28
    :int32("Trinket2ItemId") -- 0x1E2C
    :int32("Trinket2Enchantment") -- 0x1E30
    :int32("CloackItemId") -- 0x1E34
    :int32("CloackEnchantment") -- 0x1E38
    :int32("MainHandItemId") -- 0x1E3C
    :int32("MainHandEnchantment") -- 0x1E40
    :int32("OffHandItemId") -- 0x1E44
    :int32("OffHandEnchantment") -- 0x1E48
    :int32("RangedItemId") -- 0x1E4C
    :int32("RangedEnchantment") -- 0x1E50
    :int32("TabardItemId") -- 0x1E54
    :int32("TabardEnchantment") -- 0x1E58

    :int32("ChosenTitle") -- 0x1E5C
    :int32("FakeInebriation") -- 0x1E60
    :int32("UnkPad") -- 0x1E64

    :WOWGUID("HeadItemSlot") -- 0x1E68
    :WOWGUID("NeckItemSlot") -- 0x1E70
    :WOWGUID("ShoulderItemSlot") -- 0x1E78
    :WOWGUID("ShirtItemSlot") -- 0x1E80
    :WOWGUID("ChestItemSlot") -- 0x1E88
    :WOWGUID("BeltItemSlot") -- 0x1E90
    :WOWGUID("LegsItemSlot") -- 0x1E98
    :WOWGUID("FootItemSlot") -- 0x1EA0
    :WOWGUID("WristItemSlot") -- 0x1EA8
    :WOWGUID("HandsItemSlot") -- 0x1EB0
    :WOWGUID("Firnger1ItemSlot") -- 0x1EB8
    :WOWGUID("Finger2ItemSlot") -- 0x1EC0
    :WOWGUID("Trinket1ItemSlot") -- 0x1EC8
    :WOWGUID("Trinket2ItemSlot") -- 0x1ED0
    :WOWGUID("BackItemSlot") -- 0x1ED8
    :WOWGUID("MainHandItemSlot") -- 0x1EE0
    :WOWGUID("OffHandItemSlot") -- 0x1EE8
    :WOWGUID("RangedItemSlot") -- 0x1EF0
    :WOWGUID("TabardItemSlot") -- 0x1EF8

    :WOWGUID_array("ContainerSlot", 4)
    :WOWGUID_array("BagSlot", 16)
    :WOWGUID_array("BankSlot", 28)
    :WOWGUID_array("ContainerBankSlot", 7)
    :WOWGUID_array("VendorBuyBackItem", 12)
    :WOWGUID_array("KeyRing", 32)
    :WOWGUID_array("Currency", 32)

    :WOWGUID("m_farsight") -- 0x2318
    :flag64("KnownTitles1") -- 0x2320
    :flag64("KnownTitles2") -- 0x2328
    :flag64("KnownTitles3") -- 0x2330
    :flag64("KnownCurrencies") -- 0x2338
    :int32("XP") -- 0x2340
    :int32("NextLevelXP") -- 0x2344

    :PlayerSkill_array("m_skill", 128)

    :int32("FreeTalentPoints") -- 0x2948
    :int32("MainProfessionFreeSlot") -- 0x294C
    :int32("TrackCreaturesFlag") -- 0x2950
    :int32("ResourcesTrackFlags") -- 0x2954
    :float("BlockPrecentage") -- 0x2958
    :float("DodgePercentage") -- 0x295C
    :float("ParryPercentage") -- 0x2960
    :int32("ExpertiseMainHand") -- 0x2964
    :int32("ExpertiseOffHand") -- 0x2968
    :float("CritPercentageMelee") -- 0x296C
    :float("CritPercentageRaged") -- 0x2970
    :float("CritPercentageOffhand") -- 0x2974
    :float("SpellCritPercentage1") -- 0x2978
    :float("CritPercentageSpellHoly") -- 0x297C
    :float("CritPercentageSpellFire") -- 0x2980
    :float("CritPercentageSpellNature") -- 0x2984
    :float("CritPercentageSpellFrost") -- 0x2988
    :float("CritPercentageSpellShadow") -- 0x298C
    :float("CritPercentageSpellArcane") -- 0x2990
    :int32("BlockDamageValue") -- 0x2994
    :float("BlockCritPercentage") -- 0x2998

    :ExploredZonesBitflied_array("m_exploredZones", 64)

    :int32("RestXP") -- 0x2B9C
    :int32("Money") -- 0x2BA0
    :int32("UnkField") -- 0x2BA4
    :int32("SpellPowerHoly") -- 0x2BA8
    :int32("SpellPowerFire") -- 0x2BAC
    :int32("SpellPowerNature") -- 0x2BB0
    :int32("SpellPowerFrost") -- 0x2BB4
    :int32("SpellPowerShadow") -- 0x2BB8
    :int32("SpellPowerArcane") -- 0x2BBC
    :int32_array("SpellPowerNegative", 7) -- 0x2BC0
    :float_array("UnkDamagePercent", 7) -- 0x2BDC
    :int32("ModHealingDonePos") -- 0x2BF8
    :float("HealingPercent") -- 0x2BFC
    :float("HealingDonePercent") -- 0x2C00
    :int32("TargetResistance") -- 0x2C04
    :int32("TargetPhysResistance") -- 0x2C08
    :int32("UnkPad") -- 0x2C0C
    :int32("AmmotSlotItemId") -- 0x2C10
    :int32("SelfResSpell") -- 0x2C14
    :int32("PVPMedals") -- 0x2C18
    :int32_array("BuyBackPrice", 12) -- 0x2C1C
    :int32_array("BuyBackTimeStamp", 12) -- 0x2C4C
    :int32("HonorKills") -- 0x2C7C
    :int32("TodayHonorContribution") -- 0x2C80
    :int32("YesterdayHonorContribution") -- 0x2C84
    :int32("LifetimeHonorableKills") -- 0x2C88
    :int32("bytes2field") -- 0x2C8C
    :int32("WatchedFactionIndex") -- 0x2C90
    :int32("UnkCombatRating") -- 0x2C94
    :int32("DefenceRate") -- 0x2C98
    :int32("DodgeRate") -- 0x2C9C
    :int32("ParryRate") -- 0x2CA0
    :int32("BlockRate") -- 0x2CA4
    :int32("HitRateMelee") -- 0x2CA8
    :int32("HitRateRanged") -- 0x2CAC
    :int32("HitRateSpell") -- 0x2CB0
    :int32("CritRateMelee") -- 0x2CB4
    :int32("CritRateRanged") -- 0x2CB8
    :int32("CritRateSpell") -- 0x2CBC
    :int32("UnkCombatRating") -- 0x2CC0
    :int32("UnkCombatRating") -- 0x2CC4
    :int32("UnkCombatRating") -- 0x2CC8
    :int32("ResilienceRate_1") -- 0x2CCC
    :int32("ResilienceRate_2") -- 0x2CD0
    :int32("ResilienceRate_3") -- 0x2CD4
    :int32("AttackSpeed_1") -- 0x2CD8
    :int32("HasteRate_1") -- 0x2CDC
    :int32("AttackSpeed_2") -- 0x2CE0
    :int32("HasteRate_2") -- 0x2CE4
    :int32("AttackSpeed_3") -- 0x2CE8
    :int32("HasteRate_3") -- 0x2CEC
    :int32("ExpertiseRate") -- 0x2CF0
    :int32("ArmorPenetrationRate") -- 0x2CF4

    :ArenaTeam_array("m_arenaTeams", 3)

    :int32("CurrencyHonor") -- 0x2D4C
    :int32("CurrencyArenaPoint") -- 0x2D50
    :int32("MaxLevel") -- 0x2D54

    :int32_array("m_dailyQuests", 25)

    :float_array("RuneRegen", 4) -- 0x2DBC
    :int32_array("NoReagenCost", 3) -- 0x2DCC
    :int32_array("GlyphSlot", 6) -- 0x2DD8
    :int32_array("Glyph", 6) -- 0x2DF0
    :flag32("GlyphsEnabletBitField") -- 0x2E08
    :int32("PetSpellPower") -- 0x2E0C
    :flag32("UnkFlags") -- 0x2E10
    :float("PetSpellBonusDamage") -- 0x2E14

local VisibleItem = Struct("VisibleItem")
    :uint8("classID")
    :uint8("subtypeID")
    :uint8("soundOverrideSubclassID")
    :uint8("material")
    :uint8("inventoryType")
    :uint8("sheatheType")
    :uint8("pad1")
    :uint8("pad2")

local CGPlayer = Struct("CGPlayer", CGUnit)
    :paddingTo(0x1850)
    :field("unk_1850", "int32") -- 0x1850
    :field("unk_1854", "int32") -- 0x1854
    :flag32("farSightFlag") -- 0x1858

    :TSHashTable("TSHashTable__TRADESKILLLINE") -- 0x185C
    :TSHashTable("TSHashTable__PROFICIENCYSPELL") -- 0x1884

    :field("unk_18AC", "int32") -- 0x18AC
    :field("unk_18B0", "int32") -- 0x18B0
    :field("unk_18B4", "int32") -- 0x18B4
    :field("unk_18B8", "int32") -- 0x18B8
    :field("unk_18BC", "int32") -- 0x18BC
    :field("unk_18C0", "int32") -- 0x18C0
    :field("unk_18C4", "int32") -- 0x18C4
    :field("unk_18C8", "int32") -- 0x18C8

    :TSFixedArray("m_critters")

    :field("unk_18D8", "int32") -- 0x18D8
    :field("unk_18DC", "int32") -- 0x18DC
    :WOWGUID("m_lootTarget") -- 0x18E0
    :hex("unkAutoLootFlags", "int32") -- 0x18E8
    :field("unk_18EC", "int32") -- 0x18EC
    :field("unk_18F0", "int32") -- 0x18F0
    :ptr("playerInventoryPtr") -- 0x18F4
    :uint32("playerGUID_low", {hex = true}) -- 0x18F8
    :field("unk_18FC", "int32") -- 0x18FC
    :hex("unk_1900", "int32") -- 0x1900
    :hex("unk_1904", "int32") -- 0x1904
    :VisibleItem_array("m_visibleItem", 3) -- 0x1908
    :int32("standValue") -- 0x1920

    :int32("MetaSocketCount") -- 0x1924
    :int32("RedSocketCount") -- 0x1928
    :int32("YellowSocketCount") -- 0x192C
    :int32("BlueSocketCount") -- 0x1930

    :field("combatModeLastUnitMS", "int32") -- 0x1934
    :hex("combatModeLastUnitGUID", "uint64") -- 0x1938
    :int32("turnOffPVPModeMS") -- 0x1940
    :ptr("unkDanceStudioField1") -- 0x1944
    :ptr("unkDanceStudioField2") -- 0x1948
    :int32("totalPlayedTimeSeconds") -- 0x194C
    :int32("lastPlayedCmdTimestamp") -- 0x1950
    :field("unk_1954", "int32") -- 0x1954

    :ObjectFields("m_objectFields")

    :UnitFields("m_unitFields")

    :field("UnkBeginPlayerStructureField", "uint32")
    :field("unkField", "uint32")

    :PlayerFields("m_playerFields")

-- #include "load_player.lua"