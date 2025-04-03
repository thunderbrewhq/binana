#ifndef STORM_OPTIONS_H
#define STORM_OPTIONS_H

DECLARE_STRUCT(STORMOPTIONS);

struct STORMOPTIONS {
  // int smemleaksilentwarning;
  // int serrleaksilentwarning;
  // unsigned int wavechunksize;
  // int alignstreamingwavedata;
  // int echotooutputdebugstring;
  // int serrsuppresslogs;
  // int crcenabled;
  // int orderedprintfenabled;
  // int noreaderrordialog;
  // int assertlogonly;
  // int serrsuppressdialogs;
  // int serrignorerecoverable;

  // uint64_t opt00;  // dword_CAE950
  int32_t  smemleaksilentwarning;  // dword_CAE958
  int32_t  serrleaksilentwarning;  // dword_CAE95C
  uint32_t wavechunksize; // dword_CAE960
  int32_t  opt0C;  // dword_CAE964
  int32_t  opt10;  // dword_CAE968
  int32_t  opt14;  // dword_CAE96C
  int32_t  opt18;  // dword_CAE970
  int32_t  opt1C;  // dword_CAE974
  int32_t  sregunicode; // dword_CAE978
  int32_t  opt24; // dword_CAE97C
  int32_t  opt28; // dword_CAE980
};

#endif