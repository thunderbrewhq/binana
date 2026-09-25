-- #include "StructDef.lua"
-- #include "stdlib.lua"

local CMapObjGroup = Struct("CMapObjGroup")
    :int32("objectIndex")                                   -- 0x00
    :ptr("VBBList_Block", "vertsBlock")                     -- 0x04
    :ptr("VBBList_Block", "transparencyVertsBlock")         -- 0x08
    :ptr("VBBList_Block", "indicesBlock")                   -- 0x0C
    :ptr("VBBList_Block", "liquidVertsBlock")               -- 0x10
    :ptr("VBBList_Block", "liquidIndicesBlock")             -- 0x14
    :float("timer")                                         -- 0x18
    :ptr("void", "unk_1C")                                  -- 0x1C
    :int32("unk_20")                                        -- 0x20
    :int32("unk_24")                                        -- 0x24
    :int32("unk_28")                                        -- 0x28
    :int16_array("unk_2C", 2)                               -- 0x2C
    :int32("flags")                                         -- 0x30
    :CAaBox("bbox")                                         -- 0x34
    :float("distToCamera")                                  -- 0x4C
    :int32("portalStart")                                   -- 0x50
    :int32("portalCount")                                   -- 0x54
    :int32("fogs")                                          -- 0x58
    :uint16("transparencyBatchesCount")                     -- 0x5C
    :uint16("intBatchCount")                                -- 0x5E
    :int32("extBatchCount")                                 -- 0x60
    :ptr("void", "CAaBspNodePtr1")                          -- 0x64
    :ptr("void", "CAaBspNodePtr2")                          -- 0x68
    :ptr("uint16", "nodeFaceIndices")                       -- 0x6C
    :int32("bspNodesCount")                                 -- 0x70
    :int32("nodeFaceIndicesCount")                          -- 0x74
    :int32("unk_78")                                        -- 0x78
    :int32("unk_7C")                                        -- 0x7C
    :int32("unk_80")                                        -- 0x80
    :int32("unk_84")                                        -- 0x84
    :int32("unk_88")                                        -- 0x88
    :int32("unk_8C")                                        -- 0x8C
    :int32("unk_90")                                        -- 0x90
    :int32("unk_94")                                        -- 0x94
    :int32("unk_98")                                        -- 0x98
    :int32("unk_9C")                                        -- 0x9C
    :int32("unk_A0")                                        -- 0xA0
    :int32("unk_A4")                                        -- 0xA4
    :int32("unk_A8")                                        -- 0xA8
    :int32("unk_AC")                                        -- 0xAC
    :CAaBox("bbox2")                                        -- 0xB0
    :int32("unk_C8")                                        -- 0xC8
    :int32("unkFlags")                                      -- 0xCC
    :int32("unk_D0")                                        -- 0xD0
    :int32("minimapTag")                                    -- 0xD4
    :ptr("char", "groupName")                               -- 0xD8
    :ptr("SMOPoly", "polyList")                             -- 0xDC
    :ptr("uint16", "indices")                               -- 0xE0
    :int32("unk_E4")                                        -- 0xE4
    :ptr("C3Vector", "vertexList")                          -- 0xE8
    :ptr("C3Vector", "normalList")                          -- 0xEC
    :ptr("C2Vector", "textureVertexList")                   -- 0xF0
    :int32("unk_F4")                                        -- 0xF4
    :ptr("SMOBatch", "batchList")                           -- 0xF8
    :int32("unk_FC")                                        -- 0xFC
    :int32("unk_100")                                       -- 0x100
    :uint16_ptr("doodadRefList")                            -- 0x104
    :ptr("CImVector", "colorVertexList")                    -- 0x108
    :ptr("CImVector", "colorVertexListExtra")               -- 0x10C
    :int32("unk_110")                                       -- 0x110
    :C2iVector("liquidVerts")                               -- 0x114
    :C2iVector("liquidTiles")                               -- 0x11C
    :C3Vector("liquidCorner")                               -- 0x124
    :int32("luquidMaterialId")                              -- 0x130
    :ptr("SMOLiquidVert", "liquidVertexList")               -- 0x134
    :ptr("SMOLTile", "liquidTileList")                      -- 0x138
    :float("liquidHeight")                                  -- 0x13C
    :int32("unk_140")                                       -- 0x140
    :int32("unk_144")                                       -- 0x144
    :int32("unkFlag")                                       -- 0x148
    :int32("unk_14C")                                       -- 0x14C
    :int32("polyListSize")                                  -- 0x150
    :int32("indicesCount")                                  -- 0x154
    :int32("unk_158")                                       -- 0x158
    :int32("vertexListCount")                               -- 0x15C
    :int32("normalListCount")                               -- 0x160
    :int32("textureVertexListCount")                        -- 0x164
    :int32("unk_168")                                       -- 0x168
    :int32("batchListCount")                                -- 0x16C
    :int32("unk_170")                                       -- 0x170
    :int32("doodadRefListCount")                            -- 0x174
    :int32("colorVertexListSize")                           -- 0x178
    :int32("colorVertexListExtraSize")                      -- 0x17C
    :int32("wmoGroupId")                                    -- 0x180
    :ptr("void", "filePtr")                                 -- 0x184
    :int32("fileSize")                                      -- 0x188
    :ptr("CMapObj", "parent")                               -- 0x18C
    :int32("unk_190")                                       -- 0x190
    :ptr("CAsyncObject", "asyncObjPtr")                     -- 0x194
    :flag32("unkLoadedFlag")                                 -- 0x198
    :int32("unkIndexMin1")                                  -- 0x19C
    :int32("unkIndexMax1")                                  -- 0x1A0
    :uint16("unkIndexMin2")                                 -- 0x1A4
    :uint16("unkIndexMax2")                                 -- 0x1A6
    :TSList("m_list")                                       -- 0x1A8
    :TSLink("m_link")                                       -- 0x1B4

local address = 0x0078261f -- at CMap__QueryAreaId
debugger_onBreakpoint = nil
function onBreakpoint()
    local groupCount = readPointer(readPointer(ESI + 0xF4) + 0x1F4)
    local groupArray = readPointer(ESI + 0xF4) + 0x1F8
    local CMapObjGroupSize = 0x1BC
    for i = 0, groupCount, 1 do
      loadStructToTable(CMapObjGroup, readPointer(groupArray) + CMapObjGroupSize * i)
    end
    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint