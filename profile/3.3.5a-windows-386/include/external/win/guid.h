#ifndef WIN_GUID_H
#define WIN_GUID_H

DECLARE_STRUCT(GUID);

typedef GUID CLSID;

typedef const GUID* LPCGUID;
typedef GUID*       LPGUID;
typedef const GUID* REFIID; // const IID& (const GUID&)
typedef GUID*       REFGUID;

struct GUID {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t  Data4[8];
};

#endif
