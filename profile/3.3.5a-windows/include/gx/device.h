#ifndef GX_DEVICE_H
#define GX_DEVICE_H

#include "system/types.h"

#include "storm/array.h"
#include "storm/array/uint16_t.h"
#include "storm/array/uint32_t.h"
#include "storm/array/c2vector.h"
#include "storm/array/c3vector.h"
#include "storm/array/cimvector.h"

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

typedef void (*DEVICERESTOREDCALLBACK)();
STORM_TS_GROWABLE_ARRAY(DEVICERESTOREDCALLBACK);

typedef void (*TEXTURERECREATIONCALLBACK)();
STORM_TS_GROWABLE_ARRAY(TEXTURERECREATIONCALLBACK);

typedef void (*DISPLAYCHANGECALLBACK)();
STORM_TS_GROWABLE_ARRAY(DISPLAYCHANGECALLBACK);

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
  // no base implementation
  void* v_fn_1_IRsSendToHw;
  // void ICursorCreate(const CGxFormat&);
  void* v_fn_2_ICursorCreate;
  // void ICursorDestroy();
  void* v_fn_3_ICursorDestroy;
  // void ICursorDraw();
  void* v_fn_4_ICursorDraw;
  // This gets called when window is resized. It runs a list of callbacks in an array.
  // two functions that are in this array (ONLY once in-game, not in login screen):
  // * 007E7FE0
  // * 00512920
  // void NotifyOnDeviceRestored();
  void* v_fn_5_NotifyOnDeviceRestored;
  // void NotifyOnTextureRecreation();
  void* v_fn_6_NotifyOnTextureRecreation;
  // void NotifyOnDisplayChange();
  void* v_fn_7_NotifyOnDisplayChange; 
  // void `scalar deleting destructor'(unsigned int)
  void* v_fn_8_scalar_deleting_destructor;
  // int32_t DeviceCreate(const CGxFormat&);
  void* v_fn_9_DeviceCreate;
  // int32_t DeviceCreate(long (*)(void*, uint32_t, uint32_t, int32_t), CGxFormat const&);
  void* v_fn_10_DeviceCreate;
  // void DeviceDestroy();
  void* v_fn_11_DeviceDestroy;
  // void DeviceEvictResources();
  void* v_fn_12_DeviceEvictResources;
  // int32_t DeviceSetFormat(const CGxFormat&);
  void* v_fn_13_DeviceSetFormat;
  // void DeviceSetBaseMipLevel(uint32_t);
  void* v_fn_14_DeviceSetBaseMipLevel;
  // void DeviceSetGamma(CGxGammaRamp const&);
  void* v_fn_15_DeviceSetGamma;
  // void DeviceSetGamma(float);
  void* v_fn_16_DeviceSetGamma;
  // no base implementation
  // void* DeviceWindow();
  void* v_fn_17_DeviceWindow;
  // void DeviceTakeScreenShot();
  void* v_fn_18_DeviceTakeScreenShot;
  // void DeviceReadScreenShot(uint32_t&, uint32_t&, const CImVector*&) */
  void* v_fn_19_DeviceReadScreenShot;
  // void DeviceReadPixels(CiRect&, TSGrowableArray<CImVector>&);
  void* v_fn_20_DeviceReadPixels;
  // void DeviceReadDepths(CiRect&, TSGrowableArray<float>&);
  void* v_fn_21_DeviceReadDepths;
  // void DeviceWM(EGxWM, int32_t, int32_t);
  void* v_fn_22_DeviceWM;
  // void DeviceSetRenderTarget(EGxBuffer, CGxTex*, uint32_t);
  void* v_fn_23;
  // void DeviceCopyTex(CGxTex*, uint32_t, CGxTex*, uint32_t);
  void* v_fn_24;
  void* v_fn_25;
  void* v_fn_26;
  void* v_fn_27;
  // void DeviceOverride(EGxOverride, uint32_t);
  void* v_fn_28_DeviceOverride;
  // void AddDeviceRestoredCallback(DEVICERESTOREDCALLBACK);
  void* v_fn_29_AddDeviceRestoredCallback;
  // int32_t RemoveDeviceRestoredCallback(DEVICERESTOREDCALLBACK);
  void* v_fn_30_RemoveDeviceRestoredCallback;
  // void AddTextureRecreationCallback(TEXTURERECREATIONCALLBACK);
  void* v_fn_31_AddTextureRecreationCallback;
  // int32_t RemoveTextureRecreationCallback(TEXTURERECREATIONCALLBACK);
  void* v_fn_32_RemoveTextureRecreationCallback;
  // void AddDisplayChangeCallback(DISPLAYCHANGECALLBACK);
  void* v_fn_33_AddDisplayChangeCallback;
  // int32_t RemoveDisplayChangeCallback(DISPLAYCHANGECALLBACK);
  void* v_fn_34_RemoveDisplayChangeCallback;
  // void CapsWindowSize(CRect&);
  void* v_fn_35_CapsWindowSize;
  // void CapsWindowSize(CRect&);
  void* v_fn_36_CapsWindowSizeInScreenCoords;
  void* v_fn_37;
  // void ScenePresent(uint32_t);
  void* v_fn_38_ScenePresent;
  // void SceneClear(uint32_t, CImVector);
  void* v_fn_39_SceneClear;
  // void XformSetProjection(const C44Matrix&);
  void* v_fn_40_XformSetProjection;
  // void XformSetView(const C44Matrix&);
  void* v_fn_41_XformSetView;
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
  void* v_fn_71_IShaderDestroy;
  // void IShaderCreate(CGxShader*);
  void* v_fn_72_IShaderCreate;
  // void CursorSetVisible(int32_t);
  void* v_fn_73_CursorSetVisible;
  // void* CursorLock();
  void* v_fn_74_CursorLock;
  // void CursorUnlock(uint32_t, uint32_t);
  void* v_fn_75_CursorUnlock;
  // void StereoSetConvergence(float);
  void* v_fn_76_StereoSetConvergence;
  // double StereoGetConvergence();
  void* v_fn_77_StereoGetConvergence;
  // void StereoSetSeparation(float);
  void* v_fn_78_StereoSetSeparation;
  // double StereoGetSeparation();
  void* v_fn_79_StereoGetSeparation;
  // bool StereoEnabled();
  void* v_fn_80_StereoEnabled;
  // void DebugGroupBegin(const char*, char*);
  void* v_fn_81_DebugGroupBegin;
  // void DebugGroupEnd();
  void* v_fn_82_DebugGroupEnd;
  // void DebugEvent(const char*, char*);
  void* v_fn_83_DebugEvent;
};

