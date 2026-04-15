#ifndef LUA_TYPES_H
#define LUA_TYPES_H

#define LUA_REGISTRYINDEX -10000
#define LUA_ENVIRONINDEX  -10001
#define LUA_GLOBALSINDEX  -10002

DECLARE_STRUCT(lua_State);
DECLARE_STRUCT(lua_Debug);

DECLARE_UNION(L_Umaxalign);
DECLARE_STRUCT(lua_longjmp);
DECLARE_STRUCT(luaL_Reg);

DECLARE_ENUM(OpArgMask);
DECLARE_ENUM(OpMode);
DECLARE_ENUM(OpCode);

typedef const char* (*lua_Reader_interface)(lua_State* L, void* ud, size_t* sz);
typedef lua_Reader_interface lua_Reader;

typedef void (*lua_Hook_interface)(lua_State*, lua_Debug*);
typedef lua_Hook_interface lua_Hook;

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

enum OpArgMask {
    OpArgN, /* argument is not used */
    OpArgU, /* argument is used */
    OpArgR, /* argument is a register or a jump offset */
    OpArgK  /* argument is a constant or register/constant */
};

enum OpMode { iABC, iABx, iAsBx };

enum OpCode {
    /*----------------------------------------------------------------------
    name		args	description
    ------------------------------------------------------------------------*/
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

#endif
