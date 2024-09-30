#ifndef D3D9_CAPS_H
#define D3D9_CAPS_H

#include "system/types.h"

typedef enum D3DDEVTYPE D3DDEVTYPE;
typedef struct D3DVSHADERCAPS2_0 D3DVSHADERCAPS2_0;
typedef struct D3DPSHADERCAPS2_0 D3DPSHADERCAPS2_0;
typedef struct D3DCAPS9 D3DCAPS9;

enum D3DDEVTYPE {
  D3DDEVTYPE_HAL = 1,
  D3DDEVTYPE_REF = 2,
  D3DDEVTYPE_SW = 3,
  D3DDEVTYPE_NULLREF = 4,

  D3DDEVTYPE_FORCE_uint32_t = 0xffffffff
};

struct D3DVSHADERCAPS2_0 {
  uint32_t Caps;
  int32_t DynamicFlowControlDepth;
  int32_t NumTemps;
  int32_t StaticFlowControlDepth;
};

struct D3DPSHADERCAPS2_0 {
  uint32_t Caps;
  int32_t DynamicFlowControlDepth;
  int32_t NumTemps;
  int32_t StaticFlowControlDepth;
  int32_t NumInstructionSlots;
};

struct D3DCAPS9 {
  D3DDEVTYPE DeviceType;
  uint32_t AdapterOrdinal;

  uint32_t Caps;
  uint32_t Caps2;
  uint32_t Caps3;
  uint32_t PresentationIntervals;

  uint32_t CursorCaps;

  uint32_t DevCaps;

  uint32_t PrimitiveMiscCaps;
  uint32_t RasterCaps;
  uint32_t ZCmpCaps;
  uint32_t SrcBlendCaps;
  uint32_t DestBlendCaps;
  uint32_t AlphaCmpCaps;
  uint32_t ShadeCaps;
  uint32_t TextureCaps;
  uint32_t TextureFilterCaps;
  uint32_t CubeTextureFilterCaps;
  uint32_t VolumeTextureFilterCaps;
  uint32_t TextureAddressCaps;
  uint32_t VolumeTextureAddressCaps;

  uint32_t LineCaps;

  uint32_t MaxTextureWidth, MaxTextureHeight;
  uint32_t MaxVolumeExtent;

  uint32_t MaxTextureRepeat;
  uint32_t MaxTextureAspectRatio;
  uint32_t MaxAnisotropy;
  float MaxVertexW;

  float GuardBandLeft;
  float GuardBandTop;
  float GuardBandRight;
  float GuardBandBottom;

  float ExtentsAdjust;
  uint32_t StencilCaps;

  uint32_t FVFCaps;
  uint32_t TextureOpCaps;
  uint32_t MaxTextureBlendStages;
  uint32_t MaxSimultaneousTextures;

  uint32_t VertexProcessingCaps;
  uint32_t MaxActiveLights;
  uint32_t MaxUserClipPlanes;
  uint32_t MaxVertexBlendMatrices;
  uint32_t MaxVertexBlendMatrixIndex;

  float MaxPointSize;

  uint32_t MaxPrimitiveCount;
  uint32_t MaxVertexIndex;
  uint32_t MaxStreams;
  uint32_t MaxStreamStride;

  uint32_t VertexShaderVersion;
  uint32_t MaxVertexShaderConst;

  uint32_t PixelShaderVersion;
  float PixelShader1xMaxValue;

  /* DX 9 */
  uint32_t DevCaps2;

  float MaxNpatchTessellationLevel;
  uint32_t Reserved5;

  uint32_t MasterAdapterOrdinal;
  uint32_t AdapterOrdinalInGroup;
  uint32_t NumberOfAdaptersInGroup;
  uint32_t DeclTypes;
  uint32_t NumSimultaneousRTs;
  uint32_t StretchRectFilterCaps;
  D3DVSHADERCAPS2_0 VS20Caps;
  D3DPSHADERCAPS2_0 PS20Caps;
  uint32_t VertexTextureFilterCaps;
  uint32_t MaxVShaderInstructionsExecuted;
  uint32_t MaxPShaderInstructionsExecuted;
  uint32_t MaxVertexShader30InstructionSlots;
  uint32_t MaxPixelShader30InstructionSlots;
};

#endif