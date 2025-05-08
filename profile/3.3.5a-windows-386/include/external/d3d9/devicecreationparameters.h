#ifndef D3D9_DEVICECREATIONPARAMETERS_H
#define D3D9_DEVICECREATIONPARAMETERS_H

DECLARE_STRUCT(D3DDEVICE_CREATION_PARAMETERS);

#include "external/d3d9/devtype.h"

struct D3DDEVICE_CREATION_PARAMETERS {
  uint32_t      AdapterOrdinal;
  D3DDEVTYPE    DeviceType;
  void*         hFocusWindow;
  uint32_t      BehaviorFlags;
};

#endif