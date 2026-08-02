#ifndef FMOD_VORBIS_H
#define FMOD_VORBIS_H

// struct declarations
#include "system/detect.h"

DECLARE_STRUCT(highlevel_byblocktype);
DECLARE_STRUCT(highlevel_encode_setup);
DECLARE_STRUCT(OggVorbis_File);
DECLARE_STRUCT(alloc_chain);
DECLARE_STRUCT(bitrate_manager_info);
DECLARE_STRUCT(bitrate_manager_state);
DECLARE_STRUCT(drft_lookup);
DECLARE_STRUCT(envelope_band);
DECLARE_STRUCT(envelope_filter_state);
DECLARE_STRUCT(envelope_lookup);
DECLARE_STRUCT(lsfit_acc);
DECLARE_STRUCT(mdct_lookup);
DECLARE_STRUCT(ogg_packet);
DECLARE_STRUCT(ogg_page);
DECLARE_STRUCT(ogg_stream_state);
DECLARE_STRUCT(ogg_sync_state);
DECLARE_STRUCT(oggpack_buffer);
DECLARE_STRUCT(ov_callbacks);
DECLARE_STRUCT(private_state);
DECLARE_STRUCT(vorbis_block);
DECLARE_STRUCT(vorbis_block_internal);
DECLARE_STRUCT(vorbis_comment);
DECLARE_STRUCT(vorbis_dsp_state);
DECLARE_STRUCT(vorbis_func_floor);
DECLARE_STRUCT(vorbis_func_mapping);
DECLARE_STRUCT(vorbis_func_residue);
DECLARE_STRUCT(vorbis_info);
DECLARE_STRUCT(vorbis_info_floor);
DECLARE_STRUCT(vorbis_info_floor0);
DECLARE_STRUCT(vorbis_info_floor1);
DECLARE_STRUCT(vorbis_info_mapping);
DECLARE_STRUCT(vorbis_info_mapping0);
DECLARE_STRUCT(vorbis_info_mode);
DECLARE_STRUCT(vorbis_info_psy);
DECLARE_STRUCT(vorbis_info_psy_global);
DECLARE_STRUCT(vorbis_info_residue);
DECLARE_STRUCT(vorbis_info_residue0);
DECLARE_STRUCT(vorbis_look_residue0);
DECLARE_STRUCT(vorbis_look_floor);
DECLARE_STRUCT(vorbis_look_floor0);
DECLARE_STRUCT(vorbis_look_floor1);
DECLARE_STRUCT(vorbis_look_psy);
DECLARE_STRUCT(vorbis_look_psy_global);
DECLARE_STRUCT(vorbis_look_residue);
DECLARE_STRUCT(vorbis_look_transform);
DECLARE_STRUCT(static_codebook);
DECLARE_STRUCT(codebook);
DECLARE_STRUCT(encode_aux_pigeonhole);
DECLARE_STRUCT(encode_aux_nearestmatch);
DECLARE_STRUCT(encode_aux_threshmatch);

// integral types
typedef int16_t  ogg_int16_t;
typedef uint16_t ogg_uint16_t;
typedef int32_t  ogg_int32_t;
typedef uint32_t ogg_uint32_t;
typedef int64_t  ogg_int64_t;

// enums

// structs

// struct ogg_iovec_t {
//     void*    iov_base;
//     uint32_t iov_len;
// };

struct oggpack_buffer {
    int32_t  endbyte;
    int32_t  endbit;
    uint8_t* buffer;
    uint8_t* ptr;
    int32_t  storage;
};

struct ogg_page {
    uint8_t* header;
    int32_t  header_len;
    uint8_t* body;
    int32_t  body_len;
};

struct ogg_stream_state {
    uint8_t*     body_data;
    int32_t      body_storage;
    int32_t      body_fill;
    int32_t      body_returned;
    int32_t*     lacing_vals;
    ogg_int64_t* granule_vals;
    int32_t      lacing_storage;
    int32_t      lacing_fill;
    int32_t      lacing_packet;
    int32_t      lacing_returned;
    uint8_t      header[282];
    int32_t      header_fill;
    int32_t      e_o_s;
    int32_t      b_o_s;
    int32_t      serialno;
    int32_t      pageno;
    ogg_int64_t  packetno;
    ogg_int64_t  granulepos;
};

