#ifndef WIN_GUID_H
#define WIN_GUID_H

DECLARE_STRUCT(GUID);

#include "system/types.h"

struct GUID {
  uint32_t Data1;
  uint16_t Data2;
  uint16_t Data3;
  uint8_t  Data4[8];
};

#endif