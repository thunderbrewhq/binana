#ifndef COMMON_DATA_STORE_H
#define COMMON_DATA_STORE_H

DECLARE_STRUCT(CDataStore__v_table);
DECLARE_STRUCT(CDataStore);

struct CDataStore__v_table{
  void* fn_InternalInitialize;
  void* fn_InternalDestroy;
  void* fn_InternalFetchRead;
  void* fn_InternalFetchWrite;
  void* fn_destructor;
  void* fn_IsRead;
  void* fn_Reset;
  void* fn_Finalize;
  void* fn_GetBufferParams;
  void* fn_DetachBuffer;
  void* fn_GetHeaderSpace;
};

struct CDataStore {
  CDataStore__v_table* v_table;
  uint8_t* m_data;
  uint32_t m_base;
  uint32_t m_alloc;
  uint32_t m_size;
  uint32_t m_read;
};

#endif

