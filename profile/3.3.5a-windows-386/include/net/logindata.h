#ifndef NET_LOGIN_DATA_H
#define NET_LOGIN_DATA_H

DECLARE_STRUCT(LoginData);

struct LoginData {
    char    m_account[1280];
    int32_t m_loginServerID;
    uint8_t m_sessionKey[40];
    int32_t m_loginServerType;
};

#endif
