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

typedef struct CGxAppRenderState CGxAppRenderState;
typedef struct CGxPushedRenderState CGxPushedRenderState;
typedef struct ShaderConstants ShaderConstants;
typedef struct CGxDevice CGxDevice;
typedef struct CGxDevice__vtable CGxDevice__vtable;

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

// 84 functions
struct CGxDevice__vtable {
  // void ITexMarkAsUpdated(CGxTex*, unsigned int);
  void* v_fn_0_ITexMarkAsUpdated;
  // void IRsSendToHw(EGxRenderState);
  void* v_fn_1_IRsSendToHw;
  // void ICursorCreate(CGxFormat const&);
  void* v_fn_2_ICursorCreate;
  // void ICursorDestroy();
  void* v_fn_3_ICursorDestroy;
  // void ICursorDraw();
  void* v_fn_4_ICursorDraw;
  void* v_fn_5;
  void* v_fn_6;
  void* v_fn_7;
  void* v_fn_8;
  void* v_fn_9;
  void* v_fn_10_DeviceCreate;
  void* v_fn_11;
  void* v_fn_12;
  void* v_fn_13_DeviceSetFormat;
  void* v_fn_14_DeviceSetBaseMipLevel;
  void* v_fn_15_DeviceSetGamma;
  void* v_fn_16;
  void* v_fn_17;
  void* v_fn_18;
  void* v_fn_19;
  void* v_fn_20;
  void* v_fn_21;
  void* v_fn_22;
  void* v_fn_23;
  void* v_fn_24;
  void* v_fn_25;
  void* v_fn_26;
  void* v_fn_27;
  void* v_fn_28;
  void* v_fn_29;
  void* v_fn_30;
  void* v_fn_31;
  void* v_fn_32;
  void* v_fn_33;
  void* v_fn_34;
  void* v_fn_35_CapsWindowSize;
  void* v_fn_36;
  void* v_fn_37;
  void* v_fn_38;
  void* v_fn_39;
  void* v_fn_40;
  void* v_fn_41;
  void* v_fn_42;
  void* v_fn_43;
  void* v_fn_44;
  void* v_fn_45;
  void* v_fn_46;
  void* v_fn_47;
  void* v_fn_48;
  void* v_fn_49;
  void* v_fn_50;
  void* v_fn_51;
  void* v_fn_52;
  void* v_fn_53;
  void* v_fn_54;
  void* v_fn_55;
  void* v_fn_56;
  void* v_fn_57;
  void* v_fn_58;
  void* v_fn_59;
  void* v_fn_60;
  void* v_fn_61;
  void* v_fn_62;
  void* v_fn_63;
  void* v_fn_64;
  void* v_fn_65;
  void* v_fn_66;
  void* v_fn_67;
  void* v_fn_68;
  void* v_fn_69;
  void* v_fn_70;
  void* v_fn_71;
  void* v_fn_72;
  void* v_fn_73;
  void* v_fn_74;
  void* v_fn_75;
  void* v_fn_76;
  void* v_fn_77;
  void* v_fn_78;
  void* v_fn_79;
  void* v_fn_80;
  void* v_fn_81;
  void* v_fn_82;
  void* v_fn_83;
};

// this class is at least 14688 bytes in size
struct CGxDevice {
  // TODO: pointer to struct CGxDevice__vtable
  CGxDevice__vtable* v_vtable; // 0x0
  TSGrowableArray_CGxPushedRenderState m_pushedStates;
  TSGrowableArray_uint32_t m_stackOffsets;
  TSGrowableArray_EGxRenderState m_dirtyStates;
  uint32_t m_unk[73];
  CRect m_defWindowRect;
  CRect m_curWindowRect; // 0x174
  EGxApi m_api; // 0x1b4
  CGxFormat m_format;
  CGxCaps m_caps;
  // TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[GxShTargets_Last];
  TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[6];
  int32_t (*m_windowProc)(void* window, uint32_t message, uintptr_t wparam, intptr_t lparam);
  int32_t m_context;
  int32_t intF5C;
  int32_t m_windowVisible;
  int32_t intF64;
  int32_t intF6C;
  CBoundingBox m_viewport;
  C44Matrix m_projection;
  C44Matrix m_projNative;
  // CGxMatrixStack m_xforms[GxXforms_Last];
  CGxMatrixStack m_xforms[11];
  uint32_t m_appMasterEnables;
  uint32_t m_hwMasterEnables;
  TSList_CGxPool m_poolList;
  // CGxBuf* m_bufLocked[GxPoolTargets_Last];
  CGxBuf* m_bufLocked[2];
  CGxPool* m_vertexPool;
  CGxPool* m_indexPool;
  // CGxBuf* m_streamBufs[GxPoolTargets_Last];
  CGxBuf* m_streamBufs[2];
  // CGxVertexAttrib m_primVertexFormatAttrib[GxVertexBufferFormats_Last];
  CGxVertexAttrib m_primVertexFormatAttrib[14];
  // CGxBuf* m_primVertexFormatBuf[GxVertexBufferFormats_Last];
  CGxBuf* m_primVertexFormatBuf[14];
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