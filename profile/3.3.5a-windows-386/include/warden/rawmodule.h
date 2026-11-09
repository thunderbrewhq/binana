#ifndef WARDEN_RAW_MODULE_H
#define WARDEN_RAW_MODULE_H

// namespace Warden {
//
// struct RawModule;
//
// }
//
DECLARE_STRUCT(Warden__RawModule);

struct Warden__RawModule {
    uint8_t* m_image;
    uint32_t m_imageSize;
    int32_t  m_loadedDlls;
};

#endif
