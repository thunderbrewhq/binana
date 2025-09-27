#ifndef CMAPRENDERCHUNK_H
#define CMAPRENDERCHUNK_H

DECLARE_STRUCT(CMapRenderChunkLayer);
DECLARE_STRUCT(CMapRenderChunk);

#include "system/types.h"
#include "texture/texture.h"
#include "tempest/vector.h"
#include "gx/buffer.h"

struct CMapChunk;

struct CMapRenderChunkLayer
{
    int16_t flags;
    int16_t layerIndex;
    CTexture* texture;
    int32_t unkIndex;
    int32_t unkValue;
    CMapRenderChunk* owner;
};

struct CMapRenderChunk
{
    CMapRenderChunk* renderChunkPtr1;
    CMapRenderChunk* renderChunkPtr2;
    uint8_t unkFlags;
    uint8_t layersCount;
    int16_t unk_0A;
    int32_t unk_0C;
    
    CMapChunk* mapChunkPtr1;
    CMapChunk* mapChunkPtr2;
    
    C3Vector vec1;
    C3Vector vec2;
    float radius;

    CMapRenderChunkLayer layers[4];
    
    CTexture* terrainBlendTexture;
    CTexture* shadowTexture;

    CGxBuf* vertexBuf;
    CGxBuf* indicesBuf;

    int32_t unk_94;
    int32_t unk_98;
    int16_t unk_9C;
    int16_t unk_9E;
    int32_t unk_A0;
    int32_t unk_A4;
};


#endif