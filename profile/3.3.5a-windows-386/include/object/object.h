#ifndef OBJECT_OBJECT_H
#define OBJECT_OBJECT_H

DECLARE_STRUCT(CGObjectData);
DECLARE_STRUCT(CGObject);
DECLARE_STRUCT(CGObject_C);
DECLARE_STRUCT(CGObject_C__v_table);

#include "object/guid.h"
#include "object/type.h"
#include "storm/hash.h"

struct CGObjectData {
    WOWGUID     m_guid;
    OBJECT_TYPE m_type;
    int32_t     m_entryID;
    float       m_scale;
    uint32_t    pad;
};

struct CGObject {
    uint32_t*     m_data;
    CGObjectData* m_obj;
};

struct CGObject_C__v_table {
    void* unk;
};

// class CGObject_C : public CGObject, public TSHashObject<CGObject_C, CHashKeyGUID>
STORM_TS_HASH(CGObject_C, CHashKeyGUID);
struct CGObject_C {
    CGObject_C__v_table*                 v_table;
    CGObject                             _01;
    TSHashObject_CGObject_C_CHashKeyGUID _02;

    TSLink_CGObject_C m_link;
    uint32_t          unk[40];
    float             m_renderScale;
    uint32_t          unki;
    // HMODEL m_model;
    void*    m_model;
    uint32_t m_highlightTypes;
    float    m_objectHeight;
    uint32_t m_worldObject;
    uint32_t m_flags;
    uint32_t m_fadeStartTime;
    uint32_t m_fadeDuration;
    uint8_t  m_alpha;
    uint8_t  m_startAlpha;
    uint8_t  m_endAlpha;
    uint8_t  m_maxAlpha;
};

#endif
