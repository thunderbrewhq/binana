-- #include "cgunit.lua"

local QuestLog = Struct("QuestLog")
    :field("QuestId", "int32")
    :field("ObjectiveDone", "int32")
    :field("ObjectiveCounterFlag", "int32")
    :field("UnkField4", "int32")
    :field("UnkField5", "int32")

local PlayerSkill = Struct("PlayerSkill")
    :field("ID", "uint16")
    :field("Unk", "uint16")
    :field("Skill", "uint16")
    :field("SkillMax", "uint16")
    :field("UnkPad", "int32")

local WoWGUID = Struct("WOWGUID")
    :hex("guid", "uint64")

local ExploredZones = Struct("ExploredZonesBitflied")
    :hex("flag", "uint64")

local ArenaTeam = Struct("ArenaTeam")
    :field("ID", "int32")
    :field("TypeID", "int32")
    :field("MemberID", "int32")
    :field("GamesWeekID", "int32")
    :field("GamesSeasonID", "int32")
    :field("WinsSeasonID", "int32")
    :field("PersonalRateID", "int32")

local DailyQuest = Struct("DailyQuest")
    :field("id", "uint32")

local PlayerFields = Struct("PlayerFields")
    :field("DuelArbiter", "int32") -- 0x1BB0
    :field("GuildID", "int32") -- 0x1BB4
    :field("GuildRank", "int32") -- 0x1BB8
    :field("bytes1", "int32") -- 0x1BBC
    :field("bytes2", "int32") -- 0x1BC0
    :field("bytes3", "int32") -- 0x1BC4
    :field("DueldTeam", "int32") -- 0x1BC8
    :field("GuildTimestamp", "int32") -- 0x1BCC

    :structArray("QuestLog", QuestLog, 25)

    :field("HeadItemId", "int32") -- 0x1DC4
    :field("HeadEnchantment", "int32") -- 0x1DC8
    :field("NeckItemId", "int32") -- 0x1DCC
    :field("NeckEnchantment", "int32") -- 0x1DD0
    :field("ShoulderItemId", "int32") -- 0x1DD4
    :field("ShoulderEnchantment", "int32") -- 0x1DD8
    :field("ShirtItemId", "int32") -- 0x1DDC
    :field("ShirtEnchantment", "int32") -- 0x1DE0
    :field("ChestItemId", "int32") -- 0x1DE4
    :field("ChestEnchantment", "int32") -- 0x1DE8
    :field("BeltItemId", "int32") -- 0x1DEC
    :field("BeltEnchantment", "int32") -- 0x1DF0
    :field("LegsItemId", "int32") -- 0x1DF4
    :field("LegsEnchantment", "int32") -- 0x1DF8
    :field("FootItemId", "int32") -- 0x1DFC
    :field("FootEnchantment", "int32") -- 0x1E00
    :field("WristItemId", "int32") -- 0x1E04
    :field("WristEnchantment", "int32") -- 0x1E08
    :field("HandsItemId", "int32") -- 0x1E0C
    :field("HandsEnchantment", "int32") -- 0x1E10
    :field("Finger1ItemId", "int32") -- 0x1E14
    :field("Finger1Enchantment", "int32") -- 0x1E18
    :field("Finger2ItemId", "int32") -- 0x1E1C
    :field("Finger2Enchantment", "int32") -- 0x1E20
    :field("Trinket1ItemId", "int32") -- 0x1E24
    :field("Trinket1Enchantment", "int32") -- 0x1E28
    :field("Trinket2ItemId", "int32") -- 0x1E2C
    :field("Trinket2Enchantment", "int32") -- 0x1E30
    :field("CloackItemId", "int32") -- 0x1E34
    :field("CloackEnchantment", "int32") -- 0x1E38
    :field("MainHandItemId", "int32") -- 0x1E3C
    :field("MainHandEnchantment", "int32") -- 0x1E40
    :field("OffHandItemId", "int32") -- 0x1E44
    :field("OffHandEnchantment", "int32") -- 0x1E48
    :field("RangedItemId", "int32") -- 0x1E4C
    :field("RangedEnchantment", "int32") -- 0x1E50
    :field("TabardItemId", "int32") -- 0x1E54
    :field("TabardEnchantment", "int32") -- 0x1E58
    :field("ChosenTitle", "int32") -- 0x1E5C
    :field("FakeInebriation", "int32") -- 0x1E60
    :field("UnkPad", "int32") -- 0x1E64

    :hex("HeadItemSlot", "uint64") -- 0x1E68
    :hex("NeckItemSlot", "uint64") -- 0x1E70
    :hex("ShoulderItemSlot", "uint64") -- 0x1E78
    :hex("ShirtItemSlot", "uint64") -- 0x1E80
    :hex("ChestItemSlot", "uint64") -- 0x1E88
    :hex("BeltItemSlot", "uint64") -- 0x1E90
    :hex("LegsItemSlot", "uint64") -- 0x1E98
    :hex("FootItemSlot", "uint64") -- 0x1EA0
    :hex("WristItemSlot", "uint64") -- 0x1EA8
    :hex("HandsItemSlot", "uint64") -- 0x1EB0
    :hex("Firnger1ItemSlot", "uint64") -- 0x1EB8
    :hex("Finger2ItemSlot", "uint64") -- 0x1EC0
    :hex("Trinket1ItemSlot", "uint64") -- 0x1EC8
    :hex("Trinket2ItemSlot", "uint64") -- 0x1ED0
    :hex("BackItemSlot", "uint64") -- 0x1ED8
    :hex("MainHandItemSlot", "uint64") -- 0x1EE0
    :hex("OffHandItemSlot", "uint64") -- 0x1EE8
    :hex("RangedItemSlot", "uint64") -- 0x1EF0
    :hex("TabardItemSlot", "uint64") -- 0x1EF8

    :structArray("ContainerSlot", WoWGUID, 4)
    :structArray("BagSlot", WoWGUID, 16)
    :structArray("BankSlot", WoWGUID, 28)
    :structArray("ContainerBankSlot", WoWGUID, 7)
    :structArray("VendorBuyBackItem", WoWGUID, 12)
    :structArray("KeyRing", WoWGUID, 32)
    :structArray("Currency", WoWGUID, 32)

    :hex("FarsightGUID", "uint64") -- 0x2318
    :hex("KnownTitles1", "uint64") -- 0x2320
    :hex("KnownTitles2", "uint64") -- 0x2328
    :hex("KnownTitles3", "uint64") -- 0x2330
    :hex("KnownCurrencies", "uint64") -- 0x2338
    :field("XP", "int32") -- 0x2340
    :field("NextLevelXP", "int32") -- 0x2344

    :structArray("Skill", PlayerSkill, 128)

    :field("FreeTalentPoints", "int32") -- 0x2948
    :field("MainProfessionFreeSlot", "int32") -- 0x294C
    :field("TrackCreaturesFlag", "int32") -- 0x2950
    :field("ResourcesTrackFlags", "int32") -- 0x2954
    :field("BlockPrecentage", "float") -- 0x2958
    :field("DodgePercentage", "float") -- 0x295C
    :field("ParryPercentage", "float") -- 0x2960
    :field("ExpertiseMainHand", "int32") -- 0x2964
    :field("ExpertiseOffHand", "int32") -- 0x2968
    :field("CritPercentageMelee", "float") -- 0x296C
    :field("CritPercentageRaged", "float") -- 0x2970
    :field("CritPercentageOffhand", "float") -- 0x2974
    :field("SpellCritPercentage1", "float") -- 0x2978
    :field("CritPercentageSpellHoly", "float") -- 0x297C
    :field("CritPercentageSpellFire", "float") -- 0x2980
    :field("CritPercentageSpellnature", "float") -- 0x2984
    :field("CritPercentageSpellFrost", "float") -- 0x2988
    :field("CritPercentageSpellShadow", "float") -- 0x298C
    :field("CritPercentageSpellArcane", "float") -- 0x2990
    :field("BlockDamageValue", "int32") -- 0x2994
    :field("BlockCritPercentage", "float") -- 0x2998

    :structArray("ExploredZones", ExploredZones, 64)

    :field("RestXP", "int32") -- 0x2B9C
    :field("Money", "int32") -- 0x2BA0
    :field("UnkField", "int32") -- 0x2BA4
    :field("SpellPowerHoly", "int32") -- 0x2BA8
    :field("SpellPowerFire", "int32") -- 0x2BAC
    :field("SpellPowerNature", "int32") -- 0x2BB0
    :field("SpellPowerFrost", "int32") -- 0x2BB4
    :field("SpellPowerShadow", "int32") -- 0x2BB8
    :field("SpellPowerArcane", "int32") -- 0x2BBC
    :array("SpellPowerNegative", "int32", 7) -- 0x2BC0
    :array("UnkDamagePercent", "float", 7) -- 0x2BDC
    :field("ModHealingDonePos", "int32") -- 0x2BF8
    :field("HealingPercent", "float") -- 0x2BFC
    :field("HealingDonePercent", "float") -- 0x2C00
    :field("TargetResistance", "int32") -- 0x2C04
    :field("TargetPhysResistance", "int32") -- 0x2C08
    :field("UnkPad", "int32") -- 0x2C0C
    :field("AmmotSlotItemId", "int32") -- 0x2C10
    :field("SelfResSpell", "int32") -- 0x2C14
    :field("PVPMedals", "int32") -- 0x2C18
    :array("BuyBackPrice", "int32", 12) -- 0x2C1C
    :array("BuyBackTimeStamp", "int32", 12) -- 0x2C4C
    :field("HonorKills", "int32") -- 0x2C7C
    :field("TodayHonorContribution", "int32") -- 0x2C80
    :field("YesterdayHonorContribution", "int32") -- 0x2C84
    :field("LifetimeHonorableKills", "int32") -- 0x2C88
    :field("bytes2field", "int32") -- 0x2C8C
    :field("WatchedFactionIndex", "int32") -- 0x2C90
    :field("UnkCombatRating", "int32") -- 0x2C94
    :field("DefenceRate", "int32") -- 0x2C98
    :field("DodgeRate", "int32") -- 0x2C9C
    :field("ParryRate", "int32") -- 0x2CA0
    :field("BlockRate", "int32") -- 0x2CA4
    :field("HitRateMelee", "int32") -- 0x2CA8
    :field("HitRateRanged", "int32") -- 0x2CAC
    :field("HitRateSpell", "int32") -- 0x2CB0
    :field("CritRateMelee", "int32") -- 0x2CB4
    :field("CritRateRanged", "int32") -- 0x2CB8
    :field("CritRateSpell", "int32") -- 0x2CBC
    :field("UnkCombatRating", "int32") -- 0x2CC0
    :field("UnkCombatRating", "int32") -- 0x2CC4
    :field("UnkCombatRating", "int32") -- 0x2CC8
    :field("ResilienceRate_1", "int32") -- 0x2CCC
    :field("ResilienceRate_2", "int32") -- 0x2CD0
    :field("ResilienceRate_3", "int32") -- 0x2CD4
    :field("AttackSpeed_1", "int32") -- 0x2CD8
    :field("HasteRate_1", "int32") -- 0x2CDC
    :field("AttackSpeed_2", "int32") -- 0x2CE0
    :field("HasteRate_2", "int32") -- 0x2CE4
    :field("AttackSpeed_3", "int32") -- 0x2CE8
    :field("HasteRate_3", "int32") -- 0x2CEC
    :field("ExpertiseRate", "int32") -- 0x2CF0
    :field("ArmorPenetrationRate", "int32") -- 0x2CF4

    :structArray("ArenaTeam", ArenaTeam, 3)

    :field("CurrencyHonor", "int32") -- 0x2D4C
    :field("CurrencyArenaPoint", "int32") -- 0x2D50
    :field("MaxLevel", "int32") -- 0x2D54

    :structArray("DailyQuest", DailyQuest, 25)

    :array("RuneRegen", "float", 4) -- 0x2DBC
    :array("NoReagenCost", "int32", 3) -- 0x2DCC
    :array("GlyphSlot", "int32", 6) -- 0x2DD8
    :array("Glyph", "int32", 6) -- 0x2DF0
    :field("GlyphsEnabletBitField", "int32") -- 0x2E08
    :field("PetSpellPower", "int32") -- 0x2E0C
    :field("UnkFlags", "int32") -- 0x2E10
    :field("PetSpellBonusDamage", "float") -- 0x2E14

