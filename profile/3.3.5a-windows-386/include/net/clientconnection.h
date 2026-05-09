#ifndef NET_CLIENT_CONNECTION_H
#define NET_CLIENT_CONNECTION_H

DECLARE_STRUCT(ClientConnection);

#include "net/netclient.h"
#include "net/wowcsops.h"

// class ClientConnection : public RealmConnection
struct ClientConnection {
    RealmConnection _;
    // Member variables
    int32_t   m_connected;
    int32_t   m_statusComplete;
    int32_t   m_statusResult;
    WOWCS_OPS m_statusCop;
    int32_t   m_errorCode;
    uint8_t   byte2F5A;
    void (*m_cleanup)();
};

#endif
