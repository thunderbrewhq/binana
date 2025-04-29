#ifndef D3D9_VERTEXDECLARATION_H
#define D3D9_VERTEXDECLARATION_H

DECLARE_STRUCT(IDirect3DVertexDeclaration9__v_table);
DECLARE_STRUCT(IDirect3DVertexDeclaration9);

struct IDirect3DVertexDeclaration9__v_table {
  /*** IUnknown methods ***/
  void* v_fn_0_QueryInterface;
  void* v_fn_1_AddRef;
  void* v_fn_2_Release;
  /*** IDirect3DVertexDeclaration9 methods ***/
  void* v_fn_3_GetDevice;
  void* v_fn_4_GetDeclaration;
};

struct IDirect3DVertexDeclaration9 {
  IDirect3DVertexDeclaration9__v_table* v_table;
};

typedef IDirect3DVertexDeclaration9* LPDIRECT3DVERTEXDECLARATION9;

#endif