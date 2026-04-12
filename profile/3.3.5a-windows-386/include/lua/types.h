#ifndef LUA_TYPES_H
#define LUA_TYPES_H

#define LUA_REGISTRYINDEX -10000
#define LUA_ENVIRONINDEX  -10001
#define LUA_GLOBALSINDEX  -10002

DECLARE_STRUCT(lua_State);
DECLARE_STRUCT(lua_Debug);

DECLARE_STRUCT(Mbuffer);
DECLARE_UNION(L_Umaxalign);
DECLARE_STRUCT(lua_longjmp);
DECLARE_STRUCT(luaL_Reg);

struct Mbuffer {
    char*  buffer;
    size_t n;
    size_t buffsize;
};

typedef void (*lua_Hook)(lua_State*, lua_Debug*);

typedef uint8_t lu_byte;

typedef uint32_t lu_int32;

typedef uint32_t lu_mem;

typedef double lua_Number;

union L_Umaxalign {
    double u;
    void*  s;
    long   l;
};

/* chain list of long jump buffers */
struct lua_longjmp {
    lua_longjmp* previous;
    // luai_jmpbuf  b;
    int          b;
    volatile int status; /* error code */
};

typedef lu_int32 Instruction;

typedef int32_t (*lua_CFunction_interface)(lua_State*);
typedef lua_CFunction_interface lua_CFunction;

typedef void* (*lua_Alloc_interface)(void*, void*, size_t, size_t);
typedef lua_Alloc_interface lua_Alloc;

struct luaL_Reg {
    const char*   name;
    lua_CFunction func;
};

#endif
