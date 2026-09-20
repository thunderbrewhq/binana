-- #include "cgobject.lua"

local TSFixedArray = Struct("TSFixedArray")
    :uint32("m_alloc") -- 0x0
    :uint32("m_count") -- 0x4
    :ptr("m_data") -- 0x8

local TSGrowableArray = Struct("TSGrowableArray", TSFixedArray)
    :uint32("m_chunk") -- 0xC

local TSHashTable = Struct("TSHashTable")
    :ptr("void*", "v_table") -- 0x0000
    :TSList("m_fulllist")
    :uint32("m_fullnessIndicator") -- 0x0010
    :TSGrowableArray("m_slotlistarray") -- 000x14
    :uint32("m_slotmask", {hex = true}) -- 000x24

local Vector2 = Struct("Vector2")
    :float("x")
    :float("y")

local Vector3 = Struct("Vector3")
    :float("x")
    :float("y")
    :float("z")

local UnitFields = Struct("UnitFields")
    :WOWGUID("Charm") -- 0x1970
    :WOWGUID("Summon") -- 0x1978
    :WOWGUID("Critter") -- 0x1980
    :WOWGUID("CharmedBy") -- 0x1988
    :WOWGUID("SummonedBy") -- 0x1990
    :WOWGUID("CreatedBy") -- 0x1998
    :WOWGUID("Target") -- 0x19A0
    :WOWGUID("ChannelSpellTarget") -- 0x19A8
    :int32("ChannelSpellId") -- 0x19B0
    :uint8("Race") -- 0x19B4
    :uint8("Class") -- 0x19B5
    :uint8("Gender") -- 0x19B6
    :uint8("DisplayPower") -- 0x19B7
    :int32("Health") -- 0x19B8
    :int32("Mana") -- 0x19BC
    :int32("Rage") -- 0x19C0
    :int32("Focus") -- 0x19C4
    :int32("Energy") -- 0x19C8
    :int32("UnkResource1") -- 0x19CC
    :int32("UnkResource2") -- 0x19D0
    :int32("RunePower") -- 0x19D4
    :int32("MaxHealth") -- 0x19D8
    :int32("MaxMana") -- 0x19DC
    :int32("MaxRage") -- 0x19E0
    :int32("MaxFocus") -- 0x19E4
    :int32("MaxEnergy") -- 0x19E8
    :int32("UnkMaxResource1") -- 0x19EC
    :int32("UnkMaxResource2") -- 0x19F0
    :int32("MaxRunePower") -- 0x19F4
    :float("ManaRegenFlatMod") -- 0x19F8
    :float("RageRegenFlatMod") -- 0x19FC
    :float("FocusRegenFlatMod") -- 0x1A00
    :float("EnergyFlatMod") -- 0x1A04
    :float("UnkRegenFlatMod") -- 0x1A08
    :float("UnkRegenFlatMod") -- 0x1A0C
    :float("RunePowerRegenFlatMod") -- 0x1A10
    :float("ManaRegenInterruptedFlatMod") -- 0x1A14
    :float("RageRegenInterruptedFlatMod") -- 0x1A18
    :float("FocusRegenInterruptedFlatMod") -- 0x1A1C
    :float("EnergyRegenInterruptedFlatMod") -- 0x1A20
    :float("UnkRegenInterruptedFlatMod") -- 0x1A24
    :float("UnkRegenInterruptedFlatMod") -- 0x1A28
    :float("RunePowerRegenInterruptedFlatMod") -- 0x1A2C
    :int32("Level") -- 0x1A30
    :int32("FieldFactiontemplate") -- 0x1A34
    :int32("VirtualItemSlotIdMainHand") -- 0x1A38
    :int32("VirtualItemSlotIdOffHand") -- 0x1A3C
    :int32("VirtualItemSlotIdRanged") -- 0x1A40
    :flag32("Flag1") -- 0x1A44
    :flag32("Flag2") -- 0x1A48
    :int32("AuraState") -- 0x1A4C
    :int32("BaseAttackTimeMainHand") -- 0x1A50
    :int32("BaseAttackTimeOffHand") -- 0x1A54
    :int32("RangedAttackTime") -- 0x1A58
    :float("BoundingRadius") -- 0x1A5C
    :float("CombatReach") -- 0x1A60
    :int32("DisplayId") -- 0x1A64
    :int32("NativedisplayId") -- 0x1A68
    :int32("MountdisplayId") -- 0x1A6C
    :float("MinMainHandDamage") -- 0x1A70
    :float("MaxMainHandDamage") -- 0x1A74
    :int32("MinOffHandDamage") -- 0x1A78
    :int32("MaxOffHandDamage") -- 0x1A7C
    :int32("SitState") -- 0x1A80
    :int32("PetNumber") -- 0x1A84
    :int32("PetNameTamestamp") -- 0x1A88
    :int32("PetXP") -- 0x1A8C
    :int32("PetNextLevelXP") -- 0x1A90
    :int32("DynFlags") -- 0x1A94
    :float("ModCastSpeed") -- 0x1A98
    :int32("CreatedBySpell") -- 0x1A9C
    :int32("NPCFlags") -- 0x1AA0
    :int32("NPCEmoteState") -- 0x1AA4
    :int32("StatStrengthBase") -- 0x1AA8
    :int32("StatAgilityBase") -- 0x1AAC
    :int32("StatStaminaBase") -- 0x1AB0
    :int32("StatIntellectBase") -- 0x1AB4
    :int32("StatSpiritBase") -- 0x1AB8
    :int32("StatStrengthPositive") -- 0x1ABC
    :int32("StatAgilityPositive") -- 0x1AC0
    :int32("StatStaminaPositive") -- 0x1AC4
    :int32("StatIntellectPositive") -- 0x1AC8
    :int32("StatSpiritPositive") -- 0x1ACC
    :int32("StatStrengthNegative") -- 0x1AD0
    :int32("StatAgilityNegative") -- 0x1AD4
    :int32("StatStaminaNegative") -- 0x1AD8
    :int32("StatIntellectNegative") -- 0x1ADC
    :int32("StatSpiritNegative") -- 0x1AE0
    :int32("StatArmor") -- 0x1AE4
    :int32("ResistHoly") -- 0x1AE8
    :int32("ResistFire") -- 0x1AEC
    :int32("ResistNature") -- 0x1AF0
    :int32("ResistFrost") -- 0x1AF4
    :int32("ResistShadow") -- 0x1AF8
    :int32("ResistArcane") -- 0x1AFC
    :int32("UnkResist") -- 0x1B00
    :int32("ResistPositiveHoly") -- 0x1B04
    :int32("ResistPositiveFire") -- 0x1B08
    :int32("ResistPovisitveNature") -- 0x1B0C
    :int32("ResistPositiveFrost") -- 0x1B10
    :int32("ResistPositiveShadow") -- 0x1B14
    :int32("ResistPositiveArcane") -- 0x1B18
    :int32("UnkResist") -- 0x1B1C
    :int32("ResistNegativeHoly") -- 0x1B20
    :int32("ResistNegativeFire") -- 0x1B24
    :int32("ResistNegativeNature") -- 0x1B28
    :int32("ResistNegativeFrost") -- 0x1B2C
    :int32("ResistNegativeShadow") -- 0x1B30
    :int32("ResistNegativeArcane") -- 0x1B34
    :int32("UnkBaseMana") -- 0x1B38
    :int32("BaseHealth") -- 0x1B3C
    :int32("WeaponStandType") -- 0x1B40
    :int32("AttackPowerMelee") -- 0x1B44
    :int32("AttackPowerMeleeMod") -- 0x1B48
    :float("AttackPowerMeleeMulti") -- 0x1B4C
    :int32("AttackPowerRange") -- 0x1B50
    :int32("AttackPowerRangedMod") -- 0x1B54
    :float("AttackPowerRangedMulti") -- 0x1B58
    :float("MinRangedDamage") -- 0x1B5C
    :float("MaxRangedDamage") -- 0x1B60
    :int32_array("PowerCostModifier", 7) -- 0x1B64
    :float_array("PowerCostMultiplier", 7) -- 0x1B80
    :int32("MaxHealthMod") -- 0x1B9C
    :float("HoverHeight") -- 0x1BA0
    :int32("Pad") -- 0x1BA4

