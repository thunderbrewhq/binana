-- #include "cgobject.lua"

local Vector2 = Struct("Vector2")
    :field("x", "float")
    :field("y", "float")

local Vector3 = Struct("Vector3")
    :field("x", "float")
    :field("y", "float")
    :field("z", "float")

local ObjectFields = Struct("ObjectFields")
    :hex("GUID", "uint64")
    :field("type", "uint32")
    :field("unk", "uint32")
    :field("scale", "float")
    :field("pad", "uint32")

local UnitFields = Struct("UnitFields")
    :hex("CharmGUID", "uint64") -- 0x1970
    :hex("SummonGUID", "uint64") -- 0x1978
    :hex("CritterGUID", "uint64") -- 0x1980
    :hex("CharmedByGUID", "uint64") -- 0x1988
    :hex("SummonedByGUID", "uint64") -- 0x1990
    :hex("CreatedByGUID", "uint64") -- 0x1998
    :hex("TargetGUID", "uint64") -- 0x19A0
    :hex("ChannelSpellTargetGUID", "uint64") -- 0x19A8
    :field("ChanellSpellId", "int32") -- 0x19B0
    :field("Race", "uint8") -- 0x19B4
    :field("Class", "uint8") -- 0x19B5
    :field("Gender", "uint8") -- 0x19B6
    :field("DisplayPower", "uint8") -- 0x19B7
    :field("Health", "int32") -- 0x19B8
    :field("Mana", "int32") -- 0x19BC
    :field("Rage", "int32") -- 0x19C0
    :field("Focus", "int32") -- 0x19C4
    :field("Energy", "int32") -- 0x19C8
    :field("UnkResource1", "int32") -- 0x19CC
    :field("UnkResource2", "int32") -- 0x19D0
    :field("RunePower", "int32") -- 0x19D4
    :field("MaxHealth", "int32") -- 0x19D8
    :field("MaxMana", "int32") -- 0x19DC
    :field("MaxRage", "int32") -- 0x19E0
    :field("MaxFocus", "int32") -- 0x19E4
    :field("MaxEnergy", "int32") -- 0x19E8
    :field("UnkMaxResource1", "int32") -- 0x19EC
    :field("UnkMaxResource2", "int32") -- 0x19F0
    :field("MaxRunePower", "int32") -- 0x19F4
    :field("ManaRegenFlatMod", "float") -- 0x19F8
    :field("RageRegenFlatMod", "float") -- 0x19FC
    :field("FocusRegenFlatMod", "float") -- 0x1A00
    :field("EnergyFlatMod", "float") -- 0x1A04
    :field("UnkRegenFlatMod", "float") -- 0x1A08
    :field("UnkRegenFlatMod", "float") -- 0x1A0C
    :field("RunePowerRegenFlatMod", "float") -- 0x1A10
    :field("ManaRegenInterruptedFlatMod", "float") -- 0x1A14
    :field("RageRegenInterruptedFlatMod", "float") -- 0x1A18
    :field("FocusRegenInterruptedFlatMod", "float") -- 0x1A1C
    :field("EnergyRegenInterruptedFlatMod", "float") -- 0x1A20
    :field("UnkRegenInterruptedFlatMod", "float") -- 0x1A24
    :field("UnkRegenInterruptedFlatMod", "float") -- 0x1A28
    :field("RunePowerRegenInterruptedFlatMod", "float") -- 0x1A2C
    :field("Level", "int32") -- 0x1A30
    :field("FieldFactiontemplate", "int32") -- 0x1A34
    :field("VirtualItemSlotIdMainHand", "int32") -- 0x1A38
    :field("VirtualItemSlotIdOffHand", "int32") -- 0x1A3C
    :field("VirtualItemSlotIdRanged", "int32") -- 0x1A40
    :field("Flag1", "int32") -- 0x1A44
    :field("Flag2", "int32") -- 0x1A48
    :field("AuraState", "int32") -- 0x1A4C
    :field("BaseAttackTimeMainHand", "int32") -- 0x1A50
    :field("BaseAttackTimeOffHand", "int32") -- 0x1A54
    :field("RangedAttackTime", "int32") -- 0x1A58
    :field("BoundingRadius", "float") -- 0x1A5C
    :field("CombatReach", "float") -- 0x1A60
    :field("DisplayId", "int32") -- 0x1A64
    :field("NativedisplayId", "int32") -- 0x1A68
    :field("MountdisplayId", "int32") -- 0x1A6C
    :field("MinMainHandDamage", "float") -- 0x1A70
    :field("MaxMainHandDamage", "float") -- 0x1A74
    :field("MinOffHandDamage", "int32") -- 0x1A78
    :field("MaxOffHandDamage", "int32") -- 0x1A7C
    :field("SitState", "int32") -- 0x1A80
    :field("PetNumber", "int32") -- 0x1A84
    :field("PetNameTamestamp", "int32") -- 0x1A88
    :field("PetXP", "int32") -- 0x1A8C
    :field("PetNextLevelXP", "int32") -- 0x1A90
    :field("DynFlags", "int32") -- 0x1A94
    :field("ModCastSpeed", "float") -- 0x1A98
    :field("CreatedBySpell", "int32") -- 0x1A9C
    :field("NPCFlags", "int32") -- 0x1AA0
    :field("NPCEmoteState", "int32") -- 0x1AA4
    :field("StatStrengthBase", "int32") -- 0x1AA8
    :field("StatAgilityBase", "int32") -- 0x1AAC
    :field("StatStaminaBase", "int32") -- 0x1AB0
    :field("StatIntellectBase", "int32") -- 0x1AB4
    :field("StatSpiritBase", "int32") -- 0x1AB8
    :field("StatStrengthPositive", "int32") -- 0x1ABC
    :field("StatAgilityPositive", "int32") -- 0x1AC0
    :field("StatStaminaPositive", "int32") -- 0x1AC4
    :field("StatIntellectPositive", "int32") -- 0x1AC8
    :field("StatSpiritPositive", "int32") -- 0x1ACC
    :field("StatStrengthNegative", "int32") -- 0x1AD0
    :field("StatAgilityNegative", "int32") -- 0x1AD4
    :field("StatStaminaNegative", "int32") -- 0x1AD8
    :field("StatIntellectNegative", "int32") -- 0x1ADC
    :field("StatSpiritNegative", "int32") -- 0x1AE0
    :field("StatArmor", "int32") -- 0x1AE4
    :field("ResistHoly", "int32") -- 0x1AE8
    :field("ResistFire", "int32") -- 0x1AEC
    :field("ResistNature", "int32") -- 0x1AF0
    :field("ResistFrost", "int32") -- 0x1AF4
    :field("ResistShadow", "int32") -- 0x1AF8
    :field("ResistArcane", "int32") -- 0x1AFC
    :field("UnkResist", "int32") -- 0x1B00
    :field("ResistPositiveHoly", "int32") -- 0x1B04
    :field("ResistPositiveFire", "int32") -- 0x1B08
    :field("ResistPovisitveNature", "int32") -- 0x1B0C
    :field("ResistPositiveFrost", "int32") -- 0x1B10
    :field("ResistPositiveShadow", "int32") -- 0x1B14
    :field("ResistPositiveArcane", "int32") -- 0x1B18
    :field("UnkResist", "int32") -- 0x1B1C
    :field("ResistNegativeHoly", "int32") -- 0x1B20
    :field("ResistNegativeFire", "int32") -- 0x1B24
    :field("ResistNegativeNature", "int32") -- 0x1B28
    :field("ResistNegativeFrost", "int32") -- 0x1B2C
    :field("ResistNegativeShadow", "int32") -- 0x1B30
    :field("ResistNegativeArcane", "int32") -- 0x1B34
    :field("UnkBaseMana", "int32") -- 0x1B38
    :field("BaseHealth", "int32") -- 0x1B3C
    :field("WeaponStandType", "int32") -- 0x1B40
    :field("AttackPowerMelee", "int32") -- 0x1B44
    :field("AttackPowerMeleeMod", "int32") -- 0x1B48
    :field("AttackPowerMeleeMulti", "float") -- 0x1B4C
    :field("AttackPowerRange", "int32") -- 0x1B50
    :field("AttackPowerRangedMod", "int32") -- 0x1B54
    :field("AttackPowerRangedMulti", "float") -- 0x1B58
    :field("MinRangedDamage", "float") -- 0x1B5C
    :field("MaxRangedDamage", "float") -- 0x1B60
    :array("PowerCostModifier", "int32", 7) -- 0x1B64
    :array("PowerCostMultiplier", "float", 7) -- 0x1B80
    :field("MaxHealthMod", "int32") -- 0x1B9C
    :field("HoverHeight", "float") -- 0x1BA0
    :field("Pad", "int32") -- 0x1BA4

