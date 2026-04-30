#ifndef GX_DEVICE_H
#define GX_DEVICE_H

#include "system/types.h"

#include "storm/array.h"
#include "storm/array/c2vector.h"
#include "storm/array/c3vector.h"
#include "storm/array/cimvector.h"
#include "storm/array/float.h"
#include "storm/array/uint16_t.h"
#include "storm/array/uint32_t.h"

#include "tempest/box.h"
#include "tempest/matrix.h"
#include "tempest/plane.h"
#include "tempest/rect.h"
#include "tempest/vector.h"

#include "gx/apilight.h"
#include "gx/batch.h"
#include "gx/buffer.h"
#include "gx/caps.h"
#include "gx/emergencymem.h"
#include "gx/format.h"
#include "gx/matrix_stack.h"
#include "gx/query.h"
#include "gx/shader.h"
#include "gx/state_bom.h"
#include "gx/texture.h"
#include "gx/types.h"

DECLARE_STRUCT(CGxAppRenderState);
DECLARE_STRUCT(CGxPushedRenderState);
DECLARE_STRUCT(ShaderConstants);
DECLARE_STRUCT(CGxDevice);
DECLARE_STRUCT(CGxDevice__TextureTarget);
DECLARE_STRUCT(CGxDevice__v_table);
DECLARE_STRUCT(CGxDevice__GxLight);

typedef int32_t (
    *GxWindowProc_interface)(void* window, uint32_t message, uintptr_t wparam, intptr_t lparam);
typedef GxWindowProc_interface GxWindowProc;

typedef void (*DEVICERESTOREDCALLBACK_interface)();
typedef DEVICERESTOREDCALLBACK_interface DEVICERESTOREDCALLBACK;
STORM_TS_GROWABLE_ARRAY(DEVICERESTOREDCALLBACK);

typedef void (*TEXTURERECREATIONCALLBACK_interface)();
typedef TEXTURERECREATIONCALLBACK_interface TEXTURERECREATIONCALLBACK;
STORM_TS_GROWABLE_ARRAY(TEXTURERECREATIONCALLBACK);

typedef void (*STEREOCHANGEDCALLBACK_interface)();
typedef STEREOCHANGEDCALLBACK_interface STEREOCHANGEDCALLBACK;
STORM_TS_GROWABLE_ARRAY(STEREOCHANGEDCALLBACK);

struct CGxAppRenderState {
    CGxStateBom m_value;
    uint32_t    m_stackDepth;
    int32_t     m_dirty;
};
STORM_TS_FIXED_ARRAY(CGxAppRenderState);

struct CGxPushedRenderState {
    EGxRenderState m_which;
    CGxStateBom    m_value;
    uint32_t       m_stackDepth;
};
STORM_TS_GROWABLE_ARRAY(CGxPushedRenderState);

struct ShaderConstants {
    C4Vector constants[256];
    uint32_t unk1;
    uint32_t unk2;
};

struct CGxDevice__TextureTarget {
    CGxTex*  m_texture;
    uint32_t m_plane;
    void*    m_apiSpecific;
};

