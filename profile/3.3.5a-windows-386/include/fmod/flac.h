#ifndef FMOD_FLAC_H
#define FMOD_FLAC_H

// struct declarations

DECLARE_STRUCT(FLAC__EntropyCodingMethod_PartitionedRiceContents);
DECLARE_STRUCT(FLAC__EntropyCodingMethod_PartitionedRice);
DECLARE_STRUCT(FLAC__StreamDecoder);
DECLARE_STRUCT(FLAC__StreamDecoderProtected);
DECLARE_STRUCT(FLAC__StreamDecoderPrivate);
DECLARE_STRUCT(FLAC__Subframe_Constant);
DECLARE_STRUCT(FLAC__EntropyCodingMethod);
DECLARE_STRUCT(FLAC__Subframe_Fixed);
DECLARE_STRUCT(FLAC__Subframe_Verbatim);
DECLARE_STRUCT(FLAC__Subframe_LPC);
DECLARE_STRUCT(FLAC__Subframe);
DECLARE_STRUCT(FLAC__FrameHeader);
DECLARE_STRUCT(FLAC__FrameFooter);
DECLARE_STRUCT(FLAC__Frame);
DECLARE_STRUCT(FLAC__StreamMetadata_StreamInfo);
DECLARE_STRUCT(FLAC__StreamMetadata_Padding);
DECLARE_STRUCT(FLAC__StreamMetadata_Application);
DECLARE_STRUCT(FLAC__StreamMetadata_SeekPoint);
DECLARE_STRUCT(FLAC__StreamMetadata_SeekTable);
DECLARE_STRUCT(FLAC__StreamMetadata_VorbisComment_Entry);
DECLARE_STRUCT(FLAC__StreamMetadata_VorbisComment);
DECLARE_STRUCT(FLAC__StreamMetadata_CueSheet_Index);
DECLARE_STRUCT(FLAC__StreamMetadata_CueSheet_Track);
DECLARE_STRUCT(FLAC__StreamMetadata_CueSheet);
DECLARE_STRUCT(FLAC__StreamMetadata_Picture);
DECLARE_STRUCT(FLAC__StreamMetadata_Unknown);
DECLARE_STRUCT(FLAC__StreamMetadata);
DECLARE_STRUCT(FLAC__OggDecoderAspect);
DECLARE_STRUCT(FLAC__BitReader);
DECLARE_STRUCT(FLAC__CPUInfo_IA32);
DECLARE_STRUCT(FLAC__CPUInfo_PPC);
DECLARE_STRUCT(FLAC__CPUInfo);
DECLARE_STRUCT(FLAC__MD5Context);

// union declarations
DECLARE_UNION(FLAC__EntropyCodingMethod__data);
DECLARE_UNION(FLAC__Subframe__data);
DECLARE_UNION(FLAC__FrameHeader__number);
DECLARE_UNION(FLAC__StreamMetadata__data);
DECLARE_UNION(FLAC__CPUInfo__data);

// enum declarations

DECLARE_ENUM(FLAC__StreamDecoderState);
DECLARE_ENUM(FLAC__StreamDecoderInitStatus);
DECLARE_ENUM(FLAC__StreamDecoderErrorStatus);
DECLARE_ENUM(FLAC__StreamDecoderReadStatus);
DECLARE_ENUM(FLAC__StreamDecoderSeekStatus);
DECLARE_ENUM(FLAC__StreamDecoderTellStatus);
DECLARE_ENUM(FLAC__StreamDecoderLengthStatus);
DECLARE_ENUM(FLAC__StreamDecoderWriteStatus);
DECLARE_ENUM(FLAC__EntropyCodingMethodType);
DECLARE_ENUM(FLAC__SubframeType);
DECLARE_ENUM(FLAC__ChannelAssignment);
DECLARE_ENUM(FLAC__FrameNumberType);
DECLARE_ENUM(FLAC__MetadataType);
DECLARE_ENUM(FLAC__StreamMetadata_Picture_Type);
DECLARE_ENUM(FLAC__CPUInfo_Type);
DECLARE_ENUM(FLAC__OggDecoderAspectReadStatus);

