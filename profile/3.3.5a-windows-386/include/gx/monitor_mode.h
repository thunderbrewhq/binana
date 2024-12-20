#ifndef GX_MONITOR_MODE_H
#define GX_MONITOR_MODE_H

DECLARE_STRUCT(CGxMonitorMode);

#include "tempest/vector.h"
#include "storm/array.h"

struct CGxMonitorMode {
  C2iVector size;
  uint32_t bpp;
  uint32_t refreshRate;
};
STORM_TS_GROWABLE_ARRAY(CGxMonitorMode);

#endif