#ifndef DB_I_DATABASE_H
#define DB_I_DATABASE_H

DECLARE_STRUCT(IDatabase__vtable);

struct IDatabase__vtable {
  // T* GetRecord(int32_t id);
  void* v_fn_GetRecord;
};

#define DB_I_DATABASE(T) \
typedef struct IDatabase_##T IDatabase_##T; \
struct IDatabase_##T { \
  IDatabase__vtable* v_table; \
  T* m_records; \
  T** m_recordsById; \
}

#endif