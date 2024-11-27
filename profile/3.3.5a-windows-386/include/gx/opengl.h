#ifndef GX_OPENGL_H
#define GX_OPENGL_H

DECLARE_STRUCT(CGxDeviceOpenGl);

#include "gx/device.h"

// 15264 bytes - 14696 cgxdevice = 568
struct CGxDeviceOpenGl {
  CGxDevice b_base;
  uint32_t unk3968[142];
};

#endif