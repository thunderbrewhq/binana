#ifndef BC_DEBUG_ASSERT_H
#define BC_DEBUG_ASSERT_H

typedef void (*Blizzard__Debug__AssertCallback)(
    const char* expression,
    const char* message,
    const char* fileName,
    uint32_t    lineNumber);

#endif