local UnitAura = Struct("Aura")
    :hex("casterGUID", "uint64") -- 0x0C50
    :field("buffId", "int32") -- 0x0C58
    :field("unk", "int32") -- 0x0C5C
    :field("maxDuration", "int32") -- 0x0C60
    :hex("buffPtr", "int32") -- 0x0C64

local UnitBuff = Struct("Buff")
    :field("index", "int32")
    :field("buffId", "int32")

local CMovementData = Struct("CMovementData")
    :field("unk_0788", "int32") -- 0x0788
    :field("unk_078C", "int32") -- 0x078C
    :hex("TransportGUID", "uint64") -- 0x0790
    :embed("Position", Vector3)
    :hex("unkFlag", "int32") -- 0x07A4
    :field("Facing", "float") -- 0x07A8
    :field("Pitch", "float") -- 0x07AC
    :hex("dataPtr", "int32") -- 0x07B0
    :hex("unkFlag2", "int32") -- 0x07B4
    :field("unk_07B8", "int32") -- 0x07B8
    :field("unk_07BC", "int32") -- 0x07BC
    :embed("GroundNormal", Vector3)
    :hex("moveFlag1", "int32") -- 0x07CC
    :hex("moveFlag2", "int32") -- 0x07D0
    :embed("Anchor", Vector3)
    :field("AnchorFacing", "float") -- 0x07E0
    :field("AnchorPitch", "float") -- 0x07E4
    :field("unk_07E8", "int32") -- 0x07E8
    :embed("Direction", Vector3)
    :embed("Direction2d", Vector2)
    :field("cosAnchorPitch", "float") -- 0x0800
    :field("sinAnchorPitch", "float") -- 0x0804
    :field("FallTime", "int32") -- 0x0808
    :field("StartFallHeight", "float") -- 0x080C
    :field("unkFloat", "float") -- 0x0810
    :field("MoveSpeed", "float") -- 0x0814
    :field("WalkSpeed", "float") -- 0x0818
    :field("RunSpeed", "float") -- 0x081C
    :field("BackSpeed", "float") -- 0x0820
    :field("SwimSpeed", "float") -- 0x0824
    :field("BackSwimSpeed", "float") -- 0x0828
    :field("FlyMountSpeed", "float") -- 0x082C
    :field("FlyMountBackSpeed", "float") -- 0x0830
    :field("TurnSpeed", "float") -- 0x0834
    :field("FlyMountUnkUpDownRotation1", "float") -- 0x0838
    :field("FlyMountUnkUpDownRotation2", "float") -- 0x083C
    :field("FallSpeed", "float") -- 0x0840
    :hex("CGMoveSplinePtr", "int32") -- 0x0844
    :field("PerfCount", "int32") -- 0x0848
    :hex("unkFlag3", "int32") -- 0x084C
    :field("CollisonBoxHalfWidth", "float") -- 0x0850
    :field("CollisionBoxHeight", "float") -- 0x0854
    :field("ObjectScale", "float") -- 0x0858
    :field("unk_085C", "int32") -- 0x085C
    :field("unk_0860", "int32") -- 0x0860
    :field("unk_0864", "int32") -- 0x0864
    :field("unk_0868", "int32") -- 0x0868
    :field("unk_086C", "int32") -- 0x086C
    :hex("unkFlags_00", "int32") -- 0x0870
    :hex("unkFlags_01", "int32") -- 0x0874
    :hex("unkFlags_02", "int32") -- 0x0878
    :hex("unkFlags_03", "int32") -- 0x087C
    :hex("unkFlags_04", "int32") -- 0x0880
    :hex("unkFlags_05", "int32") -- 0x0884
    :hex("unkFlags_06", "int32") -- 0x0888
    :hex("unkFlags_07", "int32") -- 0x088C
    :hex("unkFlags_08", "int32") -- 0x0890
    :hex("unkFlags_09", "int32") -- 0x0894
    :hex("unkFlags_10", "int32") -- 0x0898
    :hex("unkFlags_11", "int32") -- 0x089C
    :hex("unkFlags_12", "int32") -- 0x08A0
    :hex("unkFlags_13", "int32") -- 0x08A4
    :hex("unkFlags_14", "int32") -- 0x08A8
    :hex("unkFlags_15", "int32") -- 0x08AC
    :field("unk_08B0", "int32") -- 0x08B0
    :field("unk_08B4", "int32") -- 0x08B4
    :field("unk_08B8", "int32") -- 0x08B8
    :field("unk_08BC", "int32") -- 0x08BC
    :field("unk_08C0", "int32") -- 0x08C0
    :ptr("linkedList_ptr1") -- 0x08C4
    :ptr("linkedList_ptr2") -- 0x08C8
    :ptr("CGObject_C", "objectPtr") -- 0x08CC

