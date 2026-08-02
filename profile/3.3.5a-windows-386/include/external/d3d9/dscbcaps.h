#ifndef D3D9_DSCB_CAPS_H
#define D3D9_DSCB_CAPS_H

DECLARE_STRUCT(DSCBCAPS);

typedef const DSCBCAPS* LPCDSCBCAPS;
typedef DSCBCAPS*       LPDSCBCAPS;

struct DSCBCAPS {
    uint32_t dwSize;
    uint32_t dwFlags;
    uint32_t dwBufferBytes;
    uint32_t dwReserved;
};

#endif
