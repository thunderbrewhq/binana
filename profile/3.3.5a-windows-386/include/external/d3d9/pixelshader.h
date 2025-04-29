#ifndef D3D9_PIXELSHADER_H
#define D3D9_PIXELSHADER_H

DECLARE_STRUCT(IDirect3DPixelShader9__v_table);
DECLARE_STRUCT(IDirect3DPixelShader9);

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