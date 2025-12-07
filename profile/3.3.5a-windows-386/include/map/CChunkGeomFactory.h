#ifndef CCHUNKGEOMFACTORY_H
#define CCHUNKGEOMFACTORY_H

DECLARE_STRUCT(CChunkGeomFactory);

#include "system/types.h"
#include "tempest/matrix.h"
#include "map/CChunkLiquid.h"
#include "map/CMapChunkBuf.h"

struct CChunkGeomFactory
{
    void** vtable;
    
    uint32_t unk_04;
    uint32_t unk_08;
    uint32_t unk_0C;
    uint32_t unk_10;
    CChunkLiquid* liquidChunk;
    uint32_t unk_18;
    CMapChunkBuf* mapChunkBuf;
    uint32_t unk_20;
    uint32_t unk_24;
    uint32_t unk_28;
    uint16_t unk_flags_2C;
    uint16_t unk_flags_2E;
    uint32_t unk_30;
    C44Matrix matrix;
};

#endif