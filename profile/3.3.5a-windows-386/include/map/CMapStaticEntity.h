#ifndef CMAPSTATICENTITY_H
#define CMAPSTATICENTITY_H

DECLARE_STRUCT(CMapStaticEntity);

#include "system/types.h"
#include "tempest/vector.h"
#include "tempest/box.h"
#include "storm/list.h"
#include "map/CMapBaseObj.h"

typedef struct CMapStaticEntityMapChunkLink CMapStaticEntityMapChunkLink;
STORM_TS_LIST(CMapStaticEntityMapChunkLink);
struct CMapStaticEntityMapChunkLink
{
    uint32_t objectIndex; //0x00
    CMapStaticEntity* owner; //0x04
    void* ref; //0x08 //could be CMapChunk* or CMapObjDefGroup*
    TSLink_CMapStaticEntityMapChunkLink refLink; //0x0C - 0x14
    TSLink_CMapStaticEntityMapChunkLink ownerLink; //0x14 - 0x1C
};

struct CMapStaticEntity
{
    void** vtable; //0x00
    int32_t objectIndex; //0x04
    uint16_t type; //0x08
    uint16_t refCount; //0x0A
    int32_t unk_C; //0x0C
    CMapStaticEntity* prev; //0x10
    CMapStaticEntity* next; //0x14
    
    TSExplicitList_CMapStaticEntityMapChunkLink linkList;
    

    int32_t unk_024; //0x24
    uint32_t unkFlags_28; //0x28
    int32_t unkCounter; //0x2C    
    float unk_030; //0x30
    void* unk_m2Model_034; //0x34    
    C3Vector vec1;
    float unk_044; //0x44
    CAaBox bbox;
    C3Vector vec2;    
    C3Vector position;
    float scale; //0x78    
    int32_t unk_07C; //0x7C
    int32_t unk_080; //0x80    
    CImVector m2AmbietColor; //0x84    
    CImVector m2DiffuseColor; //0x88
    float unk_08C; //0x8C
};

#endif