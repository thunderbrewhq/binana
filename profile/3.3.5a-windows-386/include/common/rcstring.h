#ifndef COMMON_RC_STRING_H
#define COMMON_RC_STRING_H

#include "common/refcount.h"

DECLARE_STRUCT(RCString);

// struct RCString : TRefCnt
struct RCString {
  TRefCnt b_base;
  uint8_t* m_str;
};

#endif