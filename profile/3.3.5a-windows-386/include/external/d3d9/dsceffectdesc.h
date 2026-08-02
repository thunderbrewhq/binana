#ifndef D3D9_DSC_EFFECT_DESC_H
#define D3D9_DSC_EFFECT_DESC_H

DECLARE_STRUCT(DSCEFFECTDESC);

typedef DSCEFFECTDESC*       LPDSCEFFECTDESC;
typedef const DSCEFFECTDESC* LPCDSCEFFECTDESC;

#include "external/win/guid.h"

struct DSCEFFECTDESC {
    uint32_t dwSize;
    uint32_t dwFlags;
    GUID     guidDSCFXClass;
    GUID     guidDSCFXInstance;
    uint32_t dwReserved1;
    uint32_t dwReserved2;
};

#endif
