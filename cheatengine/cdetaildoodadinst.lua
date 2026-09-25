-- #include "StructDef.lua"
-- #include "stdlib.lua"

local CDetailDoodadGeomVertex = Struct("CDetailDoodadGeomVertex")
    :uint16("unk_00")                                   -- 0x00
    :uint16("unk_02")                                   -- 0x02
    :uint32("unk_04")                                   -- 0x04
    :C3Vector("pos")                                    -- 0x08
    :float("angle")                                     -- 0x14
    :float("scale")                                     -- 0x18
    :C3Vector("unkVec")                                 -- 0x1C
    :CImVector("color")                                 -- 0x28
-- sizeof: 0x2C

local CDetailDoodadGeom = Struct("CDetailDoodadGeom")
    :ptr("CTexture", "texture")                         -- 0x00
    :int32("unkVertexCount")                            -- 0x04
    :int32("unkIndexCount")                             -- 0x08
    :ptr("unkVertBufStream")                            -- 0x0C
    :ptr("unkIdxBufStream")                             -- 0x10
    :TSGrowableArray("m_DetailDoodadGeomVertexArray")   -- 0x14

local CDetailDoodadInst = Struct("CDetailDoodadInst")
    :int32("objectIndex")                               -- 0x00
    :CDetailDoodadGeom_array("geom", 4)                 -- 0x04
    :int32("unkCounter")                                -- 0xA4
    :ptr("CMapChunk", "mapChunkOwner")                  -- 0xA8
    :int32("unk_09C")                                   -- 0x9C
    :int32("unk_0A0")                                   -- 0xA0
-- sizeof: 0xB4

local address = 0x00795e25 -- at CWorldScene__LocateViewer3
debugger_onBreakpoint = nil
function onBreakpoint()
    local detailDoodadInstPtr = readPointer(ECX + 0xa4)
    loadStructToTable(CDetailDoodadInst, detailDoodadInstPtr)

    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint