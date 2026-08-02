#ifndef D3D9_DSC_BUFFER_DESC_H
#define D3D9_DSC_BUFFER_DESC_H

DECLARE_STRUCT(DSCBUFFERDESC);
DECLARE_STRUCT(DSCBUFFERDESC1);

typedef const DSCBUFFERDESC1* LPCDSCBUFFERDESC1;
typedef const DSCBUFFERDESC*  LPCDSCBUFFERDESC;
typedef DSCBUFFERDESC*        LPDSCBUFFERDESC;
typedef DSCBUFFERDESC1*       LPDSCBUFFERDESC1;

#include "external/d3d9/dsceffectdesc.h"
#include "external/win/waveformatex.h"

struct DSCBUFFERDESC1 {
    uint32_t       dwSize;
    uint32_t       dwFlags;
    uint32_t       dwBufferBytes;
    uint32_t       dwReserved;
    LPWAVEFORMATEX lpwfxFormat;
};

struct DSCBUFFERDESC {
    uint32_t        dwSize;
    uint32_t        dwFlags;
    uint32_t        dwBufferBytes;
    uint32_t        dwReserved;
    LPWAVEFORMATEX  lpwfxFormat;
    uint32_t        dwFXCount;
    LPDSCEFFECTDESC lpDSCFXDesc;
};

#endif
