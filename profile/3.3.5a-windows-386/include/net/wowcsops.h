#ifndef NET_WOW_CS_OPS_H
#define NET_WOW_CS_OPS_H

DECLARE_ENUM(WOWCS_OPS);

enum WOWCS_OPS {
    COP_NONE             = 0,
    COP_INIT             = 1,
    COP_CONNECT          = 2,
    COP_AUTHENTICATE     = 3,
    COP_CREATE_ACCOUNT   = 4,
    COP_CREATE_CHARACTER = 5,
    COP_GET_CHARACTERS   = 6,
    COP_DELETE_CHARACTER = 7,
    COP_LOGIN_CHARACTER  = 8,
    COP_GET_REALMS       = 9,
    COP_WAIT_QUEUE       = 10,
};

#endif
