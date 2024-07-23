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
#include "gx/texture.h"

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
  // void ITexMarkAsUpdated(CGxTex*, uint32_t);
  void* v_fn_0_ITexMarkAsUpdated;
  // void IRsSendToHw(EGxRenderState);
  void* v_fn_1_IRsSendToHw;
  // void ICursorCreate(const CGxFormat&);
  void* v_fn_2_ICursorCreate;
  // void ICursorDestroy();
  void* v_fn_3_ICursorDestroy;
  // void ICursorDraw();
  void* v_fn_4_ICursorDraw;
  // don't know if this ever gets called (IStateSync something?)
  void* v_fn_5;
  // don't know if this ever gets called (IStateSync something?)
  void* v_fn_6;
  // don't know if this ever gets called (IStateSync something?)
  void* v_fn_7; 
  // don't know if this ever gets called (something deleted?)
  void* v_fn_8;
  void* v_fn_9;
  // int32_t DeviceCreate(long (*)(void*, uint32_t, uint32_t, int32_t), CGxFormat const&);
  void* v_fn_10_DeviceCreate;
  void* v_fn_11;
  void* v_fn_12;
  // int32_t DeviceSetFormat(struct CGxFormat const &);
  void* v_fn_13_DeviceSetFormat;
  // void DeviceSetBaseMipLevel(uint32_t);
  void* v_fn_14_DeviceSetBaseMipLevel;
  // void DeviceSetGamma(CGxGammaRamp const&);
  void* v_fn_15_DeviceSetGamma;
  void* v_fn_16;
  void* v_fn_17;
  void* v_fn_18;
  void* v_fn_19;
  void* v_fn_20;
  void* v_fn_21;
  // void DeviceWM(EGxWM, int32_t, int32_t);
  void* v_fn_22_DeviceWM;
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
  // void CapsWindowSize(CRect&);
  void* v_fn_35_CapsWindowSize;
  void* v_fn_36;
  void* v_fn_37;
  // void ScenePresent(uint32_t);
  void* v_fn_38_ScenePresent;
  void* v_fn_39;
  // void XformSetProjection(const C44Matrix&);
  void* v_fn_40_XformSetProjection;
  void* v_fn_41;
  // void Draw(CGxBatch*, int32_t);
  void* v_fn_42_Draw;
  void* v_fn_43;
  void* v_fn_44;
  void* v_fn_45;
  void* v_fn_46;
  void* v_fn_47;
  void* v_fn_48;
  void* v_fn_49;
  void* v_fn_50;
  // void MasterEnableSet(EGxMasterEnables, int);
  void* v_fn_51_MasterEnableSet;
  // void PoolSizeSet(CGxPool*, uint32_t);
  void* v_fn_52_PoolSizeSet;
  // void PoolDestroy(CGxPool*);
  void* v_fn_53_PoolDestroy;
  // char* BufLock(CGxBuf*);
  void* v_fn_54_BufLock;
  // int32_t BufUnlock(CGxBuf*, uint32_t);
  void* v_fn_55_BufUnlock;
  // void BufData(CGxBuf*, void const*, uint32_t, uint32_t); 
  void* v_fn_56_BufData;
  // int32_t TexCreate(EGxTexTarget, uint32_t, uint32_t, uint32_t, EGxTexFormat, EGxTexFormat, CGxTexFlags, void*, void (*)(EGxTexCommand, uint32_t, uint32_t, uint32_t, uint32_t, void*, uint32_t&, void const*&), char const*, CGxTex*&);
  void* v_fn_57_TexCreate;
  // void TexDestroy(CGxTex*);
  void* v_fn_58_TexDestroy;
  // int32_t TexCopy(CGxTex*, CGxTex*, const C2iVector&, const C2iVector&, const C2iVector&, uint32_t);
  void* v_fn_59_TexCopy;
  void* v_fn_60;
  void* v_fn_61;
  void* v_fn_62;
  void* v_fn_63;
  void* v_fn_64;
  void* v_fn_65;
  void* v_fn_66;
  void* v_fn_67;
  // void ShaderCreate(CGxShader*[], EGxShTarget, const char*, const char*, int32_t);
  void* v_fn_68_ShaderCreate;
  void* v_fn_69;
  // void ShaderConstantsSet(EGxShTarget, uint32_t, const float*, uint32_t);
  void* v_fn_70_ShaderConstantsSet;
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
  // pointer to struct CGxDevice__vtable
  CGxDevice__vtable* v_vtable; // 0x0 (size: 0x4)
  TSGrowableArray_CGxPushedRenderState m_pushedStates; // 0x4 (size: 0x14)
  TSGrowableArray_uint32_t m_stackOffsets; // 0x18 (size: 0x14)
  TSGrowableArray_EGxRenderState m_dirtyStates; // 0x2C (size: 0x14)
  uint32_t m_unk40[76];
  CRect m_defWindowRect; // 0x164 (size: 0x10)
  CRect m_curWindowRect; // 0x174 (size: 0x10)
  uint32_t m_unk184[12];
  EGxApi m_api; // 0x1b4
  uint32_t m_cpuFeatures;
  CGxFormat m_format;
  CGxCaps m_caps;
  uint32_t m_baseMipLevel;
  CGxGammaRamp m_gammaRamp;
  CGxGammaRamp m_systemGammaRamp;
  // TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[GxShTargets_Last];
  // TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[6];
  int32_t (*m_windowProc)(void* window, uint32_t message, uintptr_t wparam, intptr_t lparam);
  int32_t m_context;
  int32_t intF5C;
  int32_t m_windowVisible;
  int32_t intF64;
  int32_t intF68;
  int32_t intF6C;
  CBoundingBox m_viewport;
  C44Matrix m_projection;
  C44Matrix m_projNative;
  // CGxMatrixStack m_xforms[GxXforms_Last];
  CGxMatrixStack m_xforms[11];
  CGxMatrixStack m_texGen[8];
  uint32_t unk24D0[162];
  uint32_t m_appMasterEnables;
  uint32_t m_hwMasterEnables;
  TSList_CGxPool m_poolList;
  uint32_t unk276C[3];
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
  uint32_t unk28C4;
  uint32_t unk28C8;
  uint32_t unk28CC;
  uint32_t unk28D0;
  uint32_t unk28D4;
  uint32_t unk28D8;
  uint32_t unk28DC;
  uint32_t unk28E0;
  uint32_t unk28E4;
  uint32_t unk28E8;
  TSFixedArray_CGxAppRenderState m_appRenderStates;
  TSFixedArray_CGxStateBom m_hwRenderStates;
  uint32_t unk2904[20]; // 0x2904 (size 0x50) 
  int32_t m_hardwareCursor; // 0x2954 (size 0x4)
  uint32_t unk2958[1026]; // 0x2958 (size 0x1008)
  CGxTex* m_cursorTexture; // 0x3960 (size 0x4)
  // 0x3964 == 14688 (the complete size of CGxDevice)
};

#endif