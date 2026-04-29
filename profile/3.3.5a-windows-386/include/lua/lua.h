#ifndef LUA_LUA_H
#define LUA_LUA_H

// macro constants

#define LUA_REGISTRYINDEX -10000
#define LUA_ENVIRONINDEX  -10001
#define LUA_GLOBALSINDEX  -10002

// enum declarations

DECLARE_ENUM(expkind);
DECLARE_ENUM(OpArgMask);
DECLARE_ENUM(OpCode);
DECLARE_ENUM(OpMode);
DECLARE_ENUM(expkind);
DECLARE_ENUM(TMS);

// struct declarations

DECLARE_STRUCT(BlockCnt);
DECLARE_STRUCT(CallInfo);
DECLARE_STRUCT(CClosure);
DECLARE_STRUCT(ConsControl);
DECLARE_STRUCT(DumpState);
DECLARE_STRUCT(expdesc);
DECLARE_STRUCT(expdesc__s);
DECLARE_STRUCT(FuncState);
DECLARE_STRUCT(GCheader);
DECLARE_STRUCT(GCTime);
DECLARE_STRUCT(GCUsage);
DECLARE_STRUCT(global_State);
DECLARE_STRUCT(LoadS);
DECLARE_STRUCT(LClosure);
DECLARE_STRUCT(LexState);
DECLARE_STRUCT(LG);
DECLARE_STRUCT(LHS_assign);
DECLARE_STRUCT(LocVar);
DECLARE_STRUCT(lua_Debug);
DECLARE_STRUCT(luaL_Buffer);
DECLARE_STRUCT(luai_jmpbuf);
DECLARE_STRUCT(lua_longjmp);
DECLARE_STRUCT(luaL_Reg);
DECLARE_STRUCT(lua_priority);
DECLARE_STRUCT(lua_State);
DECLARE_STRUCT(lua_TValue);
DECLARE_STRUCT(MatchState_capture);
DECLARE_STRUCT(MatchState);
DECLARE_STRUCT(Mbuffer);
DECLARE_STRUCT(Node);
DECLARE_STRUCT(Profile);
DECLARE_STRUCT(Proto);
DECLARE_STRUCT(stringtable);
DECLARE_STRUCT(Table);
DECLARE_STRUCT(TKey_nk);
DECLARE_STRUCT(Token);
DECLARE_STRUCT(TString_tsv);
DECLARE_STRUCT(Udata_uv);
DECLARE_STRUCT(UpVal);
DECLARE_STRUCT(upvaldesc);
DECLARE_STRUCT(UpVal_u_l);
DECLARE_STRUCT(Zio);

// union declarations

DECLARE_UNION(Closure);
DECLARE_UNION(GCObject);
DECLARE_UNION(L_Umaxalign);
DECLARE_UNION(SemInfo);
DECLARE_UNION(TKey);
DECLARE_UNION(TString);
DECLARE_UNION(Udata);
DECLARE_UNION(UpVal_u);
DECLARE_UNION(Value);

// alias definitions

typedef lua_TValue TValue;
typedef TValue*    StkId;

typedef Zio ZIO;

// integral types

typedef uint8_t  lu_byte;
typedef uint32_t lu_int32;
typedef uint32_t lu_mem;
typedef int32_t  l_mem;
typedef int32_t  lua_Integer;
typedef lu_int32 Instruction;

// floating-point types

typedef double lua_Number;

// callback definitions

typedef const char* (*lua_Reader_interface)(lua_State* L, void* ud, size_t* sz);
typedef lua_Reader_interface lua_Reader;

typedef int32_t (*lua_Writer_interface)(lua_State* L, const void* p, size_t sz, void* ud);
typedef lua_Writer_interface lua_Writer;

typedef void (*lua_Hook_interface)(lua_State*, lua_Debug*);
typedef lua_Hook_interface lua_Hook;

typedef void (*Pfunc_interface)(lua_State* L, void* ud);
typedef Pfunc_interface Pfunc;
// added by Blizzard
typedef void (*lua_TaintEventCallback_interface)(lua_State*, int32_t, const char*, const char*);
typedef lua_TaintEventCallback_interface lua_TaintEventCallback;