// integral types

typedef int8_t      FLAC__int8;
typedef uint8_t     FLAC__uint8;
typedef FLAC__uint8 FLAC__byte;
typedef int16_t     FLAC__int16;
typedef int32_t     FLAC__int32;
typedef int32_t     FLAC__bool;
typedef int64_t     FLAC__int64;
typedef uint16_t    FLAC__uint16;
typedef uint32_t    FLAC__uint32;
typedef uint64_t    FLAC__uint64;

typedef FLAC__uint32 brword;

// callbacks

DECLARE_CALLBACK(
    FLAC__StreamDecoderReadStatus,
    FLAC__StreamDecoderReadCallback,
    const FLAC__StreamDecoder* decoder,
    FLAC__byte                 buffer[],
    size_t*                    bytes,
    void*                      client_data);
DECLARE_CALLBACK(
    FLAC__StreamDecoderSeekStatus,
    FLAC__StreamDecoderSeekCallback,
    const FLAC__StreamDecoder* decoder,
    FLAC__uint64               absolute_byte_offset,
    void*                      client_data);
DECLARE_CALLBACK(
    FLAC__StreamDecoderTellStatus,
    FLAC__StreamDecoderTellCallback,
    const FLAC__StreamDecoder* decoder,
    FLAC__uint64*              absolute_byte_offset,
    void*                      client_data);
DECLARE_CALLBACK(
    FLAC__StreamDecoderLengthStatus,
    FLAC__StreamDecoderLengthCallback,
    const FLAC__StreamDecoder* decoder,
    FLAC__uint64*              stream_length,
    void*                      client_data);

DECLARE_CALLBACK(
    FLAC__bool,
    FLAC__StreamDecoderEofCallback,
    const FLAC__StreamDecoder* decoder,
    void*                      client_data);

DECLARE_CALLBACK(
    FLAC__StreamDecoderWriteStatus,
    FLAC__StreamDecoderWriteCallback,
    const FLAC__StreamDecoder* decoder,
    const FLAC__Frame*         frame,
    const FLAC__int32* const   buffer[],
    void*                      client_data);
DECLARE_CALLBACK(
    void,
    FLAC__StreamDecoderMetadataCallback,
    const FLAC__StreamDecoder*  decoder,
    const FLAC__StreamMetadata* metadata,
    void*                       client_data);
DECLARE_CALLBACK(
    void,
    FLAC__StreamDecoderErrorCallback,
    const FLAC__StreamDecoder*     decoder,
    FLAC__StreamDecoderErrorStatus status,
    void*                          client_data);
DECLARE_CALLBACK(
    FLAC__bool,
    FLAC__BitReaderReadCallback,
    FLAC__byte buffer[],
    size_t*    bytes,
    void*      client_data);
DECLARE_CALLBACK(
    FLAC__OggDecoderAspectReadStatus,
    FLAC__OggDecoderAspectReadCallbackProxy,
    const void* decoder,
    FLAC__byte  buffer[],
    size_t*     bytes,
    void*       client_data);

// import

#include "external/stdlib/file.h"
#include "fmod/vorbis.h"

// enums

enum FLAC__StreamDecoderSeekStatus {
    FLAC__STREAM_DECODER_SEEK_STATUS_OK,
    FLAC__STREAM_DECODER_SEEK_STATUS_ERROR,
    FLAC__STREAM_DECODER_SEEK_STATUS_UNSUPPORTED
};

enum FLAC__StreamDecoderState {
    FLAC__STREAM_DECODER_SEARCH_FOR_METADATA = 0,
    FLAC__STREAM_DECODER_READ_METADATA,
    FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC,
    FLAC__STREAM_DECODER_READ_FRAME,
    FLAC__STREAM_DECODER_END_OF_STREAM,
    FLAC__STREAM_DECODER_OGG_ERROR,
    FLAC__STREAM_DECODER_SEEK_ERROR,
    FLAC__STREAM_DECODER_ABORTED,
    FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR,
    FLAC__STREAM_DECODER_UNINITIALIZED
};

