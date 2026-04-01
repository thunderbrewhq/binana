#ifndef BC_UTIL_BUFFER_H
#define BC_UTIL_BUFFER_H

// Blizzard::Util::Buffer<size_t N, typename T> : Blizzard::Util::BufferData<typename T, size_t N>
#define BC_UTIL_BUFFER(N, T)                                                                       \
    typedef struct Blizzard__Util__Buffer_##N##_##T     Blizzard__Util__Buffer_##N##_##T;          \
    typedef struct Blizzard__Util__BufferData_##T##_##N Blizzard__Util__BufferData_##T##_##N;      \
    struct Blizzard__Util__BufferData_##T##_##N {                                                  \
        uint32_t elements;                                                                         \
        T*       data;                                                                             \
        T        local[N];                                                                         \
    };                                                                                             \
    struct Blizzard__Util__Buffer_##N##_##T {                                                      \
        Blizzard__Util__BufferData_##T##_##N _;                                                    \
    };

BC_UTIL_BUFFER(300, char);
BC_UTIL_BUFFER(300, uint16_t);

#endif
