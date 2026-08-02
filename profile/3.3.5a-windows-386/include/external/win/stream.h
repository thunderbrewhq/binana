#ifndef WIN_STREAM_H
#define WIN_STREAM_H

DECLARE_STRUCT(IStream__v_table);
DECLARE_STRUCT(IStream);
DECLARE_STRUCT(STATSTG);

#include "external/win/filetime.h"
#include "external/win/guid.h"
#include "external/win/hresult.h"
#include "external/win/largeinteger.h"
#include "external/win/stream.h"

struct STATSTG {
    uint16_t*      pwcsName;
    uint32_t       type;
    ULARGE_INTEGER cbSize;
    FILETIME       mtime;
    FILETIME       ctime;
    FILETIME       atime;
    uint32_t       grfMode;
    uint32_t       grfLocksSupported;
    CLSID          clsid;
    uint32_t       grfStateBits;
    uint32_t       reserved;
};

#define INTERFACE IStream
struct IStream__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // ISequentialStream methods
    COM_P_METHOD(HRESULT, _03_Read, void* pv, uint32_t cb, uint32_t* pcbRead);
    COM_P_METHOD(HRESULT, _04_RemoteRead, uint8_t* pv, uint32_t cb, uint32_t* pcbRead);
    COM_P_METHOD(HRESULT, _05_Write, const void* pv, uint32_t cb, uint32_t* pcbWritten);
    COM_P_METHOD(HRESULT, _06_RemoteWrite, const uint8_t* pv, uint32_t cb, uint32_t* pcbWritten);
    // IStream methods
    COM_P_METHOD(
        HRESULT,
        _07_Seek,
        LARGE_INTEGER   dlibMove,
        uint32_t        dwOrigin,
        ULARGE_INTEGER* plibNewPosition);
    COM_P_METHOD(
        HRESULT,
        _08_RemoteSeek,
        LARGE_INTEGER   dlibMove,
        uint32_t        dwOrigin,
        ULARGE_INTEGER* plibNewPosition);
    COM_P_METHOD(HRESULT, _09_SetSize, ULARGE_INTEGER libNewSize);
    COM_P_METHOD(
        HRESULT,
        _10_CopyTo,
        IStream*        pstm,
        ULARGE_INTEGER  cb,
        ULARGE_INTEGER* pcbRead,
        ULARGE_INTEGER* pcbWritten);
    COM_P_METHOD(
        HRESULT,
        _11_RemoteCopyTo,
        IStream*        pstm,
        ULARGE_INTEGER  cb,
        ULARGE_INTEGER* pcbRead,
        ULARGE_INTEGER* pcbWritten);
    COM_P_METHOD(HRESULT, _12_Commit, uint32_t grfCommitFlags);
    COM_E_METHOD(HRESULT, _13_Revert);
    COM_P_METHOD(
        HRESULT,
        _14_LockRegion,
        ULARGE_INTEGER libOffset,
        ULARGE_INTEGER cb,
        uint32_t       dwLockType);
    COM_P_METHOD(
        HRESULT,
        _15_UnlockRegion,
        ULARGE_INTEGER libOffset,
        ULARGE_INTEGER cb,
        uint32_t       dwLockType);
    COM_P_METHOD(HRESULT, _16_Stat, STATSTG* pstatstg, uint32_t grfStatFlag);
    COM_P_METHOD(HRESULT, _17_Clone, IStream** ppstm);
};
#undef INTERFACE

struct IStream {
    IStream__v_table* v_table;
};

#endif
