#ifndef COMMON_MEM_POOL_H
#define COMMON_MEM_POOL_H

DECLARE_STRUCT(MemPool);
DECLARE_STRUCT(MemChunk);

#include "storm/array.h"

typedef MemChunk* pointer_to_MemChunk;
STORM_TS_FIXED_ARRAY(pointer_to_MemChunk);

struct MemChunk {
    void*    m_memblocks;
    void*    m_free;
    uint32_t m_unk2;
    uint32_t m_blockSize;
    uint32_t m_numBlocks;
};

// 24 bytes
struct MemPool {
    TSFixedArray_pointer_to_MemChunk m_memchunks;
    //
    uint32_t m_unk3;
    uint32_t m_blockSize;
    uint32_t m_unk5;
};

#endif
