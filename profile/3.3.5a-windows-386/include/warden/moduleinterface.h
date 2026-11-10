#ifndef WARDEN_MODULE_INTERFACE_H
#define WARDEN_MODULE_INTERFACE_H

DECLARE_STRUCT(Warden__ModuleInterface);
DECLARE_STRUCT(Warden__ModuleInterface__v_table);

#define INTERFACE Warden__ModuleInterface
struct Warden__ModuleInterface__v_table {
    P_METHOD(void, _00_GenerateARC4Keys, void* data, uint32_t size);
    P_METHOD(void, _01_Unload, void* keys);
    P_METHOD(void, _02_HandlePacket, void* data, uint32_t size, uint32_t* bytesConsumed);
    P_METHOD(void, _03_Tick, uint32_t size);
};
#undef INTERFACE

struct Warden__ModuleInterface {
    Warden__ModuleInterface__v_table* v_table;
};

#endif
