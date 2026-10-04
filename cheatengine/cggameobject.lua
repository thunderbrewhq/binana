-- #include "cgobject.lua"

local GameObjectFields = Struct("GameObjectFields")
    :WOWGUID("createdBy")        -- 0x000
    :uint32("displayId")        -- 0x008
    :flag32("flags")   -- 0x00C
    :float_array("parentRotation", 4) -- 0x010
    :uint32("dynamic") -- 0x020
    :uint32("faction") -- 0x024
    :uint32("level")   -- 0x028
    :uint8("state")  -- 0x02C
    :uint8("type")  -- 0x02D
    :uint8("artKit")  -- 0x02E
    :uint8("animProgress")  -- 0x02F

local CGGameObject_C = Struct("CGGameObject_C", CGObject)
    :GameObjectFields_ptr("m_gameObjectFields") -- 0x00D0
    :ptr("unk_00D4") -- 0x00D4
    :paddingTo(0xE8)
    :C3Vector("m_position") -- 0x0E8
    :flag32("unkFlag") -- 0x0F4
    :uint32("unkCounter") -- 0x00F8
    :int32("unk_00FC") -- 0x00FC
    :ptr("unkPtr")     -- 0x0100
    :flag8("m_flags")  -- 0x0104 ( |= 2 )
    :paddingTo(0x108)  -- 0x0105..0x0107
    :TSList_array("m_typeLists", 12) -- 0x0108 (12 * 0x0C = 0x90)
    :int32("unk_0198") -- 0x0198
    :int32("unk_019C") -- 0x019C
    :ptr("CGGameObject_C_Type", "m_typeSpecific") -- 0x01A0
    :ptr("CGameObjectDef", "m_gameObjDef") -- 0x01A4
    :C44Matrix("m_mtx")
    :CAaBox("m_bbox")
    :uint32("m_transportTimeDelta") -- 0x0200
    :int32("m_typeByte")    -- 0x0204 (m_gameObjectFields->type)
    :int32("unk_0208") -- 0x0208
    :int32("unk_020C") -- 0x020C
    :int32("unk_0210") -- 0x0210
    :int32("unk_0214") -- 0x0214
-- sizeof = 0x218

local vtbl2TypeName = {
    --[0xA33790] = "CGGameObject_C_Type_WorldObj",
    --[0xA33E60] = "CGGameObject_C_Type_TransportBase",
    --[0xA34750] = "CGGameObject_C_Type_TrapDoor",
    [0xA336E0] = "CGGameObject_C_Type_Binder",
    [0xA33848] = "CGGameObject_C_Type_Chair",
    [0xA33900] = "CGGameObject_C_Type_BarberChair",
    [0xA33B80] = "CGGameObject_C_Type_Door",
    [0xA33CF0] = "CGGameObject_C_Type_QuestGiver",
    [0xA33DA8] = "CGGameObject_C_Type_Generic",
    [0xA34368] = "CGGameObject_C_Type_DuelArbiter",
    [0xA33F18] = "CGGameObject_C_Type_Text",
    [0xA33FD0] = "CGGameObject_C_Type_FishingNode",
    [0xA34088] = "CGGameObject_C_Type_Ritual",
    [0xA34140] = "CGGameObject_C_Type_Mailbox",
    [0xA341F8] = "CGGameObject_C_Type_MeetingStone",
    [0xA342B0] = "CGGameObject_C_Type_CapturePoint",
    [0xA34420] = "CGGameObject_C_Type_DungeonDifficulty",
    [0xA344D0] = "CGGameObject_C_Type_DestructibleBuilding",
    [0xA34588] = "CGGameObject_C_Type_GuildBank",
    --[0xA34808] = "CGGameObject_C_Type_Transport",
    --[0xA348C0] = "CGGameObject_C_Type_MapObjTransport",
}

local CGGameObject_C_Type = Struct("CGGameObject_C_Type")
    :ptr("void*", "vtbl") -- 0x00
    :CGGameObject_C_ptr("m_owner") -- 0x04
    :uint32("TypeID") -- 0x08
    :float("Scale") -- 0x0C

