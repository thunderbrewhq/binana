#ifndef BC_THREAD_THREAD_H
#define BC_THREAD_THREAD_H

DECLARE_STRUCT(Blizzard__Thread__ThreadRecord);

typedef Blizzard__Thread__ThreadRecord* Blizzard__Thread__Thread;

struct Blizzard__Thread__ThreadRecord {
    uint32_t unk00;
    uint32_t unk04;
    uint32_t unk08;
    uint32_t unk0C;
    int32_t  start;
    int32_t  refCount;
    uint32_t unk18;
    uint32_t unk1C;
    uint32_t unk20;
    uint32_t unk24;
    uint32_t unk28;
    uint32_t unk2C;
    char     debugName[8];
};

#endif
