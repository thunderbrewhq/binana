#ifndef GX_FORMAT_H
#define GX_FORMAT_H

#include "system/types.h"

#include "tempest/vector.h"

DECLARE_ENUM(CGxFormat__Format);
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
  uint32_t apiSpecificModeID;
  bool hwTnL;
  bool hwCursor; // 0x5, UC
  int8_t fixLag;
  int8_t window;
  bool aspect; // UC
  int32_t maximize;
  CGxFormat__Format depthFormat;
  C2iVector size;
                  // set by CVGxTripleBufferCallback
  uint32_t backBufferCount; // buffering? buffer? framebufferCount?
  uint32_t multisampleCount;
  float multisampleQuality; // UC, write at 00769693
  CGxFormat__Format colorFormat;
  uint32_t refreshRate;
  uint32_t vsync;
  bool stereoEnabled; // UC, 34
  // something to do with fixed function?
  // write at 0076AD4C
  // vertexShaderTarget ?
  int32_t fixedFunction[6];
  C2iVector pos;
};

#endif
