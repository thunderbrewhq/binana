#ifndef D3D9_DEVICE_H
#define D3D9_DEVICE_H

#include <stdint.h>

#include "d3d9/caps.h"

typedef int32_t D3DFORMAT;
typedef struct D3DDISPLAYMODE D3DDISPLAYMODE;
typedef struct IDirect3D9 IDirect3D9;
typedef struct IDirect3DDevice9 IDirect3DDevice9;
typedef struct IDirect3DVertexDeclaration9 IDirect3DVertexDeclaration9;
typedef struct IDirect3DSurface9 IDirect3DSurface9;
typedef struct IDirect3DIndexBuffer9 IDirect3DIndexBuffer9;
typedef struct IDirect3DVertexBuffer9 IDirect3DVertexBuffer9;

struct D3DDISPLAYMODE {
  uint32_t Width;
  uint32_t Height;
  uint32_t RefreshRate;
  D3DFORMAT Format;
};

struct IDirect3D9 {
  void** v_vtable;
};

struct IDirect3DDevice9 {
  void** v_vtable;
};

struct IDirect3DVertexDeclaration9 {
  void** v_vtable;
};

struct IDirect3DSurface9 {
  void** v_vtable;
};

struct IDirect3DIndexBuffer9 {
  void** v_vtable;
};

struct IDirect3DVertexBuffer9 {
  void** v_vtable;
};

#endif