local UnitAura = Struct("Aura")
    :WOWGUID("caster") -- 0x0C50
    :int32("buffId") -- 0x0C58
    :int32("unk") -- 0x0C5C
    :int32("maxDuration") -- 0x0C60
    :ptr("buffPtr") -- 0x0C64

local UnitBuff = Struct("Buff")
    :int32("index")
    :int32("buffId")

local CMovementData = Struct("CMovementData")
    :int32("unk_0788") -- 0x0788
    :int32("unk_078C") -- 0x078C
    :WOWGUID("Transport") -- 0x0790
    :Vector3("Position")
    :uint32("unkFlag", {hex = true}) -- 0x07A4
    :float("Facing") -- 0x07A8
    :float("Pitch") -- 0x07AC
    :ptr("dataPtr") -- 0x07B0
    :uint32("unkFlag2", {hex = true}) -- 0x07B4
    :int32("unk_07B8") -- 0x07B8
    :int32("unk_07BC") -- 0x07BC
    :Vector3("GroundNormal")
    :flag32("moveFlag1") -- 0x07CC
    :flag32("moveFlag2") -- 0x07D0
    :Vector3("Anchor")
    :float("AnchorFacing") -- 0x07E0
    :float("AnchorPitch") -- 0x07E4
    :int32("unk_07E8") -- 0x07E8
    :Vector3("Direction")
    :Vector2("Direction2d")
    :float("cosAnchorPitch") -- 0x0800
    :float("sinAnchorPitch") -- 0x0804
    :int32("FallTime") -- 0x0808
    :float("StartFallHeight") -- 0x080C
    :float("unkFloat") -- 0x0810
    :float("MoveSpeed") -- 0x0814
    :float("WalkSpeed") -- 0x0818
    :float("RunSpeed") -- 0x081C
    :float("BackSpeed") -- 0x0820
    :float("SwimSpeed") -- 0x0824
    :float("BackSwimSpeed") -- 0x0828
    :float("FlyMountSpeed") -- 0x082C
    :float("FlyMountBackSpeed") -- 0x0830
    :float("TurnSpeed") -- 0x0834
    :float("FlyMountUnkUpDownRotation1") -- 0x0838
    :float("FlyMountUnkUpDownRotation2") -- 0x083C
    :float("FallSpeed") -- 0x0840
    :ptr("CGMoveSplinePtr") -- 0x0844
    :int32("PerfCount") -- 0x0848
    :flag32("unkFlag3") -- 0x084C
    :float("CollisonBoxHalfWidth") -- 0x0850
    :float("CollisionBoxHeight") -- 0x0854
    :float("ObjectScale") -- 0x0858
    :int32("unk_085C") -- 0x085C
    :int32("unk_0860") -- 0x0860
    :int32("unk_0864") -- 0x0864
    :int32("unk_0868") -- 0x0868
    :int32("unk_086C") -- 0x086C
    :flag32("unkFlags_00") -- 0x0870
    :flag32("unkFlags_01") -- 0x0874
    :flag32("unkFlags_02") -- 0x0878
    :flag32("unkFlags_03") -- 0x087C
    :flag32("unkFlags_04") -- 0x0880
    :flag32("unkFlags_05") -- 0x0884
    :flag32("unkFlags_06") -- 0x0888
    :flag32("unkFlags_07") -- 0x088C
    :flag32("unkFlags_08") -- 0x0890
    :flag32("unkFlags_09") -- 0x0894
    :flag32("unkFlags_10") -- 0x0898
    :flag32("unkFlags_11") -- 0x089C
    :flag32("unkFlags_12") -- 0x08A0
    :flag32("unkFlags_13") -- 0x08A4
    :flag32("unkFlags_14") -- 0x08A8
    :flag32("unkFlags_15") -- 0x08AC
    :int32("unk_08B0") -- 0x08B0
    :int32("unk_08B4") -- 0x08B4
    :int32("unk_08B8") -- 0x08B8
    :int32("unk_08BC") -- 0x08BC
    :int32("unk_08C0") -- 0x08C0
    :TSLink("m_link") -- 0x08C4
    :ptr("CGObject_C", "objectPtr") -- 0x08CC

