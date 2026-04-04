#ifndef BC_THREAD_TLS_H
#define BC_THREAD_TLS_H

DECLARE_STRUCT(Blizzard__Thread__TLSSlot);

typedef void (*Blizzard__Thread__TLSDestructor)(void*);

struct Blizzard__Thread__TLSSlot {
    uint32_t                        key;
    Blizzard__Thread__TLSDestructor destructor;
    bool                            initialized;
};

#endif
