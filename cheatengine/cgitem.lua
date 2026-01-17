-- #include "cgobject.lua"

local ObjectFields = Struct("ObjectFields")
    :hex("GUID", "uint64")
    :field("type", "uint32")
    :field("unk", "uint32")
    :field("scale", "float")
    :field("pad", "uint32")

local ItemEnchantment = Struct("ItemEnchantment")
    :array("id", "uint32", 3)

local ItemFields = Struct("ItemFields")
    :hex("Owner", "uint64")
    :hex("Contained", "uint64")
    :hex("Creator", "uint64")
    :hex("GiftCreator", "uint64")
    :field("StackCount", "int32")
    :field("Duration", "int32")
    :array("SpellCharges", "int32", 5)
    :hex("Flags", "uint32")
    :structArray("Enchantment", ItemEnchantment, 12)
    :field("PropertySeed",       "int32")
    :field("RandomPropertiesID", "int32")
    :field("Durability", "int32")
    :field("MaxDurability", "int32")
    :field("CreatePlayedTime", "int32")
    :field("Pad", "int32")

local CGItem = Struct("CGItem", CGObject)
    :paddingTo(0x3E0)
    :embed("ObjectFields", ObjectFields) -- 0x3E0
    :embed("ItemFields", ItemFields) -- 0x3F8
    :field("itemId", "int32") -- 0x4E0
    :field("scale", "float") -- 0x4E4
    :paddingTo(0x4F4)
    :field("StackCount", "int32") -- 0x4F4
    :array("SpellCharges", "int32", 5) -- 0x4F8
    :hex("Flags", "uint32") -- 0x50C
    :structArray("Enchantment", ItemEnchantment, 12) -- 0x510
    :field("Durability", "int32") -- 0x5A0
    :paddingTo(0x5A8)

-- #include "load_bagpack_item.lua"