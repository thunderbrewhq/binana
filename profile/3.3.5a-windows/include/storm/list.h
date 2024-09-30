#ifndef STORM_LIST_H
#define STORM_LIST_H

#include "system/types.h"

// TSLink<T>
#define STORM_TS_LINK(T) typedef struct TSLink_##T TSLink_##T; \
struct TSLink_##T { \
  TSLink_##T* m_prevlink; \
  T* m_next; \
}

// TSList<T>
// TSExplicitList<T>
// TSLinkedNode<T>
#define STORM_TS_LIST(T) \
STORM_TS_LINK(T); \
typedef struct TSList_##T TSList_##T; \
typedef struct TSList_##T TSExplicitList_##T; \
typedef struct TSLinkedNode_##T TSLinkedNode_##T; \
struct TSList_##T { \
  ptrdiff_t m_linkoffset; \
  TSLink_##T m_terminator; \
}; \
struct TSLinkedNode_##T { \
  TSLink_##T m_link; \
}; \
typedef TSList_##T TSExplicitList_##T

#endif