// this class is at least 14688 bytes in size
struct CGxDevice {
  // pointer to struct CGxDevice__vtable
  CGxDevice__vtable* v_vtable; // 0x0 (size: 0x4)
  TSGrowableArray_CGxPushedRenderState m_pushedStates; // 0x4 (size: 0x14)
  TSGrowableArray_uint32_t m_stackOffsets; // 0x18 (size: 0x14)
  TSGrowableArray_EGxRenderState m_dirtyStates; // 0x2C (size: 0x14)
  uint32_t m_unk34[4];
  C3Vector m_primVertex;
  C2Vector m_primTexCoord[8];
  C3Vector m_primNormal;
  CImVector m_primColor;
  TSGrowableArray_C3Vector m_primVertexArray;
  TSGrowableArray_C2Vector m_primTexCoordArray[8];
  TSGrowableArray_C3Vector m_primNormalArray;
  TSGrowableArray_CImVector m_primColorArray;
  TSGrowableArray_uint16_t m_primIndexArray;
  uint32_t m_primMask;
  CRect m_defWindowRect; // 0x164 (size: 0x10)
  CRect m_curWindowRect; // 0x174 (size: 0x10)
  TSGrowableArray_DEVICERESTOREDCALLBACK m_deviceRestoredCallbacks; // 0x184
  TSGrowableArray_TEXTURERECREATIONCALLBACK m_textureRecreationCallbacks;
  TSGrowableArray_DISPLAYCHANGECALLBACK m_displayChangeCallbacks;
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
  // Invented name, though seems to have the same place as CGxDeviceD3d::m_d3dNeedsReset (Alpha) 
  int32_t m_needsReset;
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
  uint32_t unk2904[19]; // 0x2904 (size 0x4C) 
  int32_t m_cursorVisible;
  int32_t m_hardwareCursor; // 0x2954 (size 0x4)
  uint32_t m_cursorHotspotX;
  uint32_t m_cursorHotspotY;
  uint32_t m_cursor[1024]; // 0x2960 (size 0x4)
  CGxTex* m_cursorTexture; // 0x3960 (size 0x4)
  float m_cursorDepth; // 0x3964 (size 0x4)
  // 0x3968 == 14692 (the complete size of CGxDevice)
};

#endif