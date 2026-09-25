-- #include "cmapbaseobj.lua"

local CMapObjDef = Struct("CMapObjDef", CMapBaseObj)
    :ptr("unk_24")
    :ptr("unk_28")
    :ptr("unk_2C")
    :ptr("unk_30")
    :ptr("unk_34")
    :field("unk_38", "int32")
    :C3Vector("position")
    :CAaBox("bbox")
    :CAaSphere("sphere")
    :C44Matrix("mat")
    :C44Matrix("invMat")
    :field("unk_F0", "int32")
    :ptr("CMapObj", "owner")
    :field("unk_F8", "int32")
    :field("unkFlags", "uint32")
    :field("unk_100", "int32")
    :field("unk_104", "int32")
    :field("unk_108", "int32")
    :field("unk_10C", "int32")
    :field("unk_110", "int32")
    :TSList("mapObjDefGroupLinkList")
    :TSGrowableArray("defGroups") -- if CMapObjDef has groups
    :ptr("unk_130")
    :TSGrowableArray("unkGrowableArray")
    :CImVector("color")
    :field("unk_148", "int32")
    :field("unk_14C", "int32")
    :field("unk_150", "int32")
    :ptr("unk_154")

local address = 0x0078261f -- at CMap__QueryAreaId
debugger_onBreakpoint = nil
function onBreakpoint()
    loadStructToTable(CMapObjDef, ESI)
    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint