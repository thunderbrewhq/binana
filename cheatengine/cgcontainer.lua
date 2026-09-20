-- #include "cgobject.lua"

local ContainerFields = Struct("ContainerFields")
    :int32("NumSlots")
    :int32("Pad")
    :WOWGUID_array("Slot", 36)

local ItemEnchantment = Struct("ItemEnchantment")
    :uint32_array("id", 3)

local ItemFields = Struct("ItemFields")
    :WOWGUID("Owner")
    :WOWGUID("Contained")
    :WOWGUID("Creator")
    :WOWGUID("GiftCreator")
    :int32("StackCount")
    :int32("Duration")
    :int32_array("SpellCharges", 5)
    :flag32("Flags")
    :ItemEnchantment_array("Enchantment", 12)
    :int32("PropertySeed")
    :int32("RandomPropertiesID")
    :int32("Durability")
    :int32("MaxDurability")
    :int32("CreatePlayedTime")
    :int32("Pad")

local CGContainer = Struct("CGContainer", CGObject)
    :paddingTo(0x778)
    :ObjectFields("m_objectFields") -- 0x778
    :ItemFields("m_itemFields") -- 0x790
    :ContainerFields("m_containerFields") -- 0x878
    :int32("itemId") -- 0x9A0
    :float("scale") -- 0x9A4
    :paddingTo(0xB88)


-- #include "load_player_container.lua"