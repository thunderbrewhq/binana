#ifndef GX_EMERGENCY_MEM_H
#define GX_EMERGENCY_MEM_H

#include "storm/array/uint8_t.h"

DECLARE_STRUCT(EmergencyMem);

struct EmergencyMem {
  TSGrowableArray_uint8_t m_data;
  bool m_lock;
};

#endif