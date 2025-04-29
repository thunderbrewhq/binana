#ifndef D3D9_SURFACEDESC_H
#define D3D9_SURFACEDESC_H

DECLARE_STRUCT(D3DSURFACE_DESC);

#include "external/d3d9/format.h"
#include "external/d3d9/resourcetype.h"
#include "external/d3d9/pool.h"
#include "external/d3d9/multisampletype.h"

struct D3DSURFACE_DESC {
  D3DFORMAT           Format;
  D3DRESOURCETYPE     Type;
  uint32_t            Usage;
  D3DPOOL             Pool;
  D3DMULTISAMPLE_TYPE MultiSampleType;
  uint32_t            MultiSampleQuality;
  uint32_t            Width;
  uint32_t            Height;
};

#endif