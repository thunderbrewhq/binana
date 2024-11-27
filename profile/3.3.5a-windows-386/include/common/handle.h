#ifndef COMMON_HANDLE_H
#define COMMON_HANDLE_H

#include "system/types.h"

#if !defined(DECLARE_HANDLE)
#define DECLARE_HANDLE(name) \
typedef struct name##__ { \
    int32_t unused; \
}* name
#endif

DECLARE_STRUCT(CHandleObject);

struct CHandleObject {
  int32_t m_refcount;
};

DECLARE_HANDLE(HOBJECT);

#endif