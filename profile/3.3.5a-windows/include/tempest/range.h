#ifndef TEMPEST_RANGE_H
#define TEMPEST_RANGE_H

#include "system/types.h"

DECLARE_STRUCT(CRange);
DECLARE_STRUCT(CiRange);

struct CRange {
  float l;
  float h;
};

struct CiRange {
  int32_t l;
  int32_t h;
};

#endif