#ifndef D3D9_VERTEXBUFFER_H

DECLARE_STRUCT(IDirect3DVertexBuffer9__v_table);
DECLARE_STRUCT(IDirect3DVertexBuffer9);

struct IDirect3DVertexBuffer9__v_table {
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
  /*** IDirect3DVertexBuffer9 methods ***/
  void* v_fn_11_Lock;
  void* v_fn_12_Unlock;
  void* v_fn_13_GetDesc;
};

struct IDirect3DVertexBuffer9 {
  IDirect3DVertexBuffer9__v_table* v_table;
};

typedef IDirect3DVertexBuffer9* LPDIRECT3DVERTEXBUFFER9;

#endif