typedef int32_t (*lua_CFunction_interface)(lua_State*);
typedef lua_CFunction_interface lua_CFunction;

typedef void* (*lua_Alloc_interface)(void*, void*, size_t, size_t);
typedef lua_Alloc_interface lua_Alloc;

// enums

enum expkind {
    VVOID, /* no value */
    VNIL,
    VTRUE,
    VFALSE,
    VK,         /* info = index of constant in `k' */
    VKNUM,      /* nval = numerical value */
    VLOCAL,     /* info = local register */
    VUPVAL,     /* info = index of upvalue in `upvalues' */
    VGLOBAL,    /* info = index of table; aux = index of global name in `k' */
    VINDEXED,   /* info = table register; aux = index register (or `k') */
    VJMP,       /* info = instruction pc */
    VRELOCABLE, /* info = instruction pc */
    VNONRELOC,  /* info = result register */
    VCALL,      /* info = instruction pc */
    VVARARG     /* info = instruction pc */
};

enum OpArgMask {
    OpArgN, /* argument is not used */
    OpArgU, /* argument is used */
    OpArgR, /* argument is a register or a jump offset */
    OpArgK  /* argument is a constant or register/constant */
};

enum OpCode {
    OP_MOVE,     /*	A B	R(A) := R(B)					*/
    OP_LOADK,    /*	A Bx	R(A) := Kst(Bx)					*/
    OP_LOADBOOL, /*	A B C	R(A) := (Bool)B; if (C) pc++			*/
    OP_LOADNIL,  /*	A B	R(A) := ... := R(B) := nil			*/
    OP_GETUPVAL, /*	A B	R(A) := UpValue[B]				*/

    OP_GETGLOBAL, /*	A Bx	R(A) := Gbl[Kst(Bx)]				*/
    OP_GETTABLE,  /*	A B C	R(A) := R(B)[RK(C)]				*/

    OP_SETGLOBAL, /*	A Bx	Gbl[Kst(Bx)] := R(A)				*/
    OP_SETUPVAL,  /*	A B	UpValue[B] := R(A)				*/
    OP_SETTABLE,  /*	A B C	R(A)[RK(B)] := RK(C)				*/

    OP_NEWTABLE, /*	A B C	R(A) := {} (size = B,C)				*/

    OP_SELF, /*	A B C	R(A+1) := R(B); R(A) := R(B)[RK(C)]		*/

    OP_ADD, /*	A B C	R(A) := RK(B) + RK(C)				*/
    OP_SUB, /*	A B C	R(A) := RK(B) - RK(C)				*/
    OP_MUL, /*	A B C	R(A) := RK(B) * RK(C)				*/
    OP_DIV, /*	A B C	R(A) := RK(B) / RK(C)				*/
    OP_MOD, /*	A B C	R(A) := RK(B) % RK(C)				*/
    OP_POW, /*	A B C	R(A) := RK(B) ^ RK(C)				*/
    OP_UNM, /*	A B	R(A) := -R(B)					*/
    OP_NOT, /*	A B	R(A) := not R(B)				*/
    OP_LEN, /*	A B	R(A) := length of R(B)				*/

    OP_CONCAT, /*	A B C	R(A) := R(B).. ... ..R(C)			*/

    OP_JMP, /*	sBx	pc+=sBx					*/

    OP_EQ, /*	A B C	if ((RK(B) == RK(C)) ~= A) then pc++		*/
    OP_LT, /*	A B C	if ((RK(B) <  RK(C)) ~= A) then pc++  		*/
    OP_LE, /*	A B C	if ((RK(B) <= RK(C)) ~= A) then pc++  		*/

    OP_TEST,    /*	A C	if not (R(A) <=> C) then pc++			*/
    OP_TESTSET, /*	A B C	if (R(B) <=> C) then R(A) := R(B) else pc++	*/

    OP_CALL,     /*	A B C	R(A), ... ,R(A+C-2) := R(A)(R(A+1), ... ,R(A+B-1)) */
    OP_TAILCALL, /*	A B C	return R(A)(R(A+1), ... ,R(A+B-1))		*/
    OP_RETURN,   /*	A B	return R(A), ... ,R(A+B-2)	(see note)	*/

