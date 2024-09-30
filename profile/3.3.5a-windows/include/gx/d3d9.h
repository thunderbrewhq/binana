#ifndef GX_D3D9_H
#define GX_D3D9_H

#include "gx/device.h"

#include "external/d3d9/device.h"

typedef struct CGxDeviceD3d CGxDeviceD3d;

struct CGxDeviceD3d {
  CGxDevice b_base;
  void* m_hwnd;
  uint16_t m_hwndClass;
  uint16_t unk396E;
  int32_t m_ownhwnd;
  void* m_d3dLib;
  IDirect3D9* m_d3d;
  IDirect3DDevice9* m_d3dDevice;
  D3DCAPS9 m_d3dCaps;
  int32_t m_d3dIsHwDevice;
  int32_t m_d3dNVAPI;
  uint32_t unk3AB8;
  uint32_t unk3ABC;
  uint32_t m_d3dStereoHandle;
  uint32_t unk3AC4[7];
  IDirect3DVertexDeclaration9* m_d3dVertexDecl[14];
  D3DDISPLAYMODE m_desktopDisplayMode;
  int32_t m_inScene;
  uint32_t unk3B2C;
  D3DFORMAT m_devDepthFormat;
  D3DFORMAT m_devAdapterFormat;
  uint32_t unk3B38;
  IDirect3DSurface9* m_defColorSurface;
  IDirect3DSurface9* m_defDepthSurface;
  uint32_t unk3B44;
  uint32_t unk3B48;
  int32_t m_hwCursorNeedsUpdate;
  IDirect3DTexture9* m_hwCursorTexture;
  IDirect3DSurface9* m_hwCursorBitmap;
  uint32_t unk3B58;
  IDirect3DVertexDeclaration9* m_d3dCurrentVertexDecl;
  IDirect3DIndexBuffer9* m_d3dCurrentIndexBuf;
  IDirect3DVertexBuffer9* m_d3dVertexStreamBuf[8];
  uint32_t m_d3dVertexStreamOfs[8];
  uint32_t m_d3dVertexStreamStride[8];
  uint32_t m_deviceStates[182];
  bool m_texEnabled[8];
};

#endif
