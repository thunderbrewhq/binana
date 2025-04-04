#ifndef D3D9_DEVICE_H
#define D3D9_DEVICE_H

#include "system/types.h"

#include "external/d3d9/caps.h"

typedef int32_t D3DFORMAT;

DECLARE_STRUCT(D3DDISPLAYMODE);
DECLARE_STRUCT(IDirect3D9_v_table);
DECLARE_STRUCT(IDirect3D9);
DECLARE_STRUCT(IDirect3DDevice9);
DECLARE_STRUCT(IDirect3DDevice9_v_table);
DECLARE_STRUCT(IDirect3DVertexDeclaration9);
DECLARE_STRUCT(IDirect3DSurface9__v_table);
DECLARE_STRUCT(IDirect3DSurface9);
DECLARE_STRUCT(IDirect3DIndexBuffer9);
DECLARE_STRUCT(IDirect3DVertexBuffer9);
DECLARE_STRUCT(IDirect3DTexture9);
DECLARE_STRUCT(IDirect3DVertexShader9__v_table);
DECLARE_STRUCT(IDirect3DVertexShader9);
DECLARE_STRUCT(IDirect3DPixelShader9__v_table);
DECLARE_STRUCT(IDirect3DPixelShader9);

DECLARE_STRUCT(D3DLOCKED_RECT);

struct D3DDISPLAYMODE {
  uint32_t Width;
  uint32_t Height;
  uint32_t RefreshRate;
  D3DFORMAT Format;
};

struct IDirect3D9_v_table {
  void* v_fn_1_QueryInterface;
  void* v_fn_2_AddRef;
  void* v_fn_3_Release;
  void* v_fn_4_RegisterSoftwareDevice;
  void* v_fn_5_GetAdapterCount;
  void* v_fn_6_GetAdapterIdentifier;
  void* v_fn_7_GetAdapterModeCount;
  void* v_fn_8_EnumAdapterModes;
  void* v_fn_9_GetAdapterDisplayMode;
  void* v_fn_10_CheckDeviceType;
  void* v_fn_11_CheckDeviceFormat;
  void* v_fn_12_CheckDeviceMultiSampleType;
  void* v_fn_13_CheckDepthStencilMatch;
  void* v_fn_14_CheckDeviceFormatConversion;
  void* v_fn_15_GetDeviceCaps;
  void* v_fn_16_GetAdapterMonitor;
  void* v_fn_17_CreateDevice;
};

struct IDirect3D9 {
  IDirect3D9_v_table* v_table;
};

