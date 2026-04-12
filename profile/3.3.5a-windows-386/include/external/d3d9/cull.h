#ifndef D3D9_CULL_H
#define D3D9_CULL_H

DECLARE_ENUM(D3DCULL);

enum D3DCULL {
    D3DCULL_NONE = 1,
    D3DCULL_CW   = 2,
    D3DCULL_CCW  = 3,

    D3DCULL_FORCE_DWORD = 0x7fffffff
};

#endif
