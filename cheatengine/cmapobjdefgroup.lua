-- #include "cmapbaseobj.lua"

local CMapObjDefGroup = Struct('CMapObjDefGroup', CMapBaseObj)
  :embed('bbox', CAaBox)
  :embed('sphere', CAaSphere)
  :field('unk_4C', 'float')
  :field('groupNum', 'uint32')
  :field('unkFlags', 'uint32')
  :field('unk_58', 'int32')
  :embed('ambientColor', CImVector)
  :field('unk_60', 'int32')
  :field('unk_64', 'int32')
  :field('unk_68', 'int32')
  :embed('unkExplicitList', TSExplicitList)
  :embed('doodadDefLinkList', TSExplicitList)
  :embed('mapEntityLinkList', TSExplicitList)
  :embed('unkExplicitList', TSExplicitList)
  :embed('unkExplicitList', TSExplicitList)
  :field('unk_A8', 'int32')
  :field('unk_AC', 'int32')
  :field('unk_B0', 'int32')
  :field('unk_B4', 'int32')
  :field('unk_B8', 'int32')
  :field('unk_BC', 'int32')

local address = 0x0078261f -- at CMap__QueryAreaId
debugger_onBreakpoint = nil
function onBreakpoint()
    local defGroupsNum = readPointer(ESI + 0x124)
    local defGroupsDataPtr = ESI + 0x128
    local CMapObjDefGroupSize = 0xC0
    for i = 0, defGroupsNum, 1 do
      loadStructToTable(CMapObjDefGroup, readPointer(readPointer(defGroupsDataPtr)) + CMapObjDefGroupSize * i)
    end
    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint