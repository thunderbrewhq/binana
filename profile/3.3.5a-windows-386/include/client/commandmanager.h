#ifndef CLIENT_COMMAND_MANAGER_H
#define CLIENT_COMMAND_MANAGER_H

DECLARE_STRUCT(CommandManager);

#include "net/netclient.h"

struct CommandManager {
    uint32_t   unk00;
    uint32_t   unk04;
    uint32_t   unk08;
    uint32_t   unk0C;
    uint32_t   unk10;
    uint32_t   unk14;
    uint32_t   unk18;
    uint32_t   unk1C;
    uint32_t   unk20;
    NetClient* unk24;
};

#endif
