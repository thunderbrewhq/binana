#ifndef UI_UI_ADDON_H
#define UI_UI_ADDON_H

DECLARE_ENUM(UIADDON_LOADABLE_REASON);
DECLARE_ENUM(UIADDON_SECURITY_STATUS);
DECLARE_STRUCT(UIADDON);

#include "storm/array/pointer_to_char.h"
#include "storm/hash.h"

enum UIADDON_LOADABLE_REASON {
    ADDON_LOADABLE,
    ADDON_MISSING,
    ADDON_DISABLED,
    ADDON_BANNED,
    ADDON_CORRUPT,
    ADDON_INSECURE,
    ADDON_DEMAND_LOADED,
    ADDON_INTERFACE_VERSION,
    ADDON_INCOMPATIBLE
};

enum UIADDON_SECURITY_STATUS {
    ADDON_SECURITY_SECURE,
    ADDON_SECURITY_INSECURE,
    ADDON_SECURITY_BANNED
};

STORM_TS_HASH(UIADDON, HASHKEY_STRI);
// struct UIADDON : public TSHashObject<UIADDON, HASHKEY_STRI>
struct UIADDON {
    TSHashObject_UIADDON_HASHKEY_STRI _;
    //
    uint32_t                m_unk18;
    uint32_t                m_interface; // Interface version, current = 30300
    uint32_t                m_unk20;
    UIADDON_SECURITY_STATUS m_security;
    int8_t                  m_unk28_0;
    int8_t                  m_unk28_1;
    int8_t                  m_unk28_2;
    int8_t                  m_unk28_3;
    uint32_t                m_unk2C;
    const char*             m_url;
    uint32_t                m_unk34;
    uint32_t                m_unk38;
    uint32_t                m_unk3C;
    uint32_t                m_unk40;
    uint32_t                m_unk44;
    //
    TSGrowableArray_pointer_to_char m_dependencies;
};

#endif
