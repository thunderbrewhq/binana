#ifndef D3D9_SURFACE_H
#define D3D9_SURFACE_H

DECLARE_STRUCT(IDirect3DSurface9__v_table);
DECLARE_STRUCT(IDirect3DSurface9);

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

typedef IDirect3DSurface9* LPDIRECT3DSURFACE9;

#endif