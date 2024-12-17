#ifndef DB_CLIENT_DB_H
#define DB_CLIENT_DB_H

#include "db/idatabase.h"

DECLARE_STRUCT(WowClientDB_Base);
DECLARE_STRUCT(WowClientDB_Base__v_table);

struct WowClientDB_Base__v_table {
  void* v_fn_00;
};

struct WowClientDB_Base {
  void** v_table;
  // Member variables
  int32_t m_loaded;
  int32_t m_numRecords;
  int32_t m_maxID;
  int32_t m_minID;
  const char* m_strings;
};

#define DB_CLIENT_DB(T) \
DB_I_DATABASE(T); \
typedef struct WowClientDB_Common_##T WowClientDB_Common_##T; \
typedef struct WowClientDB_##T WowClientDB_##T; \
struct WowClientDB_Common_##T { \
  WowClientDB_Base b_base; \
}; \
struct WowClientDB_##T { \
 WowClientDB_Common_##T b_base_01; \
 IDatabase_##T b_base_02; \
}

#endif
