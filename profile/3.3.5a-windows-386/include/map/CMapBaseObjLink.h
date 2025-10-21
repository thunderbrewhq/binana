#ifndef CMAPBASEOBJLINK_H
#define CMAPBASEOBJLINK_H

DECLARE_STRUCT(CMapBaseObjLink);

#include "system/types.h"
#include "storm/list.h"

STORM_TS_LIST(CMapBaseObjLink);

struct CMapBaseObj;

struct CMapBaseObjLink
{
    uint32_t objectIndex; //0x00

    CMapBaseObj* owner; //0x04
    CMapBaseObj* ref; //0x08

    TSLink_CMapBaseObjLink refLink; //0x0C - 0x14
    TSLink_CMapBaseObjLink ownerLink; //0x14 - 0x1C
};

#endif