#ifndef CRYPTO_HMAC_H
#define CRYPTO_HMAC_H

// HMAC<Hash>
#define CRYPTO_HMAC(Hash, BlockSize)                                                               \
    DECLARE_STRUCT(HMAC_##Hash);                                                                   \
    struct HMAC_##Hash {                                                                           \
        Hash    m_hash;                                                                            \
        uint8_t m_innerPad[BlockSize];                                                             \
        uint8_t m_outerPad[BlockSize];                                                             \
    };

// template <class Hash>
// class HMAC<Hash> {
//   Finish(Hash::Digest& digest);
// };

#endif
