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

#endif
