#ifndef CCHARACTERCOMPONENT_H
#define CCHARACTERCOMPONENT_H

DECLARE_STRUCT(CCharacterComponent);
DECLARE_STRUCT(ComponentData);
DECLARE_STRUCT(ItemDisplay);

#include "system/types.h"
#include "texture/texture.h"
#include "tempest/vector.h"
#include "m2/model.h"

struct ComponentData
{
    int32_t raceID;
    int32_t sexID;
    int32_t classID;
    int32_t hairColorID;
    int32_t skinID;
    int32_t faceID;
    int32_t facialHairStyleID;
    int32_t hairStyleID;
    CM2Model* m2Model;
    uint32_t flags;
    char npcBakedTexturePath[260];
    uint32_t geosets[19];  
};

struct ItemDisplay
{
    void* texture[7];
    uint32_t displayID[7];
    uint32_t displayFlag;
};

struct CCharacterComponent
{
    int32_t unk_000;
    int32_t unk_004;
    int32_t flags;
    int32_t sections;
    uint32_t objectIndex;
    EGxTexFormat texFormat;
    ComponentData componentData;

    CTexture* characterBaseSkin;
    
    // 0 - use in CreateRequest AL/AU/FO/HA/HL/HU/LL/LU/TL funcs ; use display info index 0, 1, 2, 3, 4, 5, 6, 7
    // 3 - use in CreateRequestHL func
    // 4 - use in CreateRequestHU func
    // 6 - use in CreateRequestHL func
    // 7 - use in CreateRequestHU func
    // 10 - use in CreateRequestHL func
    // 11 - use in CreateRequestHU func
    // 12 - use in CreateRequestLU func
    // 13 - use in CreateRequestTU func
    void* m_textureVariation[15];
    
    // 0 - shirt/chest display
    // 1 - chest/wrist/arms display
    // 2 - arms display
    // 3 - shirt/chest/tabard display
    // 4 - shirt/chest/tabard display
    // 5 - legs/belt display
    // 6 - legs/feet display
    // 7 - feet display
    ItemDisplay itemDisplayInfo[10];
    
    uint32_t itemModels[11];

    int32_t unk_454;
    int32_t unk_458;
    int32_t unk_45C;
    int32_t unk_460;

    uint32_t unkArray[50];
    
    int32_t unk_52C;
};


#endif