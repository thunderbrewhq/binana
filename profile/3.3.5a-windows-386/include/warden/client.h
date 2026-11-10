#ifndef WARDEN_CLIENT_H
#define WARDEN_CLIENT_H

DECLARE_STRUCT(Warden__Client__Id);
DECLARE_STRUCT(Warden__Client__Key);

DECLARE_STRUCT(Warden__Client__OurLibrary);
DECLARE_STRUCT(Warden__Client__OurLibrary__v_table);

struct Warden__Client__Id {
    // TODO: check
    uint8_t m_data[16];
};

struct Warden__Client__Key {
    // TODO: check
    uint8_t m_data[16];
};

#define INTERFACE Warden__Client__OurLibrary
struct Warden__Client__OurLibrary__v_table {
    P_METHOD(void, _00_Data, void* data, uint32_t size);
    // int32_t Warden::Client::OurLibrary::ModuleUse(
    //   const Warden::Client::Id& id,
    //   const Warden::Client::Key& key);
    P_METHOD(int32_t, _01_ModuleUse, const Warden__Client__Id* id, const Warden__Client__Key* key);
    // int32_t Warden::Client::OurLibrary::ModuleCache(
    //   const Warden::Client::Id& id,
    //   const void* data,
    //   uint32_t size);
    P_METHOD(void, _02_ModuleCache, const Warden__Client__Id* id, const void* data, uint32_t size);
    // void* Warden::Client::OurLibrary::MemoryAlloc(
    //   uint32_t size
    // );
    P_METHOD(void*, _03_MemoryAlloc, uint32_t size);
    // void Warden::Client::OurLibrary::MemoryFree(
    //   void* data
    // );
    P_METHOD(void, _04_MemoryFree, void* data);
    // void Warden::Client::OurLibrary::StateSave(
    //   const void* data,
    //   uint32_t size
    // );
    P_METHOD(void, _05_StateSave, const void* data, uint32_t size);
    // bool Warden::Client::OurLibrary::StateLoad(
    //   const void* data,
    //   uint32_t& size);
    P_METHOD(bool, _06_StateLoad, void* data, uint32_t* size);
};
#undef INTERFACE

struct Warden__Client__OurLibrary {
    Warden__Client__OurLibrary__v_table* v_table;
};

#endif
