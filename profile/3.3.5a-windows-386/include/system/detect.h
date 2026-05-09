#ifndef SYSTEM_DETECT_H
#define SYSTEM_DETECT_H

#if !defined(__GNUC__) && !defined(IDA) && !defined(GHIDRA) && !defined(BINANA_GENERATOR)
#error "Preprocessor mode not detected! You must define either IDA or GHIDRA or BINANA_GENERATOR"
#endif

#if defined(BINANA_GENERATOR)
// add custom generator defines here
#else

#define BITFIELDS_SUPPORTED

#endif

#if defined(IDA)

// why does this work?
#define DECLARE_ENUM(E) typedef enum E##__ E

#else

#define DECLARE_ENUM(E) typedef enum E E

#endif

#define DECLARE_STRUCT(T) typedef struct T T

#define DECLARE_UNION(T) typedef union T T

// callback type helper

#if defined(GHIDRA)

#define DECLARE_CALLBACK(__result__, name, ...)                                                    \
    typedef __result__ (*name##_interface)(__VA_ARGS__);                                           \
    typedef name##_interface name;

#else

#define DECLARE_CALLBACK(__result__, name, ...) typedef __result__ (*name)(__VA_ARGS__);

#endif

#if defined(IDA) || defined(CLANGD)
// void Method(int32_t a1);
#define P_METHOD(__result__, name, ...) __result__(__thiscall* name)(INTERFACE * this, __VA_ARGS__)

// void Method();
#define E_METHOD(__result__, name) __result__(__thiscall* name)(INTERFACE * this)

#else

// ghidra doesn't support calling conventions in function pointer types :(
// this hides autoanalysis for the 'this' pointer but at least has correct
// parameter types

#define P_METHOD(__result__, name, ...) __result__ (*name)(__VA_ARGS__)

#define E_METHOD(__result__, name) __result__ (*name)()

#endif

#endif
