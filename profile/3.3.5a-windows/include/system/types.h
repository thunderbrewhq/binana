#ifndef SYSTEM_TYPES_H
#define SYSTEM_TYPES_H

// stdint
#if defined(IDA) || defined(BINANA_GENERATOR)

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

typedef int32_t ptrdiff_t;
typedef uint32_t uintptr_t;
typedef int32_t intptr_t;

#else

#include <stdint.h>

#endif

// stdbool

#if defined(BINANA_GENERATOR)

typedef char bool;

#endif

#if defined(GHIDRA)

#include <stdbool.h>

#endif

// stddef
#if defined(GHIDRA)

#include <stddef.h>

#else

typedef uint32_t size_t;

#endif

// stdarg

#if defined(GHIDRA)

#include <stdarg.h>

#else

typedef char* va_list;

#endif

// other types

typedef struct fixed16 fixed16;
struct fixed16 {
  int16_t n;
};

struct ubyte4 {
  union {
    uint8_t b[4];
    uint32_t u;
  };
};

#endif