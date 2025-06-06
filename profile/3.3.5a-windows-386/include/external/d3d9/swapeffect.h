#ifndef D3D9_SWAPEFFECT_H
#define D3D9_SWAPEFFECT_H

DECLARE_ENUM(D3DSWAPEFFECT);

enum D3DSWAPEFFECT {
  D3DSWAPEFFECT_DISCARD         = 1,
  D3DSWAPEFFECT_FLIP            = 2,
  D3DSWAPEFFECT_COPY            = 3,
  D3DSWAPEFFECT_OVERLAY         = 4,
  D3DSWAPEFFECT_FLIPEX          = 5,
  D3DSWAPEFFECT_FORCE_DWORD     = 0xFFFFFFFF
};

#endif