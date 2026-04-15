#ifndef LUA_LEX_H
#define LUA_LEX_H

DECLARE_UNION(SemInfo);
DECLARE_STRUCT(LexState);

#include "lua/parser.h"
#include "lua/state.h"

union SemInfo {
    lua_Number r;
    TString*   ts;
}; /* semantics information */

typedef struct Token {
    int     token;
    SemInfo seminfo;
} Token;

struct LexState {
    int32_t    current;    /* current character (charint) */
    int32_t    linenumber; /* input line counter */
    int32_t    lastline;   /* line of last token `consumed' */
    Token      t;          /* current token */
    Token      lookahead;  /* look ahead token */
    FuncState* fs;         /* `FuncState' is private to the parser */
    lua_State* L;
    ZIO*       z;        /* input stream */
    Mbuffer*   buff;     /* buffer for tokens */
    TString*   source;   /* current source name */
    char       decpoint; /* locale decimal point */
};

#endif
