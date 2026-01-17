-- #include "StructDef.lua"

local CGObject = Struct("CGObject")

CGObject:ptr("void*", "VtablePtr") -- 0x0000
CGObject:unk(4) -- 0x0004
CGObject:ptr("dataBeginPtr") -- 0x0008
CGObject:ptr("dataEndPtr") -- 0x000C
CGObject:hex("unkFlag", "int32") -- 0x0010
CGObject:field("TypeID", "int32") -- 0x0014
CGObject:hex("low_GUID", "uint32") -- 0x0018
CGObject:paddingTo(0x30)
CGObject:hex("ObjectGuid", "uint64") -- 0x0030
CGObject:paddingTo(0x98)
CGObject:field("m_objectSacle1", "float") -- 0x0098
CGObject:field("m_objectSacle2", "float") -- 0x009C
CGObject:field("m_objectScalingEndMS", "int32") -- 0x00A0
CGObject:field("m_objectLastScale", "float") -- 0x00A4
CGObject:ptr("specialEffectPtr") -- 0x00A8
CGObject:field("objectHeight", "float") -- 0x00AC
CGObject:ptr("unkPlayerNamePtr") -- 0x00B0
CGObject:ptr("CM2Model", "m_model") -- 0x00B4
CGObject:ptr("cmapEntityPtr") -- 0x00B8
CGObject:hex("unkMovementFlags", "int32") -- 0x00BC
CGObject:field("unk_00C0", "int32") -- 0x00C0
CGObject:field("unk_00C4", "int32") -- 0x00C4
CGObject:field("m_alpha", "uint8") -- 0x00C8
CGObject:field("m_startAlpha", "uint8") -- 0x00C9
CGObject:field("m_endAlpha", "uint8") -- 0x00CA
CGObject:field("m_maxAlpha", "uint8") -- 0x00CB
CGObject:ptr("effectManagerPtr") -- 0x00CC