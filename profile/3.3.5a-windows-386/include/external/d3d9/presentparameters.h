#ifndef D3D9_PRESENTPARAMETERS_H
#define D3D9_PRESENTPARAMETERS_H

DECLARE_STRUCT(D3DPRESENT_PARAMETERS);

#include "external/d3d9/format.h"
#include "external/d3d9/multisampletype.h"
#include "external/d3d9/swapeffect.h"

struct D3DPRESENT_PARAMETERS {
  uint32_t BackBufferWidth;
  uint32_t BackBufferHeight;
  D3DFORMAT BackBufferFormat;
  uint32_t BackBufferCount;

  D3DMULTISAMPLE_TYPE MultiSampleType;
  uint32_t MultiSampleQuality;

  D3DSWAPEFFECT SwapEffect;
  void* hDeviceWindow;
  int32_t Windowed;
  int32_t EnableAutoDepthStencil;
  D3DFORMAT AutoDepthStencilFormat;
  uint32_t Flags;

  uint32_t FullScreen_RefreshRateInHz;
  uint32_t PresentationInterval;
};

#endif