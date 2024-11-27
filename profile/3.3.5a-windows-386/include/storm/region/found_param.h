#ifndef STORM_REGION_FOUND_PARAM_H
#define STORM_REGION_FOUND_PARAM_H

#include "storm/array.h"

DECLARE_STRUCT(FOUNDPARAM);

struct FOUNDPARAM {
  void* param;
  int32_t sequence;
};
STORM_TS_GROWABLE_ARRAY(FOUNDPARAM);

#endif