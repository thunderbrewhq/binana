#ifndef STORM_REGION_RECT_H
#define STORM_REGION_RECT_H

#include "storm/array.h"

DECLARE_STRUCT(RECTF);

struct RECTF {
  float left;
  float bottom;
  float right;
  float top;
};
STORM_TS_GROWABLE_ARRAY(RECTF);

#endif