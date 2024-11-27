#ifndef COMMON_REF_COUNT_H
#define COMMON_REF_COUNT_H

DECLARE_STRUCT(TRefCnt);

struct TRefCnt {
  void* vfptr;
  uint32_t m_refcnt;
};

#endif