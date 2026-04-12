#ifndef D3D9_CMP_FUNC_H
#define D3D9_CMP_FUNC_H

DECLARE_ENUM(D3DCMPFUNC);

enum D3DCMPFUNC {
    D3DCMP_NEVER        = 1,
    D3DCMP_LESS         = 2,
    D3DCMP_EQUAL        = 3,
    D3DCMP_LESSEQUAL    = 4,
    D3DCMP_GREATER      = 5,
    D3DCMP_NOTEQUAL     = 6,
    D3DCMP_GREATEREQUAL = 7,
    D3DCMP_ALWAYS       = 8,

    D3DCMP_FORCE_DWORD = 0x7fffffff
};

#endif
