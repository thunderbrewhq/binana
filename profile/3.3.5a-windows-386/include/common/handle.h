#ifndef COMMON_HANDLE_H
#define COMMON_HANDLE_H

#include "system/types.h"

DECLARE_STRUCT(CHandleObject);

struct CHandleObject {
    int32_t m_refcount;
};

DECLARE_HANDLE(HOBJECT);

#endif
