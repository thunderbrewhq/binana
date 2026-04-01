#ifndef MAP_MAP_CHUNK_BUF_H
#define MAP_MAP_CHUNK_BUF_H

DECLARE_STRUCT(CMapChunkBuf);

#include "gx/buffer.h"

struct CMapChunkBuf {
    uint32_t unk_00;
    float    flushTimer;

    uint32_t vertexDataSize;
    uint32_t indexDataSize;

    CGxBuf*  vertexBuf;
    CGxBuf*  indexBuf;
    CGxPool* vertexPool;
    CGxPool* indexPool;
    uint32_t unk_20;
    uint32_t unk_24;
};

#endif
