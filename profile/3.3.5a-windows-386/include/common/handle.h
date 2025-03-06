#ifndef COMMON_HANDLE_H
#define COMMON_HANDLE_H

#include "system/types.h"

#define DECLARE_HANDLE(I) \
typedef struct I##__ I##__; \
struct I##__ { \
    int32_t unused; \
}; \
typedef I##__* I

DECLARE_STRUCT(CHandleObject);

struct CHandleObject {
  int32_t m_refcount;
};

DECLARE_HANDLE(HOBJECT);

#endif