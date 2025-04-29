#ifndef D3D9_QUERY_H
#define D3D9_QUERY_H

DECLARE_STRUCT(IDirect3DQuery9__v_table);
DECLARE_STRUCT(IDirect3DQuery9);

struct IDirect3DQuery9__v_table {
  void* v_fn_0_QueryInterface;
  void* v_fn_1_AddRef;
  void* v_fn_2_Release;
  void* v_fn_3_GetDevice;
  void* v_fn_4_GetType;
  void* v_fn_5_GetDataSize;
  void* v_fn_6_Issue;
  void* v_fn_7_GetData;
};

struct IDirect3DQuery9 {
  IDirect3DQuery9__v_table* v_table;
};

typedef IDirect3DQuery9* LPDIRECT3DQUERY9;

#endif