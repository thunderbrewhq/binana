#ifndef MAP_MAP_BASE_OBJ_H
#define MAP_MAP_BASE_OBJ_H

DECLARE_STRUCT(CMapBaseObj);
DECLARE_STRUCT(CMapBaseObjLink);

#include "storm/list.h"

STORM_TS_LIST(CMapBaseObjLink);
struct CMapBaseObjLink {
    uint32_t objectIndex; // 0x00

    CMapBaseObj* owner; // 0x04
    CMapBaseObj* ref;   // 0x08

    TSLink_CMapBaseObjLink refLink;   // 0x0C - 0x14
    TSLink_CMapBaseObjLink ownerLink; // 0x14 - 0x1C
};

struct CMapBaseObj {
    void**   vtable;      // 0x00
    int32_t  objectIndex; // 0x04
    uint16_t type;        // 0x08
    uint16_t refCount;    // 0x0A
    int32_t  unk_C;       // 0x0C

    CMapBaseObj* prev; // 0x10
    CMapBaseObj* next; // 0x14

    TSExplicitList_CMapBaseObjLink list; // 0x18 - 0x24
};

#endif
