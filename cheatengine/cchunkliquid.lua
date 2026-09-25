-- #include "StructDef.lua"
-- #include "stdlib.lua"

local CChunkLiquid = Struct("CChunkLiquid")
    :int32("objectIndex") -- 0x000
    :int32("unk_004") -- 0x004
    :int32("unk_008") -- 0x008
    :C3Vector("topLeftCoords") -- 0x00C
    :C3Vector("center") -- 0x018
    :float("radius")  -- 0x024
    :C2Vector("height") -- 0x028
    :float("resPurgeTimer") -- 0x030
    :C2iVector("tileBegin") -- 0x034
    :C2iVector("tileEnd")   -- 0x03C
    :ptr("ptr_to_CClientLiquidEnvironment") -- 0x044
    :ptr("unk_048") -- 0x048 sound ??
    :int32("unk_04C") -- 0x04C
    :flag32("unk_050") -- 0x050
    :ptr("tiles")  -- 0x054
    :ptr("liquidInstPtr") -- 0x058
    :ptr("CMapChunk", "owner") -- 0x05C
    :TSLink("m_link1")   -- 0x060
    :ptr("unk_068") -- 0x068
    :ptr("unk_06C") -- 0x06C
    :TSLink("m_link2") -- 0x070
    :C3Vector_array("verts", 81) -- 0x078 (81 * 12 = 0x3CC)
-- sizeof: 0x444

local address = 0x00795e25 -- at CWorldScene__LocateViewer3
debugger_onBreakpoint = nil
function onBreakpoint()
    local chunkLiquidPtr = readPointer(ECX + 0x108)
    loadStructToTable(CChunkLiquid, chunkLiquidPtr)
    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint
