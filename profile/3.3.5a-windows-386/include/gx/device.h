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

DECLARE_STRUCT(CGxAppRenderState);
DECLARE_STRUCT(CGxPushedRenderState);
DECLARE_STRUCT(ShaderConstants);
DECLARE_STRUCT(CGxDevice);
DECLARE_STRUCT(CGxDevice__vtable);

typedef void (*DEVICERESTOREDCALLBACK)();
STORM_TS_GROWABLE_ARRAY(DEVICERESTOREDCALLBACK);

typedef void (*TEXTURERECREATIONCALLBACK)();
STORM_TS_GROWABLE_ARRAY(TEXTURERECREATIONCALLBACK);

typedef void (*STEREOCHANGEDCALLBACK)();
STORM_TS_GROWABLE_ARRAY(STEREOCHANGEDCALLBACK);

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
  // void ITexMarkAsUpdated(CGxTex* texId);
  void* v_fn_0_ITexMarkAsUpdated;
  // void IRsSendToHw(EGxRenderState rs);
  // no base implementation
  void* v_fn_1_IRsSendToHw;
  // void ICursorCreate(const CGxFormat& format);
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
  // void `scalar deleting destructor'(uint32_t __flags)
  void* v_fn_8_scalar_deleting_destructor;
  // int32_t DeviceCreate(const CGxFormat& format);
  void* v_fn_9_DeviceCreate;
  // int32_t DeviceCreate(long (*windowProc)(void*, uint32_t, uint32_t, int32_t), CGxFormat const& format);
  void* v_fn_10_DeviceCreate;
  // void DeviceDestroy();
  void* v_fn_11_DeviceDestroy;
  // void DeviceEvictResources();
  void* v_fn_12_DeviceEvictResources;
  // int32_t DeviceSetFormat(const CGxFormat& format);
  void* v_fn_13_DeviceSetFormat;
  // void DeviceSetBaseMipLevel(uint32_t mipLevel);
  void* v_fn_14_DeviceSetBaseMipLevel;
  // void DeviceSetGamma(CGxGammaRamp const& ramp);
  void* v_fn_15_DeviceSetGamma;
  // void DeviceSetGamma(float gamma);
  void* v_fn_16_DeviceSetGamma;
  // no base implementation
  // void* DeviceWindow();
  void* v_fn_17_DeviceWindow;
  // void DeviceTakeScreenShot();
  void* v_fn_18_DeviceTakeScreenShot;
  // void DeviceReadScreenShot(uint32_t& w, uint32_t& h, const CImVector*& pixels) */
  void* v_fn_19_DeviceReadScreenShot;
  // void DeviceReadPixels(CiRect& rect, TSGrowableArray<CImVector>& pixels);
  void* v_fn_20_DeviceReadPixels;
  // void DeviceReadDepths(CiRect& rect, TSGrowableArray<float>& depths);
  void* v_fn_21_DeviceReadDepths;
  // void DeviceWM(EGxWM wm, int32_t param1, int32_t param2);
  void* v_fn_22_DeviceWM;
  // void DeviceSetRenderTarget(EGxBuffer buffer, CGxTex* texture, uint32_t plane);
  void* v_fn_23_DeviceSetRenderTarget;
  // void v_fn_24(); DeviceReleaseDepthBuffer?
  // d3d:
  //   this->m_d3dDevice->GetDepthStencilSurface(&PTR_00C6033C);
  //   PTR_00C6033C->Release();
  void* v_fn_24; 
  // void v_fn_25(); DeviceResetDepthBuffer?
  // d3d:
  //   this->m_d3dDevice->SetDepthStencilSurface(PTR_00C6033C);
  void* v_fn_25; 
  // void v_fn_26(CGxTex* texId); DeviceResolveDepthBuffer(CGxTex*) seems to be the most logical candidate for this
  // d3d:
  //   if (this->m_context) {
  //     if (texId &&
  //          (texId->m_needsCreation ||
  //            (texId->m_apiSpecificData == nullptr &&
  //             texId->m_apiSpecificData2 == nullptr)) {
  //        this->ITexCreate(texId);
  //      }
  //      this->m_d3dDevice->SetDepthStencilSurface(texId->m_apiSpecificData);
  //   }
  // void DeviceResolveDepthBuffer(CGxTex* texId);
  void* v_fn_26_DeviceResolveDepthBuffer;
  // void DeviceCopyTex(CGxTex* a1, int32_t a2, CGxTex* a3, int32_t a4);
  void* v_fn_27_DeviceCopyTex;
  // void DeviceOverride(EGxOverride override, uint32_t value);
  void* v_fn_28_DeviceOverride;
  // void AddDeviceRestoredCallback(DEVICERESTOREDCALLBACK callback);
  void* v_fn_29_AddDeviceRestoredCallback;
  // int32_t RemoveDeviceRestoredCallback(DEVICERESTOREDCALLBACK callback);
  void* v_fn_30_RemoveDeviceRestoredCallback;
  // void AddTextureRecreationCallback(TEXTURERECREATIONCALLBACK callback);
  void* v_fn_31_AddTextureRecreationCallback;
  // int32_t RemoveTextureRecreationCallback(TEXTURERECREATIONCALLBACK callback);
  void* v_fn_32_RemoveTextureRecreationCallback;
  // void AddStereoChangedCallback(STEREOCHANGEDCALLBACK callback);
  void* v_fn_33_AddStereoChangedCallback;
  // int32_t RemoveStereoChangeCallback(STEREOCHANGEDCALLBACK callback);
  void* v_fn_34_RemoveStereoChangedCallback;
  // void CapsWindowSize(CRect& dst);
  void* v_fn_35_CapsWindowSize;
  // void CapsWindowSize(CRect& dst);
  void* v_fn_36_CapsWindowSizeInScreenCoords;
  // void LogCrashInfo(char* buffer, uint32_t size);
  void* v_fn_37_LogCrashInfo;
  // void ScenePresent(uint32_t mask);
  void* v_fn_38_ScenePresent;
  // void SceneClear(uint32_t mask, CImVector color);
  void* v_fn_39_SceneClear;
  // void XformSetProjection(const C44Matrix& matrix);
  void* v_fn_40_XformSetProjection;
  // void XformSetView(const C44Matrix& matrix);
  void* v_fn_41_XformSetView;
  // void Draw(CGxBatch*, int32_t);
  void* v_fn_42_Draw;
  // void PrimBegin(EGxPrim primType);
  void* v_fn_43_PrimBegin;
  // void PrimDrawElements();
  void* v_fn_44_PrimDrawElements;
  // void PrimVertex(const C3Vector& v);
  void* v_fn_45_PrimVertex;
  // void PrimTexCoord(uint32_t tmu, const C2Vector& t);
  void* v_fn_46_PrimTexCoord;
  // void PrimNormal(const C3Vector& n);
  void* v_fn_47_PrimNormal;
  // void PrimColor(const CImVector& c);
  void* v_fn_48_PrimColor;
  // void PrimPointSize(float s);
  void* v_fn_49_PrimPointSize;
  // void PrimeLineWidth(float w);
  void* v_fn_50_PrimLineWidth;
  // void MasterEnableSet(EGxMasterEnables state, int32_t enable);
  void* v_fn_51_MasterEnableSet;
  // void PoolSizeSet(CGxPool* pool, uint32_t size);
  void* v_fn_52_PoolSizeSet;
  // void PoolDestroy(CGxPool* pool);
  void* v_fn_53_PoolDestroy;
  // char* BufLock(CGxBuf* buf);
  void* v_fn_54_BufLock;
  // int32_t BufUnlock(CGxBuf* buf, uint32_t size);
  void* v_fn_55_BufUnlock;
  // void BufData(CGxBuf* buf, const void* data, uint32_t size, uint32_t offset); 
  void* v_fn_56_BufData;
  // int32_t TexCreate(EGxTexTarget target, uint32_t width, uint32_t height, uint32_t depth, EGxTexFormat format, EGxTexFormat dataFormat, CGxTexFlags flags, void* userArg, void (*userFunc)(EGxTexCommand, uint32_t, uint32_t, uint32_t, uint32_t, void*, uint32_t&, void const*&), const char* name, CGxTex*& texId);
  void* v_fn_57_TexCreate;
  // void TexDestroy(CGxTex* texId);
  void* v_fn_58_TexDestroy;
  // int32_t TexCopy(CGxTex* a1, CGxTex* a2, const C2iVector& a3, const C2iVector& a4, const C2iVector& a5, uint32_t a6);
  void* v_fn_59_TexCopy;
  // bool TexStretch(CGxTex* a1, CGxTex* a2, const CiRect* a3, const CiRect* a4, uint32_t a5, uint32_t a6);
  void* v_fn_60_TexStretch;
  // void TexSetCacheSize(int32_t cacheSize);
  void* v_fn_61_TexSetCacheSize;
  // void QueryCreate(CGxQuery*& query, EGxQueryType queryType);
  void* v_fn_62_QueryCreate;
  // bool QueryDestroy(CGxQuery* query);
  void* v_fn_63_QueryDestroy;
  // bool QueryBegin(CGxQuery* query);
  void* v_fn_64_QueryBegin;
  // bool QueryEnd(CGxQuery* query);
  void* v_fn_65_QueryEnd;
  // bool QueryGetParam(CGxQuery* query, EGxQueryParam param, uint32_t* data);
  void* v_fn_66_QueryGetParam;
  // bool QueryGetData(CGxQuery* query, uint32_t* data);
  void* v_fn_67_QueryGetData;
  // void ShaderCreate(CGxShader*[] shaders, EGxShTarget target, const char* a3, const char* a4, int32_t permutations);
  void* v_fn_68_ShaderCreate;
  // void ShaderRelease(CGxShader*& shader);
  void* v_fn_69_ShaderRelease;
  // void ShaderConstantsSet(EGxShTarget target, uint32_t index, const float* constraints, uint32_t count);
  void* v_fn_70_ShaderConstantsSet;
  // void IShaderReload(CGxShader* shader, const char* a2, const char* a3);
  void* v_fn_71_IShaderReload;
  // void IShaderCreate(CGxShader* shader);
  void* v_fn_72_IShaderCreate;
  // void CursorSetVisible(int32_t visible);
  void* v_fn_73_CursorSetVisible;
  // uint32_t* CursorLock();
  void* v_fn_74_CursorLock;
  // void CursorUnlock(uint32_t x, uint32_t y);
  void* v_fn_75_CursorUnlock;
  // void StereoSetConvergence(float c);
  void* v_fn_76_StereoSetConvergence;
  // double StereoGetConvergence();
  void* v_fn_77_StereoGetConvergence;
  // void StereoSetSeparation(float s);
  void* v_fn_78_StereoSetSeparation;
  // double StereoGetSeparation();
  void* v_fn_79_StereoGetSeparation;
  // bool StereoEnabled();
  void* v_fn_80_StereoEnabled;
  // void DebugGroupBegin(const char* a1, char* a2);
  void* v_fn_81_DebugGroupBegin;
  // void DebugGroupEnd();
  void* v_fn_82_DebugGroupEnd;
  // void DebugEvent(const char* a1, char* a2);
  void* v_fn_83_DebugEvent;
};

// this class is 14692 bytes in size
struct CGxDevice {
  // pointer to struct CGxDevice__vtable
  CGxDevice__vtable* v_vtable; // 0x0 (size: 0x4)
  TSGrowableArray_CGxPushedRenderState m_pushedStates; // 0x4 (size: 0x14)
  TSGrowableArray_uint32_t m_stackOffsets; // 0x18 (size: 0x14)
  TSGrowableArray_EGxRenderState m_dirtyStates; // 0x2C (size: 0x14)
  EGxPrim m_primType;
  uint32_t m_unk38[2]; // m_indexLocked-m_vertexLocked?
  int32_t m_inBeginEnd;
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
  TSGrowableArray_STEREOCHANGEDCALLBACK m_stereoChangedCallbacks; // check darwin @ 00a2b779
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
  uint32_t unk24D0[102];
  // uint32_t unk2536[60];
  TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[6];
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