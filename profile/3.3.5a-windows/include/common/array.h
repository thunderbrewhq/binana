#ifndef COMMON_ARRAY_H
#define COMMON_ARRAY_H

#include "storm/array.h"

#define COMMON_SIMPLE_SORTED_ARRAY(T) STORM_TS_GROWABLE_ARRAY(T); \
typedef struct CSimpleSortedArray_##T CSimpleSortedArray_##T; \
struct CSimpleSortedArray_##T { \
  TSGrowableArray_##T m_array; \
  uint32_t m_count; \
  uint32_t m_maxcount; \
  uint32_t m_iterator; \
};

#define COMMON_SIMPLE_SORTED_ARRAY_POINTER_TO(T) STORM_TS_GROWABLE_ARRAY_POINTER_TO(T); \
typedef struct CSimpleSortedArray_pointer_to_##T CSimpleSortedArray_pointer_to_##T; \
struct CSimpleSortedArray_pointer_to_##T { \
  TSGrowableArray_pointer_to_##T m_array; \
  uint32_t m_count; \
  uint32_t m_maxcount; \
  uint32_t m_iterator; \
};

#endif