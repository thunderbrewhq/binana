#ifndef LUA_STATE_H
#define LUA_STATE_H

DECLARE_STRUCT(stringtable);

DECLARE_STRUCT(CallInfo);

DECLARE_STRUCT(global_State);

DECLARE_STRUCT(lua_State);

#include "lua/object.h"
#include "lua/types.h"

struct stringtable {
    GCObject** hash;
    lu_int32   nuse;
    int32_t    size;
};

struct CallInfo {
    StkId        base;
    StkId        func;
    StkId        top;
    Instruction* savedpc;
    int32_t      nresults;
    int32_t      tailcalls;
};

struct global_State {
    stringtable   strt;
    lua_Alloc     frealloc;
    void*         ud;
    lu_byte       currentwhite;
    lu_byte       gcstate;
    int32_t       sweepstrgc;
    GCObject*     rootgc;
    GCObject**    sweepgc;
    GCObject*     gray;
    GCObject*     grayagain;
    GCObject*     weak;
    GCObject*     tmudata;
    Mbuffer       buff;
    lu_mem        GCthreshold;
    lu_mem        totalbytes;
    lu_mem        estimate;
    lu_mem        gcdept;
    int32_t       gcpause;
    int32_t       gcstepmul;
    lua_CFunction panic;
    TValue        l_registry;
    lua_State*    mainthread;
    UpVal         uvhead;
    Table*        mt[9];
    TString*      tmname[0];
};

struct lua_State {
    GCObject*     next;
    lu_byte       tt;
    lu_byte       marked;
    lu_byte       status;
    StkId         top;
    StkId         base;
    global_State* l_G;
    CallInfo*     ci;
    Instruction*  savedpc;
    StkId         stack_last;
    StkId         stack;
    CallInfo*     end_ci;
    CallInfo*     base_ci;
    int32_t       stacksize;
    int32_t       size_ci;
    uint16_t      nCcalls;
    lu_byte       hookmask;
    lu_byte       allowhook;
    int32_t       basehookcount;
    int32_t       hookcount;
    lua_Hook      hook;
    TValue        l_gt;
    TValue        env;
    GCObject*     openupval;
    GCObject*     gclist;
    lua_longjmp*  errorJmp;
    ptrdiff_t     errfunc;
};

union GCObject {
    GCheader  gch;
    TString   ts;
    Udata     u;
    Closure   cl;
    Table     h;
    Proto     p;
    UpVal     uv;
    lua_State th;
};

#endif
