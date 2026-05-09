#ifndef STORM_CRYPTO_ARC4_H
#define STORM_CRYPTO_ARC4_H

DECLARE_STRUCT(SARC4Key);

struct SARC4Key {
    uint8_t state[256];
    uint8_t x;
    uint8_t y;
};

#endif
