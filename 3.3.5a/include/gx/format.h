#ifndef GX_FORMAT_H
#define GX_FORMAT_H

#include <stdint.h>
#include <stdbool.h>

#include "tempest/vector.h"

typedef enum CGxFormat__Format CGxFormat__Format;
typedef struct CGxFormat CGxFormat;

enum CGxFormat__Format {
  Fmt_Rgb565 = 0,
  Fmt_ArgbX888 = 1,
  Fmt_Argb8888 = 2,
  Fmt_Argb2101010 = 3,
  Fmt_Ds160 = 4,
  Fmt_Ds24X = 5,
  Fmt_Ds248 = 6,
  Fmt_Ds320 = 7,
  Formats_Last = 8
};

struct CGxFormat {
  bool hwTnL;
  int8_t window;
  int32_t maximize;
  CGxFormat__Format depthFormat;
  C2iVector size;
  uint32_t sampleCount;
  CGxFormat__Format colorFormat;
  uint32_t refreshRate;
  uint32_t vsync;
  C2iVector pos;
};

#endif
