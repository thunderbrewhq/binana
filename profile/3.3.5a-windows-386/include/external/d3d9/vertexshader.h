#ifndef D3D9_VERTEXSHADER_H
#define D3D9_VERTEXSHADER_H

DECLARE_STRUCT(IDirect3DVertexShader9__v_table);
DECLARE_STRUCT(IDirect3DVertexShader9);

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

typedef IDirect3DVertexShader9* LPDIRECT3DVERTEXSHADER9;

#endif