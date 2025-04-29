#ifndef D3D9_DISPLAYMODE_H
#define D3D9_DISPLAYMODE_H

DECLARE_STRUCT(D3DDISPLAYMODE);

#include "external/d3d9/format.h"

struct D3DDISPLAYMODE {
  uint32_t Width;
  uint32_t Height;
  uint32_t RefreshRate;
  D3DFORMAT Format;
};

#endif