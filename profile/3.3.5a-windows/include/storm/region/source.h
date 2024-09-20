#ifndef STORM_REGION_SOURCE_H
#define STORM_REGION_SOURCE_H

#include "storm/array.h"
#include "storm/region/rect.h"

DECLARE_STRUCT(SOURCE);

struct SOURCE {
  RECTF rect;
  void* param;
  int32_t sequence;
  uint32_t flags;
};
STORM_TS_GROWABLE_ARRAY(SOURCE);

#endif