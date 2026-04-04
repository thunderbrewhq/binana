#ifndef BC_STRING_QUICK_FORMAT_H
#define BC_STRING_QUICK_FORMAT_H

#define BC_STRING_QUICK_FORMAT(N)                                                                  \
    typedef struct Blizzard__String__QuickFormat_##N Blizzard__String__QuickFormat_##N;            \
    struct Blizzard__String__QuickFormat_##N {                                                     \
        char m_buffer[N];                                                                          \
    };

// Blizzard::String::QuickFormat<1024>
BC_STRING_QUICK_FORMAT(1024);

#endif
