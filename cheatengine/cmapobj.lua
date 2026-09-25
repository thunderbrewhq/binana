-- #include "StructDef.lua"
-- #include "stdlib.lua"

local CMapObj = Struct("CMapObj")
    :int32("objectIndex")                                   -- 0x000
    :int32("unk_04")                                        -- 0x004
    :TSLink("m_link1")
    :TSLink("m_link2")
    :int32("unk_18")                                        -- 0x018
    :string("m_wmoName", 260)                               -- 0x01C
    :ptr("SMOHeader", "header")                             -- 0x120
    :ptr("char", "textureNameList")                         -- 0x124
    :ptr("char", "groupNameList")                           -- 0x128
    :ptr("char", "skybox")                                  -- 0x12C
    :ptr("SMOGroupInfo", "groupInfo")                       -- 0x130
    :ptr("C3Vector", "portalVertexList")                    -- 0x134
    :ptr("SMOPortal", "portalList")                         -- 0x138
    :ptr("SMOPortalRef", "portalRefList")                   -- 0x13C
    :ptr("C3Vector", "visBlockVertList")                    -- 0x140
    :ptr("SMOVisibleBlock", "visBlockList")                 -- 0x144
    :ptr("SMOLight", "lightList")                           -- 0x148
    :ptr("SMODoodadSet", "doodadSetList")                   -- 0x14C
    :ptr("char", "doodadNameList")                          -- 0x150
    :ptr("SMODoodadDef", "doodadDefList")                   -- 0x154
    :ptr("SMOFog", "fogList")                               -- 0x158
    :ptr("C4Plane", "convexVolumePlanes")                   -- 0x15C
    :ptr("SMOMaterial", "materialList")                     -- 0x160
    :int32("texturesSize")                                  -- 0x164
    :int32("groupNameSize")                                 -- 0x168
    :int32("groupInfoCount")                                -- 0x16C
    :int32("planeVertCount")                                -- 0x170
    :int32("portalsCount")                                  -- 0x174
    :int32("portalRefCount")                                -- 0x178
    :int32("visBlockVertCount")                             -- 0x17C
    :int32("visBlockCount")                                 -- 0x180
    :int32("ligtsCount")                                    -- 0x184
    :int32("doodadSetCount")                                -- 0x188
    :int32("doodadNameSize")                                -- 0x18C
    :int32("doodadDefCount")                                -- 0x190
    :int32("fogsCount")                                     -- 0x194
    :int32("convexVolumePlaneCount")                        -- 0x198
    :int32("materialsCount")                                -- 0x19C
    :CImVector("color")                                     -- 0x1A0
    :int32("unk_1A4")                                       -- 0x1A4
    :CAaBox("bbox")                                         -- 0x1A8
    :float("distToCamera")                                  -- 0x1C0
    :int32("unk_1C4")                                       -- 0x1C4
    :int32("unk_1C8")                                       -- 0x1C8
    :ptr("void", "pWmoData")                                -- 0x1CC
    :int32("wmoFileSize")                                   -- 0x1D0
    :int32("refCount")                                      -- 0x1D4
    :float("flushTimer")                                    -- 0x1D8
    :ptr("CAsyncObject", "asyncObject")                     -- 0x1DC
    :int32("isGroupLoaded")                                 -- 0x1E0
    :int32("unk_1E4")                                       -- 0x1E4
    :TSList("m_mapObjGroupList")                            -- 0x1E8
    :int32("mapObjGroupCount")                              -- 0x1F4
    :ptrArray("CMapObjGroup", "mapObjGroupArray", 512)      -- 0x1F8


local address = 0x0078261f -- at CMap__QueryAreaId
debugger_onBreakpoint = nil
function onBreakpoint()
    loadStructToTable(CMapObj, readPointer(ESI + 0xF4))
    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint