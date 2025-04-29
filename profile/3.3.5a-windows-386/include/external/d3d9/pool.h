#ifndef D3D9_POOL_H
#define D3D9_POOL_H

DECLARE_ENUM(D3DPOOL);

enum D3DPOOL {
  D3DPOOL_DEFAULT                 = 0,
  D3DPOOL_MANAGED                 = 1,
  D3DPOOL_SYSTEMMEM               = 2,
  D3DPOOL_SCRATCH                 = 3,

  D3DPOOL_FORCE_DWORD             = 0x7fffffff
};

#endif