#ifndef WMOCHUNKS_H
#define WMOCHUNKS_H

#include "tempest/box.h"
#include "tempest/plane.h"
#include "tempest/quaternion.h"

DECLARE_STRUCT(SMOHeader);
DECLARE_STRUCT(SMOGroupInfo);
DECLARE_STRUCT(SMOPortal);
DECLARE_STRUCT(SMOPortalRef);
DECLARE_STRUCT(SMOVisibleBlock);
DECLARE_STRUCT(SMOLight);
DECLARE_STRUCT(SMODoodadSet);
DECLARE_STRUCT(SMODoodadDef);
DECLARE_STRUCT(SMOFog);
DECLARE_STRUCT(SMOMaterial);
DECLARE_STRUCT(SMOPoly);
DECLARE_STRUCT(SMOBatch);
DECLARE_STRUCT(SMOLiquidVert);
DECLARE_STRUCT(SMOLTile);

struct SMOHeader
{
    uint32_t nTextures;
    uint32_t nGroups;   
    uint32_t nPortals;
    uint32_t nLights;
    uint32_t nDoodadNames;
    uint32_t nDoodadDefs;
    uint32_t nDoodadSets;
    uint32_t ambColor;
    uint32_t wmoID;
    CAaBox bounding_box;
    uint16_t flag_do_not_attenuate_vertices_based_on_distance_to_portal : 1;
    uint16_t flag_use_unified_render_path : 1;
    uint16_t flag_use_liquid_type_dbc_id : 1;
    uint16_t flag_do_not_fix_vertex_color_alpha: 1;
    uint16_t flag_lod : 1;
    uint16_t flag_default_max_lod : 1;
    uint16_t : 10;
    uint16_t numLod;
};

struct SMOGroupInfo
{
    uint32_t flags;
    CAaBox bbox;
    uint32_t nameOffset;
};

struct SMOPortal
{
    uint16_t startVertex;
    uint16_t count;
    C4Plane plane;
};

struct SMOPortalRef
{
    uint16_t portalIndex;
    uint16_t groupIndex;
    int16_t side;
    uint16_t filler;
};

struct SMOVisibleBlock
{
    uint16_t firstVertex;
    uint16_t count;
};

struct SMOLight
{
    uint8_t type;
    uint8_t atten;
    uint8_t pad[2];

    CImVector color;
    C3Vector position;
    float intensity;

    C4Quaternion rotation;

    float attenStart;
    float attenEnd;
};

struct SMODoodadSet
{
    char name[0x14];
    uint32_t startIdx;
    uint32_t count;
    uint32_t pad;
};

struct SMODoodadDef
{
    uint32_t nameIndex : 24;
    uint32_t flag_AcceptProjTex : 1;
    uint32_t flag_0x2 : 1;
    uint32_t flag_0x4 : 1;
    uint32_t flag_0x8 : 1;
    uint32_t unk : 4;
    C3Vector position;
    C4Quaternion orientation;
    float scale;
    CImVector color;
};

struct SMOFog
{
    uint32_t flag_infinite_radius : 1;
    uint32_t : 3;
    uint32_t flag_0x10 : 1;
    uint32_t : 27;

    C3Vector position;
    float smallerRadius;
    float largerRadius;

    float fogEnd;
    float fogStartScalar;
    CImVector fogColor;

    //under water
    float uwFogEnd;
    float uwFogStartScalar;
    CImVector uwFogColor;
};

struct SMOMaterial
{
    uint32_t F_UNLIT    : 1;
    uint32_t F_UNFOGGED : 1;
    uint32_t F_UNCULLED : 1;
    uint32_t F_EXTLIGHT : 1;
    uint32_t F_SIDN     : 1;
    uint32_t F_WINDOW   : 1;
    uint32_t F_CLAMP_S  : 1;
    uint32_t F_CLAMP_T  : 1;
    uint32_t flag_0x100 : 1;
    uint32_t : 23;

    uint32_t shader;

    uint32_t blendMode;
    uint32_t texture1;

    CImVector sidnColor;
    CImVector frameSidnColor;

    uint32_t texture2;
    CImVector diffColor;

    uint32_t groundType;

    uint32_t texture3;
    uint32_t color2;
    uint32_t flags2;
    uint32_t runTimeData[4];
};

struct SMOPoly
{
    uint8_t F_UNK_0x01: 1;
    uint8_t F_NOCAMCOLLIDE : 1;
    uint8_t F_DETAIL : 1;
    uint8_t F_COLLISION : 1;
    uint8_t F_HINT : 1;
    uint8_t F_RENDER : 1;
    uint8_t F_CULL_OBJECTS : 1;
    uint8_t F_COLLIDE_HIT : 1;

    uint8_t materialId;
};

struct SMOBatch
{
    int8_t unused[12];
    uint32_t indexStart;
    uint16_t indexCount;
    uint16_t vertexStart;
    uint16_t vertexEnd;    
    uint8_t flags;
    uint8_t texture;
};

struct SMOLiquidVert
{
    union
    {
        struct SMOWVert
        {
            uint8_t flow1;
            uint8_t flow2;
            uint8_t flow1Pct;
            uint8_t filler;
            float height;
        } waterVert;

        struct SMOMVert
        {
            int16_t s;
            int16_t t;
            float height;
        } magmaVert;
    };
};

struct SMOLTile
{
    uint8_t legacyLiquidType : 4;
    uint8_t unknown1 : 1;
    uint8_t unknown2 : 1;
    uint8_t fishable : 1;
    uint8_t shared : 1;
};


#endif