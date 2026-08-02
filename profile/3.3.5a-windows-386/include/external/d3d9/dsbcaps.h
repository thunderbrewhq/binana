#ifndef D3D9_DSB_CAPS_H
#define D3D9_DSB_CAPS_H

DECLARE_STRUCT(DSBCAPS);

struct DSBCAPS {
    uint32_t dwSize;
    uint32_t dwFlags;
    uint32_t dwBufferBytes;
    uint32_t dwUnlockTransferRate;
    uint32_t dwPlayCpuOverhead;
};

typedef DSBCAPS*       LPDSBCAPS;
typedef const DSBCAPS* LPCDSBCAPS;

#endif