local CGGameObject_C_TypeAnimated = Struct("CGGameObject_C_TypeAnimated", CGGameObject_C_Type)
    :int32("m_animationState") -- 0x010
    :int32("m_previousAnimState") -- 0x014
    :uint32("m_sequenceTime") -- 0x018
    :uint32("unkSoundHanle") -- 0x01C
    :paddingTo(0x24)
    :ptr("unk_SoundPtr")
    :paddingTo(0x30) -- 0x10..0x2F

local CGGameObject_C_Type_Chair = Struct("CGGameObject_C_Type_Chair", CGGameObject_C_Type)
    :C3Vector("m_position")
    :int32("unk_1C")   -- 0x1C
    :int32("unk_20")   -- 0x20
    :int32("unk_24")   -- 0x24
    :int32("unk_28")   -- 0x28
    :int32("unk_2C")   -- 0x2C
    :int32("unk_30")   -- 0x30
    :int32("unk_34")   -- 0x34
    :int32("unk_38")   -- 0x38
    :int32("unk_3C")   -- 0x3C
    :int32("unk_40")   -- 0x40
    :int32("unk_44")   -- 0x44
    :int32("unk_48")   -- 0x48

local CGGameObject_C_Type_BarberChair = Struct("CGGameObject_C_Type_BarberChair", CGGameObject_C_Type)
    :C3Vector("m_position")
    :int32("unk_1C")   -- 0x1C
    :int32("unk_20")   -- 0x20
    :int32("unk_24")   -- 0x24
    :int32("unk_28")   -- 0x28
    :int32("unk_2C")   -- 0x2C
    :int32("unk_30")   -- 0x30
    :int32("unk_34")   -- 0x34
    :int32("unk_38")   -- 0x38
    :int32("unk_3C")   -- 0x3C
    :int32("unk_40")   -- 0x40
    :int32("unk_44")   -- 0x44
    :int32("unk_48")   -- 0x48

