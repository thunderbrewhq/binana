#ifndef CMAPAREA_H
#define CMAPAREA_H

DECLARE_STRUCT(CMapArea);
DECLARE_STRUCT(CMapChunk);
DECLARE_STRUCT(CMapAreaTexture);

struct CMapAreaTexture
{
    char* textureName;
    CTexture* texture;
};

struct CMapChunk;

#include "async/object.h"
#include "map/ADTchunks.h"
#include "storm/array.h"
#include "texture/texture.h"
#include "map/CMapBaseObj.h"
#include "map/CMapBaseObjLink.h"
#include "map/CMapDoodadDef.h"
#include "map/CMapObjDef.h"

STORM_TS_GROWABLE_ARRAY(CMapAreaTexture);

typedef struct CMapAreaLink CMapAreaLink;
STORM_TS_LIST(CMapAreaLink);
struct CMapAreaLink
{
    uint32_t objectIndex; //0x00
    CMapArea* owner; //0x04
    void* ref; //0x08
    TSLink_CMapAreaLink refLink; //0x0C - 0x14
    TSLink_CMapAreaLink ownerLink; //0x14 - 0x1C
};

typedef struct CMapAreaChunkLink CMapAreaChunkLink;
STORM_TS_LIST(CMapAreaChunkLink);
struct CMapAreaChunkLink
{
    uint32_t objectIndex; //0x00
    CMapChunk* owner; //0x04
    CMapArea* ref; //0x08
    TSLink_CMapAreaChunkLink refLink; //0x0C - 0x14
    TSLink_CMapAreaChunkLink ownerLink; //0x14 - 0x1C
}; 

struct CMapArea
{
    void** vtable;
    uint32_t objectIndex;
    uint16_t type;
    uint16_t refCount;
    uint32_t unk_0C;
    CMapArea* perv;
    CMapArea* next;

    TSExplicitList_CMapAreaLink linkList;

    C3Vector bottomRight;
    C3Vector topLeft;
    C3Vector topLeft2;

    C2iVector index;
    C2iVector tileChunkIndex;

    TSGrowableArray_CMapAreaTexture textures;

    SMMapHeader* header;

    int32_t unk_6C;
    CAsyncObject* asyncObject;
    
    TSExplicitList_CMapAreaChunkLink chunkLinkList;
    
    void* filePtr;
    int32_t fileSize;
    
    SMChunkInfo* chunkInfo;
    int32_t unk_8C;
    SMDoodadDef* doodadDef;
    SMMapObjDef* mapObjDef;
    int32_t doodadDefCount;
    int32_t mapObjDefCount;
    char* m2FileNames;
    char* wmoFileNames;
    uint32_t* modelFilenamesOffsets;
    uint32_t* wmoFilenamesOffsets;
    int16_t* flyingBbox;
    int32_t* textureFlags;
    uint8_t* unk_B8; //MH20
    
    CMapChunk* mapChunks[256];
};


typedef struct CMapChunkLink CMapChunkLink;
STORM_TS_LIST(CMapChunkLink);
struct CMapChunkLink
{
    uint32_t objectIndex; //0x00
    CMapChunk* owner; //0x04
    CMapArea* ref; //0x08
    TSLink_CMapChunkLink refLink; //0x0C - 0x14
    TSLink_CMapChunkLink ownerLink; //0x14 - 0x1C
};

typedef struct CMapChunkDoodadDefLink CMapChunkDoodadDefLink;
STORM_TS_LIST(CMapChunkDoodadDefLink);
struct CMapChunkDoodadDefLink
{
    uint32_t objectIndex; //0x00
    CMapDoodadDef* owner; //0x04
    CMapChunk* ref; //0x08
    TSLink_CMapChunkDoodadDefLink refLink; //0x0C - 0x14
    TSLink_CMapChunkDoodadDefLink ownerLink; //0x14 - 0x1C
};

typedef struct CMapChunkMapObjDefLink CMapChunkMapObjDefLink;
STORM_TS_LIST(CMapChunkMapObjDefLink);
struct CMapChunkMapObjDefLink
{
    uint32_t objectIndex; //0x00
    CMapObjDef* owner; //0x04
    CMapChunk* ref; //0x08
    TSLink_CMapChunkMapObjDefLink refLink; //0x0C - 0x14
    TSLink_CMapChunkMapObjDefLink ownerLink; //0x14 - 0x1C
};

typedef struct CChunkLiquid CChunkLiquid;
STORM_TS_LIST(CChunkLiquid);

struct CMapChunk
{
    void** vtable;
    uint32_t objectIndex;
    uint16_t type;
    uint16_t refCount;
    uint32_t unk_0C;
    CMapChunk* prev;
    CMapChunk* next;

    TSExplicitList_CMapChunkLink linkList;

    C2iVector aIndex;
    C2iVector sOffset;
    C2iVector cOffset;

    C3Vector center;
    float radius;
    CAaBox bbox;
    C3Vector bottomRight;
    C3Vector topLeft;
    C3Vector topLeftCoords;
    float distToCamera;
    CAaBox bbox2;
    
    void* detailDoodadInst;
    void* renderChunk;

    int32_t unk_AC;
    int32_t areaId;
    int32_t unk_B4;
    int32_t unk_B8;
    int32_t unk_BC;
    int32_t unk_C0;
    
    TSExplicitList_CMapChunkDoodadDefLink doodadDefLinkList;
    TSExplicitList_CMapChunkMapObjDefLink mapObjDefLinkList;    
    
    int32_t TSExplicitList__m_linkoffset_DC;
    void* TSExplicitList__ptr_E0;
    void* TSExplicitList__ptr2_E4;
    
    // Light
    int32_t TSExplicitList__m_linkoffset_E8;
    void* TSExplicitList__ptr_EC;
    void* TSExplicitList__ptr2_F0;

    // CMapSoundEmitter
    int32_t TSExplicitList__m_linkoffset_F4;
    void* TSExplicitList__ptr_F8;
    void* TSExplicitList__ptr2_FC;

    // CChunkLiquid
    TSExplicitList_CChunkLiquid liquidChunkLinkList;

    uint8_t* chunkInfoBeginPtr;
    SMChunk* header;
    uint8_t* lowQualityTexMap;
    uint8_t* predTexture;
    float* vertices;
    uint32_t* vertexShading;
    int8_t* normals;
    uint8_t* shadowMap;
    SMLayer* layers;
    uint8_t* additionalShadowmap;
    uint8_t* MCRF_ptr;
    SMLiquidChunk* liquid;
    CWSoundEmitter* soundEmitters;

    // liquid related fields
    int32_t unk_140;
    int32_t unk_144;
    int32_t unk_148;
    int32_t unk_14C;
    int32_t unk_150;
    int32_t unk_154;
};

#endif