#ifndef GX_QUERY_H
#define GX_QUERY_H

DECLARE_STRUCT(CGxQuery);

#include "storm/list.h"
#include "gx/types.h"

STORM_TS_LIST(CGxQuery);
struct CGxQuery {
  void* m_apiSpecific;
  EGxQueryType m_type;
  TSLink_CGxQuery m_link;
};

#endif