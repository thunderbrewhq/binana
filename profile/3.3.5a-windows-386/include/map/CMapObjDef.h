#ifndef CMAPOBJDEF_H
#define CMAPOBJDEF_H

DECLARE_STRUCT(CMapObjDef);
DECLARE_STRUCT(CMapObjDefGroup);

#include "tempest/box.h"
#include "tempest/sphere.h"
#include "tempest/matrix.h"
#include "tempest/vector.h"
#include "storm/array.h"
#include "storm/list.h"
#include "map/CMapDoodadDef.h"
#include "map/CMapArea.h"

STORM_TS_GROWABLE_ARRAY(CMapObjDefGroup);

struct CMapChunk;
typedef struct CMapObjDefMapChunkLink CMapObjDefMapChunkLink;
STORM_TS_LIST(CMapObjDefMapChunkLink);
struct CMapObjDefMapChunkLink
{
    uint32_t objectIndex; //0x00
    CMapObjDef* owner; //0x04
    CMapChunk* ref; //0x08
    TSLink_CMapObjDefMapChunkLink refLink; //0x0C - 0x14
    TSLink_CMapObjDefMapChunkLink ownerLink; //0x14 - 0x1C
};

typedef struct CMapObjDefMapObjDefGroupLink CMapObjDefMapObjDefGroupLink;
STORM_TS_LIST(CMapObjDefMapObjDefGroupLink);
struct CMapObjDefMapObjDefGroupLink
{
    uint32_t objectIndex; //0x00
    CMapObjDefGroup* owner; //0x04
    CMapObjDef* ref; //0x08
    TSLink_CMapObjDefMapObjDefGroupLink refLink; //0x0C - 0x14
    TSLink_CMapObjDefMapObjDefGroupLink ownerLink; //0x14 - 0x1C
};

struct CMapObjDef
{
    void** vtable; //0x00
    int32_t objectIndex; //0x04
    uint16_t type; //0x08
    uint16_t refCount; //0x0A
    int32_t unk_C; //0x0C
    CMapObjDef* prev; //0x10
    CMapObjDef* next; //0x14
    
    TSExplicitList_CMapObjDefMapChunkLink linkList;

    void* unk_24; //0x24
    void* unk_28; //0x28
    void* unk_2C; //0x2C
    void* unk_30; //0x30
    void* unk_34; //0x34
    int32_t unk_38; //0x38
    
    C3Vector position;
    CAaBox bbox;
    CAaSphere sphere;
    C44Matrix mat;
    C44Matrix invMat;

    int32_t unk_F0; //0xF0
    void* CMapObjPtr_owner; //0xF4
    int32_t unk_F8; //0xF8
    uint32_t unkFlags; //0xFC
    int32_t unk_100; //0x100
    int32_t unk_104; //0x104
    int32_t unk_108; //0x108
    int32_t unk_10C; //0x10C
    int32_t unk_110; //0x110

    TSExplicitList_CMapObjDefMapObjDefGroupLink mapObjDefGroupLinkList;
    
    TSGrowableArray_CMapObjDefGroup defGroups;
    
    void* unk_130; //0x130
    
    int32_t TSGrowableArray__m_alloc; //0x134
    int32_t TSGrowableArray__m_count; //0x138
    void* TSGrowableArray__m_data; //0x13C
    int32_t TSGrowableArray__m_chunk; //0x140
    
    uint32_t argbColor; //0x144
    int32_t unk_148; //0x148
    int32_t unk_14C; //0x14C
    int32_t unk_150; //0x150
    void* unk_154; //0x154
};

typedef struct CMapObjDefGroupMapObjDefLink CMapObjDefGroupMapObjDefLink;
STORM_TS_LIST(CMapObjDefGroupMapObjDefLink);
struct CMapObjDefGroupMapObjDefLink
{
    uint32_t objectIndex; //0x00
    CMapObjDefGroup* owner; //0x04
    CMapObjDef* ref; //0x08
    TSLink_CMapObjDefGroupMapObjDefLink refLink; //0x0C - 0x14
    TSLink_CMapObjDefGroupMapObjDefLink ownerLink; //0x14 - 0x1C
};

typedef struct CMapObjDefGroupDoodadDefLink CMapObjDefGroupDoodadDefLink;
STORM_TS_LIST(CMapObjDefGroupDoodadDefLink);
struct CMapObjDefGroupDoodadDefLink
{
    uint32_t objectIndex; //0x00
    CMapDoodadDef* owner; //0x04
    CMapObjDef* ref; //0x08
    TSLink_CMapObjDefGroupDoodadDefLink refLink; //0x0C - 0x14
    TSLink_CMapObjDefGroupDoodadDefLink ownerLink; //0x14 - 0x1C
};

struct CMapObjDefGroup
{
    void* vtable; //0x00
    int32_t objectIndex; //0x04
    uint16_t type; //0x08
    uint16_t refCount; //0x0A
    int32_t unk_C; //0x0C
    CMapObjDefGroup* prev; //0x10
    CMapObjDefGroup* next; //0x14

    TSExplicitList_CMapObjDefGroupMapObjDefLink linkList;

    CAaBox bbox;
    CAaSphere sphere;

    float unk_4C; //0x4C
    
    uint32_t groupNum; //0x50
    uint32_t unkFlags; //0x54
    int32_t unk_58; //0x58
    uint32_t ambientColor; //0x5C
    int32_t unk_60; //0x60
    int32_t unk_64; //0x64
    int32_t unk_68; //0x68
    
    //CWFrustum
    int32_t TSExplicitList__m_linkoffset_unk_6C; //0x6C
    void* TSExplicitList__m_ptr1_unk_70; //0x70
    void* TSExplicitList__m_ptr2_unk_74; //0x74
    
    // CMapDoodadDef
    TSExplicitList_CMapObjDefGroupDoodadDefLink doodadDefLinkList;
    
    int32_t TSExplicitList__m_linkoffset_unk_84; //0x84
    void* TSExplicitList__m_ptr1_unk_88; //0x88
    void* TSExplicitList__m_ptr2_unk_8C; //0x8C
    
    int32_t TSExplicitList__m_linkoffset_unk_90; //0x90
    void* TSExplicitList__m_ptr1_unk_94; //0x94
    void* TSExplicitList__m_ptr2_unk_98; //0x98
    
    int32_t TSExplicitList__m_linkoffset_unk_9C; //0x9C
    void* TSExplicitList__m_ptr1_unk_A0; //0xA0
    void* TSExplicitList__m_ptr2_unk_A4; //0xA4
    
    int32_t unk_A8; //0xA8
    int32_t unk_AC; //0xAC
    int32_t unk_B0; //0xB0
    int32_t unk_B4; //0xB4
    int32_t unk_B8; //0xB8
    int32_t unk_BC; //0xBC
};

#endif
