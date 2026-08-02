#ifndef D3D9_DS_BUFFER_DESC_H
#define D3D9_DS_BUFFER_DESC_H

DECLARE_STRUCT(DSBUFFERDESC);
DECLARE_STRUCT(DSBUFFERDESC1);

typedef DSBUFFERDESC*        LPDSBUFFERDESC;
typedef DSBUFFERDESC1*       LPDSBUFFERDESC1;
typedef const DSBUFFERDESC*  LPCDSBUFFERDESC;
typedef const DSBUFFERDESC1* LPCDSBUFFERDESC1;

#include "external/win/guid.h"
#include "external/win/waveformatex.h"

struct DSBUFFERDESC1 {
    uint32_t       dwSize;
    uint32_t       dwFlags;
    uint32_t       dwBufferBytes;
    uint32_t       dwReserved;
    LPWAVEFORMATEX lpwfxFormat;
};

struct DSBUFFERDESC {
    uint32_t       dwSize;
    uint32_t       dwFlags;
    uint32_t       dwBufferBytes;
    uint32_t       dwReserved;
    LPWAVEFORMATEX lpwfxFormat;
    GUID           guid3DAlgorithm;
};

#endif