// 84 functions
#define INTERFACE CGxDevice
struct CGxDevice__v_table {
    // void ITexMarkAsUpdated(CGxTex* texId);
    P_METHOD(void, _00_ITexMarkAsUpdated, CGxTex* texId);
    // void IRsSendToHw(EGxRenderState rs);
    // no base implementation
    P_METHOD(void, _01_IRsSendToHw, EGxRenderState rs);
    // void ICursorCreate(const CGxFormat& format);
    P_METHOD(void, _02_ICursorCreate, CGxFormat* format);
    // void ICursorDestroy();
    E_METHOD(void, _03_ICursorDestroy);
    // void ICursorDraw();
    E_METHOD(void, _04_ICursorDraw);
    // This gets called when window is resized. It runs a list of callbacks in an array.
    // two functions that are in this array (ONLY once in-game, not in login screen):
    // * 007E7FE0
    // * 00512920
    // void NotifyOnDeviceRestored();
    E_METHOD(void, _05_NotifyOnDeviceRestored);
    // void NotifyOnTextureRecreation();
    E_METHOD(void, _06_NotifyOnTextureRecreation);
    // void NotifyOnStereoChanged();
    E_METHOD(void, _07_NotifyOnStereoChanged);
    // void `scalar deleting destructor'(uint32_t __flags)
    P_METHOD(void, _08_scalar_deleting_destructor, uint32_t __flags);
    // int32_t DeviceCreate(uintptr_t hwnd, const CGxFormat& format);
    P_METHOD(int32_t, _09_DeviceCreate, uintptr_t hwnd, CGxFormat* format);
    // int32_t DeviceCreate(long (*windowProc)(void*, uint32_t, uint32_t, int32_t), CGxFormat const&
    // format);
    P_METHOD(int32_t, _10_DeviceCreate, GxWindowProc windowProc, CGxFormat* format);
    // void DeviceDestroy();
    E_METHOD(void, _11_DeviceDestroy);
    // void DeviceEvictResources();
    E_METHOD(void, _12_DeviceEvictResources);
    // int32_t DeviceSetFormat(const CGxFormat& format);
    P_METHOD(int32_t, _13_DeviceSetFormat, CGxFormat* format);
    // void DeviceSetBaseMipLevel(uint32_t mipLevel);
    P_METHOD(void, _14_DeviceSetBaseMipLevel, uint32_t mipLevel);
    // void DeviceSetGamma(const CGxGammaRamp& ramp);
    P_METHOD(void, _15_DeviceSetGamma, CGxGammaRamp* ramp);
    // void DeviceSetGamma(float gamma);
    P_METHOD(void, _16_DeviceSetGamma, float gamma);
    // no base implementation
    // void* DeviceWindow();
    E_METHOD(void*, _17_DeviceWindow);
    // void DeviceTakeScreenShot();
    E_METHOD(void, _18_DeviceTakeScreenShot);
    // void DeviceReadScreenShot(uint32_t& w, uint32_t& h, const CImVector*& pixels) */
    P_METHOD(void, _19_DeviceReadScreenShot, uint32_t* w, uint32_t* h, CImVector** pixels);
    // void DeviceReadPixels(CiRect& rect, TSGrowableArray<CImVector>& pixels);
    P_METHOD(void, _20_DeviceReadPixels, CiRect* rect, TSGrowableArray_CImVector* pixels);
    // void DeviceReadDepths(CiRect& rect, TSGrowableArray<float>& depths);
    P_METHOD(void, _21_DeviceReadDepths, CiRect* rect, TSGrowableArray_float* depths);
    // void DeviceWM(EGxWM wm, int32_t param1, int32_t param2);
    P_METHOD(void, _22_DeviceWM, EGxWM wm, int32_t param1, int32_t param2);
    // void DeviceSetRenderTarget(EGxBuffer buffer, CGxTex* texture, uint32_t plane);
    P_METHOD(void, _23_DeviceSetRenderTarget, EGxBuffer buffer, CGxTex* texture, uint32_t plane);
    // void v_fn_24(); DeviceReleaseDepthBuffer?
    // d3d:
    //   this->m_d3dDevice->GetDepthStencilSurface(&PTR_00C6033C);
    //   PTR_00C6033C->Release();
    E_METHOD(void, _24);
    // void v_fn_25(); DeviceResetDepthBuffer?
    // d3d:
    //   this->m_d3dDevice->SetDepthStencilSurface(PTR_00C6033C);
    E_METHOD(void, _25);
    // void v_fn_26(CGxTex* texId); DeviceResolveDepthBuffer(CGxTex*) seems to be the most logical
    // candidate for this d3d:
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
    P_METHOD(void, _26_DeviceResolveDepthBuffer, CGxTex* texId);
    // void DeviceCopyTex(CGxTex* sourceTex, uint32_t sourcePlane, CGxTex* destTex, uint32_t
    // destPlane);
    P_METHOD(
        void,
        _27_DeviceCopyTex,
        CGxTex*  sourceTex,
        uint32_t sourcePlane,
        CGxTex*  destTex,
        uint32_t destPlane);
    // void DeviceOverride(EGxOverride override, uint32_t value);
    P_METHOD(void, _28_DeviceOverride, EGxOverride override, uint32_t value);
    // void AddDeviceRestoredCallback(DEVICERESTOREDCALLBACK callback);
    P_METHOD(void, _29_AddDeviceRestoredCallback, DEVICERESTOREDCALLBACK callback);
    // int32_t RemoveDeviceRestoredCallback(DEVICERESTOREDCALLBACK callback);
    P_METHOD(int32_t, _30_RemoveDeviceRestoredCallback, DEVICERESTOREDCALLBACK callback);
    // void AddTextureRecreationCallback(TEXTURERECREATIONCALLBACK callback);
    P_METHOD(void, _31_AddTextureRecreationCallback, TEXTURERECREATIONCALLBACK callback);
    // int32_t RemoveTextureRecreationCallback(TEXTURERECREATIONCALLBACK callback);
    P_METHOD(int32_t, _32_RemoveTextureRecreationCallback, TEXTURERECREATIONCALLBACK callback);
    // void AddStereoChangedCallback(STEREOCHANGEDCALLBACK callback);
    P_METHOD(void, _33_AddStereoChangedCallback, STEREOCHANGEDCALLBACK callback);
    // int32_t RemoveStereoChangeCallback(STEREOCHANGEDCALLBACK callback);
    P_METHOD(int32_t, _34_RemoveStereoChangedCallback, STEREOCHANGEDCALLBACK callback);
    // void CapsWindowSize(CRect& dst);
    P_METHOD(void, _35_CapsWindowSize, CRect* dst);
    // void CapsWindowSizeInScreenCoords(CRect& dst);
    P_METHOD(void, _36_CapsWindowSizeInScreenCoords, CRect* dst);
    // void LogCrashInfo(char* buffer, uint32_t buffersize);
    P_METHOD(void, _37_LogCrashInfo, char* buffer, uint32_t buffersize);
    // void ScenePresent();
    E_METHOD(void, _38_ScenePresent);
    // void SceneClear(uint32_t mask, CImVector color);
    P_METHOD(void, _39_SceneClear, uint32_t mask, CImVector color);
    // void XformSetProjection(const C44Matrix& matrix);
    P_METHOD(void, _40_XformSetProjection, C44Matrix* matrix);
    // void XformSetView(const C44Matrix& matrix);
    P_METHOD(void, _41_XformSetView, C44Matrix* matrix);
    // void Draw(CGxBatch* batch, int32_t indexed);
    P_METHOD(void, _42_Draw, CGxBatch* batch, int32_t indexed);
    // void PrimBegin(EGxPrim primType);
    P_METHOD(void, _43_PrimBegin, EGxPrim primType);
    // void PrimDrawElements();
    E_METHOD(void, _44_PrimDrawElements);
    // void PrimVertex(const C3Vector& v);
    P_METHOD(void, _45_PrimVertex, C3Vector* v);
    // void PrimTexCoord(uint32_t tmu, const C2Vector& t);
    P_METHOD(void, _46_PrimTexCoord, uint32_t tmu, C2Vector* t);
    // void PrimNormal(const C3Vector& n);
    P_METHOD(void, _47_PrimNormal, C3Vector* n);
    // void PrimColor(const CImVector& c);
    P_METHOD(void, _48_PrimColor, CImVector* c);
    // void PrimPointSize(float s);
    P_METHOD(void, _49_PrimPointSize, float s);
    // void PrimLineWidth(float w);
    P_METHOD(void, _50_PrimLineWidth, float w);
    // void MasterEnableSet(EGxMasterEnables state, int32_t enable);
    P_METHOD(void, _51_MasterEnableSet, EGxMasterEnables state, int32_t enable);
    // void PoolSizeSet(CGxPool* pool, uint32_t size);
    P_METHOD(void, _52_PoolSizeSet, CGxPool* pool, uint32_t size);
    // void PoolDestroy(CGxPool* pool);
    P_METHOD(void, _53_PoolDestroy, CGxPool* pool);
    // char* BufLock(CGxBuf* buf);
    P_METHOD(char*, _54_BufLock, CGxBuf* buf);
    // int32_t BufUnlock(CGxBuf* buf, uint32_t size);
    P_METHOD(int32_t, _55_BufUnlock, CGxBuf* buf, uint32_t size);
    // void BufData(CGxBuf* buf, const void* data, uint32_t size, uint32_t offset);
    P_METHOD(void, _56_BufData, CGxBuf* buf, const void* data, uint32_t size, uint32_t offset);
    // int32_t TexCreate(EGxTexTarget target, uint32_t width, uint32_t height, uint32_t depth,
    // EGxTexFormat format, EGxTexFormat dataFormat, CGxTexFlags flags, void* userArg, void
    // (*userFunc)(EGxTexCommand, uint32_t, uint32_t, uint32_t, uint32_t, void*, uint32_t&, void
    // const*&), const char* name, CGxTex*& texId);
    P_METHOD(
        int32_t,
        _57_TexCreate,
        EGxTexTarget  target,
        uint32_t      width,
        uint32_t      height,
        uint32_t      depth,
        EGxTexFormat  format,
        EGxTexFormat  dataFormat,
        CGxTexFlags   flags,
        void*         userArg,
        GxTexCallback userFunc,
        const char*   name,
        CGxTex**      texId);
    // void TexDestroy(CGxTex* texId);
    P_METHOD(void, _58_TexDestroy, CGxTex* texId);
    // int32_t TexCopy(CGxTex* destTex, CGxTex* sourceTex, const C2iVector& pos, const C2iVector&
    // size, uint32_t level, uint32_t plane);
    P_METHOD(
        int32_t,
        _59_TexCopy,
        CGxTex*    destTex,
        CGxTex*    sourceTex,
        C2iVector* pos,
        C2iVector* size,
        uint32_t   level,
        uint32_t   plane);
    // bool TexStretch(CGxTex* sourceTex, CGxTex* destTex, const CiRect* destRect, const CiRect*
    // sourceRect, uint32_t level, uint32_t plane);
    P_METHOD(
        bool,
        _60_TexStretch,
        CGxTex*       sourceTex,
        CGxTex*       destTex,
        const CiRect* destRect,
        const CiRect* sourceRect,
        uint32_t      level,
        uint32_t      plane);
    // void TexSetCacheSize(int32_t cacheSize);
    P_METHOD(void, _61_TexSetCacheSize, int32_t cacheSize);
    // void QueryCreate(CGxQuery*& query, EGxQueryType type);
    P_METHOD(void, _62_QueryCreate, CGxQuery** query, EGxQueryType type);
    // void QueryDestroy(CGxQuery*& query);
    P_METHOD(void, _63_QueryDestroy, CGxQuery** query);
    // bool QueryBegin(CGxQuery* query);
    P_METHOD(bool, _64_QueryBegin, CGxQuery* query);
    // bool QueryEnd(CGxQuery* query);
    P_METHOD(bool, _65_QueryEnd, CGxQuery* query);
    // bool QueryGetParam(CGxQuery* query, EGxQueryParam param, uint32_t* data);
    P_METHOD(bool, _66_QueryGetParam, CGxQuery* query, EGxQueryParam param, uint32_t* data);
    // bool QueryGetData(CGxQuery* query, uint32_t* data);
    P_METHOD(bool, _67_QueryGetData, CGxQuery* query, uint32_t* data);
    // void ShaderCreate(CGxShader* shaders[], EGxShTarget target, const char* a3, const char* a4,
    // int32_t permutations);
    P_METHOD(
        void,
        _68_ShaderCreate,
        CGxShader** shaders,
        EGxShTarget target,
        const char* a3,
        const char* a4,
        int32_t     permutations);
    // void ShaderDestroy(CGxShader*& shader);
    P_METHOD(void, _69_ShaderDestroy, CGxShader** shader);
    // void ShaderConstantsSet(EGxShTarget target, uint32_t index, const float* constraints,
    // uint32_t count);
    P_METHOD(
        void,
        _70_ShaderConstantsSet,
        EGxShTarget  target,
        uint32_t     index,
        const float* constraints,
        uint32_t     count);
    // void IShaderReload(CGxShader* shader, const char* a2, const char* a3);
    P_METHOD(void, _71_IShaderReload, CGxShader* shader, const char* a2, const char* a3);
    // void IShaderCreate(CGxShader* shader);
    P_METHOD(void, _72_IShaderCreate, CGxShader* shader);
    // void CursorSetVisible(int32_t visible);
    P_METHOD(void, _73_CursorSetVisible, int32_t visible);
    // uint32_t* CursorLock();
    E_METHOD(uint32_t*, _74_CursorLock);
    // void CursorUnlock(uint32_t x, uint32_t y);
    P_METHOD(void, _75_CursorUnlock, uint32_t x, uint32_t y);
    // void StereoSetConvergence(float c);
    P_METHOD(void, _76_StereoSetConvergence, float c);
    // float StereoGetConvergence();
    E_METHOD(float, _77_StereoGetConvergence);
    // void StereoSetSeparation(float s);
    P_METHOD(void, _78_StereoSetSeparation, float s);
    // double StereoGetSeparation();
    E_METHOD(double, _79_StereoGetSeparation);
    // bool StereoEnabled();
    E_METHOD(bool, _80_StereoEnabled);
    // void DebugGroupBegin(const char* a1, char* a2);
    P_METHOD(void, _81_DebugGroupBegin, const char* a1, char* a2);
    // void DebugGroupEnd();
    E_METHOD(void, _82_DebugGroupEnd);
    // void DebugEvent(const char* a1, char* a2);
    P_METHOD(void, _83_DebugEvent, const char* a1, char* a2);
};
#undef INTERFACE