enum FLAC__StreamDecoderInitStatus {
    FLAC__STREAM_DECODER_INIT_STATUS_OK = 0,
    FLAC__STREAM_DECODER_INIT_STATUS_UNSUPPORTED_CONTAINER,
    FLAC__STREAM_DECODER_INIT_STATUS_INVALID_CALLBACKS,
    FLAC__STREAM_DECODER_INIT_STATUS_MEMORY_ALLOCATION_ERROR,
    FLAC__STREAM_DECODER_INIT_STATUS_ERROR_OPENING_FILE,
    FLAC__STREAM_DECODER_INIT_STATUS_ALREADY_INITIALIZED
};

enum FLAC__StreamDecoderErrorStatus {
    FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC,
    FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER,
    FLAC__STREAM_DECODER_ERROR_STATUS_FRAME_CRC_MISMATCH,
    FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM
};

enum FLAC__StreamDecoderReadStatus {
    FLAC__STREAM_DECODER_READ_STATUS_CONTINUE,
    FLAC__STREAM_DECODER_READ_STATUS_END_OF_STREAM,
    FLAC__STREAM_DECODER_READ_STATUS_ABORT
};

enum FLAC__StreamDecoderTellStatus {
    FLAC__STREAM_DECODER_TELL_STATUS_OK,
    FLAC__STREAM_DECODER_TELL_STATUS_ERROR,
    FLAC__STREAM_DECODER_TELL_STATUS_UNSUPPORTED
};

enum FLAC__StreamDecoderLengthStatus {
    FLAC__STREAM_DECODER_LENGTH_STATUS_OK,
    FLAC__STREAM_DECODER_LENGTH_STATUS_ERROR,
    FLAC__STREAM_DECODER_LENGTH_STATUS_UNSUPPORTED
};

enum FLAC__StreamDecoderWriteStatus {
    FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE,
    FLAC__STREAM_DECODER_WRITE_STATUS_ABORT
};

enum FLAC__EntropyCodingMethodType {
    FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE = 0
};

enum FLAC__SubframeType {
    FLAC__SUBFRAME_TYPE_CONSTANT = 0,
    FLAC__SUBFRAME_TYPE_VERBATIM = 1,
    FLAC__SUBFRAME_TYPE_FIXED    = 2,
    FLAC__SUBFRAME_TYPE_LPC      = 3
};

enum FLAC__ChannelAssignment {
    FLAC__CHANNEL_ASSIGNMENT_INDEPENDENT = 0,
    FLAC__CHANNEL_ASSIGNMENT_LEFT_SIDE   = 1,
    FLAC__CHANNEL_ASSIGNMENT_RIGHT_SIDE  = 2,
    FLAC__CHANNEL_ASSIGNMENT_MID_SIDE    = 3
};

enum FLAC__FrameNumberType {
    FLAC__FRAME_NUMBER_TYPE_FRAME_NUMBER,
    FLAC__FRAME_NUMBER_TYPE_SAMPLE_NUMBER
};

enum FLAC__MetadataType {
    FLAC__METADATA_TYPE_STREAMINFO     = 0,
    FLAC__METADATA_TYPE_PADDING        = 1,
    FLAC__METADATA_TYPE_APPLICATION    = 2,
    FLAC__METADATA_TYPE_SEEKTABLE      = 3,
    FLAC__METADATA_TYPE_VORBIS_COMMENT = 4,
    FLAC__METADATA_TYPE_CUESHEET       = 5,
    FLAC__METADATA_TYPE_PICTURE        = 6,
    FLAC__METADATA_TYPE_UNDEFINED      = 7
};

