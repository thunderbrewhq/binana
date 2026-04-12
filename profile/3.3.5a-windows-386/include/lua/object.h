#ifndef LUA_OBJECT_H
#define LUA_OBJECT_H

DECLARE_UNION(GCObject);

DECLARE_STRUCT(GCheader);

DECLARE_UNION(Value);

DECLARE_STRUCT(lua_TValue);
typedef lua_TValue TValue;
typedef TValue*    StkId;

DECLARE_STRUCT(TString_tsv);
DECLARE_UNION(TString);

DECLARE_STRUCT(Udata_uv);
DECLARE_UNION(Udata);

DECLARE_STRUCT(Proto);

DECLARE_STRUCT(LocVar);

DECLARE_STRUCT(UpVal_u_l);
DECLARE_UNION(UpVal_u);
DECLARE_STRUCT(UpVal);

DECLARE_STRUCT(CClosure);

DECLARE_STRUCT(LClosure);

DECLARE_UNION(Closure);

DECLARE_STRUCT(TKey_nk);
DECLARE_UNION(TKey);

DECLARE_STRUCT(Node);

DECLARE_STRUCT(Table);

#include "lua/types.h"

struct GCheader {
    GCObject* next;
    lu_byte   tt;
    lu_byte   marked;
};

union Value {
    GCObject*  gc;
    void*      p;
    lua_Number n;
    int32_t    b;
};

struct lua_TValue {
    Value    value;
    int32_t  tt;
    uint32_t tainted; // UC: Added by Blizzard
};

struct TString_tsv {
    GCObject* next;
    lu_byte   tt;
    lu_byte   marked;
    lu_byte   reserved;
    uint32_t  hash;
    size_t    len;
};

union TString {
    L_Umaxalign dummy;
    TString_tsv tsv;
};

struct Udata_uv {
    GCObject* next;
    lu_byte   tt;
    lu_byte   marked;
    Table*    metatable;
    Table*    env;
    size_t    len;
};

union Udata {
    L_Umaxalign dummy;
    Udata_uv    uv;
};

struct Proto {
    GCObject*    next;
    uint32_t     unk04;
    lu_byte      tt;
    lu_byte      marked;
    TValue*      k;
    Instruction* code;
    Proto**      p;
    int32_t*     lineinfo;
    LocVar*      locvars;
    TString**    upvalues;
    TString*     source;
    int32_t      sizeupvalues;
    int32_t      sizek;
    int32_t      sizecode;
    int32_t      sizelineinfo;
    int32_t      sizep;
    int32_t      sizelocvars;
    int32_t      linedefined;
    int32_t      lastlinedefined;
    GCObject*    gclist;
    lu_byte      nups;
    lu_byte      numparams;
    lu_byte      is_vararg;
    lu_byte      maxstacksize;
};

struct LocVar {
    TString* varname;
    int32_t  startpc;
    int32_t  endpc;
};

struct UpVal_u_l {
    UpVal* prev;
    UpVal* next;
};

union UpVal_u {
    TValue    value;
    UpVal_u_l l;
};

struct UpVal {
    GCObject* next;
    lu_byte   tt;
    lu_byte   marked;
    TValue*   v;
    UpVal_u   u;
};

struct CClosure {
    GCObject*     next;
    lu_byte       tt;
    lu_byte       marked;
    lu_byte       isC;
    lu_byte       nupvalues;
    GCObject*     gclist;
    Table*        env;
    lua_CFunction f;
    TValue        upvalue[1];
};

struct LClosure {
    GCObject* next;
    lu_byte   tt;
    lu_byte   marked;
    lu_byte   isC;
    lu_byte   nupvalues;
    GCObject* gclist;
    Table*    env;
    Proto*    p;
    UpVal*    upvals[1];
};

union Closure {
    CClosure c;
    LClosure l;
};

struct TKey_nk {
    Value   value;
    int32_t tt;
    Node*   next;
};

union TKey {
    TKey_nk nk;
    TValue  tvk;
};

struct Node {
    TValue i_val;
    TKey   i_key;
};

struct Table {
    GCObject* next;
    uint32_t  unk04;
    lu_byte   tt;
    lu_byte   marked;
    lu_byte   flags;
    lu_byte   lsizenode;
    Table*    metatable;
    TValue*   array;
    Node*     node;
    Node*     lastfree;
    GCObject* gclist;
    int32_t   sizearray;
};

#endif