// this class is 14692 bytes in size
struct CGxDevice {
    // pointer to struct CGxDevice__vtable
    CGxDevice__v_table*                       v_table;        // 0x0 (size: 0x4)
    TSGrowableArray_CGxPushedRenderState      m_pushedStates; // 0x4 (size: 0x14)
    TSGrowableArray_uint32_t                  m_stackOffsets; // 0x18 (size: 0x14)
    TSGrowableArray_EGxRenderState            m_dirtyStates;  // 0x2C (size: 0x14)
    EGxPrim                                   m_primType;
    int32_t                                   m_indexLocked;
    int32_t                                   m_vertexLocked;
    int32_t                                   m_inBeginEnd;
    C3Vector                                  m_primVertex;
    C2Vector                                  m_primTexCoord[8];
    C3Vector                                  m_primNormal;
    CImVector                                 m_primColor;
    TSGrowableArray_C3Vector                  m_primVertexArray;
    TSGrowableArray_C2Vector                  m_primTexCoordArray[8];
    TSGrowableArray_C3Vector                  m_primNormalArray;
    TSGrowableArray_CImVector                 m_primColorArray;
    TSGrowableArray_uint16_t                  m_primIndexArray;
    uint32_t                                  m_primMask;
    CRect                                     m_defWindowRect;           // 0x164 (size: 0x10)
    CRect                                     m_curWindowRect;           // 0x174 (size: 0x10)
    TSGrowableArray_DEVICERESTOREDCALLBACK    m_deviceRestoredCallbacks; // 0x184
    TSGrowableArray_TEXTURERECREATIONCALLBACK m_textureRecreationCallbacks;
    TSGrowableArray_STEREOCHANGEDCALLBACK     m_stereoChangedCallbacks; // check darwin @ 00a2b779
    EGxApi                                    m_api;                    // 0x1b4
    uint32_t                                  m_cpuFeatures;
    CGxFormat                                 m_format;
    CGxCaps                                   m_caps;
    uint32_t                                  m_baseMipLevel;
    CGxGammaRamp                              m_gammaRamp;
    CGxGammaRamp                              m_systemGammaRamp;
    // TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[GxShTargets_Last];
    // TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[6];
    int32_t (*m_windowProc)(void* window, uint32_t message, uintptr_t wparam, intptr_t lparam);
    int32_t m_context;
    // Set to zero by CGxDevice::ScenePresent
    // prevents Draw from working if != 0
    // m_inRenderPass?
    int32_t intF5C;
    int32_t m_windowVisible;
    // set to 1 by ICursorClip
    int32_t m_windowFocus;
    // Incremented by CGxDevice::ScenePresent
    int32_t m_frameCount; // m_perfCounter?
    // seems to have the same place as CGxDeviceD3d::m_d3dNeedsReset (Alpha)
    int32_t      m_viewportDirty; // m_viewportDirty
    CBoundingBox m_viewport;
    C44Matrix    m_projection;
    C44Matrix    m_projNative;
    // CGxMatrixStack m_xforms[GxXforms_Last];
    CGxMatrixStack m_xforms[11];
    CGxMatrixStack m_texGen[8];
    // used by CGxDevice::ClipPlaneSet
    // seems to be a bitmask to note which clip planes are set
    uint32_t m_clipPlaneMask;
    // used by:
    //   CGxDevice::ClipPlaneSet
    C4Plane m_clipPlane[6]; // m_clipPlanes?
    // used by
    //   CGxDeviceD3d::DeviceSetRenderTarget
    //     set to 1
    //   CGxDeviceD3d::IStateSyncScissorRect
    int32_t m_scissorRectDirty; // m_scissorRectDirty?
    CRect   m_scissorRect;
    // something to do with lighting?
    // uint32_t unk2548[72];
    CGxApiLight m_lights[4];
    // uint32_t unk2536[60];
    TSHashTable_CGxShader_HASHKEY_STRI m_shaderList[6];
    uint32_t                           m_appMasterEnables;
    uint32_t                           m_hwMasterEnables;
    TSList_CGxPool                     m_poolList;
    uint32_t                           unk276C[3];
    // CGxBuf* m_bufLocked[GxPoolTargets_Last];
    CGxBuf*  m_bufLocked[2];
    CGxPool* m_vertexPool;
    CGxPool* m_indexPool;
    // CGxBuf* m_streamBufs[GxPoolTargets_Last];
    CGxBuf* m_streamBufs[2];
    // CGxVertexAttrib m_primVertexFormatAttrib[GxVertexBufferFormats_Last];
    CGxVertexAttrib m_primVertexFormatAttrib[14];
    // CGxBuf* m_primVertexFormatBuf[GxVertexBufferFormats_Last];
    CGxBuf*               m_primVertexFormatBuf[14];
    uint32_t              m_primVertexMask;
    uint32_t              m_primVertexDirty;
    EGxVertexBufferFormat m_primVertexFormat;
    CGxBuf*               m_primVertexBuf;
    uint32_t              m_primVertexSize;
    CGxBuf*               m_primIndexBuf;
    int32_t               m_primIndexDirty;
    // EmergencyMem m_emergencyMem[GxPoolTargets_Last];
    EmergencyMem                   m_emergencyMem[2]; // 0x28C4
    TSFixedArray_CGxAppRenderState m_appRenderStates;
    TSFixedArray_CGxStateBom       m_hwRenderStates;
    // Accessed by ITexForceRecreation
    TSExplicitList_CGxTex     m_textures; // 0x2904 (size 0xC)
    CGxDevice__TextureTarget  m_textureTarget[2];
    TSExplicitList_CGxQuery   m_queryList;     // 0x2928
    int32_t                   m_scrShotClick;  // 0x2934
    uint32_t                  m_scrShotWidth;  // 0x2938
    uint32_t                  m_scrShotHeight; // 0x293C
    TSGrowableArray_CImVector m_scrShotPixels; // 0x2940
    int32_t                   m_cursorVisible;
    int32_t                   m_hwCursor; // 0x2954 (size 0x4)
    uint32_t                  m_cursorHotspotX;
    uint32_t                  m_cursorHotspotY;
    uint32_t                  m_cursor[1024];  // 0x2960 (size 0x4)
    CGxTex*                   m_cursorTexture; // 0x3960 (size 0x4)
    float                     m_cursorDepth;   // 0x3964 (size 0x4)
                                               // 0x3968 == 14692 (the complete size of CGxDevice)
};

#endif
