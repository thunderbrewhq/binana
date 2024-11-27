#ifndef STORM_BIG_H
#define STORM_BIG_H

DECLARE_STRUCT(BigData);
DECLARE_STRUCT(BigBuffer);
DECLARE_STRUCT(BigStack);

#include "storm/array/uint8_t.h"
#include "storm/array/uint32_t.h"

struct BigBuffer {
  TSGrowableArray_uint32_t m_data;
  uint32_t m_offset;
};

struct BigStack {
  BigBuffer m_buffer[16];
  uint32_t m_used;
};

struct BigData {
  BigBuffer m_primary;
  BigStack m_stack;
  TSGrowableArray_uint8_t m_output;
};

#endif