#ifndef NET_REALM_RESPONSE_H
#define NET_REALM_RESPONSE_H

DECLARE_STRUCT(RealmResponse__v_table);
DECLARE_STRUCT(RealmResponse);

#include "net/characterinfo.h"
#include "net/netclient.h"

#define INTERFACE RealmResponse
struct RealmResponse__v_table {
    // void HandleAuthResponse(RealmConnection* connection, uint8_t authResult);
    P_METHOD(void, HandleAuthResponse, RealmConnection* connection, uint8_t authResult);
    // void CharacterListReceived(
    //   RealmConnection*                    realmConnection,
    //   const TSFixedArray<CHARACTER_INFO>& characterList,
    //   int32_t                             listResult);
    P_METHOD(
        void,
        CharacterListReceived,
        RealmConnection*             realmConnection,
        TSFixedArray_CHARACTER_INFO* characterList,
        int32_t                      listResult);
    // void GameServerResult(
    //   RealmConnection* connection,
    //   const char* a3,
    //   const char* a4,
    //   const char* a5)
    P_METHOD(
        void,
        GameServerResult,
        RealmConnection* connection,
        const char*      a3,
        const char*      a4,
        const char*      a5);
};
#undef INTERFACE

struct RealmResponse {
    RealmResponse__v_table* v_table;
};

#endif
