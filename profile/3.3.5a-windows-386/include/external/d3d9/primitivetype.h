#ifndef D3D9_PRIMITIVETYPE_H
#define D3D9_PRIMITIVETYPE_H

DECLARE_ENUM(D3DPRIMITIVETYPE);

enum D3DPRIMITIVETYPE {
  D3DPT_POINTLIST             = 1,
  D3DPT_LINELIST              = 2,
  D3DPT_LINESTRIP             = 3,
  D3DPT_TRIANGLELIST          = 4,
  D3DPT_TRIANGLESTRIP         = 5,
  D3DPT_TRIANGLEFAN           = 6,

  D3DPT_FORCE_DWORD           = 0x7fffffff
};

#endif