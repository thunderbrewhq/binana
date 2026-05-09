#ifndef NET_ADDR_H
#define NET_ADDR_H

DECLARE_STRUCT(NETADDR);
DECLARE_STRUCT(NETCONNADDR);

struct NETADDR {
    uint16_t family;
    char     data[14];
};

struct NETCONNADDR {
    NETADDR peerAddr;
    NETADDR selfAddr;
};

#endif
