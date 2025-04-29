#ifndef COMMON_DATA_MANAGER_H
#define COMMON_DATA_MANAGER_H

DECLARE_STRUCT(CBaseManaged);
DECLARE_STRUCT(CDataMgr);

DECLARE_ENUM(CBaseManaged__ManagedTypeIds);
DECLARE_ENUM(CBaseManaged__ManagedFlags);

#include "system/types.h"
#include "common/handle.h"
#include "storm/array.h"
#include "storm/list.h"
#include "tempest/vector.h"

typedef HOBJECT HDATAMGR;
typedef CBaseManaged* pointer_to_CBaseManaged;

STORM_TS_FIXED_ARRAY(pointer_to_CBaseManaged);
STORM_TS_LIST(CBaseManaged);

enum CBaseManaged__ManagedTypeIds {
  // TODO
  COORD = 3,
  FLOAT = 6,
  DATATYPEIDS = 7
};

enum CBaseManaged__ManagedFlags {
  ALWAYSUPDATE = 0x1,
  READONLY = 0x2,
  REQUIRESUPDATE = 0x4,
  UPDATED = 0x8,
};

struct CBaseManaged {
  void* v_vtable;
  TSLink_CBaseManaged m_link;
  uint8_t m_dataTypeId;
  uint8_t m_flags;
  void (*m_updateFcn)(float, void*, void*);
  void* m_updateData;
  float m_updatePriority;
};

// class CDataMgr : public CHandleObject
struct CDataMgr {
  CHandleObject b_base;
  TSFixedArray_pointer_to_CBaseManaged m_managedArray;
  TSExplicitList_CBaseManaged m_updateList;
};

// class TManaged<T> : public CBaseManaged
#define COMMON_T_MANAGED(T) \
typedef struct TManaged_##T TManaged_##T; \
struct TManaged_##T { \
  CBaseManaged b_base; \
  T m_data; \
}; 
// declare types
COMMON_T_MANAGED(float);
COMMON_T_MANAGED(C3Vector);

#endif
