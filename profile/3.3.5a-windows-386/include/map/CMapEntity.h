#ifndef CMAPENTITY_H
#define CMAPENTITY_H

DECLARE_STRUCT(CMapEntity);

#include "system/types.h"
#include "tempest/vector.h"
#include "tempest/box.h"
#include "storm/list.h"
#include "map/CMapBaseObj.h"

typedef struct CMapEntityMapChunkLink CMapEntityMapChunkLink;
STORM_TS_LIST(CMapEntityMapChunkLink);
struct CMapEntityMapChunkLink
{
    uint32_t objectIndex; //0x00
    CMapEntity* owner; //0x04
    void* ref; //0x08 //could be CMapChunk* or CMapObjDefGroup*
    TSLink_CMapEntityMapChunkLink refLink; //0x0C - 0x14
    TSLink_CMapEntityMapChunkLink ownerLink; //0x14 - 0x1C
};

struct CMapEntity
{
    //CMapBaseObj fields
    void** vtable; //0x00
    int32_t objectIndex; //0x04
    uint16_t type; //0x08
    uint16_t refCount; //0x0A
    int32_t unk_C; //0x0C
    CMapEntity* prev; //0x10
    CMapEntity* next; //0x14
    
    TSExplicitList_CMapEntityMapChunkLink linkList;
    //end

    //CMapStaticEntity fields
    int32_t unk_024; //0x24
    uint32_t unkFlags_28; //0x28
    int32_t unkCounter; //0x2C    
    float unk_030; //0x30
    void* unk_m2Model_034; //0x34    
    C3Vector vec1;
    float unk_044; //0x44
    CAaBox bboxStaticEntity;
    C3Vector vec2;    
    C3Vector position;
    float scale; //0x78    
    int32_t unk_07C; //0x7C
    int32_t unk_080; //0x80    
    CImVector m2AmbietColor; //0x84    
    CImVector m2DiffuseColor; //0x88
    float unk_08C; //0x8C
    //end

    //CMapEntity fields
    int32_t unk_090; //0x90
    int32_t unk_094; //0x94
    uint64_t guid; //0x98
    int32_t unk_0A0; //0xA0
    int32_t unk_0A4; //0xA4

    int32_t unk_0A8; //0xA8
    int32_t unk_0AC; //0xAC
    int32_t unk_0B0; //0xB0
    int32_t unk_0B4; //0xB4
    int32_t unk_0B8; //0xB8
    int32_t unk_0BC; //0xBC
    CImVector ambientTarget;
    float dirLightScaleTarget;
    int32_t unk_0C8; //0xC8
    int32_t unk_0CC; //0xCC
    //end
};

#endif