local CGUnit = Struct("CGUnit", CGObject)
    :ptr("unitDataPtr") -- 0x00D0
    :ptr("unk_00D4") -- 0x00D4
    :CMovementData_ptr("m_moveData") -- 0x00D8

    --mirror handlers
    :TSList_array("m_lists", 142)
    :paddingTo(0x788)

    :CMovementData("m_movementData") -- 0x0788

    :float("m_facingAngle") -- 0x08D0
    :field("unk_08D4", "int32") -- 0x08D4
    :field("unk_08D8", "int32") -- 0x08D8
    :float("m_facingAngle") -- 0x08DC
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
    :float("m_mountScale") -- 0x0990
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
    :int32("objectNextUpdateMillisec") -- 0x09BC
    :int32("mountModelId") -- 0x09C0
    :field("unk_09C4", "int32") -- 0x09C4
    :field("unk_09C8", "int32") -- 0x09C8
    :field("unk_09CC", "int32") -- 0x09CC
    :field("unk_09D0", "int32") -- 0x09D0
    :field("unk_09D4", "int32") -- 0x09D4
    :Vector3("GroundNormal")
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
    :WOWGUID("unkGUID") -- 0x0A20
    :field("unk_0A28", "int32") -- 0x0A28
    :field("unk_0A2C", "int32") -- 0x0A2C
    :flag32("unkJumpFlags") -- 0x0A30
    :field("unk_0A34", "int32") -- 0x0A34
    :flag32("unk_0A38") -- 0x0A38
    :int32("m_footprintTexId") -- 0x0A3C
    :int32("m_terrain") -- 0x0A40
    :Vector2("m_footPrintSize")
    :float("m_footPrintScale") -- 0x0A4C
    :float("m_facingAngle") -- 0x0A50
    :float("m_pitchAngle") -- 0x0A54
    :ptr("unk_0A58") -- 0x0A58
    :int32("UnkSpellCounter") -- 0x0A5C
    :int32("m_channelSpellId") -- 0x0A60
    :field("unk_0A64", "int32") -- 0x0A64
    :field("unk_0A68", "int32") -- 0x0A68
    :int32("m_channelSpellId") -- 0x0A6C
    :flag32("unkCastSchoolImmunFlag") -- 0x0A70
    :flag32("unkCastImmunFlag") -- 0x0A74
    :int32("m_spellCastStartMS") -- 0x0A78
    :int32("m_spellCastEndMS") -- 0x0A7C
    :field("unk_0A80", "int32") -- 0x0A80
    :field("unk_0A84", "int32") -- 0x0A84
    :field("unk_0A88", "int32") -- 0x0A88
    :field("unk_0A8C", "int32") -- 0x0A8C
    :field("unk_0A90", "int32") -- 0x0A90
    :float("m_facingAngle") -- 0x0A94
    :float("unkAnimValue") -- 0x0A98
    :float("unkAnimValue") -- 0x0A9C
    :float("m_HeadFacingAngle") -- 0x0AA0
    :field("unk_0AA4", "int32") -- 0x0AA4
    :field("unk_0AA8", "int32") -- 0x0AA8
    :Vector3("SmoothFacing")
    :ptr("unk_0AB8") -- 0x0AB8
    :int32("objectUpdateMillisec") -- 0x0ABC
    :field("unk_0AC0", "int32") -- 0x0AC0
    :field("unk_0AC4", "int32") -- 0x0AC4
    :field("unk_0AC8", "int32") -- 0x0AC8
    :ptr("unkSoundPtr") -- 0x0ACC
    :field("unk_0AD0", "int32") -- 0x0AD0
    :field("unk_0AD4", "int32") -- 0x0AD4
    :int32("m_mountFootprintTexId") -- 0x0AD8
    :Vector2("m_mountFootprintSize")
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
    :float("m_selectionRadius") -- 0x0B0C
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
    :float("m_unitScale") -- 0x0B3C
    :ptr("unkDisplayModeIdRangedPtr") -- 0x0B40
    :field("unk_0B44", "int32") -- 0x0B44
    :field("unk_0B48", "int32") -- 0x0B48
    :ptr("CCharacterComponentPtr") -- 0x0B4C
    :ptr("unkEquipedMainHandModelPtr") -- 0x0B50
    :field("unk_0B54", "int32") -- 0x0B54
    :flag32("unkObjectWeaponLastStandValue") -- 0x0B58
    :flag32("unkObjectWeaponCurrentStandFlag") -- 0x0B5C
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
    :flag32("UnkCombatFlag") -- 0x0BEC
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

    :Aura_array("m_aura", 16)

    :int32("m_auraCount") -- 0x0DD0
    :Buff_array("m_unitBuff", 16)

    :int32("m_auraCountSorted") -- 0x0E54
    :Buff_array("m_unitBuffSorted", 16)

    :paddingTo(0xFB0)

    :int32("UnitHealthPredicted") -- 0x0FB0
    :int32("UnitManaPredicted") -- 0x0FB4
    :int32("UnitRagePredicted") -- 0x0FB8
    :int32("UnitFocusPredicted") -- 0x0FBC
    :int32("UnitEnergyPredicted") -- 0x0FC0
    :int32("UnkPowerPredicted") -- 0x0FC4
    :int32("UnkPowerPredicted") -- 0x0FC8
    :int32("UnitRunePowerPredicted") -- 0x0FCC
    :int32("UnkPowerPredictionTimer") -- 0x0FD0
    :field("unk_0FD4", "int32") -- 0x0FD4
    :field("unk_0FD8", "int32") -- 0x0FD8
    :field("unk_0FDC", "int32") -- 0x0FDC
    :TSHashTable("TSHashTable__UnitThreat") -- 0x0FE0    
    :ptr("playerBeginPtr") -- 0x1008 --if not a player then 8 byte GUID
    :ptr("playerEndPtr") -- 0x100C
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