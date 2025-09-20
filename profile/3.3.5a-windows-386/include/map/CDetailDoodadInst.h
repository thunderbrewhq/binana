#ifndef CDETAILDOODADINST_H
#define CDETAILDOODADINST_H

DECLARE_STRUCT(CDetailDoodadGeomVertex);
DECLARE_STRUCT(CDetailDoodadGeom);
DECLARE_STRUCT(CDetailDoodadInst);

#include "system/types.h"
#include "texture/texture.h"
#include "tempest/vector.h"
#include "storm/array.h"

struct CMapChunk;

struct CDetailDoodadGeomVertex
{
    uint16_t unk_00;
    uint16_t unk_02;
    uint32_t unk_04;
    C3Vector pos;
    float angle;
    float scale;
    C3Vector unkVec;
    uint32_t color;
};

STORM_TS_GROWABLE_ARRAY(CDetailDoodadGeomVertex);

struct CDetailDoodadGeom
{
    CTexture* texture;
    int32_t unkVertexCount;
    int32_t unkIndexCount;
    void* unkVertBufStream;
    void* unkIdxBufStream;
    TSGrowableArray_CDetailDoodadGeomVertex data;
};

struct CDetailDoodadInst
{
    int32_t objectIndex;
    CDetailDoodadGeom geom[4];
    int32_t unkCounter;
    CMapChunk* mapChunkOwner;
    int32_t unk_09C;
    int32_t unk_0A0;
};


#endif