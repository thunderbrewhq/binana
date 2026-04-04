#ifndef BC_SYSTEM_USING_USING_H
#define BC_SYSTEM_USING_USING_H

DECLARE_STRUCT(System_Using__UsingRec);
DECLARE_STRUCT(System_Using__Depends);

struct System_Using__Depends {
    uint16_t               id;
    System_Using__Depends* next;
};

struct System_Using__UsingRec {
    char*    name;
    uint16_t id;
    uint16_t refCount;
    void (*shutdownproc)();
    uint16_t               dependCount;
    System_Using__Depends* depends;
};

#endif
