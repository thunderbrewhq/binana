#ifndef OBJECT_OBJECT_H
#define OBJECT_OBJECT_H

DECLARE_STRUCT(CGObjectData);
DECLARE_STRUCT(CGObject);
DECLARE_STRUCT(CGObject_C__v_table);

#include "object/guid.h"
#include "object/type.h"

struct CGObjectData {
  WOWGUID m_guid;
  OBJECT_TYPE m_type;
  int32_t m_entryID;
  float m_scale;
  uint32_t pad;
};

struct CGObject {
  uint32_t* m_data;
  CGObjectData* m_obj;
};

struct CGObject_C__v_table {
  void* unk;
};

// class CGObject_C : CGObject {
struct CGObject_C {
  CGObject_C__v_table* v_table;
  CGObject b_base;
  uint32_t unk[42];
  float m_renderScale;
  uint32_t unki;
  // HMODEL m_model;
  void* m_model;
  uint32_t m_highlightTypes;
  float m_objectHeight;
  uint32_t m_worldObject;
  uint32_t m_flags;
  uint32_t m_fadeStartTime;
  uint32_t m_fadeDuration;
  uint8_t m_alpha;
  uint8_t m_startAlpha;
  uint8_t m_endAlpha;
  uint8_t m_maxAlpha;
};

#endif