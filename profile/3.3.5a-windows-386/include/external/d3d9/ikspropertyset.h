#ifndef D3D9_I_KS_PROPERTY_SET_H
#define D3D9_I_KS_PROPERTY_SET_H

DECLARE_STRUCT(IKsPropertySet__v_table);
DECLARE_STRUCT(IKsPropertySet);

typedef IKsPropertySet* LPKSPROPERTYSET;

#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IKsPropertySet
struct IKsPropertySet__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IKsPropertySet methods ***/
    COM_P_METHOD(
        HRESULT,
        _03_Get,
        REFGUID   rgid,
        uint32_t  x1,
        void*     p1,
        uint32_t  x2,
        void*     p2,
        uint32_t  x3,
        uint32_t* px4);
    COM_P_METHOD(
        HRESULT,
        _04_Set,
        REFGUID  rgid,
        uint32_t x1,
        void*    p1,
        uint32_t x2,
        void*    p2,
        uint32_t x3);
    COM_P_METHOD(HRESULT, _05_QuerySupport, REFGUID rgid, uint32_t x1, uint32_t* px2);
};

#undef INTERFACE

struct IKsPropertySet {
    IKsPropertySet__v_table* v_table;
};

#endif
