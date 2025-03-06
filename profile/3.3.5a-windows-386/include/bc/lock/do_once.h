#ifndef BC_LOCK_DO_ONCE_H
#define BC_LOCK_DO_ONCE_H

DECLARE_STRUCT(Blizzard__Lock__DoOnceData);

struct Blizzard__Lock__DoOnceData {
  bool done;
  int32_t atomic;
};

#endif
