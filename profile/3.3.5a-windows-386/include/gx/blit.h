#ifndef GX_BLIT_H
#define GX_BLIT_H

DECLARE_ENUM(BlitAlpha);
DECLARE_ENUM(BlitFormat);

#include "tempest/vector.h"

enum BlitAlpha {
  BlitAlpha_0 = 0,
  BlitAlpha_1 = 1,
  BlitAlpha_8 = 2,
  BlitAlpha_Filler = 3,
  BlitAlphas_Last = 4
};

enum BlitFormat {
  BlitFormat_Unknown = 0,
  BlitFormat_Abgr8888 = 1,
  BlitFormat_Argb8888 = 2,
  BlitFormat_Argb4444 = 3,
  BlitFormat_Argb1555 = 4,
  BlitFormat_Rgb565 = 5,
  BlitFormat_Dxt1 = 6,
  BlitFormat_Dxt3 = 7,
  BlitFormat_Dxt5 = 8,
  BlitFormat_Uv88 = 9,
  BlitFormat_Gr1616F = 10,
  BlitFormat_R32F = 11,
  BlitFormat_D24X8 = 12,
  BlitFormats_Last = 13
};

// typedef void (*BLIT_FUNCTION)(const C2iVector&, const void*, uint32_t, void*, uint32_t);
typedef void (*BLIT_FUNCTION)(C2iVector*, void*, uint32_t, void*, uint32_t);

#endif