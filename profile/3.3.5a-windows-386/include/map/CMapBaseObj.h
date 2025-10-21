#ifndef CMAPBASEOBJ_H
#define CMAPBASEOBJ_H

DECLARE_STRUCT(CMapBaseObj);

#include "system/types.h"
#include "map/CMapBaseObjLink.h"

struct CMapBaseObj
{
    void** vtable; //0x00
    int32_t objectIndex; //0x04
    uint16_t type; //0x08
    uint16_t refCount; //0x0A
    int32_t unk_C; //0x0C

    CMapBaseObj* prev; //0x10
    CMapBaseObj* next; //0x14
    
    TSExplicitList_CMapBaseObjLink list; //0x18 - 0x24
};

#endif