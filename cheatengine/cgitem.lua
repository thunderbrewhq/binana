-- #include "cgobject.lua"

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

local CGItem = Struct("CGItem", CGObject)
    :paddingTo(0x3E0)
    :ObjectFields("m_objectFields") -- 0x3E0
    :ItemFields("ItemFields") -- 0x3F8
    :int32("itemId") -- 0x4E0
    :float("scale") -- 0x4E4
    :paddingTo(0x4F4)
    :int32("StackCount") -- 0x4F4
    :int32_array("SpellCharges", 5) -- 0x4F8
    :flag32("Flags") -- 0x50C
    :ItemEnchantment_array("Enchantment", 12) -- 0x510
    :int32("Durability") -- 0x5A0
    :paddingTo(0x5A8)

-- #include "load_bagpack_item.lua"