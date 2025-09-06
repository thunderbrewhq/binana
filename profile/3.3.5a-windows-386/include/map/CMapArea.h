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
#include "ADTchunks.h"
#include "storm/array.h"
#include "texture/texture.h"

STORM_TS_GROWABLE_ARRAY(CMapAreaTexture);

struct CMapArea
{
    void** vtable;
    int32_t objectIndex;
    uint16_t flags;
    uint16_t pad_0A;
    int32_t unk_0C;

    CMapArea* perv;
    CMapArea* next;

    int32_t TSExplicitList__m_linkoffset_18;
    void* TSExplicitList__ptr_1C;
    void* TSExplicitList__ptr2_20;

    C3Vector bottomRight;
    C3Vector topLeft;
    C3Vector topLeft2;

    C2iVector index;
    C2iVector tileChunkIndex;

    TSGrowableArray_CMapAreaTexture textures;

    SMMapHeader* header;

    int32_t unk_6C;
    CAsyncObject* asyncObject;
    
    int32_t TSExplicitList__m_linkoffset_unk_74;
    void* TSExplicitList__ptr_unk_78;
    void* TSExplicitList__ptr2_unk_7C;
    
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
    
    CMapChunk mapChunks[256];
};

struct CMapChunk
{
    void** vtable;
    int32_t objectIndex;
    int32_t unk_08;

    int32_t TSExplicitList__m_linkoffset_0C;
    void* TSExplicitList__ptr1_10;
    void* TSExplicitList__ptr2_14;

    int32_t TSExplicitList__m_linkoffset_18;
    void* TSExplicitList__ptr1_1C;
    void* TSExplicitList__ptr2_20;

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
    
    void* detailDoodadInstPtr;
    void* renderChunkPtr;

    int32_t unk_AC;
    int32_t areaId;
    int32_t unk_B4;
    int32_t unk_B8;
    int32_t unk_BC;
    int32_t unk_C0;
    
    // CMapDoodadDef
    int32_t TSExplicitList__m_linkoffset_C4;
    void* TSExplicitList__ptr_C8;
    void* TSExplicitList__ptr2_CC;
    
    // CMapObjDef
    int32_t TSExplicitList__m_linkoffset_D0;
    void* TSExplicitList__ptr_D4;
    void* TSExplicitList__ptr2_D8;
    
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
    int32_t TSExplicitList__m_linkoffset_100;
    void* TSExplicitList__ptr_104;
    void* TSExplicitList__ptr2_108;

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