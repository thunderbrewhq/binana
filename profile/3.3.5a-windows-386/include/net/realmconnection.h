#ifndef NET_REALM_CONNECTION
#define NET_REALM_CONNECTION

DECLARE_STRUCT(RealmConnection);

#include "net/characterinfo.h"
#include "net/realmresponse.h"

struct RealmConnection {
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

#endif