enum FLAC__StreamMetadata_Picture_Type {
    FLAC__STREAM_METADATA_PICTURE_TYPE_OTHER                = 0,
    FLAC__STREAM_METADATA_PICTURE_TYPE_FILE_ICON_STANDARD   = 1,
    FLAC__STREAM_METADATA_PICTURE_TYPE_FILE_ICON            = 2,
    FLAC__STREAM_METADATA_PICTURE_TYPE_FRONT_COVER          = 3,
    FLAC__STREAM_METADATA_PICTURE_TYPE_BACK_COVER           = 4,
    FLAC__STREAM_METADATA_PICTURE_TYPE_LEAFLET_PAGE         = 5,
    FLAC__STREAM_METADATA_PICTURE_TYPE_MEDIA                = 6,
    FLAC__STREAM_METADATA_PICTURE_TYPE_LEAD_ARTIST          = 7,
    FLAC__STREAM_METADATA_PICTURE_TYPE_ARTIST               = 8,
    FLAC__STREAM_METADATA_PICTURE_TYPE_CONDUCTOR            = 9,
    FLAC__STREAM_METADATA_PICTURE_TYPE_BAND                 = 10,
    FLAC__STREAM_METADATA_PICTURE_TYPE_COMPOSER             = 11,
    FLAC__STREAM_METADATA_PICTURE_TYPE_LYRICIST             = 12,
    FLAC__STREAM_METADATA_PICTURE_TYPE_RECORDING_LOCATION   = 13,
    FLAC__STREAM_METADATA_PICTURE_TYPE_DURING_RECORDING     = 14,
    FLAC__STREAM_METADATA_PICTURE_TYPE_DURING_PERFORMANCE   = 15,
    FLAC__STREAM_METADATA_PICTURE_TYPE_VIDEO_SCREEN_CAPTURE = 16,
    FLAC__STREAM_METADATA_PICTURE_TYPE_FISH                 = 17,
    FLAC__STREAM_METADATA_PICTURE_TYPE_ILLUSTRATION         = 18,
    FLAC__STREAM_METADATA_PICTURE_TYPE_BAND_LOGOTYPE        = 19,
    FLAC__STREAM_METADATA_PICTURE_TYPE_PUBLISHER_LOGOTYPE   = 20,
    FLAC__STREAM_METADATA_PICTURE_TYPE_UNDEFINED
};

enum FLAC__CPUInfo_Type {
    FLAC__CPUINFO_TYPE_IA32,
    FLAC__CPUINFO_TYPE_PPC,
    FLAC__CPUINFO_TYPE_UNKNOWN
};

enum FLAC__OggDecoderAspectReadStatus {
    FLAC__OGG_DECODER_ASPECT_READ_STATUS_OK = 0,
    FLAC__OGG_DECODER_ASPECT_READ_STATUS_END_OF_STREAM,
    FLAC__OGG_DECODER_ASPECT_READ_STATUS_LOST_SYNC,
    FLAC__OGG_DECODER_ASPECT_READ_STATUS_NOT_FLAC,
    FLAC__OGG_DECODER_ASPECT_READ_STATUS_UNSUPPORTED_MAPPING_VERSION,
    FLAC__OGG_DECODER_ASPECT_READ_STATUS_ABORT,
    FLAC__OGG_DECODER_ASPECT_READ_STATUS_ERROR,
    FLAC__OGG_DECODER_ASPECT_READ_STATUS_MEMORY_ALLOCATION_ERROR
};

//

struct FLAC__EntropyCodingMethod_PartitionedRiceContents {
    uint32_t* parameters;
    uint32_t* raw_bits;
    uint32_t  capacity_by_order;
};

struct FLAC__EntropyCodingMethod_PartitionedRice {
    uint32_t                                                 order;
    const FLAC__EntropyCodingMethod_PartitionedRiceContents* contents;
};

union FLAC__EntropyCodingMethod__data {
    FLAC__EntropyCodingMethod_PartitionedRice partitioned_rice;
};