struct IDirect3DDevice9_v_table {
  void* v_fn_0_QueryInterface;
  void* v_fn_1_AddRef;
  void* v_fn_2_Release;
  void* v_fn_3_TestCooperativeLevel;
  void* v_fn_4_GetAvailableTextureMem;
  void* v_fn_5_EvictManagedResources;
  void* v_fn_6_GetDirect3D;
  void* v_fn_7_GetDeviceCaps;
  void* v_fn_8_GetDisplayMode;
  void* v_fn_9_GetCreationParameters;
  void* v_fn_10_SetCursorProperties;
  void* v_fn_11_SetCursorPosition;
  void* v_fn_12_ShowCursor;
  void* v_fn_13_CreateAdditionalSwapChain;
  void* v_fn_14_GetSwapChain;
  void* v_fn_15_GetNumberOfSwapChains;
  void* v_fn_16_Reset;
  void* v_fn_17_Present;
  void* v_fn_18_GetBackBuffer;
  void* v_fn_19_GetRasterStatus;
  void* v_fn_20_SetDialogBoxMode;
  void* v_fn_21_SetGammaRamp;
  void* v_fn_22_GetGammaRamp;
  void* v_fn_23_CreateTexture;
  void* v_fn_24_CreateVolumeTexture;
  void* v_fn_25_CreateCubeTexture;
  void* v_fn_26_CreateVertexBuffer;
  void* v_fn_27_CreateIndexBuffer;
  void* v_fn_28_CreateRenderTarget;
  void* v_fn_29_CreateDepthStencilSurface;
  void* v_fn_30_UpdateSurface;
  void* v_fn_31_UpdateTexture;
  void* v_fn_32_GetRenderTargetData;
  void* v_fn_33_GetFrontBufferData;
  void* v_fn_34_StretchRect;
  void* v_fn_35_ColorFill;
  void* v_fn_36_CreateOffscreenPlainSurface;
  void* v_fn_37_SetRenderTarget;
  void* v_fn_38_GetRenderTarget;
  void* v_fn_39_SetDepthStencilSurface;
  void* v_fn_40_GetDepthStencilSurface;
  void* v_fn_41_BeginScene;
  void* v_fn_42_EndScene;
  void* v_fn_43_Clear;
  void* v_fn_44_SetTransform;
  void* v_fn_45_GetTransform;
  void* v_fn_46_MultiplyTransform;
  void* v_fn_47_SetViewport;
  void* v_fn_48_GetViewport;
  void* v_fn_49_SetMaterial;
  void* v_fn_50_GetMaterial;
  void* v_fn_51_SetLight;
  void* v_fn_52_GetLight;
  void* v_fn_53_LightEnable;
  void* v_fn_54_GetLightEnable;
  void* v_fn_55_SetClipPlane;
  void* v_fn_56_GetClipPlane;
  void* v_fn_57_SetRenderState;
  void* v_fn_58_GetRenderState;
  void* v_fn_59_CreateStateBlock;
  void* v_fn_60_BeginStateBlock;
  void* v_fn_61_EndStateBlock;
  void* v_fn_62_SetClipStatus;
  void* v_fn_63_GetClipStatus;
  void* v_fn_64_GetTexture;
  void* v_fn_65_SetTexture;
  void* v_fn_66_GetTextureStageState;
  void* v_fn_67_SetTextureStageState;
  void* v_fn_68_GetSamplerState;
  void* v_fn_69_SetSamplerState;
  void* v_fn_70_ValidateDevice;
  void* v_fn_71_SetPaletteEntries;
  void* v_fn_72_GetPaletteEntries;
  void* v_fn_73_SetCurrentTexturePalette;
  void* v_fn_74_GetCurrentTexturePalette;
  void* v_fn_75_SetScissorRect;
  void* v_fn_76_GetScissorRect;
  void* v_fn_77_SetSoftwareVertexProcessing;
  void* v_fn_78_GetSoftwareVertexProcessing;
  void* v_fn_79_SetNPatchMode;
  void* v_fn_80_GetNPatchMode;
  void* v_fn_81_DrawPrimitive;
  void* v_fn_82_DrawIndexedPrimitive;
  void* v_fn_83_DrawPrimitiveUP;
  void* v_fn_84_DrawIndexedPrimitiveUP;
  void* v_fn_85_ProcessVertices;
  void* v_fn_86_CreateVertexDeclaration;
  void* v_fn_87_SetVertexDeclaration;
  void* v_fn_88_GetVertexDeclaration;
  void* v_fn_89_SetFVF;
  void* v_fn_90_GetFVF;
  void* v_fn_91_CreateVertexShader;
  void* v_fn_92_SetVertexShader;
  void* v_fn_93_GetVertexShader;
  void* v_fn_94_SetVertexShaderConstantF;
  void* v_fn_95_GetVertexShaderConstantF;
  void* v_fn_96_SetVertexShaderConstantI;
  void* v_fn_97_GetVertexShaderConstantI;
  void* v_fn_98_SetVertexShaderConstantB;
  void* v_fn_99_GetVertexShaderConstantB;
  void* v_fn_100_SetStreamSource;
  void* v_fn_101_GetStreamSource;
  void* v_fn_102_SetStreamSourceFreq;
  void* v_fn_103_GetStreamSourceFreq;
  void* v_fn_104_SetIndices;
  void* v_fn_105_GetIndices;
  void* v_fn_106_CreatePixelShader;
  void* v_fn_107_SetPixelShader;
  void* v_fn_108_GetPixelShader;
  void* v_fn_109_SetPixelShaderConstantF;
  void* v_fn_110_GetPixelShaderConstantF;
  void* v_fn_111_SetPixelShaderConstantI;
  void* v_fn_112_GetPixelShaderConstantI;
  void* v_fn_113_SetPixelShaderConstantB;
  void* v_fn_114_GetPixelShaderConstantB;
  void* v_fn_115_DrawRectPatch;
  void* v_fn_116_DrawTriPatch;
  void* v_fn_117_DeletePatch;
     
  void* v_fn_118_CreateQuery;
};

struct IDirect3DDevice9 {
  IDirect3DDevice9_v_table* v_table;
};

struct IDirect3DVertexDeclaration9 {
  void** v_table;
};

struct IDirect3DSurface9__v_table {
  /*** IUnknown methods ***/
  void* v_fn_0_QueryInterface;
  void* v_fn_1_AddRef;
  void* v_fn_2_Release;
  /*** IDirect3DResource9 methods ***/
  void* v_fn_3_GetDevice;
  void* v_fn_4_SetPrivateData;
  void* v_fn_5_GetPrivateData;
  void* v_fn_6_FreePrivateData;
  void* v_fn_7_SetPriority;
  void* v_fn_8_GetPriority;
  void* v_fn_9_PreLoad;
  void* v_fn_10_GetType;
  /*** IDirect3DSurface9 methods ***/
  void* v_fn_11_GetContainer;
  void* v_fn_12_GetDesc;
  void* v_fn_13_LockRect;
  void* v_fn_14_UnlockRect;
  void* v_fn_15_GetDC;
  void* v_fn_16_ReleaseDC;
};

struct IDirect3DSurface9 {
  IDirect3DSurface9__v_table* v_table;
};

struct IDirect3DIndexBuffer9 {
  void** v_table;
};

struct IDirect3DVertexBuffer9 {
  void** v_table;
};

struct IDirect3DTexture9 {
  void** v_table;
};

struct D3DLOCKED_RECT {
  int32_t Pitch;
  void* pBits;
};

struct IDirect3DVertexShader9__v_table {
  void* v_fn_0_QueryInterface;
  void* v_fn_1_AddRef;
  void* v_fn_2_Release;
  void* v_fn_3_GetDevice;
  void* v_fn_4_GetFunction;
};

struct IDirect3DVertexShader9 {
  IDirect3DVertexShader9__v_table* v_table;
};

struct IDirect3DPixelShader9__v_table {
  void* v_fn_0_QueryInterface;
  void* v_fn_1_AddRef;
  void* v_fn_2_Release;
  void* v_fn_3_GetDevice;
  void* v_fn_4_GetFunction;
};

struct IDirect3DPixelShader9 {
  IDirect3DPixelShader9__v_table* v_v_table;
};

#endif