local CGUnit = Struct("CGUnit", CGObject)
    :ptr("unitDataPtr") -- 0x00D0
    :ptr("unk_00D4") -- 0x00D4
    :ptr("CMovementData", "m_moveDataPtr") -- 0x00D8

    --mirror handlers
    :paddingTo(0x788)

    :embed("CMovementData", CMovementData) -- 0x0788

    :field("unitFacingAngle", "float") -- 0x08D0
    :field("unk_08D4", "int32") -- 0x08D4
    :field("unk_08D8", "int32") -- 0x08D8
    :field("unitFacingAngle", "float") -- 0x08DC
    :field("unk_08E0", "int32") -- 0x08E0
    :field("unk_08E4", "int32") -- 0x08E4
    :field("unk_08E8", "int32") -- 0x08E8
    :field("unk_08EC", "int32") -- 0x08EC
    :field("unk_08F0", "int32") -- 0x08F0
    :field("unk_08F4", "int32") -- 0x08F4
    :field("unk_08F8", "int32") -- 0x08F8
    :field("unk_08FC", "int32") -- 0x08FC
    :field("unk_0900", "int32") -- 0x0900
    :field("unk_0904", "int32") -- 0x0904
    :field("unk_0908", "int32") -- 0x0908
    :field("unk_090C", "int32") -- 0x090C
    :field("unk_0910", "int32") -- 0x0910
    :field("unk_0914", "int32") -- 0x0914
    :field("unk_0918", "int32") -- 0x0918
    :field("unk_091C", "int32") -- 0x091C
    :field("unk_0920", "int32") -- 0x0920
    :field("unk_0924", "int32") -- 0x0924
    :field("unk_0928", "int32") -- 0x0928
    :field("unk_092C", "int32") -- 0x092C
    :field("unk_0930", "int32") -- 0x0930
    :field("unk_0934", "int32") -- 0x0934
    :field("unk_0938", "int32") -- 0x0938
    :field("unk_093C", "int32") -- 0x093C
    :field("unk_0940", "int32") -- 0x0940
    :field("unk_0944", "int32") -- 0x0944
    :field("unk_0948", "int32") -- 0x0948
    :field("unk_094C", "int32") -- 0x094C
    :field("unk_0950", "int32") -- 0x0950
    :field("unk_0954", "int32") -- 0x0954
    :ptr("unk_0958") -- 0x0958
    :ptr("unk_095C") -- 0x095C
    :field("unk_0960", "int32") -- 0x0960
    :ptr("unkCreatureStatsPtr") -- 0x0964
    :ptr("CreatureDisplayInfoPtr") -- 0x0968
    :ptr("CreatureDisplayInfoExtraPtr") -- 0x096C
    :ptr("CreatureModelDataPtr") -- 0x0970
    :ptr("CreatureSoundDataPtr") -- 0x0974
    :ptr("mountedCreatureSoundDataPtr") -- 0x0978
    :ptr("unkBloodPoolPtr") -- 0x097C
    :field("unk_0980", "int32") -- 0x0980
    :field("unk_0984", "int32") -- 0x0984
    :field("unk_0988", "int32") -- 0x0988
    :ptr("m_mountM2modelPtr") -- 0x098C
    :field("m_mountScale", "float") -- 0x0990
    :ptr("unk_0994") -- 0x0994
    :field("unk_0998", "int32") -- 0x0998
    :field("unk_099C", "int32") -- 0x099C
    :field("unk_09A0", "int32") -- 0x09A0
    :field("unk_09A4", "int32") -- 0x09A4
    :field("unk_09A8", "int32") -- 0x09A8
    :field("unk_09AC", "int32") -- 0x09AC
    :field("unk_09B0", "int32") -- 0x09B0
    :field("unk_09B4", "int32") -- 0x09B4
    :field("unk_09B8", "int32") -- 0x09B8
    :field("objectNextUpdateMillisec", "int32") -- 0x09BC
    :field("mountModelId", "int32") -- 0x09C0
    :field("unk_09C4", "int32") -- 0x09C4
    :field("unk_09C8", "int32") -- 0x09C8
    :field("unk_09CC", "int32") -- 0x09CC
    :field("unk_09D0", "int32") -- 0x09D0
    :field("unk_09D4", "int32") -- 0x09D4
    :embed("GroundNormal", Vector3)
    :field("unk_09E4", "int32") -- 0x09E4
    :field("unk_09E8", "int32") -- 0x09E8
    :field("unk_09EC", "int32") -- 0x09EC
    :field("unk_09F0", "int32") -- 0x09F0
    :ptr("unk_09F4") -- 0x09F4
    :field("unk_09F8", "int32") -- 0x09F8
    :field("unk_09FC", "int32") -- 0x09FC
    :ptr("unk_0A00") -- 0x0A00
    :field("unk_0A04", "int32") -- 0x0A04
    :field("unk_0A08", "int32") -- 0x0A08
    :field("unk_0A0C", "int32") -- 0x0A0C
    :field("unk_0A10", "int32") -- 0x0A10
    :field("unk_0A14", "int32") -- 0x0A14
    :field("unk_0A18", "int32") -- 0x0A18
    :field("unk_0A1C", "int32") -- 0x0A1C
    :hex("unkGUID", "uint64") -- 0x0A20
    :field("unk_0A28", "int32") -- 0x0A28
    :field("unk_0A2C", "int32") -- 0x0A2C
    :hex("unkJumpFlags", "int32") -- 0x0A30
    :field("unk_0A34", "int32") -- 0x0A34
    :hex("unk_0A38", "int32") -- 0x0A38
    :field("m_footprintTexId", "int32") -- 0x0A3C
    :field("m_terrain", "int32") -- 0x0A40
    :embed("m_footPrintSize", Vector2)
    :field("m_footPrintScale", "float") -- 0x0A4C
    :field("m_facingAngle", "float") -- 0x0A50
    :field("m_pitchAngle", "float") -- 0x0A54
    :ptr("unk_0A58") -- 0x0A58
    :field("UnkSpellCounter", "int32") -- 0x0A5C
    :field("m_channelSpellId", "int32") -- 0x0A60
    :field("unk_0A64", "int32") -- 0x0A64
    :field("unk_0A68", "int32") -- 0x0A68
    :field("m_channelSpellId", "int32") -- 0x0A6C
    :field("unkCastSchoolImmunFlag", "int32") -- 0x0A70
    :field("unkCastImmunFlag", "int32") -- 0x0A74
    :field("m_spellCastStartMS", "int32") -- 0x0A78
    :field("m_spellCastEndMS", "int32") -- 0x0A7C
    :field("unk_0A80", "int32") -- 0x0A80
    :field("unk_0A84", "int32") -- 0x0A84
    :field("unk_0A88", "int32") -- 0x0A88
    :field("unk_0A8C", "int32") -- 0x0A8C
    :field("unk_0A90", "int32") -- 0x0A90
    :field("m_facingAngle", "float") -- 0x0A94
    :field("unkAnimValue", "float") -- 0x0A98
    :field("unkAnimValue", "float") -- 0x0A9C
    :field("m_HeadFacingAngle", "float") -- 0x0AA0
    :field("unk_0AA4", "int32") -- 0x0AA4
    :field("unk_0AA8", "int32") -- 0x0AA8
    :embed("SmoothFacing", Vector3)
    :ptr("unk_0AB8") -- 0x0AB8
    :field("objectUpdateMillisec", "int32") -- 0x0ABC
    :field("unk_0AC0", "int32") -- 0x0AC0
    :field("unk_0AC4", "int32") -- 0x0AC4
    :field("unk_0AC8", "int32") -- 0x0AC8
    :ptr("unkSoundPtr") -- 0x0ACC
    :field("unk_0AD0", "int32") -- 0x0AD0
    :field("unk_0AD4", "int32") -- 0x0AD4
    :field("m_mountFootprintTexId", "int32") -- 0x0AD8
    :embed("m_mountFootprintSize", Vector2)
    :ptr("unk_0AE4", "int32") -- 0x0AE4
    :ptr("unk_0AE8", "int32") -- 0x0AE8
    :ptr("unk_0AEC", "int32") -- 0x0AEC
    :field("unk_0AF0", "int32") -- 0x0AF0
    :field("unk_0AF4", "int32") -- 0x0AF4
    :field("unk_0AF8", "int32") -- 0x0AF8
    :field("unk_0AFC", "int32") -- 0x0AFC
    :field("unk_0B00", "int32") -- 0x0B00
    :field("unk_0B04", "int32") -- 0x0B04
    :field("unk_0B08", "int32") -- 0x0B08
    :field("m_selectionRadius", "float") -- 0x0B0C
    :field("unk_0B10", "int32") -- 0x0B10
    :field("unk_0B14", "int32") -- 0x0B14
    :field("unkFloatValue", "float") -- 0x0B18
    :field("unk_0B1C", "int32") -- 0x0B1C
    :field("unk_0B20", "int32") -- 0x0B20
    :field("unk_0B24", "int32") -- 0x0B24
    :field("unk_0B28", "int32") -- 0x0B28
    :field("unk_0B2C", "int32") -- 0x0B2C
    :field("unk_0B30", "int32") -- 0x0B30
    :field("unk_0B34", "int32") -- 0x0B34
    :field("unk_0B38", "int32") -- 0x0B38
    :field("m_unitScale", "float") -- 0x0B3C
    :ptr("unkDisplayModeIdRangedPtr") -- 0x0B40
    :field("unk_0B44", "int32") -- 0x0B44
    :field("unk_0B48", "int32") -- 0x0B48
    :ptr("CCharacterComponentPtr") -- 0x0B4C
    :ptr("unkEquipedMainHandModelPtr") -- 0x0B50
    :field("unk_0B54", "int32") -- 0x0B54
    :hex("unkObjectWeaponLastStandValue", "int32") -- 0x0B58
    :hex("unkObjectWeaponCurrentStandFlag", "int32") -- 0x0B5C
    :field("unk_0B60", "int32") -- 0x0B60
    :field("unk_0B64", "int32") -- 0x0B64
    :field("unk_0B68", "int32") -- 0x0B68
    :field("unk_0B6C", "int32") -- 0x0B6C
    :field("unk_0B70", "int32") -- 0x0B70
    :field("unk_0B74", "int32") -- 0x0B74
    :field("unk_0B78", "int32") -- 0x0B78
    :field("unk_0B7C", "int32") -- 0x0B7C
    :field("unk_0B80", "int32") -- 0x0B80
    :field("unk_0B84", "int32") -- 0x0B84
    :hex("unk_0B88", "uint32") -- 0x0B88
    :hex("unk_0B8C", "uint32") -- 0x0B8C
    :hex("unk_0B90", "uint32") -- 0x0B90
    :field("unk_0B94", "int32") -- 0x0B94
    :field("unk_0B98", "int32") -- 0x0B98
    :field("unk_0B9C", "int32") -- 0x0B9C
    :field("unk_0BA0", "int32") -- 0x0BA0
    :field("unk_0BA4", "int32") -- 0x0BA4
    :field("unk_0BA8", "int32") -- 0x0BA8
    :field("unk_0BAC", "int32") -- 0x0BAC
    :field("unk_0BB0", "int32") -- 0x0BB0
    :field("unk_0BB4", "int32") -- 0x0BB4
    :field("unk_0BB8", "int32") -- 0x0BB8
    :field("unk_0BBC", "int32") -- 0x0BBC
    :field("unk_0BC0", "int32") -- 0x0BC0
    :field("unk_0BC4", "int32") -- 0x0BC4
    :field("unk_0BC8", "int32") -- 0x0BC8
    :field("unkFloatValue", "float") -- 0x0BCC
    :field("unk_0BD0", "int32") -- 0x0BD0
    :field("unk_0BD4", "int32") -- 0x0BD4
    :field("unk_0BD8", "int32") -- 0x0BD8
    :field("unk_0BDC", "int32") -- 0x0BDC
    :field("unk_0BE0", "int32") -- 0x0BE0
    :field("unk_0BE4", "int32") -- 0x0BE4
    :field("unk_0BE8", "int32") -- 0x0BE8
    :hex("UnkCombatFlag", "int32") -- 0x0BEC
    :field("unk_0BF0", "int32") -- 0x0BF0
    :field("unk_0BF4", "int32") -- 0x0BF4
    :field("unk_0BF8", "int32") -- 0x0BF8
    :field("unk_0BFC", "int32") -- 0x0BFC
    :field("unk_0C00", "int32") -- 0x0C00
    :field("unk_0C04", "int32") -- 0x0C04
    :field("unk_0C08", "int32") -- 0x0C08
    :field("unk_0C0C", "int32") -- 0x0C0C
    :field("unk_0C10", "int32") -- 0x0C10
    :field("unk_0C14", "int32") -- 0x0C14
    :field("unk_0C18", "int32") -- 0x0C18
    :field("unk_0C1C", "int32") -- 0x0C1C
    :field("unk_0C20", "int32") -- 0x0C20
    :field("unk_0C24", "int32") -- 0x0C24
    :field("unk_0C28", "int32") -- 0x0C28
    :field("unk_0C2C", "int32") -- 0x0C2C
    :field("unk_0C30", "int32") -- 0x0C30
    :field("unk_0C34", "int32") -- 0x0C34
    :ptr("CGNamePlateFramePtr") -- 0x0C38
    :field("unk_0C3C", "int32") -- 0x0C3C
    :field("unk_0C40", "int32") -- 0x0C40
    :field("unk_0C44", "int32") -- 0x0C44
    :field("unk_0C48", "int32") -- 0x0C48
    :field("unk_0C4C", "int32") -- 0x0C4C

    :structArray("UnitAura", UnitAura, 16)

    :field("m_auraCount", "int32") -- 0x0DD0
    :structArray("UnitBuff", UnitBuff, 16)

    :field("auraCount", "int32") -- 0x0E54
    :structArray("UnitBuffSorted", UnitBuff, 16)

    :paddingTo(0xFB0)

    :field("UnitHealthPredicted", "int32") -- 0x0FB0
    :field("UnitManaPredicted", "int32") -- 0x0FB4
    :field("UnitRagePredicted", "int32") -- 0x0FB8
    :field("UnitFocusPredicted", "int32") -- 0x0FBC
    :field("UnitEnergyPredicted", "int32") -- 0x0FC0
    :field("UnkPowerPredicted", "int32") -- 0x0FC4
    :field("UnkPowerPredicted", "int32") -- 0x0FC8
    :field("UnitRunePowerPredicted", "int32") -- 0x0FCC
    :field("UnkPowerPredictionTimer", "int32") -- 0x0FD0
    :field("unk_0FD4", "int32") -- 0x0FD4
    :field("unk_0FD8", "int32") -- 0x0FD8
    :field("unk_0FDC", "int32") -- 0x0FDC
    :ptr("ThreatVtblPtr") -- 0x0FE0
    :field("unk_0FE4", "int32") -- 0x0FE4
    :field("unk_0FE8", "int32") -- 0x0FE8
    :field("unk_0FEC", "int32") -- 0x0FEC
    :field("unk_0FF0", "int32") -- 0x0FF0
    :field("unk_0FF4", "int32") -- 0x0FF4
    :field("unk_0FF8", "int32") -- 0x0FF8
    :field("unk_0FFC", "int32") -- 0x0FFC
    :field("unk_1000", "int32") -- 0x1000
    :field("unk_1004", "int32") -- 0x1004
    :hex("playerBeginPtr", "int32") -- 0x1008 --if not a player then 8 byte GUID
    :hex("playerEndPtr", "int32") -- 0x100C
    :field("unk_1010", "int32") -- 0x1010
    :paddingTo(0x1068)
    :field("Health", "uint32") -- 0x1068
    :field("Mana", "uint32") -- 0x106C
    :paddingTo(0x1088)
    :field("MaxHealth", "uint32") -- 0x1088
    :field("MaxMana", "uint32") -- 0x108C
    :paddingTo(0x1110)
    :field("maxInteractDistance", "float") -- 0x1100
    :padding(0x33C)

-- #include "load_unit_target.lua"