struct ogg_packet {
    uint8_t*    packet;
    int32_t     bytes;
    int32_t     b_o_s;
    int32_t     e_o_s;
    ogg_int64_t granulepos;
    ogg_int64_t packetno;
};

struct ogg_sync_state {
    uint8_t* data;
    int32_t  storage;
    int32_t  fill;
    int32_t  returned;
    int32_t  unsynced;
    int32_t  headerbytes;
    int32_t  bodybytes;
};

struct vorbis_info {
    int32_t version;
    int32_t channels;
    int32_t rate;
    int32_t bitrate_upper;
    int32_t bitrate_nominal;
    int32_t bitrate_lower;
    int32_t bitrate_window;
    void*   codec_setup;
};

struct vorbis_dsp_state {
    int32_t      analysisp;
    vorbis_info* vi;
    float**      pcm;
    float**      pcmret;
    int32_t      pcm_storage;
    int32_t      pcm_current;
    int32_t      pcm_returned;
    int32_t      preextrapolate;
    int32_t      eofflag;
    int32_t      lW;
    int32_t      W;
    int32_t      nW;
    int32_t      centerW;
    ogg_int64_t  granulepos;
    ogg_int64_t  sequence;
    ogg_int64_t  glue_bits;
    ogg_int64_t  time_bits;
    ogg_int64_t  floor_bits;
    ogg_int64_t  res_bits;
    void*        backend_state; // 0x68 confirmed
};

struct alloc_chain {
    void*        ptr;
    alloc_chain* next;
};

struct vorbis_block {
    float**           pcm;
    oggpack_buffer    opb;
    int32_t           lW;
    int32_t           W;
    int32_t           nW;
    int32_t           pcmend;
    int32_t           mode;
    int32_t           eofflag;
    ogg_int64_t       granulepos;
    ogg_int64_t       sequence;
    vorbis_dsp_state* vd;
    void*             localstore;
    int32_t           localtop;
    int32_t           localalloc;
    int32_t           totaluse;
    alloc_chain*      reap;
    int32_t           glue_bits;
    int32_t           time_bits;
    int32_t           floor_bits;
    int32_t           res_bits;
    void*             internal; // this gets commented out in FMOD sources
};

struct vorbis_comment {
    char**   user_comments;
    int32_t* comment_lengths;
    int32_t  comments;
    char*    vendor;
};

struct ov_callbacks {
    uint32_t (*read_func)(void* ptr, size_t size, size_t nmemb, void* datasource);
    int32_t (*seek_func)(void* datasource, ogg_int64_t offset, int32_t whence);
    int32_t (*close_func)(void* datasource);
    int32_t (*tell_func)(void* datasource);
};

struct mdct_lookup {
    int32_t  n;
    int32_t  log2n;
    float*   trig;
    int32_t* bitrev;
    float    scale;
};

struct envelope_filter_state {
    float   ampbuf[17];
    int32_t ampptr;
    float   nearDC[15];
    float   nearDC_acc;
    float   nearDC_partialacc;
    int32_t nearptr;
};

struct envelope_band {
    int32_t begin;
    int32_t end;
    float*  window;
    float   total;
};

struct envelope_lookup {
    int32_t                ch;
    int32_t                winlength;
    int32_t                searchstep;
    float                  minenergy;
    mdct_lookup            mdct;
    float*                 mdct_win;
    envelope_band          band[7];
    envelope_filter_state* filter;
    int32_t                stretch;
    int32_t*               mark;
    int32_t                storage;
    int32_t                current;
    int32_t                curmark;
    int32_t                cursor;
};

struct vorbis_block_internal {
    float**         pcmdelay;
    float           ampmax;
    int32_t         blocktype;
    oggpack_buffer* packetblob[15];
};

struct vorbis_info_mode {
    int32_t blockflag;
    int32_t windowtype;
    int32_t transformtype;
    int32_t mapping;
};