struct FLAC__EntropyCodingMethod {
    FLAC__EntropyCodingMethodType   type;
    FLAC__EntropyCodingMethod__data data;
};

struct FLAC__Subframe_Constant {
    FLAC__int32 value;
};

struct FLAC__Subframe_Verbatim {
    const FLAC__int32* data;
};

struct FLAC__Subframe_Fixed {
    FLAC__EntropyCodingMethod entropy_coding_method;
    uint32_t                  order;
    FLAC__int32               warmup[4];
    const FLAC__int32*        residual;
};

struct FLAC__Subframe_LPC {
    FLAC__EntropyCodingMethod entropy_coding_method;
    uint32_t                  order;
    uint32_t                  qlp_coeff_precision;
    int32_t                   quantization_level;
    FLAC__int32               qlp_coeff[32];
    FLAC__int32               warmup[32];
    const FLAC__int32*        residual;
};

union FLAC__Subframe__data {
    FLAC__Subframe_Constant constant;
    FLAC__Subframe_Fixed    fixed;
    FLAC__Subframe_LPC      lpc;
    FLAC__Subframe_Verbatim verbatim;
};

struct FLAC__Subframe {
    FLAC__SubframeType   type;
    FLAC__Subframe__data data;
    uint32_t             wasted_bits;
};

union FLAC__FrameHeader__number {
    FLAC__uint32 frame_number;
    FLAC__uint64 sample_number;
};

struct FLAC__FrameHeader {
    uint32_t                  blocksize;
    uint32_t                  sample_rate;
    uint32_t                  channels;
    FLAC__ChannelAssignment   channel_assignment;
    uint32_t                  bits_per_sample;
    FLAC__FrameNumberType     number_type;
    FLAC__FrameHeader__number number;
    FLAC__uint8               crc;
};

struct FLAC__FrameFooter {
    FLAC__uint16 crc;
};

struct FLAC__Frame {
    FLAC__FrameHeader header;
    FLAC__Subframe    subframes[8];
    FLAC__FrameFooter footer;
};

struct FLAC__StreamMetadata_StreamInfo {
    uint32_t     min_blocksize;
    uint32_t     max_blocksize;
    uint32_t     min_framesize;
    uint32_t     max_framesize;
    uint32_t     sample_rate;
    uint32_t     channels;
    uint32_t     bits_per_sample;
    FLAC__uint64 total_samples;
    FLAC__byte   md5sum[16];
};

struct FLAC__StreamMetadata_Padding {
    int32_t dummy;
};

struct FLAC__StreamMetadata_Application {
    FLAC__byte  id[4];
    FLAC__byte* data;
};

struct FLAC__StreamMetadata_SeekPoint {
    FLAC__uint64 sample_number;
    FLAC__uint64 stream_offset;
    uint32_t     frame_samples;
};

struct FLAC__StreamMetadata_SeekTable {
    uint32_t                        num_points;
    FLAC__StreamMetadata_SeekPoint* points;
};

struct FLAC__StreamMetadata_VorbisComment_Entry {
    FLAC__uint32 length;
    FLAC__byte*  entry;
};

struct FLAC__StreamMetadata_VorbisComment {
    FLAC__StreamMetadata_VorbisComment_Entry  vendor_string;
    FLAC__uint32                              num_comments;
    FLAC__StreamMetadata_VorbisComment_Entry* comments;
};

struct FLAC__StreamMetadata_CueSheet_Index {
    FLAC__uint64 offset;
    FLAC__byte   number;
};

struct FLAC__StreamMetadata_CueSheet_Track {
    FLAC__uint64 offset;
    FLAC__byte   number;
    char         isrc[13];
#if defined(BITFIELDS_SUPPORTED)
    uint32_t type : 1;
    uint32_t pre_emphasis : 1;
#else
    uint32_t flags;
#endif
    FLAC__byte                           num_indices;
    FLAC__StreamMetadata_CueSheet_Index* indices;
};

