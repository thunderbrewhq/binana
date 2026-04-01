#ifndef MAP_CHUNK_LIQUID_H
#define MAP_CHUNK_LIQUID_H

#include "storm/list.h"

DECLARE_STRUCT(CChunkLiquid);
STORM_TS_LIST(CChunkLiquid);

#include "map/mapchunk.h"
#include "tempest/vector.h"

struct CChunkLiquid {
    int32_t objectIndex;
    int32_t unk_004;
    int32_t unk_008;

    C3Vector      topLeftCoords;
    C3Vector      center;
    float         radius;
    C2Vector      height;
    float         resPurgeTimer;
    C2iVector     tileBegin;
    C2iVector     tileEnd;
    int32_t       unk_044;
    int32_t       unk_048;
    int32_t       unk_04C;
    int32_t       unk_050;
    uint8_t*      tiles;
    uint8_t*      liquidInstPtr;
    CMapChunk*    owner;
    CChunkLiquid* prev;
    CChunkLiquid* next;
    int32_t       unk_068;
    int32_t       unk_06C;
    int32_t       unk_070;
    int32_t       unk_074;
    C3Vector      verts[81];
};

#endif
