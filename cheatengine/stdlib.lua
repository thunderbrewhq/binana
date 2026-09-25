local WoWGUID = Struct("WOWGUID")
    :hex("guid", "uint64")

local TSLink = Struct("TSLink")
    :TSLink_ptr("m_prevlink")
    :ptr("m_next")

local TSList = Struct("TSList") -- also TSExplicitList
    :uint32("m_linkoffset", {hex = true})
    :TSLink("m_terminator")

local TSLinkedNode = Struct("TSLinkedNode")
    :TSLink("m_link")

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
    :flag32("m_slotmask") -- 000x24

local HASHKEY_STRI = Struct("HASHKEY_STRI")
    :int8_ptr("m_str")

local C2Vector = Struct("C2Vector")
    :float("x")
    :float("y")

local C2iVector = Struct("C2iVector")
    :int32("x")
    :int32("y")

local C3Vector = Struct("C3Vector")
    :float("x")
    :float("y")
    :float("z")

local CImVector = Struct("CImVector")
    :uint8("r")
    :uint8("g")
    :uint8("b")
    :uint8("a")

local CAaBox = Struct("CAaBox")
    :C3Vector("top")
    :C3Vector("bottom")

local CAaSphere = Struct("CAaSphere")
    :C3Vector("center")
    :float("d")

local C44Matrix = Struct("C44Matrix")
    :float_array("m", 16)

local RCString = Struct("RCString")
    :ptr("void*", "vtbl")
    :uint32("m_refCnt")
    :int8_ptr("m_str")