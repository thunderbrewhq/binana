#ifndef NET_NET_CLIENT_H
#define NET_NET_CLIENT_H

DECLARE_STRUCT(CLIENT_NETSTATS);
DECLARE_STRUCT(NetClient);
DECLARE_STRUCT(NetClient__v_table);
DECLARE_STRUCT(NetClient__HELDMESSAGE);
DECLARE_STRUCT(RealmConnection);
DECLARE_STRUCT(NETCLIENTNODE);

#include "net/characterinfo.h"
#include "net/logindata.h"
#include "net/message_handler.h"
#include "net/neteventqueue.h"
#include "net/netstate.h"
#include "net/realmresponse.h"
#include "net/wowconnectionresponse.h"
#include "object/objectmanager.h"
#include "storm/list.h"

struct CLIENT_NETSTATS {
    uint32_t bytesSent;
    uint32_t messagesSent;
    uint32_t sendTimestamp;
    uint32_t bytesReceived;
    uint32_t messagesReceived;
    uint32_t receivTimestamp;
    uint32_t logTimestamp;
};

// class NetClient::HELDMESSAGE : public TSLinkedNode<NetClient::HELDMESSAGE>
STORM_TS_LIST(NetClient__HELDMESSAGE);
struct NetClient__HELDMESSAGE {
    TSLinkedNode_NetClient__HELDMESSAGE _;
    CDataStore                          msg;
};

// first 11 methods inherited from WowConnectionResponse
#define INTERFACE NetClient
struct NetClient__v_table {
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

    // int32_t Initialize();
    E_METHOD(int32_t, _11_Initialize);

    // void Destroy();
    E_METHOD(void, _12_Destroy);

    // void DelayedDelete();
    E_METHOD(void, _13_DelayedDelete);

    // int32_t HandleData(uint32_t timeReceived, void* data, int32_t size);
    P_METHOD(int32_t, _14_HandleData, uint32_t timeReceived, void* data, int32_t size);

    // ???
    E_METHOD(void, _15);

    // int32_t HandleConnect();
    E_METHOD(int32_t, _16_HandleConnect);

    // int32_t HandleDisconnect();
    E_METHOD(int32_t, _17_HandleDisconnect);

    // int32_t HandleCantConnect();
    E_METHOD(int32_t, _18_HandleCantConnect);

    // void ValidateMessageId(uint32_t messageId);
    E_METHOD(void, _19_ValidateMessageId);
};
#undef INTERFACE

// class NetClient : public WowConnectionResponse
struct NetClient {
    // vtables are merged here:
    // WowConnectionResponse {
    NetClient__v_table* v_table;
    // }
    LoginData                     m_loginData;
    NETSTATE                      m_netState;
    bool                          m_suspended;
    MESSAGE_HANDLER               m_handlers[1311];
    void*                         m_handlerParams[1311];
    NETEVENTQUEUE*                m_netEventQueue;
    WowConnection*                m_serverConnection;
    WowConnection*                m_redirectConnection;
    ATOMIC32                      m_refCount;
    bool                          m_deleteMe;
    uint32_t                      unk2E48;
    uint32_t                      m_pingSent;
    uint32_t                      m_pingSequence;
    uint32_t                      m_latency[16];
    uint32_t                      m_latencyStart;
    uint32_t                      m_latencyEnd;
    uint32_t                      m_bytesSent;
    uint32_t                      m_bytesReceived;
    uint32_t                      m_connectedTimestamp;
    SCritSect                     m_pingLock;
    ClntObjMgr*                   m_objMgr;
    TSList_NetClient__HELDMESSAGE m_heldMessages; // invented name
    // uint32_t              unk2ED4;
    // uint32_t              unk2ED8;
    // uint32_t              unk2EDC;
};

// class RealmConnection : public NetClient
struct RealmConnection {
    NetClient                   _;
    RealmResponse*              m_realmResponse;
    uint32_t                    m_restrictHuman;
    uint32_t                    m_restrictDwarf;
    uint32_t                    m_restrictGnome;
    uint32_t                    m_restrictNightElf;
    uint32_t                    m_restrictDraenei;
    uint32_t                    m_restrictOrc;
    uint32_t                    m_restrictTroll;
    uint32_t                    m_restrictTauren;
    uint32_t                    m_restrictUndead;
    uint32_t                    m_restrictBloodElf;
    TSFixedArray_CHARACTER_INFO m_characterList;
    uint8_t                     m_authenticated;
    uint32_t                    m_queuePosition;
    uint32_t                    m_freeCharacterMigration;
    uint32_t                    m_billingTimeRemaining;
    uint32_t                    m_billingTimeRested;
    uint8_t                     m_billingFlags;
    uint8_t                     m_accountExpansion;
};

// struct NETCLIENTNODE : TSLinkedNode<NETCLIENTNODE>
STORM_TS_LIST(NETCLIENTNODE);
struct NETCLIENTNODE {
    TSLinkedNode_NETCLIENTNODE _;
    NetClient*                 client;
};

#endif
