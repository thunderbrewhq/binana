#ifndef D3D9_LOCKEDRECT_H
#define D3D9_LOCKEDRECT_H

DECLARE_STRUCT(D3DLOCKED_RECT);

struct D3DLOCKED_RECT {
  int32_t Pitch;
  void* pBits;
};

#endif