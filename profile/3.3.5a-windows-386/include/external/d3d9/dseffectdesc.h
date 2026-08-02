#ifndef D3D9_DS_EFFECT_DESC_H
#define D3D9_DS_EFFECT_DESC_H

DECLARE_STRUCT(DSEFFECTDESC);

typedef DSEFFECTDESC*       LPDSEFFECTDESC;
typedef const DSEFFECTDESC* LPCDSEFFECTDESC;

#include "external/win/guid.h"

struct DSEFFECTDESC {
    uint32_t  dwSize;
    uint32_t  dwFlags;
    GUID      guidDSFXClass;
    uintptr_t dwReserved1;
    uintptr_t dwReserved2;
};

#endif