local CGGameObject_C_Type_GuildBank = Struct("CGGameObject_C_Type_GuildBank", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Mailbox = Struct("CGGameObject_C_Type_Mailbox", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_MeetingStone = Struct("CGGameObject_C_Type_MeetingStone", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_CapturePoint = Struct("CGGameObject_C_Type_CapturePoint", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Door = Struct("CGGameObject_C_Type_Door", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_FishingNode = Struct("CGGameObject_C_Type_FishingNode", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Button = Struct("CGGameObject_C_Type_Button", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Chest = Struct("CGGameObject_C_Type_Chest", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Trap = Struct("CGGameObject_C_Type_Trap", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_AreaDamage = Struct("CGGameObject_C_Type_AreaDamage", CGGameObject_C_TypeAnimated)

local DestructibleStateInfo = Struct("DestructibleStateInfo")
    :ptr("char", "m_modelName")      -- 0x00 GameObjectDisplayInfo.ModelName
    :uint32("m_displayId")           -- 0x04 GameObjectDisplayInfo ID
    :ptr("CMapObjDef", "m_mapObj")   -- 0x08
    :uint8("m_loadPending")          -- 0x0C 1 = wait World__ObjectIsLoaded
    :uint8("m_playRebuildAnim")      -- 0x0D 1 for state 0 / 3
    :uint8("pad_0E")                 -- 0x0E
    :uint8("pad_0F")                 -- 0x0F

local CGGameObject_C_Type_DestructibleBuilding = Struct("CGGameObject_C_Type_DestructibleBuilding", CGGameObject_C_Type)
    :ptr("CMapObjDef", "m_mapObjPtr") -- 0x10
    :DestructibleStateInfo_array("m_states", 4)
    :int32("m_lastStateIndex")  -- 0x54 = 0xFFFFFFFF
    :float("m_baseZ")   -- 0x58
    :uint32("m_animStartMs")   -- 0x5C
    :int32("m_animDurationMs")   -- 0x60
    :int32("unk_64")   -- 0x64
    :ptr("CMapObjDef", "m_mapObjPtr") -- 0x68
    :float("m_currentHeight")   -- 0x6C
    :int32("unk_70")   -- 0x70
    :int32("unkSoundHandler")   -- 0x74
    :int32("unk_78")   -- 0x78
    :int32("unk_7C")   -- 0x7C
    :int32("unk_80")   -- 0x80
    :int32("unk_84")   -- 0x84
    :int32("unk_88")   -- 0x88
    :int32("unk_8C")   -- 0x8C
    :int32("unk_90")   -- 0x90
    :C3Vector("unk_vec3") -- 0x94
    :float("unk_Float")   -- 0xA0
    :int32("unk_A4")   -- 0xA4
    :ptr("DestructibleModelData", "m_dbcRec")   -- 0xA8
    :uint8("unk_waitBoolFlag")   -- 0xAC = 1
    :uint8("unk_AD")   -- 0xAD
    :uint8("unk_AE")   -- 0xAE
    :uint8("unk_AF")   -- 0xAF
-- sizeof = 0xB0

-- waypoint/spawn point for various purposes: a ship (transport) spawn point, event spawn point, ore node etc
local CGGameObject_C_Type_Binder = Struct("CGGameObject_C_Type_Binder", CGGameObject_C_Type)

-- fireplace, torchlight too
local CGGameObject_C_Type_DuelArbiter = Struct("CGGameObject_C_Type_DuelArbiter", CGGameObject_C_TypeAnimated)

-- readable openworld book
local CGGameObject_C_Type_Text = Struct("CGGameObject_C_Type_Text", CGGameObject_C_TypeAnimated)

-- for testing (horde) .go xyz -3708 -2532 70 1
local CGGameObject_C_Type_QuestGiver = Struct("CGGameObject_C_Type_QuestGiver", CGGameObject_C_TypeAnimated)

-- road sign
local CGGameObject_C_Type_Generic = Struct("CGGameObject_C_Type_Generic", CGGameObject_C_TypeAnimated)

-- warlock's healthstone-summoning portal 
local CGGameObject_C_Type_Ritual = Struct("CGGameObject_C_Type_Ritual", CGGameObject_C_TypeAnimated)

-- dungeon/raid diffuculty entrance skull
local CGGameObject_C_Type_DungeonDifficulty = Struct("CGGameObject_C_Type_DungeonDifficulty", CGGameObject_C_Type)
    :int32("unk_10")   -- 0x10
    :int32("unk_14")   -- 0x14
    :int32("unk_18")   -- 0x18
    :int32("unk_1C")   -- 0x1C
    :int32("unk_20")   -- 0x20

local CGGameObject_C_Type_TransportBase = Struct("CGGameObject_C_Type_TransportBase", CGGameObject_C_Type)
    :ptr("CMapObjDef", "m_mapObjDefPtr") -- 0x10
    :TSList("m_passengerList") -- 0x14
    :C3Vector("m_pos") -- 0x20
    :float("m_speed")   -- 0x2C
    :uint32("m_currentTime")   -- 0x30
    :int32("m_loaded")   -- 0x34
    :int32("m_lastSequence")  -- 0x38
    :uint32("m_transportUpdateTime")   -- 0x3C


local ShipPath__Segment = Struct("ShipPath__Segment")
    :uint32("m_startTime") -- 0x00
    :float("m_distance") -- 0x04
    :uint32("m_duration") -- 0x08
-- sizeof = 0x0C

local ShipPath__TimeEvent = Struct("ShipPath__TimeEvent")
    :uint32("m_time") -- 0x00
    :uint32("m_event") -- 0x04
-- sizeof = 0x08

local ShipPath__Leg = Struct("ShipPath__Leg")
    :int32("m_mapId") -- 0x000
    :ptr("m_loadingScreenFuncPtr") -- 0x004
    :float("m_splineLength") -- 0x008
    :C3Vector_array("m_vectors", 25)
    -- TSFixedArray<C3Vector>
    :TSFixedArray("m_vec3Array")
    :int32("unk_144") -- 0x144
    :int32("unk_0148")
    :float_array("m_floats", 25)
    :TSFixedArray("m_unkArray")
    :int32("unk_1BC") -- 0x1BC
    :int32("unk_1C0")
    :int32("unk_1C4")
    :int32("unk_1C8")
    :int32("unk_1CC")
    :int32("unk_1D0")
    -- TSFixedArray<ShipPath__Segment>
    :TSFixedArray("m_segments")
    :int32("unk_1E0") -- 0x1E0
-- sizeof = 0x1E4

local ShipPathParams = Struct("ShipPathParams")
    :int32("m_unkIndex")
    :float_array("m_unkValues", 10)
-- sizeof = 0x2C

local ShipPath = Struct("ShipPath")
    :ShipPathParams_ptr("unk_paramsPtr")
    :int32("m_pathId") -- 0x04
    -- TSFixedArray<ShipPath::Leg>
    :uint32("m_alloc") -- 0x08
    :uint32("m_count") -- 0x0C
    :ptr("ShipPath__Leg", "m_data") -- 0x10
    :int32("unk_014") -- 0x14
    -- TSFixedArray<ShipPath::TimeEvent>
    :uint32("m_alloc") -- 0x18
    :uint32("m_count") -- 0x1C
    :ptr("ShipPath__TimeEvent", "m_data") -- 0x20
    :int32("unk_024") -- 0x24
    :float("m_speed") -- 0x28
    :uint32("m_totalPathTimeMS") -- 0x2C
    :float("m_totalDistance") -- 0x30
    :uint32("m_pausePathTimeMS") -- 0x34
    :uint32("m_timeOffsetMS") -- 0x38
    :uint8("m_waitAtPausePoint") -- 0x3C
    :uint8("m_isPaused") -- 0x3D
    :uint8("unk_3E") -- 0x3E
    :uint8("unk_3F") -- 0x3F
    :paddingTo(0x40)

-- zeppelin between orgri and thunder bluff, battleships in icecrown, etc
local CGGameObject_C_Type_MapObjTransport = Struct("CGGameObject_C_Type_MapObjTransport", CGGameObject_C_Type_TransportBase)
    :ShipPath("m_shipPath")
    :int32("unk_80")   -- 0x80
-- sizeof = 0x84

-- thunder bluff elevator
local CGGameObject_C_Type_Transport = Struct("CGGameObject_C_Type_Transport", CGGameObject_C_Type_TransportBase)
    :ptr("unk_movementSequencePtr")   -- 0x40
    :uint32("m_movementCount") -- 0x44
    :uint32("m_movementIndex") -- 0x48
    :ptr("unk_rotationPtr")   -- 0x4C
    :uint32("m_rotationKeyCount")     -- 0x50
    :uint32("m_rotationKeyIndex")     -- 0x54
    :int32("m_currentSequence")  -- 0x58
    :int32("m_stateChangeTime")   -- 0x5C
    :int32("unk_60")   -- 0x60
-- sizeof = 0x64



local address = 0x51f838 -- at CGGameUI__HandleObjectTrackChange
debugger_onBreakpoint = nil
function onBreakpoint()    
    local addr, objectType = GetCGObjectAddr(readQword(0x00bd07a0)) -- mouseover guid
    if addr and objectType == "gameobject" then
        loadStructToTable(CGGameObject_C, addr)

        local gameObjectClassName = vtbl2TypeName[readPointer(readPointer(addr + 0x1A0))]
        if gameObjectClassName then
            loadStructToTable(StructRegistry[gameObjectClassName], readPointer(addr + 0x1A0))
        end

        debugger_onBreakpoint = nil
        debug_removeBreakpoint(address)
        debug_continueFromBreakpoint(co_run)
        return 1
    end

    local playerAddr, _ = GetCGObjectAddr(readQword(0xC79D10)) -- local player GUID from game connection class
    local playerTransportGUIDoffset = 0x790
    local addr, objectType = GetCGObjectAddr(readQword(playerAddr + playerTransportGUIDoffset))
    if addr and objectType == "gameobject" then
        loadStructToTable(CGGameObject_C, addr)
        local transportVtblAddr = readPointer(readPointer(addr + 0x1A0))
        if transportVtblAddr == 0xA34808 then
            loadStructToTable(CGGameObject_C_Type_Transport, readPointer(addr + 0x1A0))
        end
        if transportVtblAddr == 0xA348C0 then
            loadStructToTable(CGGameObject_C_Type_MapObjTransport, readPointer(addr + 0x1A0))
        end
    end

    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint

