#ifndef SRB_SRB_H
#define SRB_SRB_H

DECLARE_STRUCT(SRB);
DECLARE_STRUCT(SRB_HAInquiry);

// these structures are byte-packed
#pragma pack(push, 1)

struct SRB {
    uint8_t  SRB_Cmd;
    uint8_t  SRB_Status;
    uint8_t  SRB_HaId;
    uint8_t  SRB_Flags;
    uint32_t SRB_Hdr_Rsvd;
};

struct SRB_HAInquiry {
    uint8_t  SRB_Cmd;
    uint8_t  SRB_Status;
    uint8_t  SRB_HaId;
    uint8_t  SRB_Flags;
    uint32_t SRB_Hdr_Rsvd;
    uint8_t  HA_Count;
    uint8_t  HA_SCSI_ID;
    uint8_t  HA_ManagerId[16];
    uint8_t  HA_Identifier[16];
    uint8_t  HA_Unique[16];
    uint16_t HA_Rsvd1;
};

struct SRB_GDEVBlock {
    uint8_t  SRB_Cmd;
    uint8_t  SRB_Status;
    uint8_t  SRB_HaId;
    uint8_t  SRB_Flags;
    uint32_t SRB_Hdr_Rsvd;
    uint8_t  SRB_Target;
    uint8_t  SRB_Lun;
    uint8_t  SRB_DeviceType;
    uint8_t  SRB_Rsvd1;
};

struct SRB_ExecSCSICmd {
    uint8_t  SRB_Cmd;
    uint8_t  SRB_Status;
    uint8_t  SRB_HaId;
    uint8_t  SRB_Flags;
    uint32_t SRB_Hdr_Rsvd;
    uint8_t  SRB_Target;
    uint8_t  SRB_Lun;
    uint16_t SRB_Rsvd1;
    uint32_t SRB_BufLen;
    uint8_t* SRB_BufPointer;
    uint8_t  SRB_SenseLen;
    uint8_t  SRB_CDBLen;
    uint8_t  SRB_HaStat;
    uint8_t  SRB_TargStat;
    void*    SRB_PostProc;
    uint8_t  SRB_Rsvd2[20];
    uint8_t  CDBByte[16];
    uint8_t  SenseArea[16];
};

struct SRB_Abort {
    uint8_t  SRB_Cmd;
    uint8_t  SRB_Status;
    uint8_t  SRB_HaId;
    uint8_t  SRB_Flags;
    uint32_t SRB_Hdr_Rsvd;
    void*    SRB_ToAbort;
};

#pragma pack(pop)

#endif
