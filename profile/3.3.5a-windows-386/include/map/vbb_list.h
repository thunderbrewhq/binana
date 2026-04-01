#ifndef MAP_VBB_LIST_H
#define MAP_VBB_LIST_H

DECLARE_STRUCT(VBBList);
DECLARE_STRUCT(VBBList_Block);

#include "gx/buffer.h"
#include "system/types.h"

struct VBBList_Block {
    VBBList_Block*  next;
    VBBList_Block*  prev;
    EGxPoolUsage    poolUsage;
    uint32_t        offset;
    uint32_t        capacity;
    CGxPool*        pool;
    CGxBuf*         buffer;
    VBBList_Block** listHead;
};

struct VBBList {
    int32_t       singlePool;
    EGxPoolTarget target;
    EGxPoolUsage  usage;

    CGxPool* pool;

    uint32_t unk_10;

    // singlePool == true
    VBBList_Block* listHeadA;
    VBBList_Block* freeCandidate;

    uint32_t unk_1C;

    // singlePool == false
    VBBList_Block* listHeadB;
    VBBList_Block* allBlocks;
};

#endif