local PlayerCritterArray = Struct("CritterArray")
    :field("memoryCapacity", "uint32")
    :field("count", "uint32")
    :hex("memoryPtr", "uint32")

local CGPlayer = Struct("CGPlayer", CGUnit)
    :paddingTo(0x1850)
    :field("unk_1850", "int32") -- 0x1850
    :field("unk_1854", "int32") -- 0x1854
    :field("farSightFlag", "int32") -- 0x1858
    :ptr("unkTradeSkillObjVtbl") -- 0x185C
    :field("unk_1860", "int32") -- 0x1860
    :field("unk_1864", "int32") -- 0x1864
    :field("unk_1868", "int32") -- 0x1868
    :field("unk_186C", "int32") -- 0x186C
    :field("unk_1870", "int32") -- 0x1870
    :field("unk_1874", "int32") -- 0x1874
    :field("unk_1878", "int32") -- 0x1878
    :field("unk_187C", "int32") -- 0x187C
    :field("unk_1880", "int32") -- 0x1880
    :ptr("unkTradeSkillObjVptr") -- 0x1884
    :field("unk_1888", "int32") -- 0x1888
    :field("unk_188C", "int32") -- 0x188C
    :field("unk_1890", "int32") -- 0x1890
    :field("unk_1894", "int32") -- 0x1894
    :field("unk_1898", "int32") -- 0x1898
    :field("unk_189C", "int32") -- 0x189C
    :ptr("unk_18A0") -- 0x18A0
    :field("unk_18A4", "int32") -- 0x18A4
    :field("unk_18A8", "int32") -- 0x18A8
    :field("unk_18AC", "int32") -- 0x18AC
    :field("unk_18B0", "int32") -- 0x18B0
    :field("unk_18B4", "int32") -- 0x18B4
    :field("unk_18B8", "int32") -- 0x18B8
    :field("unk_18BC", "int32") -- 0x18BC
    :field("unk_18C0", "int32") -- 0x18C0
    :field("unk_18C4", "int32") -- 0x18C4
    :field("unk_18C8", "int32") -- 0x18C8

    :embed("m_critters", PlayerCritterArray)

    :field("unk_18D8", "int32") -- 0x18D8
    :field("unk_18DC", "int32") -- 0x18DC
    :hex("LootTargetGUID", "uint64") -- 0x18E0
    :hex("unkAutoLootFlags", "int32") -- 0x18E8
    :field("unk_18EC", "int32") -- 0x18EC
    :field("unk_18F0", "int32") -- 0x18F0
    :ptr("playerInventoryPtr") -- 0x18F4
    :field("playerGUID", "int32") -- 0x18F8
    :field("unk_18FC", "int32") -- 0x18FC
    :hex("unk_1900", "int32") -- 0x1900
    :hex("unk_1904", "int32") -- 0x1904
    :hex("MainHandVisibleItemClassID", "int32") -- 0x1908
    :hex("MainHandVisibleItemSubtypeID", "int32") -- 0x190C
    :hex("OffHandVisibleItemClassID", "int32") -- 0x1910
    :hex("unkOffHandInventoryType", "int32") -- 0x1914
    :hex("RangedVisibleItemClassID", "int32") -- 0x1918
    :hex("unkRangedVisibleItemInventoryType", "int32") -- 0x191C
    :field("standValue", "int32") -- 0x1920
    :field("MetaSocketCount", "int32") -- 0x1924
    :field("RedSocketCount", "int32") -- 0x1928
    :field("YellowSocketCount", "int32") -- 0x192C
    :field("BlueSocketCount", "int32") -- 0x1930
    :field("combatModeLastUnitMS", "int32") -- 0x1934
    :hex("combatModeLastUnitGUID", "uint64") -- 0x1938
    :field("turnOffPVPModeMS", "int32") -- 0x1940
    :field("unkDanceStudioField1", "int32") -- 0x1944
    :field("unkDanceStudioField2", "int32") -- 0x1948
    :field("totalPlayedTimeSeconds", "int32") -- 0x194C
    :field("lastPlayedCmdTimestamp", "int32") -- 0x1950
    :field("unk_1954", "int32") -- 0x1954

    :embed("objectFields", ObjectFields)

    :embed("unitFields", UnitFields)

    :field("UnkBeginPlayerStructureField", "uint32")
    :field("unkField", "uint32")

    :embed("playerFields", PlayerFields)

-- #include "load_player.lua"