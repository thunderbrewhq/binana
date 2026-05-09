#ifndef NET_MESSAGE_HANDLER_H
#define NET_MESSAGE_HANDLER_H

#include "common/datastore.h"
#include "net/message.h"

typedef int32_t (
    *MESSAGE_HANDLER_interface)(void* param, NETMESSAGE msgId, uint32_t time, CDataStore* msg);
typedef MESSAGE_HANDLER_interface MESSAGE_HANDLER;

#endif
