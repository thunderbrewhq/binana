#ifndef CONSOLE_VAR_H
#define CONSOLE_VAR_H

DECLARE_STRUCT(CVar);

#include "common/rcstring.h"
#include "storm/hash.h"

STORM_TS_HASH(CVar, HASHKEY_STRI);

// class CVar : public TSHashObject<CVar, HASHKEY_STRI>
struct CVar {
  TSHashObject_CVar_HASHKEY_STRI b_base;
  uint32_t m_category;
  uint32_t m_flags;
  RCString m_stringValue;
  float m_floatValue;
  int32_t m_intValue;
  int32_t m_modified;
  RCString m_defaultValue;
  RCString m_resetValue;
  RCString m_latchedValue;
  RCString m_help;
  bool (*m_callback)(CVar*, const char*, const char*, void*);
  void* m_arg;
};

#endif