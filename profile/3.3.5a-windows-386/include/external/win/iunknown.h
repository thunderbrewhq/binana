#ifndef WIN_I_UNKNOWN_H
#define WIN_I_UNKNOWN_H

DECLARE_STRUCT(IUnknown);
DECLARE_STRUCT(IUnknown__v_table);

typedef IUnknown* LPUNKNOWN;

#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IUnknown
struct IUnknown__v_table {
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
};
#undef INTERFACE

struct IUnknown {
    IUnknown__v_table* v_table;
};

#endif
