#ifndef CRYPTO_SHA1_H
#define CRYPTO_SHA1_H

DECLARE_STRUCT(SHA1);
DECLARE_STRUCT(SHA1__Digest);

#include "crypto/hmac.h"

struct SHA1 {
    uint64_t m_size;
    uint32_t m_hash[5];
    uint8_t  m_data[64];
};

// SHA1::Digest
struct SHA1__Digest {
    uint8_t d[20];
};

CRYPTO_HMAC(SHA1, 64);

#endif
