#ifndef CMAPDOODADDEF_H
#define CMAPDOODADDEF_H

DECLARE_STRUCT(CMapDoodadDef);

#include "tempest/box.h"
#include "tempest/matrix.h"
#include "tempest/vector.h"
#include "storm/list.h"
#include "map/CMapArea.h"

typedef struct CMapDoodadDefMapChunkLink CMapDoodadDefMapChunkLink;
STORM_TS_LIST(CMapDoodadDefMapChunkLink);
struct CMapDoodadDefMapChunkLink
{
    uint32_t objectIndex; //0x00
    CMapDoodadDef* owner; //0x04
    CMapBaseObj* ref; //0x08 //could be CMapChunk* or CMapObjDefGroup*
    TSLink_CMapDoodadDefMapChunkLink refLink; //0x0C - 0x14
    TSLink_CMapDoodadDefMapChunkLink ownerLink; //0x14 - 0x1C
};

struct CMapDoodadDef
{
    void** vtable; //0x00
    int32_t objectIndex; //0x04
    uint16_t type; //0x08
    uint16_t refCount; //0x0A
    int32_t unk_C; //0x0C
    CMapDoodadDef* prev; //0x10
    CMapDoodadDef* next; //0x14
    
    TSExplicitList_CMapDoodadDefMapChunkLink linkList;
    
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
    
    //CMapDoodadDef fields
    uint32_t unkFlags_090; //0x90    
    void* unk_094; //0x94
    void* unk_098; //0x98
    void* prevMapDoodadDef_09C; //0x9C
    void* nextMapDoodadDef_0A0; //0xA0    
    int32_t unk_0A4; //0xA4
    int32_t unk_0A8; //0xA8
    int32_t unk_0AC; //0xAC
    int32_t unk_0B0; //0xB0
    int32_t unk_0B4; //0xB4
    int32_t unk_0B8; //0xB8
    int32_t unk_0BC; //0xBC    
	CAaBox bboxDoodadDef;
	C44Matrix mat;	
    C44Matrix identity;	
    int32_t unk_158; //0x158 sound
    int32_t unk_15C; //0x15C
    int32_t unk_160; //0x160
    int32_t unk_164; //0x164
    int32_t unk_168; //0x168
    int32_t unk_16C; //0x16C
    //end
};

#endif