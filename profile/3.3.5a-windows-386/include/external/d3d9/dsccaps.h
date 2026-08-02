#ifndef D3D9_DSC_CAPS_H
#define D3D9_DSC_CAPS_H

DECLARE_STRUCT(DSCCAPS);

typedef const DSCCAPS* LPCDSCCAPS;
typedef DSCCAPS*       LPDSCCAPS;

struct DSCCAPS {
    uint32_t dwSize;
    uint32_t dwFlags;
    uint32_t dwFormats;
    uint32_t dwChannels;
};

#endif
