#ifndef CMAPCHUNKBUF_H
#define CMAPCHUNKBUF_H

DECLARE_STRUCT(CMapChunkBuf);

#include "system/types.h"
#include "gx/buffer.h"

struct CMapChunkBuf
{
    uint32_t unk_00;
    float flushTimer;

    uint32_t vertexDataSize;
    uint32_t indexDataSize;

    CGxBuf* vertexBuf;
    CGxBuf* indexBuf;
    CGxPool* vertexPool;
    CGxPool* indexPool;
    uint32_t unk_20;
    uint32_t unk_24;
};

#endif