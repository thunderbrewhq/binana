#ifndef WIN_I_PROPERTY_STORE_H
#define WIN_I_PROPERTY_STORE_H

DECLARE_STRUCT(IPropertyStore);
DECLARE_STRUCT(IPropertyStore__v_table);
DECLARE_STRUCT(PROPERTYKEY);

#include "external/win/guid.h"
#include "external/win/hresult.h"
#include "external/win/propvariant.h"

struct PROPERTYKEY {
    GUID     category;
    uint32_t propertyID;
};

// const PROPERTYKEY&
typedef PROPERTYKEY* REFPROPERTYKEY;

#define INTERFACE IPropertyStore
struct IPropertyStore__v_table {
    // public:
    //     virtual HRESULT F_STDCALL GetCount  (DWORD *cProps) = 0;
    //     virtual HRESULT F_STDCALL GetAt     (DWORD iProp, PROPERTYKEY *pkey) = 0;
    //     virtual HRESULT F_STDCALL GetValue  (REFPROPERTYKEY key, PROPVARIANT *pv) = 0;
    //     virtual HRESULT F_STDCALL SetValue  (REFPROPERTYKEY key, REFPROPVARIANT propvar) = 0;
    //     virtual HRESULT F_STDCALL Commit    (void) = 0;
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IPropertyStore methods
    COM_P_METHOD(HRESULT, _03_GetCount, uint32_t* cProps);
    COM_P_METHOD(HRESULT, _04_GetAt, uint32_t iProp, PROPERTYKEY* pkey);
    COM_P_METHOD(HRESULT, _05_GetValue, REFPROPERTYKEY key, PROPVARIANT* pv);
    COM_P_METHOD(HRESULT, _06_SetValue, REFPROPERTYKEY key, REFPROPVARIANT propvar);
    COM_E_METHOD(HRESULT, _07_Commit);
};
#undef INTERFACE

struct IPropertyStore {
    IPropertyStore__v_table* v_table;
};

#endif
