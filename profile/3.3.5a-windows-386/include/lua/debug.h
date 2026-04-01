#ifndef LUA_DEBUG_H
#define LUA_DEBUG_H

DECLARE_STRUCT(lua_Debug);

struct lua_Debug {
    int32_t event;
    char*   name;
    char*   namewhat;
    char*   what;
    char*   source;
    int32_t currentline;
    int32_t nups;
    int32_t linedefined;
    int32_t lastlinedefined;
    char    short_src[60];
    int32_t i_ci;
};

#endif
