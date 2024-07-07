#ifndef STORM_ARRAY_H
#define STORM_ARRAY_H

#define STORM_TS_BASE_ARRAY(type) typedef struct TSBaseArray_##type TSBaseArray_##type; \
struct TSBaseArray_##type { \
  void** vtable; \
  uint32_t m_alloc; \
  uint32_t m_count; \
  type* m_data; \
};

#define STORM_TS_FIXED_ARRAY(type) typedef struct TSFixedArray_##type TSFixedArray_##type; \
struct TSFixedArray_##type { \
  void** vtable; \
  uint32_t m_alloc; \
  uint32_t m_count; \
  type* m_data; \
};

#define STORM_TS_GROWABLE_ARRAY(type) typedef struct TSGrowableArray_##type TSGrowableArray_##type; \
struct TSGrowableArray_##type { \
  void** vtable; \
  uint32_t m_alloc; \
  uint32_t m_count; \
  type* m_data; \
  uint32_t m_chunk; \
};

#endif
