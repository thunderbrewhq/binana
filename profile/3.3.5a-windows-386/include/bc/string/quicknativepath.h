#ifndef BC_STRING_QUICK_NATIVE_PATH_H
#define BC_STRING_QUICK_NATIVE_PATH_H

#define BC_STRING_QUICK_NATIVE_PATH(N) \
typedef struct Blizzard__String__QuickNativePath_##N Blizzard__String__QuickNativePath_##N; \
struct Blizzard__String__QuickNativePath_##N { \
  uint32_t length; \
  char* path; \
  char buffer[N]; \
}

BC_STRING_QUICK_NATIVE_PATH(300);
BC_STRING_QUICK_NATIVE_PATH(1024);

#endif