struct FLAC__StreamMetadata_CueSheet {
    char                                 media_catalog_number[129];
    FLAC__uint64                         lead_in;
    FLAC__bool                           is_cd;
    uint32_t                             num_tracks;
    FLAC__StreamMetadata_CueSheet_Track* tracks;
};

struct FLAC__StreamMetadata_Picture {
    FLAC__StreamMetadata_Picture_Type type;
    char*                             mime_type;
    FLAC__byte*                       description;
    FLAC__uint32                      width;
    FLAC__uint32                      height;
    FLAC__uint32                      depth;
    FLAC__uint32                      colors;
    FLAC__uint32                      data_length;
    FLAC__byte*                       data;
};

struct FLAC__StreamMetadata_Unknown {
    FLAC__byte* data;
};

union FLAC__StreamMetadata__data {
    FLAC__StreamMetadata_StreamInfo    stream_info;
    FLAC__StreamMetadata_Padding       padding;
    FLAC__StreamMetadata_Application   application;
    FLAC__StreamMetadata_SeekTable     seek_table;
    FLAC__StreamMetadata_VorbisComment vorbis_comment;
    FLAC__StreamMetadata_CueSheet      cue_sheet;
    FLAC__StreamMetadata_Picture       picture;
    FLAC__StreamMetadata_Unknown       unknown;
};

struct FLAC__StreamMetadata {
    FLAC__MetadataType         type;
    FLAC__bool                 is_last;
    uint32_t                   length;
    FLAC__StreamMetadata__data data;
};

// size = [0x1D4]
struct FLAC__OggDecoderAspect {
    FLAC__bool       use_first_serial_number; // 0x000
    int32_t          serial_number;           // 0x004
    ogg_stream_state stream_state;            // 0x008
    ogg_sync_state   sync_state;              // 0x170
    uint32_t         version_major;           // 0x18C
    uint32_t         version_minor;           // 0x190
    FLAC__bool       need_serial_number;      // 0x194
    FLAC__bool       end_of_stream;           // 0x198
    FLAC__bool       have_working_page;       // 0x19C
    ogg_page         working_page;            // 0x1A0
    FLAC__bool       have_working_packet;     // 0x1B0
    ogg_packet       working_packet;          // 0x1B4
};

struct FLAC__BitReader {
    brword*                     buffer;
    uint32_t                    capacity;
    uint32_t                    words;
    uint32_t                    bytes;
    uint32_t                    consumed_words;
    uint32_t                    consumed_bits;
    uint32_t                    read_crc16;
    uint32_t                    crc16_align;
    FLAC__BitReaderReadCallback read_callback;
    void*                       client_data;
};

struct FLAC__CPUInfo_IA32 {
    FLAC__bool cmov;
    FLAC__bool mmx;
    FLAC__bool fxsr;
    FLAC__bool sse;
    FLAC__bool sse2;
    FLAC__bool _3dnow;
    FLAC__bool ext3dnow;
    FLAC__bool extmmx;
};

struct FLAC__CPUInfo_PPC {
    FLAC__bool altivec;
    FLAC__bool ppc64;
};

union FLAC__CPUInfo__data {
    FLAC__CPUInfo_IA32 ia32;
    FLAC__CPUInfo_PPC  ppc;
};

struct FLAC__CPUInfo {
    FLAC__bool          use_asm;
    FLAC__CPUInfo_Type  type;
    FLAC__CPUInfo__data data;
};

struct FLAC__MD5Context {
    FLAC__uint32 buf[4];
    FLAC__uint32 bytes[2];
    FLAC__uint32 in[16];
    FLAC__byte*  internal_buf;
    uint32_t     capacity;
};

