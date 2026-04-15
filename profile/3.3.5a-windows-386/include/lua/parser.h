#ifndef LUA_PARSER_H
#define LUA_PARSER_H

DECLARE_STRUCT(upvaldesc);
DECLARE_STRUCT(BlockCnt);
DECLARE_STRUCT(FuncState);

#include "lua/lex.h"
#include "lua/object.h"
#include "lua/types.h"

struct upvaldesc {
    lu_byte k;
    lu_byte info;
};

struct BlockCnt {
    BlockCnt* previous;
    int32_t   breaklist;
    lu_byte   nactvar;
    lu_byte   upval;
    lu_byte   isbreakable;
};

struct FuncState {
    Proto*     f;
    Table*     h;
    FuncState* prev;
    LexState*  ls;
    lua_State* L;
    BlockCnt*  bl;
    int32_t    pc;
    int32_t    lasttarget;
    int32_t    jpc;
    int32_t    freereg;
    int32_t    nk;
    int32_t    np;
    int16_t    nlocvars;
    lu_byte    nactvar;
    upvaldesc  upvalues[60];
    uint16_t   actvar[200];
};

#endif