    OP_FORLOOP, /*	A sBx	R(A)+=R(A+2);
                             if R(A) <?= R(A+1) then { pc+=sBx; R(A+3)=R(A) }*/
    OP_FORPREP, /*	A sBx	R(A)-=R(A+2); pc+=sBx				*/

    OP_TFORLOOP, /*	A C	R(A+3), ... ,R(A+2+C) := R(A)(R(A+1), R(A+2));
                             if R(A+3) ~= nil then R(A+2)=R(A+3) else pc++	*/
    OP_SETLIST,  /*	A B C	R(A)[(C-1)*FPF+i] := R(A+i), 1 <= i <= B	*/

    OP_CLOSE,   /*	A 	close all variables in the stack up to (>=) R(A)*/
    OP_CLOSURE, /*	A Bx	R(A) := closure(KPROTO[Bx], R(A), ... ,R(A+n))	*/

    OP_VARARG /*	A B	R(A), R(A+1), ..., R(A+B-1) = vararg		*/
};

enum OpMode {
    iABC,
    iABx,
    iAsBx
};

enum TMS {
    TM_INDEX,
    TM_NEWINDEX,
    TM_GC,
    TM_MODE,
    TM_EQ, /* last tag method with `fast' access */
    TM_ADD,
    TM_SUB,
    TM_MUL,
    TM_DIV,
    TM_MOD,
    TM_POW,
    TM_UNM,
    TM_LEN,
    TM_LT,
    TM_LE,
    TM_CONCAT,
    TM_CALL,
    TM_N /* number of elements in the enum */
};

// aux

struct LoadS {
    const char* s;
    size_t      size;
};

// align

union L_Umaxalign {
    double u;
    void*  s;
    long   l;
};

// debug

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

// dump

struct DumpState {
    lua_State* L;
    lua_Writer writer;
    void*      data;
    int32_t    strip;
    int32_t    status;
};

// lexer

union SemInfo {
    lua_Number r;
    TString*   ts;
};

struct Token {
    int32_t token;
    SemInfo seminfo;
};

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

// parser

struct expdesc__s {
    int32_t info;
    int32_t aux;
};

struct expdesc {
    expkind k;
    int32_t unk04; // added by Blizzard, presumably
    union {
        expdesc__s s;
        lua_Number nval;
    } u;
    int32_t t; /* patch list of `exit when true' */
    int32_t f; /* patch list of `exit when false' */
};

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

// NOTE: in Lua, this is an anonymous struct.
struct lua_priority {
    lu_byte left;
    lu_byte right;
};

struct ConsControl {
    expdesc  v;       /* last list item read */
    expdesc* t;       /* table descriptor */
    int32_t  nh;      /* total number of `record' elements */
    int32_t  na;      /* total number of array elements */
    int32_t  tostore; /* number of array elements pending to be stored */
};

struct LHS_assign {
    LHS_assign* prev;
    expdesc     v; /* variable (global, local, upvalue, or indexed) */
};

// proto

struct LocVar {
    TString* varname;
    int32_t  startpc;
    int32_t  endpc;
};

struct Proto {
    GCObject*    next;
    const char*  taint;
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

// struct BlockCnt {
//     BlockCnt* previous;
//     int32_t   breaklist;
//     lu_byte   nactvar;
//     lu_byte   upval;
//     lu_byte   isbreakable;
// };
//
// struct CallInfo {
//     StkId        base;
//     StkId        func;
//     StkId        top;
//     Instruction* savedpc;
//     int32_t      nresults;
//     int32_t      tailcalls;
// };

// value

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

// string

struct TString_tsv {
    GCObject*   next;
    const char* taint;
    lu_byte     tt;
    lu_byte     marked;
    lu_byte     reserved;
    uint32_t    hash;
    size_t      len;
};

union TString {
    L_Umaxalign dummy;
    TString_tsv tsv;
};

// table

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
    GCObject*   next;
    const char* taint;
    lu_byte     tt;
    lu_byte     marked;
    lu_byte     flags;
    lu_byte     lsizenode;
    Table*      metatable;
    TValue*     array;
    Node*       node;
    Node*       lastfree;
    GCObject*   gclist;
    int32_t     sizearray;
};

