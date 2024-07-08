#ifndef GX_DEVICE_H
#define GX_DEVICE_H

#include <stdint.h>

#include "storm/array.h"
#include "storm/array/uint32_t.h"

#include "tempest/box.h"
#include "tempest/matrix.h"
#include "tempest/rect.h"
#include "tempest/vector.h"

#include "gx/types.h"
#include "gx/caps.h"
#include "gx/format.h"
#include "gx/state_bom.h"
#include "gx/shader.h"
#include "gx/matrix_stack.h"
#include "gx/buffer.h"

typedef struct CGxDevice CGxDevice;

struct CGxAppRenderState {
  CGxStateBom m_value;
  uint32_t m_stackDepth;
  int32_t m_dirty;
};
STORM_TS_FIXED_ARRAY(CGxAppRenderState);

struct CGxPushedRenderState {
  EGxRenderState m_which;
  CGxStateBom m_value;
  uint32_t m_stackDepth;
};
STORM_TS_GROWABLE_ARRAY(CGxPushedRenderState);

struct ShaderConstants {
  C4Vector constants[256];
  uint32_t unk1;
  uint32_t unk2;
};

// minimum size in binary: 3944 bytes
struct CGxDevice {
  // TODO: pointer to struct CGxDevice__vtable
  void* v_vtable;
  TSGrowableArray_CGxPushedRenderState m_pushedStates;
  TSGrowableArray_uint32_t m_stackOffsets;
  TSGrowableArray_EGxRenderState m_dirtyStates;
  CRect m_defWindowRect;
  CRect m_curWindowRect;
  EGxApi m_api;
  CGxFormat m_format;
  CGxCaps m_caps;
  TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[GxShTargets_Last];
  int32_t (*m_windowProc)(void* window, uint32_t message, uintptr_t wparam, intptr_t lparam);
  int32_t m_context;
  int32_t intF5C;
  int32_t m_windowVisible;
  int32_t intF64;
  int32_t intF6C;
  CBoundingBox m_viewport;
  C44Matrix m_projection;
  C44Matrix m_projNative;
  CGxMatrixStack m_xforms[GxXforms_Last];
  uint32_t m_appMasterEnables;
  uint32_t m_hwMasterEnables;
  TSList_CGxPool m_poolList;
  CGxBuf* m_bufLocked[GxPoolTargets_Last];
  CGxPool* m_vertexPool;
  CGxPool* m_indexPool;
  CGxBuf* m_streamBufs[GxPoolTargets_Last];
  CGxVertexAttrib m_primVertexFormatAttrib[GxVertexBufferFormats_Last];
  CGxBuf* m_primVertexFormatBuf[GxVertexBufferFormats_Last];
  uint32_t m_primVertexMask;
  uint32_t m_primVertexDirty;
  EGxVertexBufferFormat m_primVertexFormat;
  CGxBuf* m_primVertexBuf;
  uint32_t m_primVertexSize;
  CGxBuf* m_primIndexBuf;
  int32_t m_primIndexDirty;
  TSFixedArray_CGxAppRenderState m_appRenderStates;
  TSFixedArray_CGxStateBom m_hwRenderStates;
  uint32_t m_baseMipLevel; // TODO placeholder
};

#endif