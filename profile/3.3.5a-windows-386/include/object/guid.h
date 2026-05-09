#ifndef OBJECT_GUID_H
#define OBJECT_GUID_H

DECLARE_STRUCT(CHashKeyGUID);

#include "system/types.h"

typedef uint64_t WOWGUID;

struct CHashKeyGUID {
    WOWGUID m_guid;
};

#endif
