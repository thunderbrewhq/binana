#ifndef BC_FILE_PROCESS_DIR_H
#define BC_FILE_PROCESS_DIR_H

DECLARE_STRUCT(Blizzard__File__ProcessDirParms);

struct Blizzard__File__ProcessDirParms {
    const char* pathRoot;
    const char* filename;
    void*       cookie;
    bool        isDir;
};

typedef bool (*Blizzard__File__ProcessDirCallback)(const Blizzard__File__ProcessDirParms* parms);

#endif
