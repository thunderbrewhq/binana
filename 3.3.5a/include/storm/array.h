#ifndef STORM_ARRAY_H
#define STORM_ARRAY_H

#include "system/types.h"

#define STORM_TS_BASE_ARRAY(T) typedef struct TSBaseArray_##T TSBaseArray_##T; \
struct TSBaseArray_##T { \
  uint32_t m_alloc; \
  uint32_t m_count; \
  T* m_data; \
};

#define STORM_TS_FIXED_ARRAY(T) typedef struct TSFixedArray_##T TSFixedArray_##T; \
struct TSFixedArray_##T { \
  uint32_t m_alloc; \
  uint32_t m_count; \
  T* m_data; \
};

#define STORM_TS_GROWABLE_ARRAY(T) typedef struct TSGrowableArray_##T TSGrowableArray_##T; \
struct TSGrowableArray_##T { \
  uint32_t m_alloc; \
  uint32_t m_count; \
  T* m_data; \
  uint32_t m_chunk; \
};

// "pointer-to" types hack

#define STORM_TS_BASE_ARRAY_POINTER_TO(T) typedef struct TSBaseArray_pointer_to_##T TSBaseArray_pointer_to_##T; \
struct TSBaseArray_pointer_to_##T { \
  uint32_t m_alloc; \
  uint32_t m_count; \
  T** m_data; \
};

#define STORM_TS_FIXED_ARRAY_POINTER_TO(T) typedef struct TSFixedArray_pointer_to_##T TSFixedArray_pointer_to_##T; \
struct TSFixedArray_pointer_to_##T { \
  uint32_t m_alloc; \
  uint32_t m_count; \
  T** m_data; \
};

#define STORM_TS_GROWABLE_ARRAY_POINTER_TO(T) typedef struct TSGrowableArray_pointer_to_##T TSGrowableArray_pointer_to_##T; \
struct TSGrowableArray_pointer_to_##T { \
  uint32_t m_alloc; \
  uint32_t m_count; \
  T** m_data; \
  uint32_t m_chunk; \
};

#endif
