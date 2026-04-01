#ifndef BC_FILE_STREAM_H
#define BC_FILE_STREAM_H

DECLARE_STRUCT(Blizzard__File__StreamRecord);

// Stream is defined as a pointer to StreamRecord
typedef Blizzard__File__StreamRecord* Blizzard__File__Stream;

#include "bc/file/fileinfo.h"
#include "bc/file/streaminginfo.h"

struct Blizzard__File__StreamRecord {
    void*                          fileHandle;
    int32_t                        mode;
    bool                           infoValid;
    uint32_t                       unk0C; // not present in Diablo 3 Switch
    Blizzard__File__FileInfo       info;
    Blizzard__File__StreamingInfo* streaming; // GetFileInfo only gets a size if this is null or points to a zero value
    char*                          pathname;  // name is a pointer to &filehandle (0x00) + sizeof(StreamRecord)
                                              // extra buffer that holds the actual data of name
};

#endif
