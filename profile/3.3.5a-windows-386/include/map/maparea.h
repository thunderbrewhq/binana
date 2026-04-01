#ifndef MAP_MAP_AREA_H
#define MAP_MAP_AREA_H

DECLARE_STRUCT(CMapArea);
DECLARE_STRUCT(CMapAreaTexture);
DECLARE_STRUCT(CMapAreaLink);
DECLARE_STRUCT(CMapAreaChunkLink);

#include "map/adt_chunks.h"
#include "map/mapchunk.h"
#include "storm/array.h"
#include "storm/list.h"
#include "tempest/vector.h"
#include "texture/texture.h"

STORM_TS_GROWABLE_ARRAY(CMapAreaTexture);
struct CMapAreaTexture {
    char*     textureName;
    CTexture* texture;
};

STORM_TS_LIST(CMapAreaLink);
struct CMapAreaLink {
    uint32_t            objectIndex; // 0x00
    CMapArea*           owner;       // 0x04
    void*               ref;         // 0x08
    TSLink_CMapAreaLink refLink;     // 0x0C - 0x14
    TSLink_CMapAreaLink ownerLink;   // 0x14 - 0x1C
};

STORM_TS_LIST(CMapAreaChunkLink);
struct CMapAreaChunkLink {
    uint32_t                 objectIndex; // 0x00
    CMapChunk*               owner;       // 0x04
    CMapArea*                ref;         // 0x08
    TSLink_CMapAreaChunkLink refLink;     // 0x0C - 0x14
    TSLink_CMapAreaChunkLink ownerLink;   // 0x14 - 0x1C
};

struct CMapArea {
    void**    vtable;
    uint32_t  objectIndex;
    uint16_t  type;
    uint16_t  refCount;
    uint32_t  unk_0C;
    CMapArea* prev;
    CMapArea* next;

    TSExplicitList_CMapAreaLink linkList;

    C3Vector bottomRight;
    C3Vector topLeft;
    C3Vector topLeft2;

    C2iVector index;
    C2iVector tileChunkIndex;

    TSGrowableArray_CMapAreaTexture textures;

    SMMapHeader* header;

    int32_t       unk_6C;
    CAsyncObject* asyncObject;

    TSExplicitList_CMapAreaChunkLink chunkLinkList;

    void*   filePtr;
    int32_t fileSize;

    SMChunkInfo* chunkInfo;
    int32_t      unk_8C;
    SMDoodadDef* doodadDef;
    SMMapObjDef* mapObjDef;
    int32_t      doodadDefCount;
    int32_t      mapObjDefCount;
    char*        m2FileNames;
    char*        wmoFileNames;
    uint32_t*    modelFilenamesOffsets;
    uint32_t*    wmoFilenamesOffsets;
    int16_t*     flyingBbox;
    int32_t*     textureFlags;
    uint8_t*     unk_B8; // MH20

    CMapChunk* mapChunks[256];
};
#endif