// size = 0x1F8
struct FLAC__StreamDecoderProtected {
    FLAC__StreamDecoderState state;              // 0x000
    uint32_t                 channels;           // 0x004
    FLAC__ChannelAssignment  channel_assignment; // 0x008
    uint32_t                 bits_per_sample;    // 0x00C
    uint32_t                 sample_rate;        // 0x010
    uint32_t                 blocksize;          // 0x014
    FLAC__bool               md5_checking;       // 0x018
    FLAC__OggDecoderAspect   ogg_decoder_aspect; // 0x020
};

// size = 0x17F8
struct FLAC__StreamDecoderPrivate {
    FLAC__bool                          is_ogg;
    FLAC__StreamDecoderReadCallback     read_callback;
    FLAC__StreamDecoderSeekCallback     seek_callback;
    FLAC__StreamDecoderTellCallback     tell_callback;
    FLAC__StreamDecoderLengthCallback   length_callback;
    FLAC__StreamDecoderEofCallback      eof_callback;
    FLAC__StreamDecoderWriteCallback    write_callback;
    FLAC__StreamDecoderMetadataCallback metadata_callback;
    FLAC__StreamDecoderErrorCallback    error_callback;
    void (*local_lpc_restore_signal)(
        const FLAC__int32 residual[],
        uint32_t          data_len,
        const FLAC__int32 qlp_coeff[],
        uint32_t          order,
        int32_t           lp_quantization,
        FLAC__int32       data[]);
    void (*local_lpc_restore_signal_64bit)(
        const FLAC__int32 residual[],
        uint32_t          data_len,
        const FLAC__int32 qlp_coeff[],
        uint32_t          order,
        int32_t           lp_quantization,
        FLAC__int32       data[]);
    void (*local_lpc_restore_signal_16bit)(
        const FLAC__int32 residual[],
        uint32_t          data_len,
        const FLAC__int32 qlp_coeff[],
        uint32_t          order,
        int32_t           lp_quantization,
        FLAC__int32       data[]);
    void (*local_lpc_restore_signal_16bit_order8)(
        const FLAC__int32 residual[],
        uint32_t          data_len,
        const FLAC__int32 qlp_coeff[],
        uint32_t          order,
        int32_t           lp_quantization,
        FLAC__int32       data[]);
    void*                                             client_data;
    FILE*                                             file;
    FLAC__BitReader*                                  input;
    FLAC__int32*                                      output[8];
    FLAC__int32*                                      residual[8];
    FLAC__EntropyCodingMethod_PartitionedRiceContents partitioned_rice_contents[8];
    uint32_t                                          output_capacity;
    uint32_t                                          output_channels;
    FLAC__uint32                                      last_frame_number;
    FLAC__uint32                                      last_block_size;
    FLAC__uint64                                      samples_decoded;
    FLAC__bool                                        has_stream_info;
    FLAC__bool                                        has_seek_table;
    FLAC__StreamMetadata                              stream_info;
    FLAC__StreamMetadata                              seek_table;
    FLAC__bool                                        metadata_filter[128];
    FLAC__byte*                                       metadata_filter_ids;
    uint32_t                                          metadata_filter_ids_count;
    uint32_t                                          metadata_filter_ids_capacity;
    FLAC__Frame                                       frame;
    FLAC__bool                                        cached;
    FLAC__CPUInfo                                     cpuinfo;
    FLAC__byte                                        header_warmup[2];
    FLAC__byte                                        lookahead;
    FLAC__int32*                                      residual_unaligned[8];
    FLAC__bool                                        do_md5_checking;
    FLAC__bool                                        internal_reset_hack;
    FLAC__bool                                        is_seeking;
    FLAC__MD5Context                                  md5context;
    FLAC__byte                                        computed_md5sum[16];
    FLAC__Frame                                       last_frame;
    FLAC__uint64                                      first_frame_offset;
    FLAC__uint64                                      target_sample;
    uint32_t                                          unparseable_frame_count;
    FLAC__bool                                        got_a_frame;
};

// size = 0x8
struct FLAC__StreamDecoder {
    FLAC__StreamDecoderProtected* protected_;
    FLAC__StreamDecoderPrivate*   private_;
};

#endif
