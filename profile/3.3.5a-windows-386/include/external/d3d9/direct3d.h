#ifndef D3D9_DIRECT3D_H
#define D3D9_DIRECT3D_H

DECLARE_STRUCT(IDirect3D9__v_table);
DECLARE_STRUCT(IDirect3D9);

struct IDirect3D9__v_table {
   /*** IUnknown methods ***/
  void* v_fn_1_QueryInterface;
  void* v_fn_2_AddRef;
  void* v_fn_3_Release;
  /*** IDirect3D9 methods ***/
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
  IDirect3D9__v_table* v_table;
};

typedef IDirect3D9* LPDIRECT3D9;

#endif