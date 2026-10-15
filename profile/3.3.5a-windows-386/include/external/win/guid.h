#ifndef WIN_GUID_H
#define WIN_GUID_H

DECLARE_STRUCT(__GUID);

typedef __GUID _CLSID;

typedef const __GUID* _LPCGUID;
typedef __GUID*       _LPGUID;
typedef const __GUID* _REFIID; // const IID& (const GUID&)
typedef __GUID*       _REFGUID;

struct __GUID {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t  Data4[8];
};

#endif
