-- #include "cgobject.lua"

local ObjectFields = Struct("ObjectFields")
    :hex("GUID", "uint64")
    :field("type", "uint32")
    :field("unk", "uint32")
    :field("scale", "float")
    :field("pad", "uint32")

local ContainerSlot = Struct("ContainerSlot")
    :hex("guid", "uint64")

local ContainerFields = Struct("ContainerFields")
    :field("NumSlots", "int32")
    :field("Pad", "int32")
    :structArray("Slot", ContainerSlot, 36)

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

local CGContainer = Struct("CGContainer", CGObject)
    :paddingTo(0x778)
    :embed("ObjectFields", ObjectFields) -- 0x778
    :embed("ItemFields", ItemFields) -- 0x790
    :embed("ContainerFields", ContainerFields) -- 0x878
    :field("itemId", "int32") -- 0x9A0
    :field("scale", "float") -- 0x9A4
    :paddingTo(0xB88)


-- #include "load_player_container.lua"