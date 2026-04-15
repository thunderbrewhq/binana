#ifndef LUA_ZIO_H
#define LUA_ZIO_H

DECLARE_STRUCT(Mbuffer);
DECLARE_STRUCT(Zio);
typedef Zio ZIO;

struct Mbuffer {
    char*  buffer;
    size_t n;
    size_t buffsize;
};

#include "lua/state.h"
#include "lua/types.h"

struct Zio {
    size_t      n; /* bytes still unread */
    const char* p; /* current position in buffer */
    lua_Reader  reader;
    void*       data; /* additional data */
    lua_State*  L;    /* Lua state (for reader) */
};

#endif