struct vorbis_look_floor0 {
    int32_t             ln;
    int32_t             m;
    int32_t**           linearmap;
    int32_t             n[2];
    vorbis_info_floor0* vi;
    int32_t             bits;
    int32_t             frames;
};

struct vorbis_look_floor1 {
    int32_t             sorted_index[65];
    int32_t             forward_index[65];
    int32_t             reverse_index[65];
    int32_t             hineighbor[65];
    int32_t             loneighbor[65];
    int32_t             posts;
    int32_t             n;
    int32_t             quant_q;
    vorbis_info_floor1* vi;
    int32_t             phrasebits;
    int32_t             postbits;
    int32_t             frames;
};

struct lsfit_acc {
    int32_t x0;
    int32_t x1;
    int32_t xa;
    int32_t ya;
    int32_t x2a;
    int32_t y2a;
    int32_t xya;
    int32_t an;
};

struct vorbis_func_floor {
    void (*pack)(vorbis_info_floor*, oggpack_buffer*);
    vorbis_info_floor* (*unpack)(vorbis_info*, oggpack_buffer*);
    vorbis_look_floor* (*look)(vorbis_dsp_state*, vorbis_info_floor*);
    void (*free_info)(vorbis_info_floor*);
    void (*free_look)(vorbis_look_floor*);
    void* (*inverse1)(vorbis_block*, vorbis_look_floor*);
    int32_t (*inverse2)(vorbis_block*, vorbis_look_floor*, void* buffer, float*);
};

struct vorbis_info_floor0 {
    int32_t order;
    int32_t rate;
    int32_t barkmap;
    int32_t ampbits;
    int32_t ampdB;
    int32_t numbooks;
    int32_t books[16];
    float   lessthan;
    float   greaterthan;
};

struct vorbis_info_floor1 {
    int32_t partitions;
    int32_t partitionclass[31];
    int32_t class_dim[16];
    int32_t class_subs[16];
    int32_t class_book[16];
    int32_t class_subbook[16][8];
    int32_t mult;
    int32_t postlist[65];
    float   maxover;
    float   maxunder;
    float   maxerr;
    float   twofitweight;
    float   twofitatten;
    int32_t n;
};

struct vorbis_func_residue {
    void (*pack)(vorbis_info_residue*, oggpack_buffer*);
    vorbis_info_residue* (*unpack)(vorbis_info*, oggpack_buffer*);
    vorbis_look_residue* (*look)(vorbis_dsp_state*, vorbis_info_residue*);
    void (*free_info)(vorbis_info_residue*);
    void (*free_look)(vorbis_look_residue*);
    int32_t** (*class)(vorbis_block*, vorbis_look_residue*, float**, int32_t*, int32_t);
    int32_t (*forward)(
        oggpack_buffer*,
        vorbis_block*,
        vorbis_look_residue*,
        float**,
        float**,
        int32_t*,
        int32_t,
        int32_t**);
    int32_t (*inverse)(vorbis_block*, vorbis_look_residue*, float**, int32_t*, int32_t);
};

struct vorbis_info_residue0 {
    int32_t begin;
    int32_t end;
    int32_t grouping;
    int32_t partitions;
    int32_t groupbook;
    int32_t secondstages[64];
    int32_t booklist[256];
    float   classmetric1[64];
    float   classmetric2[64];
};

struct vorbis_look_residue0 {
    vorbis_info_residue0* info;
    int32_t               parts;
    int32_t               stages;
    codebook*             fullbooks;
    codebook*             phrasebook;
    codebook***           partbooks;
    int32_t               partvals;
    int32_t**             decodemap;
    int32_t               postbits;
    int32_t               phrasebits;
    int32_t               frames;
};

struct vorbis_func_mapping {
    void (*pack)(vorbis_info*, vorbis_info_mapping*, oggpack_buffer*);
    vorbis_info_mapping* (*unpack)(vorbis_info*, oggpack_buffer*);
    void (*free_info)(vorbis_info_mapping*);
    int32_t (*forward)(vorbis_block* vb);
    int32_t (*inverse)(vorbis_block* vb, vorbis_info_mapping*);
};

