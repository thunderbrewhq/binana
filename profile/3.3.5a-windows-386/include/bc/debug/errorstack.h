#ifndef BC_DEBUG_ERROR_STACK_H
#define BC_DEBUG_ERROR_STACK_H

DECLARE_STRUCT(Blizzard__Debug__ErrorStackRecord);

typedef Blizzard__Debug__ErrorStackRecord* Blizzard__Debug__ErrorStack;

struct Blizzard__Debug__ErrorStackRecord {
    Blizzard__Debug__ErrorStackRecord* prev;
    //
    int32_t level;
    char*   flattened;
    char*   str_;
    int32_t code_;
    int32_t category_;
};

#endif
