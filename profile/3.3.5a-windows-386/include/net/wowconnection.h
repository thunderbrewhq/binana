#ifndef NET_WOW_CONNECTION_H
#define NET_WOW_CONNECTION_H

DECLARE_STRUCT(WowConnection);
DECLARE_STRUCT(WowConnection__SENDNODE);

DECLARE_ENUM(WOW_CONN_STATE);
DECLARE_ENUM(WOWC_TYPE);
DECLARE_ENUM(WC_SEND_RESULT);

DECLARE_CALLBACK(void, WOWCONNECTIONINIT);

#include "net/wowconnectionresponse.h"
#include "storm/atomic.h"
#include "storm/crypto/arc4.h"
#include "storm/list.h"
#include "storm/thread.h"

enum WOW_CONN_STATE {
    WOWC_UNINITIALIZED = 0,
    WOWC_INITIALIZED   = 1,
    WOWC_CONNECTING    = 2,
    WOWC_LISTENING     = 3,
    WOWC_ACCEPTED      = 4,
    WOWC_CONNECTED     = 5,
    WOWC_DISCONNECTED  = 6,
    WOWC_DISCONNECTING = 7,
    WOWC_ERROR         = 8,
};

enum WOWC_TYPE {
    WOWC_TYPE_MESSAGES = 0,
    WOWC_TYPE_STREAM   = 1,
};

enum WC_SEND_RESULT {
    WC_SEND_SENT   = 0,
    WC_SEND_QUEUED = 1,
    WC_SEND_ERROR  = 2
};

STORM_TS_LIST(WowConnection__SENDNODE);
// struct SENDNODE : public TSLinkedNode<SENDNODE> {
struct WowConnection__SENDNODE {
    TSLinkedNode_WowConnection__SENDNODE _;
    uint8_t*                             data;
    uint32_t                             size;
    uint32_t                             offset;
    uint32_t                             datasize;
    uint8_t                              header[8];
    uint32_t                             uint20;
    uint32_t                             allocsize;
};

STORM_TS_LIST(WowConnection);
struct WowConnection {
    // this struct is a WIP
    ATOMIC32               m_refCount;       // 0x0
    int32_t                m_sock;           // 0x4
    int32_t                m_oldsock;        // 0x8 (doublecheck this)
    int32_t                unk0C;            // 0xC
    WOW_CONN_STATE         m_connState;      // 0x10
    WowConnectionResponse* m_response;       // 0x14
    int32_t                unk18;            // 0x18
    uint8_t*               m_readBuffer;     // 0x1C
    int32_t                m_readBytes;      // 0x20
    int32_t                m_readBufferSize; // 0x24
    SCritSect              m_outLock;        // 0x28
    int32_t                unk50;            // 0x50
    int32_t                unk54;            // 0x54
    int32_t                unk58;            // 0x58
    int32_t                unk5C;            // 0x5C
    int32_t                unk60;            // 0x60
    int32_t                unk64;            // 0x64
    int32_t                unk68;            // 0x68
    uint32_t               m_connectAddress; // natrist: 0x6C
    uint16_t               m_connectPort;    // natrist: 0x70
    // NETCONNADDR                    m_peer;
    int32_t                m_connectRetryInterval; // 0x74 (doublecheck this)
    int32_t                unk78;                  // 0x78
    int32_t                unk7C;                  // 0x7C
    NETCONNADDR            m_peer;                 // 0x80
    int32_t                unkA0;                  // 0xA0
    SCritSect              m_responseLock;         // 0xA4
    int32_t                m_responseRef;          // 0xCC
    uintptr_t              m_responseRefThread;    // 0xD0
    WowConnectionResponse* responseD4;             // 0xD4
    int32_t                unkD8;                  // 0xD8
    int32_t                unkDC;                  // 0xDC
    // int32_t                unkE0;                  // 0xE0
    // int32_t                unkE4;                  // 0xE4
    // int32_t                unkE8;                  // 0xE8
    TSList_WowConnection__SENDNODE m_sendList;     // 0xE0
    int32_t                        m_sendDepth;    // 0xEC
    int32_t                        unkF0;          // 0xF0
    int32_t                        m_maxSendDepth; // 0xF4
    int32_t                        m_serviceFlags; // 0xF8
    // this is some kind of TSList
    int32_t unkFC;  // 0xFC
    int32_t unk100; // 0x100
    int32_t unk104; // 0x104
    // TSList_WowConnection__SENDNODE m_sendList;
    // int32_t              m_sendDepth;      // 0xCC ?
    // uint32_t             m_sendDepthBytes; // 0xD4 ?
    // int32_t              m_maxSendDepth;   // 0xF4
    // uint32_t             m_serviceFlags;
    // TSLink_WowConnection m_netlink;
    // uint32_t             unk98[28];
    SCritSect m_lock;  // 0x108
    int32_t   unk130;  // 0x130
    int32_t   unk134;  // 0x134
    void*     m_event; // 0x138
    int32_t   unk13C;  // 0x13C
    int32_t   unk140;  // 0x140
    int32_t   unk144;  // 0x144
    // ATOMIC32  m_serviceCount;
    // uint32_t  unk134[3];
    // void*     m_event;
    // WOWC_TYPE m_type;
    SARC4Key m_sendKey;            // 0x148
    SARC4Key m_receiveKey;         // 0x24A
    uint8_t  m_sendKeyInit[20];    // 0x34C
    uint8_t  m_receiveKeyInit[20]; // 0x360
    bool     m_encrypt;            // 0x374
    uint8_t  uint375;              // 0x375
    uint8_t  uint376;              // 0x376
};

#endif
