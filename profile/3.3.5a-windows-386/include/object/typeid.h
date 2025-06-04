#ifndef OBJECT_TYPEID_H
#define OBJECT_TYPEID_H

DECLARE_ENUM(OBJECT_TYPE_ID);

enum OBJECT_TYPE_ID {
  ID_OBJECT               = 0x0,
  ID_ITEM                 = 0x1,
  ID_CONTAINER            = 0x2,
  ID_UNIT                 = 0x3,
  ID_PLAYER               = 0x4,
  ID_GAMEOBJECT           = 0x5,
  ID_DYNAMICOBJECT        = 0x6,
  ID_CORPSE               = 0x7,
  NUM_CLIENT_OBJECT_TYPES = 0x8,
  ID_AIGROUP              = 0x8,
  ID_AREATRIGGER          = 0x9,
  NUM_OBJECT_TYPES        = 0xA
};

#endif