#ifndef NET_CHARACTER_INFO
#define NET_CHARACTER_INFO

DECLARE_STRUCT(CHARACTER_INFO);

#include "object/guid.h"
#include "storm/array.h"
#include "tempest/vector.h"

STORM_TS_FIXED_ARRAY(CHARACTER_INFO);
struct CHARACTER_INFO {
    WOWGUID  guid;
    char     name[48];
    uint32_t mapID;
    uint32_t zoneID;
    uint32_t guildID;
    C3Vector position;
    uint32_t inventoryItemDisplayID[23];
    uint32_t inventoryItemType[23];
    uint32_t inventoryItemVisualID[23];
    uint32_t petDisplayInfoID;
    uint32_t petExperienceLevel;
    uint32_t petCreatureFamilyID;
    uint32_t flags;
    uint32_t customizeFlags;
    uint8_t  raceID;
    uint8_t  classID;
    uint8_t  sexID;
    uint8_t  skinColorID;
    uint8_t  faceID;
    uint8_t  hairStyleID;
    uint8_t  hairColorID;
    uint8_t  facialHairStyleID;
    uint8_t  experienceLevel;
    uint8_t  firstLogin;
};

#endif
