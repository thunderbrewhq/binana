#ifndef STORM_HASH_H
#define STORM_HASH_H

#include <stdint.h>

#include "storm/array.h"
#include "storm/list.h"

#define STORM_TS_HASH(T, K) \
STORM_TS_LIST(T) \
STORM_TS_GROWABLE_ARRAY(TSList_##T) \
typedef struct TSHashTable_##T##_##K TSHashTable_##T##_##K; \
typedef struct TSHashObject_##T##_##K TSHashObject_##T##_##K; \
struct TSHashTable_##T##_##K { \
  TSList_##T m_fulllist; \
  uint32_t m_fulllist; \
  TSGrowableArray_TSList_##T m_slotlistarray; \
  uint32_t m_slotmask; \
}; \
struct TSHashObject_##T##_##K { \
  uint32_t m_hashval; \
  TSLink_##T m_linktoslot; \
  TSLink_##T m_linktofull; \
  K m_key; \
};

typedef struct HASHKEY_PTR HASHKEY_PTR;
typedef struct HASHKEY_STR HASHKEY_STR;
typedef struct HASHKEY_STRI HASHKEY_STRI;
typedef struct HASHKEY_NONE HASHKEY_NONE;

struct HASHKEY_PTR {
  void* m_key;
};

struct HASHKEY_STR {
  char* m_str;
};

struct HASHKEY_STRI {
  char* m_str;
};

struct HASHKEY_NONE {
};

#endif