struct vorbis_info_mapping0 {
    int32_t submaps;
    int32_t chmuxlist[256];
    int32_t floorsubmap[16];
    int32_t residuesubmap[16];
    int32_t coupling_steps;
    int32_t coupling_mag[256];
    int32_t coupling_ang[256];
};

struct drft_lookup {
    int32_t  n;
    float*   trigcache;
    int32_t* splitcache;
};

struct vorbis_info_psy {
    int32_t blockflag;
    float   ath_adjatt;
    float   ath_maxatt;
    float   tone_masteratt[3];
    float   tone_centerboost;
    float   tone_decay;
    float   tone_abs_limit;
    float   toneatt[17];
    int32_t noisemaskp;
    float   noisemaxsupp;
    float   noisewindowlo;
    float   noisewindowhi;
    int32_t noisewindowlomin;
    int32_t noisewindowhimin;
    int32_t noisewindowfixed;
    float   noiseoff[3][17];
    float   noisecompand[40];
    float   max_curve_dB;
    int32_t normal_channel_p;
    int32_t normal_point_p;
    int32_t normal_start;
    int32_t normal_partition;
    double  normal_thresh;
};

struct vorbis_info_psy_global {
    int32_t eighth_octave_lines;
    float   preecho_thresh[7];
    float   postecho_thresh[7];
    float   stretch_penalty;
    float   preecho_minenergy;
    float   ampmax_att_per_sec;
    int32_t coupling_pkHz[15];
    int32_t coupling_pointlimit[2][15];
    int32_t coupling_prepointamp[15];
    int32_t coupling_postpointamp[15];
    int32_t sliding_lowpass[2][15];
};

struct vorbis_look_psy_global {
    float                   ampmax;
    int32_t                 channels;
    vorbis_info_psy_global* gi;
    int32_t                 coupling_pointlimit[2][3];
};

struct vorbis_look_psy {
    int32_t          n;
    vorbis_info_psy* vi;
    float***         tonecurves;
    float**          noiseoffset;
    float*           ath;
    int32_t*         octave;
    int32_t*         bark;
    int32_t          firstoc;
    int32_t          shiftoc;
    int32_t          eighth_octave_lines;
    int32_t          total_octave_lines;
    int32_t          rate;
    float            m_val;
};

struct bitrate_manager_state {
    int32_t managed;
    int32_t avg_reservoir;
    int32_t minmax_reservoir;
    int32_t avg_bitsper;
    int32_t min_bitsper;
    int32_t max_bitsper;
    int32_t short_per_long;
    // TODO: check this. float fuckery exists elsewhere, so this may explain the difference in the size of this struct
    // double        avgfloat;
    float         avgfloat;
    vorbis_block* vb;
    int32_t       choice;
};

struct bitrate_manager_info {
    int32_t avg_rate;
    int32_t min_rate;
    int32_t max_rate;
    int32_t reservoir_bits;
    double  reservoir_bias;
    double  slew_damp;
};

struct private_state {
    envelope_lookup*        ve; // 0x00 confirmed
    int32_t                 window[2];
    vorbis_look_transform** transform[2]; // 0x0C confirmed
    drft_lookup             fft_look[2];  // 0x14 confirmed
    int32_t                 modebits;
    vorbis_look_floor**     flr;        // 0x30 confirmed
    vorbis_look_residue**   residue;    // 0x34 confirmed
    vorbis_look_psy*        psy;        // 0x38 confirmed
    vorbis_look_psy_global* psy_g_look; // 0x3C confirmed
    uint8_t*                header;
    uint8_t*                header1;
    uint8_t*                header2;
    bitrate_manager_state   bms;
    ogg_int64_t             sample_count; // 0x78 confirmed
};

struct static_codebook {
    int32_t                  dim;
    int32_t                  entries;
    int32_t*                 lengthlist;
    int32_t                  maptype;
    int32_t                  q_min;
    int32_t                  q_delta;
    int32_t                  q_quant;
    int32_t                  q_sequencep;
    int32_t*                 quantlist;
    encode_aux_nearestmatch* nearest_tree;
    encode_aux_threshmatch*  thresh_tree;
    encode_aux_pigeonhole*   pigeon_tree;
    int32_t                  allocedp;
};

