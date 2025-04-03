#ifndef OS_PROCESSOR_FEATURES_H
#define OS_PROCESSOR_FEATURES_H

DECLARE_STRUCT(ProcessorFeatures);

struct ProcessorFeatures {
  // vendor ID string
  uint32_t std_0b; // 00
  uint32_t std_0d; // 04
  uint32_t std_0c; // 08
  // standard
  uint32_t std_0a; // 0C

  uint32_t std_1b; // 10
  uint32_t std_1d; // 14
  uint32_t std_4a; // 18
  // extended
  uint32_t ext_0a; // 1C

  uint32_t ext_1c; // 20
  uint32_t ext_1d; // 24
  uint32_t ext_8c; // 28

  // processor brand string
  uint32_t ext_2a; // 2C
  uint32_t ext_2b; // 30
  uint32_t ext_2c; // 34
  uint32_t ext_2d; // 38
  
  uint32_t ext_3a; // 3C
  uint32_t ext_3b; // 40
  uint32_t ext_3c; // 44
  uint32_t ext_3d; // 48

  uint32_t ext_4a; // 4c
  uint32_t ext_4b; // 50
  uint32_t ext_4c; // 54
  uint32_t ext_4d; // 58
};

#endif