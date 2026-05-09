#ifndef NET_WOW_CONNECTION_RESPONSE_H
#define NET_WOW_CONNECTION_RESPONSE_H

DECLARE_STRUCT(WowConnectionResponse__v_table);
DECLARE_STRUCT(WowConnectionResponse);

#include "common/datastore.h"
#include "net/addr.h"
#include "net/wowconnection.h"

#define INTERFACE WowConnectionResponse
struct WowConnectionResponse__v_table {
    P_METHOD(void, _00_scalar_deleting_destructor, uint8_t __flags);
    // void WCMessageReady(WowConnection* conn, uint32_t timeStamp, CDataStore* msg);
    P_METHOD(void, _01_WCMessageReady, WowConnection* conn, uint32_t timeStamp, CDataStore* msg);
    // void WCConnected(
    //      WowConnection*     conn,
    //      WowConnection*     inbound,
    //      uint32_t           timeStamp,
    //      const NETCONNADDR* addr)                                                           = 0;
    P_METHOD(
        void,
        _02_WCConnected,
        WowConnection*     conn,
        WowConnection*     inbound,
        uint32_t           timeStamp,
        const NETCONNADDR* addr);
    // void WCCantConnect(WowConnection* conn, uint32_t timeStamp, NETCONNADDR* addr) = 0;
    P_METHOD(void, _03_WCCantConnect, WowConnection* conn, uint32_t timeStamp, NETCONNADDR* addr);

    // void WCDisconnected(WowConnection* conn, uint32_t timeStamp, NETCONNADDR* addr) {};
    P_METHOD(void, _04_WCCDisconnected, WowConnection* conn, uint32_t timeStamp, NETCONNADDR* addr);

    // void WCGlobalLock();
    E_METHOD(void, _05_WCGlobalLock);

    // void WCGlobalUnlock();
    E_METHOD(void, _06_WCGlobalUnlock);

    // void WCDataReady(WowConnection* conn, uint32_t timeStamp, uint8_t* data, int32_t len) {};
    P_METHOD(
        void,
        _07_WCDataReady,
        WowConnection* conn,
        uint32_t       timeStamp,
        uint8_t*       data,
        int32_t        len);

    // void WCWriteReady(WowConnection* conn);
    P_METHOD(void, _08_WCWriteReady, WowConnection* conn);

    // void NotifyAboutToDoReads();
    E_METHOD(void, _09_NotifyAboutToDoReads);

    // void NotifySendDepthExceeded(WowConnection* conn);
    P_METHOD(void, _10_NotifySendDepthExceeded, WowConnection* conn);
};
#undef INTERFACE

struct WowConnectionResponse {
    WowConnectionResponse__v_table* v_table;
};

#endif
