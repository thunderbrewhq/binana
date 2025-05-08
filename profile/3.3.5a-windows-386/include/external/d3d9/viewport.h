#ifndef D3D9_VIEWPORT_H
#define D3D9_VIEWPORT_H

DECLARE_STRUCT(D3DVIEWPORT9);

struct D3DVIEWPORT9 {
  uint32_t X;
  uint32_t Y;
  uint32_t Width;
  uint32_t Height;
  float MinZ;
  float MaxZ;
};

#endif