struct encode_aux_nearestmatch {
    int32_t* ptr0;
    int32_t* ptr1;
    int32_t* p;
    int32_t* q;
    int32_t  aux;
    int32_t  alloc;
};

struct encode_aux_threshmatch {
    float*   quantthresh;
    int32_t* quantmap;
    int32_t  quantvals;
    int32_t  threshvals;
};

struct encode_aux_pigeonhole {
    float    min;
    float    del;
    int32_t  mapentries;
    int32_t  quantvals;
    int32_t* pigeonmap;
    int32_t  fittotal;
    int32_t* fitlist;
    int32_t* fitmap;
    int32_t* fitlength;
};

struct codebook {
    int32_t                dim;
    int32_t                entries;
    int32_t                used_entries;
    const static_codebook* c;
    float*                 valuelist;
    ogg_uint32_t*          codelist;
    int32_t*               dec_index;
    char*                  dec_codelengths;
    ogg_uint32_t*          dec_firsttable;
    int32_t                dec_firsttablen;
    int32_t                dec_maxlength;
};

struct highlevel_byblocktype {
    double tone_mask_setting;
    double tone_peaklimit_setting;
    double noise_bias_setting;
    double noise_compand_setting;
};

struct highlevel_encode_setup {
    void*                 setup;
    int32_t               set_in_stone;
    double                base_setting;
    double                long_setting;
    double                short_setting;
    double                impulse_noisetune;
    int32_t               managed;
    int32_t               bitrate_min;
    int32_t               bitrate_av;
    double                bitrate_av_damp;
    int32_t               bitrate_max;
    int32_t               bitrate_reservoir;
    double                bitrate_reservoir_bias;
    int32_t               impulse_block_p;
    int32_t               noise_normalize_p;
    double                stereo_point_setting;
    double                lowpass_kHz;
    double                ath_floating_dB;
    double                ath_absolute_dB;
    double                amplitude_track_dBpersec;
    double                trigger_setting;
    highlevel_byblocktype block[4];
};

struct codec_setup_info {
    int32_t                blocksizes[2];
    int32_t                modes;
    int32_t                maps;
    int32_t                floors;
    int32_t                residues;
    int32_t                books;
    int32_t                psys;
    vorbis_info_mode*      mode_param[64];
    int32_t                map_type[64];
    vorbis_info_mapping*   map_param[64];
    int32_t                floor_type[64];
    vorbis_info_floor*     floor_param[64];
    int32_t                residue_type[64];
    vorbis_info_residue*   residue_param[64];
    static_codebook*       book_param[256];
    codebook*              fullbooks;
    vorbis_info_psy*       psy_param[4];
    vorbis_info_psy_global psy_g_param;
    bitrate_manager_info   bi;
    highlevel_encode_setup hi;
    int32_t                halfrate_flag;
};

// size = ???
struct OggVorbis_File {
    void*            datasource;
    int32_t          seekable;
    ogg_int64_t      offset;
    ogg_int64_t      end;
    ogg_sync_state   oy;
    int32_t          links;
    ogg_int64_t*     offsets;
    ogg_int64_t*     dataoffsets; // 0x3C confirmed
    int32_t*         serialnos;   // 0x40 confirmed
    ogg_int64_t*     pcmlengths;  // 0x44 confirmed
    vorbis_info*     vi;          // 0x48 confirmed
    vorbis_comment*  vc;          // 0x4C confirmed
    ogg_int64_t      pcm_offset;
    int32_t          ready_state; // 0x58 confirmed
    int32_t          current_serialno;
    int32_t          current_link;
    float            bittrack;  // 0x64 confirmed
    float            samptrack; // 0x68 confirmed
    ogg_stream_state os;        // 0x70 confirmed
    vorbis_dsp_state vd;
    vorbis_block     vb;
    ov_callbacks     callbacks; // 0x2B8 confirmed
};

#endif
