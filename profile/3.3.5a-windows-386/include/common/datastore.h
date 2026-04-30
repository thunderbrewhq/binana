#ifndef COMMON_DATA_STORE_H
#define COMMON_DATA_STORE_H

DECLARE_STRUCT(CDataStore__v_table);
DECLARE_STRUCT(CDataStore);

#define INTERFACE CDataStore
struct CDataStore__v_table {
    // void InternalInitialize(uint8_t*& data, uint32_t& base, uint32_t& alloc);
    P_METHOD(void, _00_InternalInitialize, uint8_t** data, uint32_t* base, uint32_t* alloc);
    // void InternalDestroy(uint8_t*& data, uint32_t& base, uint32_t& alloc);
    P_METHOD(void, _01_InternalDestroy, uint8_t** data, uint32_t* base, uint32_t* alloc);
    // int32_t InternalFetchRead(
    //   uint32_t pos,
    //   uint32_t bytes,
    //   uint8_t*& data,
    //   uint32_t& base,
    //   uint32_t& alloc);
    P_METHOD(
        int32_t,
        _02_InternalFetchRead,
        uint32_t  pos,
        uint32_t  bytes,
        uint8_t** data,
        uint32_t* base,
        uint32_t* alloc);
    // int32_t InternalFetchWrite(
    //   uint32_t pos,
    //   uint32_t bytes,
    //   uint8_t*& data,
    //   uint32_t& base,
    //   uint32_t& alloc,
    //   const char* fileName,
    //   int32_t lineNumber);
    P_METHOD(
        int32_t,
        _03_InternalFetchWrite,
        uint32_t    pos,
        uint32_t    bytes,
        uint32_t**  data,
        uint32_t*   base,
        uint32_t*   alloc,
        const char* fileName,
        int32_t     linenumber);
    // ~CDataStore();
    E_METHOD(void, _04_destructor);
    // int32_t IsRead();
    E_METHOD(int32_t, _05_IsRead);
    // void Reset();
    E_METHOD(void, _06_Reset);
    // void Finalize();
    E_METHOD(void, _07_Finalize);
    // void GetBufferParams(const void** data, uint32_t* size, uint32_t* alloc) const;
    P_METHOD(void, _08_GetBufferParams, const void** data, uint32_t* size, uint32_t* alloc);
    // void DetachBuffer(void** data, uint32_t* size, uint32_t* alloc);
    P_METHOD(void, _09_DetachBuffer, void** data, uint32_t* size, uint32_t* alloc);
    // uint32_t GetHeaderSpace();
    E_METHOD(uint32_t, _10_GetHeaderSpace);
};
#undef INTERFACE

struct CDataStore {
    CDataStore__v_table* v_table;
    uint8_t*             m_data;
    uint32_t             m_base;
    uint32_t             m_alloc;
    uint32_t             m_size;
    uint32_t             m_read;
};

#endif