// upvalue

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
    // TODO: this should exist if taint is part of the CommonHeader macro
    // But does it actually?
    //    const char* taint;
    lu_byte tt;
    lu_byte marked;
    TValue* v;
    UpVal_u u;
};

// userdata

struct Udata_uv {
    GCObject*   next;
    const char* taint;
    lu_byte     tt;
    lu_byte     marked;
    Table*      metatable;
    Table*      env;
    size_t      len;
};

union Udata {
    L_Umaxalign dummy;
    Udata_uv    uv;
};

// closure

// Added by Blizzard - invented name
struct Profile {
    int32_t calls;  // incremented by luaD_precall_profile, wowpedia calls this variable in the Lua
                    // interface "calls"
    int32_t depth;  // incremented by luaV_execute_profile in the handler for OP_CALL
                    // seems to be the "stack" or "level" of the function call
    int64_t marker; // unsure what this is. It's not read out directly into the results:
                    // it could be the initial "moment" from which other measurements are based.
    int64_t flat;   // time without subroutines
                  // increases by the function execution time in each call of  luaD_precall_profile
    int64_t total; // time with subroutines
                   // increases by the function execution time in each call of  luaD_precall_profile
};

struct CClosure {
    GCObject*     next;
    const char*   taint;
    lu_byte       tt;
    lu_byte       marked;
    lu_byte       isC;
    lu_byte       nupvalues;
    GCObject*     gclist;
    Table*        env;
    Profile*      profile;
    lua_CFunction f;
    TValue        upvalue[1];
};

struct LClosure {
    GCObject*   next;
    const char* taint;
    lu_byte     tt;
    lu_byte     marked;
    lu_byte     isC;
    lu_byte     nupvalues;
    GCObject*   gclist;
    Table*      env;
    Profile*    profile;
    Proto*      p;
    UpVal*      upvals[1];
};

union Closure {
    CClosure c;
    LClosure l;
};

// zio

struct Mbuffer {
    char*  buffer;
    size_t n;
    size_t buffsize;
};

struct Zio {
    size_t      n; /* bytes still unread */
    const char* p; /* current position in buffer */
    lua_Reader  reader;
    void*       data; /* additional data */
    lua_State*  L;    /* Lua state (for reader) */
};

// state

struct luaL_Reg {
    const char*   name;
    lua_CFunction func;
};

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

// invented names - structure created by Blizzard
struct GCUsage {
    const char* tag;
    lu_mem      usage;
    GCUsage*    next;
};

// invented names - structure created by Blizzard
struct GCTime {
    const char* tag;
    int64_t     time;
    GCTime*     next;
};

struct global_State {
    stringtable   strt;
    lua_Alloc     frealloc;
    void*         ud;
    lu_byte       profile;
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
    GCUsage*      gcusage;
    GCTime*       gctime;
    lua_CFunction panic;
    TValue        l_registry;
    lua_State*    mainthread;
    UpVal         uvhead;
    Table*        mt[9];
    // uint32_t      unkBC;
    // uint32_t unkC0;
    TString* tmname[17];
};

struct lua_State {
    GCObject* next;
    // Added by Blizzard
    // Set to:
    // - lua_tainted
    // - lua_gctag
    const char*   taint;
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
    uint32_t      unk78;
    uint32_t      unk7C;
};

struct LG {
    lua_State    l;
    global_State g;
};

struct luaL_Buffer {
    char*      p;   /* current position in buffer */
    int32_t    lvl; /* number of strings in the stack (level) */
    lua_State* L;
    char       buffer[512]; // BUFSIZ == 512
};

// object

struct GCheader {
    GCObject*   next;
    const char* taint;
    lu_byte     tt;
    lu_byte     marked;
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

// strlib

struct MatchState_capture {
    const char* init;
    ptrdiff_t   len;
};

struct MatchState {
    const char*        src_init; /* init of source string */
    const char*        src_end;  /* end (`\0') of source string */
    lua_State*         L;
    int32_t            level; /* total number of captures (finished or unfinished) */
    MatchState_capture capture[32];
};

struct luai_jmpbuf {
    int32_t opaque[16];
};

struct lua_longjmp {
    lua_longjmp* previous;
    luai_jmpbuf  b;
    int32_t      status;
};

#endif
