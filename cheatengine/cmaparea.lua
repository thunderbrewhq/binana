-- #include "cmapbaseobj.lua"

local CMapAreaTexture = Struct("CMapAreaTexture")
    :uint32("memoryCapacity")
    :uint32("count")
    :ptr("memoryPtr")

local CMapArea = Struct("CMapArea", CMapBaseObj)
    :C3Vector("bottomRight")
    :C3Vector("topLeft")
    :C3Vector("topLeft2")
    :C2iVector("index")
    :C2iVector("tileChunkIndex")
    :TSGrowableArray("m_textures")
    :ptr("SMMapHeader", "header")
    :field("unk_6C", "int32")
    :ptr("CAsyncObject", "asyncObject")
    :TSList("chunkLinkList")
    :ptr("filePtr")
    :int32("fileSize")
    :ptr("SMChunkInfo", "chunkInfo")
    :field("unk_8C", "int32")
    :ptr("SMDoodadDef", "doodadDef")
    :ptr("SMMapObjDef", "mapObjDef")
    :int32("doodadDefCount")
    :int32("mapObjDefCount")
    :ptr("m2FileNames")
    :ptr("wmoFileNames")
    :ptr("modelFilenamesOffsets")
    :ptr("wmoFilenamesOffsets")
    :ptr("flyingBbox")
    :ptr("textureFlags")
    :ptr("unk_B8")
    :ptrArray("CMapChunk", "mapChunk", 256)

local address = 0x007b5c18 -- at CMap__PreUpdateAreas
debugger_onBreakpoint = nil
function onBreakpoint()
    loadStructToTable(CMapArea, ESI)
    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint