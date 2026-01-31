-- #include "cmapbaseobj.lua"

local CMapAreaTexture = Struct("CMapAreaTexture")
    :field("memoryCapacity", "uint32")
    :field("count", "uint32")
    :hex("memoryPtr", "uint32")

local CMapArea = Struct('CMapArea', CMapBaseObj)
    :embed('bottomRight', C3Vector)
    :embed('topLeft', C3Vector)
    :embed('topLeft2', C3Vector)
    :embed('index', C2iVector)
    :embed('tileChunkIndex', C2iVector)
    :embed("textures", TSGrowableArray)
    :ptr('SMMapHeader', 'header')
    :field('unk_6C', 'int32')
    :ptr('CAsyncObject', 'asyncObject')
    :embed('chunkLinkList', TSExplicitList)
    :ptr('filePtr')
    :field('fileSize', 'int32')
    :ptr('SMChunkInfo', 'chunkInfo')
    :field('unk_8C', 'int32')
    :ptr('SMDoodadDef', 'doodadDef')
    :ptr('SMMapObjDef', 'mapObjDef')
    :field('doodadDefCount', 'int32')
    :field('mapObjDefCount', 'int32')
    :ptr('m2FileNames')
    :ptr('wmoFileNames')
    :ptr('modelFilenamesOffsets')
    :ptr('wmoFilenamesOffsets')
    :ptr('flyingBbox')
    :ptr('textureFlags')
    :ptr('unk_B8')
    :ptrArray('mapChunk', 256)

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