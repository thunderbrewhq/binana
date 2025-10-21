#ifndef ADTCHUNKS_H
#define ADTCHUNKS_H

DECLARE_STRUCT(SMMapHeader);
DECLARE_STRUCT(SMChunkInfo);
DECLARE_STRUCT(SMDoodadDef);
DECLARE_STRUCT(SMMapObjDef);
DECLARE_STRUCT(SMChunk);
DECLARE_STRUCT(SLVert);
DECLARE_STRUCT(SMLayer);
DECLARE_STRUCT(SLTiles);
DECLARE_STRUCT(SWFlowv);
DECLARE_STRUCT(SOVert);
DECLARE_STRUCT(SMVert);
DECLARE_STRUCT(SWVert);
DECLARE_STRUCT(SMLiquidChunk);
DECLARE_STRUCT(CWSoundEmitter);

#include "tempest/vector.h"
#include "tempest/box.h"
#include "tempest/sphere.h"

struct SMMapHeader
{
    uint32_t flags;
    uint32_t mcin;                  // MCIN*, Cata+: obviously gone. probably all offsets gone, except mh2o(which remains in root file).
    uint32_t mtex;                 // MTEX*
    uint32_t mmdx;                 // MMDX*
    uint32_t mmid;                 // MMID*
    uint32_t mwmo;                 // MWMO*
    uint32_t mwid;                 // MWID*
    uint32_t mddf;                 // MDDF*
    uint32_t modf;                 // MODF*
    uint32_t mfbo;                 // MFBO*   this is only set if flags & mhdr_MFBO.
    uint32_t mh2o;                 // MH2O*
    uint32_t mtxf;                 // MTXF*
    uint8_t mamp_value;             // Cata+, explicit MAMP chunk overrides data
    uint8_t padding[3];
    uint32_t unused[3];
};

struct SMChunkInfo
{
    uint32_t offset;               // absolute offset.
    uint32_t size;                 // the size of the MCNK chunk, this is refering to.
    uint32_t flags;                // always 0. only set in the client., FLAG_LOADED = 1
    union
    {
        char pad[4];                 
        uint32_t asyncId;            // not in the adt file. client use only 
    };
};

struct SMDoodadDef
{
    uint32_t nameId;              // references an entry in the MMID chunk, specifying the model t                                // if flag mddf_entry_is_filedata_id is set, a file data id instead, ignoring MMID.
    uint32_t uniqueId;            // this ID should be unique for all ADTs currently loaded. Best, they are unique for the whole map. Blizzar                                 // these unique for the whole game.
    C3Vector position;           // This is relative to a corner of the map. Subtract 17066 from the non vertical values and you should start t                               // something that makes sense. You'll then likely have to negate one of the non vertical values in wha                               // coordinate system you're using to finally move it into place.
    C3Vector rotation;           // degrees. This is not the same coordinate system orientation like the ADT itself! (see history.)
    uint16_t scale;               // 1024 is the default size equaling 1.0f.
    uint16_t flags;               // values from enum MDDFFlags.
};

struct SMMapObjDef
{
    uint32_t nameId;              // references an entry in the MWID chunk, specifying the model to use.
    uint32_t uniqueId;            // this ID should be unique for all ADTs currently loaded. Best, they are unique for the whole map.
    C3Vector position;
    C3Vector rotation;           // same as in MDDF.
    CAaBox extents;              // position plus the transformed wmo bounding box. used for defining if they are rendered as well as collision.
    uint16_t flags;               // values from enum MODFFlags.
    uint16_t doodadSet;           // which WMO doodad set is used. Traditionally references WMO#MODS_chunk, if modf_use_sets_from_mwds is set, references #MWDR_.28Shadowlands.2B.29
    uint16_t nameSet;             // which WMO name set is used. Used for renaming goldshire inn to northshire inn while using the same model.
    uint16_t scale;               // Legion+: scale, 1024 means 1 (same as MDDF). Padding in 0.5.3 alpha. 
};

struct SMChunk
{
    uint32_t flags;
    C2iVector index;
    uint32_t nLayers;
    uint32_t nDoodadRefs;
    uint32_t ofsHeight;
    uint32_t ofsNormal;
    uint32_t ofsLayer;
    uint32_t ofsRefs;
    uint32_t ofsAlpha;
    uint32_t sizeAlpha;
    uint32_t ofsShadow;
    uint32_t sizeShadow;
    uint32_t areaid;
    uint32_t nMapObjRefs;
    uint32_t holes;
    uint8_t low_quality_texture_map[0x10];
    uint32_t predTex;
    uint32_t nEffectDoodad;
    uint32_t ofsSndEmitters;
    uint32_t nSndEmitters;
    uint32_t ofsLiquid;
    uint32_t sizeLiquid;
    C3Vector position;
    uint32_t ofsMCCV;
    uint32_t unused1;
    uint32_t unused2;
};

struct SMLayer
{
    uint32_t textureId;
    uint32_t flags;
    uint32_t offsetInMCAL;
    uint32_t offectId;
};

struct SWVert
{
    char depth;
    char flow0Pct;
    char flow1Pct;
    char filler;
    float height;
};

struct SOVert
{
    char depth;
    char foam;
    char wet;
    char filler;
};

struct SMVert
{
    uint16_t s;
    uint16_t t;
    float height;
};

struct SLVert
{
    union
    {
        SWVert waterVert;
        SOVert oceanVert;
        SMVert magmaVert;
    };
};

struct SLTiles
{
  char tiles[8][8];
};

struct SWFlowv
{
    CAaSphere sphere;
    C3Vector dir;
    float velocity;
    float amplitude;
    float frequency;
};

struct SMLiquidChunk
{
    float minHeight;
    float maxHeight;
    
    SLVert verts[9*9];

    SLTiles tiles;

    uint32_t nFlowvs;
    SWFlowv flowvs[2];
};

struct CWSoundEmitter
{
    uint32_t entry_id;
    C3Vector position;
    C3Vector size;
};

#endif