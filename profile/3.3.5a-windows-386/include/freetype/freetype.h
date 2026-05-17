#ifndef FREETYPE_FREETYPE_H
#define FREETYPE_FREETYPE_H

// struct declarations
DECLARE_STRUCT(AH_Edge);
DECLARE_STRUCT(AH_Face_Globals);
DECLARE_STRUCT(AH_Globals);
DECLARE_STRUCT(AH_Hinter);
DECLARE_STRUCT(AH_Outline);
DECLARE_STRUCT(AH_Point);
DECLARE_STRUCT(AH_Segment);
DECLARE_STRUCT(CFF_FD_Select);
DECLARE_STRUCT(CFF_Font);
DECLARE_STRUCT(CFF_Font_Dict);
DECLARE_STRUCT(CFF_Index);
DECLARE_STRUCT(CFF_Private);
DECLARE_STRUCT(CFF_SubFont);
DECLARE_STRUCT(CID_FaceRec);
DECLARE_STRUCT(CID_FontDict);
DECLARE_STRUCT(CID_GlyphSlotRec);
DECLARE_STRUCT(CID_Info);
DECLARE_STRUCT(CID_Loader);
DECLARE_STRUCT(CID_Parser);
DECLARE_STRUCT(CID_SizeRec);
DECLARE_STRUCT(CID_Subrs);
DECLARE_STRUCT(FT_AutoHinterRec);
DECLARE_STRUCT(FT_AutoHinter_Interface);
DECLARE_STRUCT(FT_BBox);
DECLARE_STRUCT(FT_Bitmap);
DECLARE_STRUCT(FT_Bitmap_Size);
DECLARE_STRUCT(FT_CharMapRec);
DECLARE_STRUCT(FT_DriverRec);
DECLARE_STRUCT(FT_Driver_Class);
DECLARE_STRUCT(FT_FaceRec);
DECLARE_STRUCT(FT_Face_InternalRec);
DECLARE_STRUCT(FT_Generic);
DECLARE_STRUCT(FT_GlyphLoad);
DECLARE_STRUCT(FT_GlyphLoader);
DECLARE_STRUCT(FT_GlyphRec);
DECLARE_STRUCT(FT_GlyphSlotRec);
DECLARE_STRUCT(FT_Glyph_Class);
DECLARE_STRUCT(FT_Glyph_Metrics);
DECLARE_STRUCT(FT_LibraryRec);
DECLARE_STRUCT(FT_ListNodeRec);
DECLARE_STRUCT(FT_ListRec);
DECLARE_STRUCT(FT_Matrix);
DECLARE_STRUCT(FT_MemoryRec);
DECLARE_STRUCT(FT_ModuleRec);
DECLARE_STRUCT(FT_Module_Class);
DECLARE_STRUCT(FT_Outline);
DECLARE_STRUCT(FT_Outline_Funcs);
DECLARE_STRUCT(FT_Parameter);
DECLARE_STRUCT(FT_Raster_Funcs);
DECLARE_STRUCT(FT_Raster_Params);
DECLARE_STRUCT(FT_RendererRec);
DECLARE_STRUCT(FT_Renderer_Class);
DECLARE_STRUCT(FT_SizeRec);
DECLARE_STRUCT(FT_Size_InternalRec);
DECLARE_STRUCT(FT_Size_Metrics);
DECLARE_STRUCT(FT_Slot_InternalRec);
DECLARE_STRUCT(FT_Span);
DECLARE_STRUCT(FT_StreamRec);
DECLARE_STRUCT(FT_SubGlyph);
DECLARE_STRUCT(FT_UnitVector);
DECLARE_STRUCT(FT_Vector);
DECLARE_STRUCT(PSNames_Interface);
DECLARE_STRUCT(PS_Table);
DECLARE_STRUCT(PS_Table_Funcs);
DECLARE_STRUCT(PS_UniMap);
DECLARE_STRUCT(PS_Unicodes);
DECLARE_STRUCT(SFNT_Header);
DECLARE_STRUCT(SFNT_Interface);
DECLARE_STRUCT(T1_Blend);
DECLARE_STRUCT(T1_Builder);
DECLARE_STRUCT(T1_Builder);
DECLARE_STRUCT(T1_Builder_Funcs);
DECLARE_STRUCT(T1_Decoder);
DECLARE_STRUCT(T1_Decoder_Funcs);
DECLARE_STRUCT(T1_Decoder_Zone);
DECLARE_STRUCT(T1_DesignMap);
DECLARE_STRUCT(T1_Encoding);
DECLARE_STRUCT(T1_FaceRec);
DECLARE_STRUCT(T1_Field);
DECLARE_STRUCT(T1_Font);
DECLARE_STRUCT(T1_FontInfo);
DECLARE_STRUCT(T1_Parser);
DECLARE_STRUCT(T1_Parser_Funcs);
DECLARE_STRUCT(T1_Private);
DECLARE_STRUCT(T1_Token);
DECLARE_STRUCT(T2_Builder);
DECLARE_STRUCT(T2_Decoder);
DECLARE_STRUCT(T2_Decoder_Zone);
DECLARE_STRUCT(T2_DriverRec);
DECLARE_STRUCT(T2_GlyphSlotRec);
DECLARE_STRUCT(T2_Parser);
DECLARE_STRUCT(TBand);
DECLARE_STRUCT(TPoint);
DECLARE_STRUCT(TProfile);
DECLARE_STRUCT(TRaster_Instance);
DECLARE_STRUCT(TTC_Header);
DECLARE_STRUCT(TT_CMap0);
DECLARE_STRUCT(TT_CMap2);
DECLARE_STRUCT(TT_CMap2SubHeader);
DECLARE_STRUCT(TT_CMap4);
DECLARE_STRUCT(TT_CMap4Segment);
DECLARE_STRUCT(TT_CMap6);
DECLARE_STRUCT(TT_CMapTable);
DECLARE_STRUCT(TT_CharMapRec);
DECLARE_STRUCT(TT_FaceRec);
DECLARE_STRUCT(TT_Gasp);
DECLARE_STRUCT(TT_GaspRange);
DECLARE_STRUCT(TT_GlyphZone);
DECLARE_STRUCT(TT_Hdmx);
DECLARE_STRUCT(TT_HdmxRec);
DECLARE_STRUCT(TT_Header);
DECLARE_STRUCT(TT_HoriHeader);
DECLARE_STRUCT(TT_Kern_0_Pair);
DECLARE_STRUCT(TT_Loader);
DECLARE_STRUCT(TT_MaxProfile);
DECLARE_STRUCT(TT_NameRec);
DECLARE_STRUCT(TT_NameTable);
DECLARE_STRUCT(TT_OS2);
DECLARE_STRUCT(TT_PCLT);
DECLARE_STRUCT(TT_Post_20);
DECLARE_STRUCT(TT_Post_25);
DECLARE_STRUCT(TT_Post_Names);
DECLARE_STRUCT(TT_Postscript);
DECLARE_STRUCT(TT_SBit_Line_Metrics);
DECLARE_STRUCT(TT_SBit_Metrics);
DECLARE_STRUCT(TT_SBit_Range);
DECLARE_STRUCT(TT_SBit_Scale);
DECLARE_STRUCT(TT_SBit_Strike);
DECLARE_STRUCT(TT_SizeRec);
DECLARE_STRUCT(TT_Size_Metrics);
DECLARE_STRUCT(TT_Table);
DECLARE_STRUCT(TT_VertHeader);

// union declarations
DECLARE_UNION(FT_StreamDesc);

// enum declarations
DECLARE_ENUM(FT_Encoding);
DECLARE_ENUM(FT_Frame_Op);
DECLARE_ENUM(FT_Glyph_Format);
DECLARE_ENUM(FT_Module_Flags);
DECLARE_ENUM(FT_Outline_Flags);
DECLARE_ENUM(FT_Palette_Mode);
DECLARE_ENUM(FT_Pixel_Mode);
DECLARE_ENUM(FT_Raster_Flag);
DECLARE_ENUM(T1_EncodingType);
DECLARE_ENUM(T1_Field_Location);
DECLARE_ENUM(T1_Field_Type);
DECLARE_ENUM(T1_Token_Type);
DECLARE_ENUM(T2_Operator);
DECLARE_ENUM(TStates);
DECLARE_ENUM(t2_kind); // not actually a named enum in source code

// integral types
typedef int16_t  FT_F2Dot14;
typedef int16_t  FT_FWord; /* distance in FUnits */
typedef int16_t  FT_Int16;
typedef int16_t  FT_Short;
typedef int32_t  FT_Error;
typedef int32_t  FT_F26Dot6;
typedef int32_t  FT_Fixed;
typedef int32_t  FT_Int32;
typedef int32_t  FT_Int;
typedef int32_t  FT_Long;
typedef int32_t  FT_Pos;
typedef int64_t  FT_Int64;
typedef int8_t   FT_Char;
typedef size_t   FT_Offset;
typedef size_t   FT_PtrDist;
typedef uint16_t FT_UFWord; /* unsigned distance */
typedef uint16_t FT_UShort;
typedef uint16_t FT_Uint16;
typedef uint32_t FT_UInt;
typedef uint32_t FT_ULong;
typedef uint32_t FT_Uint32;
typedef uint64_t FT_Uint64;
typedef uint8_t  FT_Bool;
typedef uint8_t  FT_Byte;
typedef uint8_t  FT_String;
typedef void*    FT_Pointer;

typedef FT_Int AH_Angle;
typedef FT_Int AH_Blue;
typedef FT_Int AH_Direction;
typedef FT_Int AH_Edge_Flags;
typedef FT_Int AH_Flags;
typedef FT_Int AH_Hinter_Flags;

// struct aliases
typedef CID_FaceRec*         CID_Face;
typedef CID_GlyphSlotRec*    CID_GlyphSlot;
typedef CID_SizeRec*         CID_Size;
typedef FT_AutoHinterRec*    FT_AutoHinter;
typedef FT_CharMapRec*       FT_CharMap;
typedef FT_DriverRec*        FT_Driver;
typedef FT_FaceRec*          FT_Face;
typedef FT_Face_InternalRec* FT_Face_Internal;
typedef FT_GlyphRec*         FT_Glyph;
typedef FT_GlyphSlotRec*     FT_GlyphSlot;
typedef FT_LibraryRec*       FT_Library;
typedef FT_ListNodeRec*      FT_ListNode;
typedef FT_ListRec*          FT_List;
typedef FT_MemoryRec*        FT_Memory;
typedef FT_ModuleRec*        FT_Module;
typedef FT_RendererRec*      FT_Renderer;
typedef FT_SizeRec*          FT_Size;
typedef FT_Size_InternalRec* FT_Size_Internal;
typedef FT_StreamRec*        FT_Stream;
typedef T1_FaceRec*          T1_Face;
typedef T2_DriverRec*        T2_Driver;
typedef T2_GlyphSlotRec*     T2_GlyphSlot;
typedef TT_CharMapRec*       TT_CharMap;
typedef TT_FaceRec*          TT_Face;
typedef TT_SizeRec*          TT_Size;

// typedef FT_RasterRec_*    FT_Raster;
typedef void*                TT_ExecContextRec;
typedef TT_ExecContextRec*   TT_ExecContext;
typedef void*                FT_Raster;
typedef FT_Slot_InternalRec* FT_Slot_Internal;
typedef TT_Face              T2_Face;
typedef FT_GlyphSlot         TT_GlyphSlot;
typedef FT_Size              T2_Size;

// callbacks
DECLARE_CALLBACK(void*, FT_Alloc_Func, FT_Memory memory, int32_t size);
DECLARE_CALLBACK(void, FT_Free_Func, FT_Memory memory, void* block);
DECLARE_CALLBACK(
    void*,
    FT_Realloc_Func,
    FT_Memory memory,
    int32_t   cur_size,
    int32_t   new_size,
    void*     block);

DECLARE_CALLBACK(
    uint32_t,
    FT_Stream_IO,
    FT_Stream stream,
    uint32_t  offset,
    uint8_t*  buffer,
    uint32_t  count);

DECLARE_CALLBACK(void, FT_Stream_Close, FT_Stream stream);

DECLARE_CALLBACK(int32_t, FT_Outline_MoveTo_Func, FT_Vector* to, void* user);
DECLARE_CALLBACK(int32_t, FT_Outline_LineTo_Func, FT_Vector* to, void* user);
DECLARE_CALLBACK(int32_t, FT_Outline_ConicTo_Func, FT_Vector* control, FT_Vector* to, void* user);
DECLARE_CALLBACK(
    int32_t,
    FT_Outline_CubicTo_Func,
    FT_Vector* control1,
    FT_Vector* control2,
    FT_Vector* to,
    void*      user);

DECLARE_CALLBACK(void, FT_Raster_Span_Func, int32_t y, int32_t count, FT_Span* spans, void* user);
DECLARE_CALLBACK(int32_t, FT_Raster_BitTest_Func, int32_t y, int32_t x, void* user);
DECLARE_CALLBACK(void, FT_Raster_BitSet_Func, int32_t y, int32_t x, void* user);
DECLARE_CALLBACK(int32_t, FT_Raster_New_Func, void* memory, FT_Raster* raster);
DECLARE_CALLBACK(void, FT_Raster_Done_Func, FT_Raster raster);
DECLARE_CALLBACK(
    void,
    FT_Raster_Reset_Func,
    FT_Raster raster,
    uint8_t*  pool_base,
    uint32_t  pool_size);
DECLARE_CALLBACK(int32_t, FT_Raster_Set_Mode_Func, FT_Raster raster, uint32_t mode, void* args);
DECLARE_CALLBACK(int32_t, FT_Raster_Render_Func, FT_Raster raster, FT_Raster_Params* params);

DECLARE_CALLBACK(void, FT_Generic_Finalizer, void* object);

DECLARE_CALLBACK(void, FT_Module_Interface);
DECLARE_CALLBACK(FT_Error, FT_Module_Constructor, FT_Module module);
DECLARE_CALLBACK(void, FT_Module_Destructor, FT_Module module);
DECLARE_CALLBACK(FT_Module_Interface, FT_Module_Requester, FT_Module module, const char* name);

DECLARE_CALLBACK(
    FT_Error,
    FTDriver_initFace,
    FT_Stream     stream,
    FT_Face       face,
    FT_Int        typeface_index,
    FT_Int        num_params,
    FT_Parameter* parameters);
DECLARE_CALLBACK(void, FTDriver_doneFace, FT_Face face);
DECLARE_CALLBACK(FT_Error, FTDriver_initSize, FT_Size size);
DECLARE_CALLBACK(void, FTDriver_doneSize, FT_Size size);
DECLARE_CALLBACK(FT_Error, FTDriver_initGlyphSlot, FT_GlyphSlot slot);
DECLARE_CALLBACK(void, FTDriver_doneGlyphSlot, FT_GlyphSlot slot);
DECLARE_CALLBACK(
    FT_Error,
    FTDriver_setCharSizes,
    FT_Size    size,
    FT_F26Dot6 char_width,
    FT_F26Dot6 char_height,
    FT_UInt    horz_resolution,
    FT_UInt    vert_resolution);
DECLARE_CALLBACK(
    FT_Error,
    FTDriver_setPixelSizes,
    FT_Size size,
    FT_UInt pixel_width,
    FT_UInt pixel_height);
DECLARE_CALLBACK(
    FT_Error,
    FTDriver_loadGlyph,
    FT_GlyphSlot slot,
    FT_Size      size,
    FT_UInt      glyph_index,
    FT_Int       load_flags);
DECLARE_CALLBACK(FT_UInt, FTDriver_getCharIndex, FT_CharMap charmap, FT_Long charcode);
DECLARE_CALLBACK(FT_Long, FTDriver_getNextChar, FT_CharMap charmap, FT_Long charcode);
DECLARE_CALLBACK(
    FT_Error,
    FTDriver_getKerning,
    FT_Face    face,
    FT_UInt    left_glyph,
    FT_UInt    right_glyph,
    FT_Vector* kerning);

DECLARE_CALLBACK(FT_Error, FTDriver_attachFile, FT_Face face, FT_Stream stream);
DECLARE_CALLBACK(
    FT_Error,
    FTDriver_getAdvances,
    FT_Face    face,
    FT_UInt    first,
    FT_UInt    count,
    FT_Bool    vertical,
    FT_UShort* advances);
DECLARE_CALLBACK(
    FT_Error,
    FTRenderer_render,
    FT_Renderer  renderer,
    FT_GlyphSlot slot,
    FT_UInt      mode,
    FT_Vector*   origin);
DECLARE_CALLBACK(
    FT_Error,
    FTRenderer_transform,
    FT_Renderer  renderer,
    FT_GlyphSlot slot,
    FT_Matrix*   matrix,
    FT_Vector*   delta);
DECLARE_CALLBACK(void, FTRenderer_getCBox, FT_Renderer renderer, FT_GlyphSlot slot, FT_BBox* cbox);
DECLARE_CALLBACK(
    FT_Error,
    FTRenderer_setMode,
    FT_Renderer renderer,
    FT_ULong    mode_tag,
    FT_Pointer  mode_ptr);

DECLARE_CALLBACK(FT_Error, FT_Glyph_Init_Func, FT_Glyph glyph, FT_GlyphSlot slot);
DECLARE_CALLBACK(void, FT_Glyph_Done_Func, FT_Glyph glyph);
DECLARE_CALLBACK(
    void,
    FT_Glyph_Transform_Func,
    FT_Glyph   glyph,
    FT_Matrix* matrix,
    FT_Vector* delta);
DECLARE_CALLBACK(void, FT_Glyph_BBox_Func, FT_Glyph glyph, FT_BBox* abbox);
DECLARE_CALLBACK(FT_Error, FT_Glyph_Copy_Func, FT_Glyph source, FT_Glyph target);
DECLARE_CALLBACK(FT_Error, FT_Glyph_Prepare_Func, FT_Glyph glyph, FT_GlyphSlot slot);

DECLARE_CALLBACK(void, FT_DebugHook_Func, void* arg);

DECLARE_CALLBACK(FT_Error, FT_List_Iterator, FT_ListNode node, void* user);
DECLARE_CALLBACK(FT_Error, FT_List_Iterate, FT_List list, FT_List_Iterator iterator, void* user);
DECLARE_CALLBACK(void, FT_List_Destructor, FT_Memory memory, void* data, void* user);
DECLARE_CALLBACK(
    void,
    FT_List_Finalize,
    FT_List            list,
    FT_List_Destructor destroy,
    FT_Memory          memory,
    void*              user);

DECLARE_CALLBACK(
    void,
    FT_AutoHinter_Get_Global_Func,
    FT_AutoHinter hinter,
    FT_Face       face,
    void**        global_hints,
    int32_t*      global_len);
DECLARE_CALLBACK(void, FT_AutoHinter_Done_Global_Func, FT_AutoHinter hinter, void* global);
DECLARE_CALLBACK(void, FT_AutoHinter_Reset_Func, FT_AutoHinter hinter, FT_Face face);
DECLARE_CALLBACK(
    FT_Error,
    FT_AutoHinter_Load_Func,
    FT_AutoHinter hinter,
    FT_GlyphSlot  slot,
    FT_Size       size,
    FT_UInt       glyph_index,
    FT_ULong      load_flags);

DECLARE_CALLBACK(void, T1_Field_Parser, FT_Face face, FT_Pointer parser);

DECLARE_CALLBACK(FT_Error, T1_Builder_Check_Points_Func, T1_Builder* builder, FT_Int count);
DECLARE_CALLBACK(
    void,
    T1_Builder_Add_Point_Func,
    T1_Builder* builder,
    FT_Pos      x,
    FT_Pos      y,
    FT_Byte     flag);
DECLARE_CALLBACK(FT_Error, T1_Builder_Add_Point1_Func, T1_Builder* builder, FT_Pos x, FT_Pos y);
DECLARE_CALLBACK(FT_Error, T1_Builder_Add_Contour_Func, T1_Builder* builder);
DECLARE_CALLBACK(FT_Error, T1_Builder_Start_Point_Func, T1_Builder* builder, FT_Pos x, FT_Pos y);
DECLARE_CALLBACK(void, T1_Builder_Close_Contour_Func, T1_Builder* builder);

DECLARE_CALLBACK(FT_Error, T1_Decoder_Callback, T1_Decoder* decoder, FT_UInt glyph_index);

DECLARE_CALLBACK(FT_ULong, PS_Unicode_Value_Func, const char* glyph_name);
DECLARE_CALLBACK(
    FT_UInt,
    PS_Unicode_Index_Func,
    FT_UInt      num_glyphs,
    const char** glyph_names,
    FT_ULong     unicode);
DECLARE_CALLBACK(const char*, PS_Macintosh_Name_Func, FT_UInt name_index);
DECLARE_CALLBACK(const char*, PS_Adobe_Std_Strings_Func, FT_UInt string_index);
typedef FT_Error (*PS_Build_Unicodes_Func)(
    FT_Memory    memory,
    FT_UInt      num_glyphs,
    const char** glyph_names,
    PS_Unicodes* unicodes);

DECLARE_CALLBACK(
    FT_Error,
    PS_Build_Unicodes_Func,
    FT_Memory    memory,
    FT_UInt      num_glyphs,
    const char** glyph_names,
    PS_Unicodes* unicodes);
DECLARE_CALLBACK(FT_UInt, PS_Lookup_Unicode_Func, PS_Unicodes* unicodes, FT_UInt unicode);

DECLARE_CALLBACK(FT_UInt, TT_CharMap_Func, TT_CMapTable* charmap, FT_ULong char_code);

DECLARE_CALLBACK(
    FT_Error,
    TT_Goto_Table_Func,
    TT_Face   face,
    FT_ULong  tag,
    FT_Stream stream,
    FT_ULong* length);

DECLARE_CALLBACK(
    FT_Error,
    TT_Access_Glyph_Frame_Func,
    TT_Loader* loader,
    FT_UInt    glyph_index,
    FT_ULong   offset,
    FT_UInt    byte_count);

DECLARE_CALLBACK(FT_Error, TT_Load_Glyph_Element_Func, TT_Loader* loader);

DECLARE_CALLBACK(void, TT_Forget_Glyph_Frame_Func, TT_Loader* loader);

DECLARE_CALLBACK(FT_Error, TT_Interpreter, void* exec_context);

DECLARE_CALLBACK(
    FT_Error,
    TT_Init_Face_Func,
    FT_Stream     stream,
    TT_Face       face,
    FT_Int        face_index,
    FT_Int        num_params,
    FT_Parameter* params);
DECLARE_CALLBACK(
    FT_Error,
    TT_Load_Face_Func,
    FT_Stream     stream,
    TT_Face       face,
    FT_Int        face_index,
    FT_Int        num_params,
    FT_Parameter* params);

DECLARE_CALLBACK(void, TT_Done_Face_Func, TT_Face);

DECLARE_CALLBACK(
    FT_Module_Interface,
    SFNT_Get_Interface_Func,
    FT_Module   module,
    const char* interface);

DECLARE_CALLBACK(
    FT_Error,
    TT_Load_Any_Func,
    TT_Face   face,
    FT_ULong  tag,
    FT_Long   offset,
    FT_Byte*  buffer,
    FT_ULong* length);

DECLARE_CALLBACK(
    FT_Error,
    TT_Load_SFNT_Header_Func,
    TT_Face      face,
    FT_Stream    stream,
    FT_Long      face_index,
    SFNT_Header* sfnt);

DECLARE_CALLBACK(
    FT_Error,
    TT_Load_Directory_Func,
    TT_Face      face,
    FT_Stream    stream,
    SFNT_Header* sfnt);

DECLARE_CALLBACK(FT_Error, TT_Load_Table_Func, TT_Face face, FT_Stream stream);

DECLARE_CALLBACK(FT_Error, TT_Load_Metrics_Func, TT_Face face, FT_Stream stream, FT_Bool vertical);

DECLARE_CALLBACK(void, TT_Free_Table_Func, TT_Face face);

DECLARE_CALLBACK(
    FT_Error,
    TT_Set_SBit_Strike_Func,
    TT_Face   face,
    FT_Int    x_ppem,
    FT_Int    y_ppem,
    FT_ULong* astrike_index);

DECLARE_CALLBACK(
    FT_Error,
    TT_Load_SBit_Image_Func,
    TT_Face          face,
    FT_ULong         strike_index,
    FT_UInt          glyph_index,
    FT_UInt          load_flags,
    FT_Stream        stream,
    FT_Bitmap*       amap,
    TT_SBit_Metrics* ametrics);

DECLARE_CALLBACK(FT_Error, TT_Get_PS_Name_Func, TT_Face face, FT_UInt index, FT_String** PSname);

DECLARE_CALLBACK(FT_Error, TT_CharMap_Load_Func, TT_Face face, TT_CMapTable* cmap, FT_Stream input);

DECLARE_CALLBACK(FT_Error, TT_CharMap_Free_Func, TT_Face face, TT_CMapTable* cmap);

DECLARE_CALLBACK(void, Function_Sweep_Init, TRaster_Instance* raster, int16_t* min, int16_t* max);
DECLARE_CALLBACK(
    void,
    Function_Sweep_Span,
    TRaster_Instance* raster,
    int16_t           y,
    FT_F26Dot6        x1,
    FT_F26Dot6        x2,
    TProfile*         left,
    TProfile*         right);
DECLARE_CALLBACK(void, Function_Sweep_Step, TRaster_Instance* raster);

DECLARE_CALLBACK(void, TSplitter, TPoint* base);

// enums

enum FT_Pixel_Mode {
    ft_pixel_mode_none = 0,
    ft_pixel_mode_mono,
    ft_pixel_mode_grays,
    ft_pixel_mode_pal2,
    ft_pixel_mode_pal4,
    ft_pixel_mode_pal8,
    ft_pixel_mode_rgb15,
    ft_pixel_mode_rgb16,
    ft_pixel_mode_rgb24,
    ft_pixel_mode_rgb32,

    ft_pixel_mode_max /* do not remove */
};

enum FT_Palette_Mode {
    ft_palette_mode_rgb = 0,
    ft_palette_mode_rgba,

    ft_palettte_mode_max /* do not remove */
};

enum FT_Outline_Flags {
    ft_outline_none            = 0,
    ft_outline_owner           = 1,
    ft_outline_even_odd_fill   = 2,
    ft_outline_reverse_fill    = 4,
    ft_outline_ignore_dropouts = 8,
    ft_outline_high_precision  = 256,
    ft_outline_single_pass     = 512
};

enum FT_Glyph_Format {
    ft_glyph_format_none      = 0,
    ft_glyph_format_composite = 0x636F6D70,
    ft_glyph_format_bitmap    = 0x62697473,
    ft_glyph_format_outline   = 0x6F75746C,
    ft_glyph_format_plotter   = 0x706C6F74
};

enum FT_Raster_Flag {
    ft_raster_flag_default = 0,
    ft_raster_flag_aa      = 1,
    ft_raster_flag_direct  = 2,
    ft_raster_flag_clip    = 4
};

enum FT_Module_Flags {
    ft_module_font_driver = 1, /* this module is a font driver  */
    ft_module_renderer    = 2, /* this module is a renderer     */
    ft_module_hinter      = 4, /* this module is a glyph hinter */
    ft_module_styler      = 8, /* this module is a styler       */

    ft_module_driver_scalable = 0x100,    /* the driver supports scalable  */
                                          /* fonts                         */
    ft_module_driver_no_outlines = 0x200, /* the driver does not support   */
                                          /* vector outlines               */
    ft_module_driver_has_hinter = 0x400   /* the driver provides its own   */
                                          /* hinter                        */
};

enum FT_Encoding {
    ft_encoding_none           = 0x00000000,
    ft_encoding_symbol         = 0x73796D62,
    ft_encoding_unicode        = 0x756E6963,
    ft_encoding_latin_2        = 0x6C617432,
    ft_encoding_sjis           = 0x736A6973,
    ft_encoding_gb2312         = 0x67622020,
    ft_encoding_big5           = 0x62696735,
    ft_encoding_wansung        = 0x77616E73,
    ft_encoding_johab          = 0x6A6F6861,
    ft_encoding_adobe_standard = 0x41444F42,
    ft_encoding_adobe_expert   = 0x41444245,
    ft_encoding_adobe_custom   = 0x41444243,
    ft_encoding_apple_roman    = 0x61726D6E
};

enum T1_Field_Location {
    t1_field_cid_info,
    t1_field_font_dict,
    t1_field_font_info,
    t1_field_private,

    /* do not remove */
    t1_field_location_max
};

enum T1_Field_Type {
    t1_field_none = 0,
    t1_field_bool,
    t1_field_integer,
    t1_field_fixed,
    t1_field_string,
    t1_field_integer_array,
    t1_field_fixed_array,
    t1_field_callback,

    /* do not remove */
    t1_field_max
};

enum T1_Token_Type {
    t1_token_none = 0,
    t1_token_any,
    t1_token_string,
    t1_token_array,

    /* do not remove */
    t1_token_max
};

enum FT_Frame_Op {
    ft_frame_end       = 0x00,
    ft_frame_start     = 0x04,
    ft_frame_byte      = 0x08,
    ft_frame_schar     = 0x09,
    ft_frame_ushort_be = 0x0C,
    ft_frame_short_be  = 0x0D,
    ft_frame_ushort_le = 0x0E,
    ft_frame_short_le  = 0x0F,
    ft_frame_ulong_be  = 0x10,
    ft_frame_ulong_le  = 0x11,
    ft_frame_long_be   = 0x12,
    ft_frame_long_le   = 0x13,
    ft_frame_uoff3_be  = 0x14,
    ft_frame_uoff3_le  = 0x15,
    ft_frame_off3_be   = 0x16,
    ft_frame_off3_le   = 0x17,
    ft_frame_bytes     = 0x18,
    ft_frame_skip      = 0x19
};

enum t2_kind {
    t2_kind_none = 0,
    t2_kind_num,
    t2_kind_fixed,
    t2_kind_string,
    t2_kind_bool,
    t2_kind_delta,
    t2_kind_callback,

    t2_kind_max /* do not remove */
};

enum T2_Operator {
    t2_op_unknown = 0,

    t2_op_rmoveto,
    t2_op_hmoveto,
    t2_op_vmoveto,

    t2_op_rlineto,
    t2_op_hlineto,
    t2_op_vlineto,

    t2_op_rrcurveto,
    t2_op_hhcurveto,
    t2_op_hvcurveto,
    t2_op_rcurveline,
    t2_op_rlinecurve,
    t2_op_vhcurveto,
    t2_op_vvcurveto,

    t2_op_flex,
    t2_op_hflex,
    t2_op_hflex1,
    t2_op_flex1,

    t2_op_endchar,

    t2_op_hstem,
    t2_op_vstem,
    t2_op_hstemhm,
    t2_op_vstemhm,

    t2_op_hintmask,
    t2_op_cntrmask,

    t2_op_abs,
    t2_op_add,
    t2_op_sub,
    t2_op_div,
    t2_op_neg,
    t2_op_random,
    t2_op_mul,
    t2_op_sqrt,

    t2_op_blend,

    t2_op_drop,
    t2_op_exch,
    t2_op_index,
    t2_op_roll,
    t2_op_dup,

    t2_op_put,
    t2_op_get,
    t2_op_store,
    t2_op_load,

    t2_op_and,
    t2_op_or,
    t2_op_not,
    t2_op_eq,
    t2_op_ifelse,

    t2_op_callsubr,
    t2_op_callgsubr,
    t2_op_return,

    /* do not remove */
    t2_op_max
};

enum T1_EncodingType {
    t1_encoding_none = 0,
    t1_encoding_array,
    t1_encoding_standard,
    t1_encoding_expert
};

enum TStates {
    Unknown,
    Ascending,
    Descending,
    Flat
};

// base
struct FT_MemoryRec {
    void*           user;
    FT_Alloc_Func   alloc;
    FT_Free_Func    free;
    FT_Realloc_Func realloc;
};

union FT_StreamDesc {
    int32_t value;
    void*   pointer;
};

struct FT_StreamRec {
    uint8_t* base;
    uint32_t size;
    uint32_t pos;

    FT_StreamDesc   descriptor;
    FT_StreamDesc   pathname;
    FT_Stream_IO    read;
    FT_Stream_Close close;

    FT_Memory memory;
    uint8_t*  cursor;
    uint8_t*  limit;
};

// types

struct FT_UnitVector {
    FT_F2Dot14 x;
    FT_F2Dot14 y;
};

// image

struct FT_BBox {
    FT_Pos xMin, yMin;
    FT_Pos xMax, yMax;
};

struct FT_Vector {
    FT_Pos x;
    FT_Pos y;
};

struct FT_Bitmap {
    int32_t  rows;
    int32_t  width;
    int32_t  pitch;
    uint8_t* buffer;
    int16_t  num_grays;
    uint8_t  pixel_mode;
    uint8_t  palette_mode;
    void*    palette;
};

struct FT_Outline {
    int16_t    n_contours; /* number of contours in glyph        */
    int16_t    n_points;   /* number of points in the glyph      */
    FT_Vector* points;     /* the outline's points               */
    uint8_t*   tags;       /* the points flags                   */
    uint16_t*  contours;   /* the contour end points             */
    int32_t    flags;      /* outline masks                      */
};

struct FT_Outline_Funcs {
    FT_Outline_MoveTo_Func  move_to;
    FT_Outline_LineTo_Func  line_to;
    FT_Outline_ConicTo_Func conic_to;
    FT_Outline_CubicTo_Func cubic_to;
    int32_t                 shift;
    FT_Pos                  delta;
};

struct FT_Span {
    int16_t  x;
    uint16_t len;
    uint8_t  coverage;
};

struct FT_Raster_Params {
    FT_Bitmap*             target;
    void*                  source;
    int32_t                flags;
    FT_Raster_Span_Func    gray_spans;
    FT_Raster_Span_Func    black_spans;
    FT_Raster_BitTest_Func bit_test;
    FT_Raster_BitSet_Func  bit_set;
    void*                  user;
    FT_BBox                clip_box;
};

struct FT_Raster_Funcs {
    FT_Glyph_Format         glyph_format;
    FT_Raster_New_Func      raster_new;
    FT_Raster_Reset_Func    raster_reset;
    FT_Raster_Set_Mode_Func raster_set_mode;
    FT_Raster_Render_Func   raster_render;
    FT_Raster_Done_Func     raster_done;
};

struct FT_Matrix {
    FT_Fixed xx, xy;
    FT_Fixed yx, yy;
};

struct FT_Generic {
    void*                data;
    FT_Generic_Finalizer finalizer;
};

struct FT_ListNodeRec {
    FT_ListNode prev;
    FT_ListNode next;
    void*       data;
};

struct FT_ListRec {
    FT_ListNode head;
    FT_ListNode tail;
};

// module

struct FT_ModuleRec {
    FT_Module_Class* clazz;
    FT_Library       library;
    FT_Memory        memory;
    FT_Generic       generic;
};

// objects

struct FT_Face_InternalRec {
    FT_UShort max_points;
    FT_Short  max_contours;

    FT_Matrix transform_matrix;
    FT_Vector transform_delta;
    FT_Int    transform_flags;

    const char* postscript_name;
};

struct FT_Slot_InternalRec {
    FT_GlyphLoader* loader;
    FT_Bool         glyph_transformed;
    FT_Matrix       glyph_matrix;
    FT_Vector       glyph_delta;
    void*           glyph_hints;
};
typedef FT_Slot_InternalRec FT_GlyphSlot_InternalRec;

struct FT_CharMapRec {
    FT_Face     face;
    FT_Encoding encoding;
    FT_UShort   platform_id;
    FT_UShort   encoding_id;
};

struct FT_Bitmap_Size {
    FT_Short height;
    FT_Short width;
};

struct FT_FaceRec {
    FT_Long          num_faces;
    FT_Long          face_index;
    FT_Long          face_flags;
    FT_Long          style_flags;
    FT_Long          num_glyphs;
    FT_String*       family_name;
    FT_String*       style_name;
    FT_Int           num_fixed_sizes;
    FT_Bitmap_Size*  available_sizes;
    FT_Int           num_charmaps;
    FT_CharMap*      charmaps;
    FT_Generic       generic;
    FT_BBox          bbox;
    FT_UShort        units_per_EM;
    FT_Short         ascender;
    FT_Short         descender;
    FT_Short         height;
    FT_Short         max_advance_width;
    FT_Short         max_advance_height;
    FT_Short         underline_position;
    FT_Short         underline_thickness;
    FT_GlyphSlot     glyph;
    FT_Size          size;
    FT_CharMap       charmap;
    FT_Driver        driver;
    FT_Memory        memory;
    FT_Stream        stream;
    FT_ListRec       sizes_list;
    FT_Generic       autohint;
    void*            extensions;
    FT_Face_Internal internal;
};

struct FT_Size_Metrics {
    FT_UShort x_ppem;      /* horizontal pixels per EM               */
    FT_UShort y_ppem;      /* vertical pixels per EM                 */
    FT_Fixed  x_scale;     /* two scales used to convert font units  */
    FT_Fixed  y_scale;     /* to 26.6 frac. pixel coordinates..      */
    FT_Pos    ascender;    /* ascender in 26.6 frac. pixels          */
    FT_Pos    descender;   /* descender in 26.6 frac. pixels         */
    FT_Pos    height;      /* text height in 26.6 frac. pixels       */
    FT_Pos    max_advance; /* max horizontal advance, in 26.6 pixels */
};

struct FT_SizeRec {
    FT_Face          face;    /* parent face object              */
    FT_Generic       generic; /* generic pointer for client uses */
    FT_Size_Metrics  metrics; /* size metrics                    */
    FT_Size_Internal internal;
};

struct FT_Glyph_Metrics {
    FT_Pos width;        /* glyph width  */
    FT_Pos height;       /* glyph height */
    FT_Pos horiBearingX; /* left side bearing in horizontal layouts */
    FT_Pos horiBearingY; /* top side bearing in horizontal layouts  */
    FT_Pos horiAdvance;  /* advance width for horizontal layout     */
    FT_Pos vertBearingX; /* left side bearing in vertical layouts */
    FT_Pos vertBearingY; /* top side bearing in vertical layouts  */
    FT_Pos vertAdvance;  /* advance height for vertical layout    */
};

struct FT_SubGlyph {
    FT_Int    index;
    FT_UShort flags;
    FT_Int    arg1;
    FT_Int    arg2;
    FT_Matrix transform;
};

struct FT_GlyphSlotRec {
    FT_Library       library;
    FT_Face          face;
    FT_GlyphSlot     next;
    FT_UInt          flags;
    FT_Generic       generic;
    FT_Glyph_Metrics metrics;
    FT_Fixed         linearHoriAdvance;
    FT_Fixed         linearVertAdvance;
    FT_Vector        advance;
    FT_Glyph_Format  format;
    FT_Bitmap        bitmap;
    FT_Int           bitmap_left;
    FT_Int           bitmap_top;
    FT_Outline       outline;
    FT_UInt          num_subglyphs;
    FT_SubGlyph*     subglyphs;
    void*            control_data;
    int32_t          control_len;
    void*            other;
    FT_Slot_Internal internal;
};

struct FT_GlyphLoad {
    FT_Outline   outline;       /* outline             */
    FT_UInt      num_subglyphs; /* number of subglyphs */
    FT_SubGlyph* subglyphs;     /* subglyphs           */
    FT_Vector*   extra_points;  /* extra points table  */
};

struct FT_GlyphLoader {
    FT_Memory    memory;
    FT_UInt      max_points;
    FT_UInt      max_contours;
    FT_UInt      max_subglyphs;
    FT_Bool      use_extra;
    FT_GlyphLoad base;
    FT_GlyphLoad current;
    void*        other; /* for possible future extension? */
};

struct FT_Parameter {
    FT_ULong   tag;
    FT_Pointer data;
};

struct FT_Module_Class {
    FT_ULong              module_flags;
    FT_Int                module_size;
    const FT_String*      module_name;
    FT_Fixed              module_version;
    FT_Fixed              module_requires;
    const void*           module_interface;
    FT_Module_Constructor module_init;
    FT_Module_Destructor  module_done;
    FT_Module_Requester   get_interface;
};

struct FT_Driver_Class {
    FT_Module_Class        root;
    FT_Int                 face_object_size;
    FT_Int                 size_object_size;
    FT_Int                 slot_object_size;
    FTDriver_initFace      init_face;
    FTDriver_doneFace      done_face;
    FTDriver_initSize      init_size;
    FTDriver_doneSize      done_size;
    FTDriver_initGlyphSlot init_slot;
    FTDriver_doneGlyphSlot done_slot;
    FTDriver_setCharSizes  set_char_sizes;
    FTDriver_setPixelSizes set_pixel_sizes;
    FTDriver_loadGlyph     load_glyph;
    FTDriver_getCharIndex  get_char_index;
    FTDriver_getKerning    get_kerning;
    FTDriver_attachFile    attach_file;
    FTDriver_getAdvances   get_advances;
};

struct FT_DriverRec {
    FT_ModuleRec     root;
    FT_Driver_Class* clazz;
    FT_ListRec       faces_list;
    void*            extensions;
    FT_GlyphLoader*  glyph_loader;
};

struct FT_Renderer_Class {
    FT_Module_Class      root;
    FT_Glyph_Format      glyph_format;
    FTRenderer_render    render_glyph;
    FTRenderer_transform transform_glyph;
    FTRenderer_getCBox   get_glyph_cbox;
    FTRenderer_setMode   set_mode;
    FT_Raster_Funcs*     raster_class;
};

struct FT_GlyphRec {
    FT_Library            library;
    const FT_Glyph_Class* clazz;
    FT_Glyph_Format       format;
    FT_Vector             advance;
};

struct FT_Glyph_Class {
    FT_UInt                 glyph_size;
    FT_Glyph_Format         glyph_format;
    FT_Glyph_Init_Func      glyph_init;
    FT_Glyph_Done_Func      glyph_done;
    FT_Glyph_Copy_Func      glyph_copy;
    FT_Glyph_Transform_Func glyph_transform;
    FT_Glyph_BBox_Func      glyph_bbox;
    FT_Glyph_Prepare_Func   glyph_prepare;
};

struct FT_RendererRec {
    FT_ModuleRec          root;
    FT_Renderer_Class*    clazz;
    FT_Glyph_Format       glyph_format;
    FT_Glyph_Class        glyph_class;
    FT_Raster             raster;
    FT_Raster_Render_Func raster_render;
    FTRenderer_render     render;
};

struct FT_LibraryRec {
    FT_Memory   memory; /* library's memory manager */
    FT_Generic  generic;
    FT_UInt     num_modules;
    FT_Module   modules[16];  /* module objects  */
    FT_ListRec  renderers;    /* list of renderers        */
    FT_Renderer cur_renderer; /* current outline renderer */
    FT_Module   auto_hinter;
    FT_Byte*    raster_pool;            /* scan-line conversion */
                                        /* render pool          */
    FT_ULong          raster_pool_size; /* size of render pool in bytes */
    FT_DebugHook_Func debug_hooks[4];
};

struct FT_AutoHinter_Interface {
    FT_AutoHinter_Reset_Func       reset_face;
    FT_AutoHinter_Load_Func        load_glyph;
    FT_AutoHinter_Get_Global_Func  get_global_hints;
    FT_AutoHinter_Done_Global_Func done_global_hints;
};

struct AH_Point {
    AH_Flags     flags; /* point flags used by hinter */
    FT_Pos       ox, oy;
    FT_Pos       fx, fy;
    FT_Pos       x, y;
    FT_Pos       u, v;
    AH_Direction in_dir;  /* direction of inwards vector  */
    AH_Direction out_dir; /* direction of outwards vector */
    AH_Angle     in_angle;
    AH_Angle     out_angle;
    AH_Point*    next; /* next point in contour     */
    AH_Point*    prev; /* previous point in contour */
};

struct AH_Segment {
    AH_Edge_Flags flags;
    AH_Direction  dir;
    AH_Point*     first;     /* first point in edge segment             */
    AH_Point*     last;      /* last point in edge segment              */
    AH_Point**    contour;   /* ptr to first point of segment's contour */
    FT_Pos        pos;       /* position of segment           */
    FT_Pos        min_coord; /* minimum coordinate of segment */
    FT_Pos        max_coord; /* maximum coordinate of segment */
    AH_Edge*      edge;
    AH_Segment*   edge_next;
    AH_Segment*   link;       /* link segment               */
    AH_Segment*   serif;      /* primary segment for serifs */
    FT_Pos        num_linked; /* number of linked segments  */
    FT_Int        score;
};

struct AH_Edge {
    AH_Edge_Flags flags;
    AH_Direction  dir;
    AH_Segment*   first;
    AH_Segment*   last;
    FT_Pos        fpos;
    FT_Pos        opos;
    FT_Pos        pos;
    AH_Edge*      link;
    AH_Edge*      serif;
    FT_Int        num_linked;
    FT_Int        score;
    FT_Pos*       blue_edge;
};

struct AH_Outline {
    FT_Memory    memory;
    AH_Direction vert_major_dir; /* vertical major direction   */
    AH_Direction horz_major_dir; /* horizontal major direction */
    FT_Fixed     x_scale;
    FT_Fixed     y_scale;
    FT_Pos       edge_distance_threshold;
    FT_Int       max_points;
    FT_Int       num_points;
    AH_Point*    points;
    FT_Int       max_contours;
    FT_Int       num_contours;
    AH_Point**   contours;
    FT_Int       num_hedges;
    AH_Edge*     horz_edges;
    FT_Int       num_vedges;
    AH_Edge*     vert_edges;
    FT_Int       num_hsegments;
    AH_Segment*  horz_segments;
    FT_Int       num_vsegments;
    AH_Segment*  vert_segments;
};

struct AH_Globals {
    FT_Int num_widths;
    FT_Int num_heights;
    FT_Pos widths[12];
    FT_Pos heights[12];
    FT_Pos blue_refs[5];
    FT_Pos blue_shoots[5];
};

struct AH_Face_Globals {
    FT_Face    face;
    AH_Globals design;
    AH_Globals scaled;
    FT_Fixed   x_scale;
    FT_Fixed   y_scale;
    FT_Bool    control_overshoot;
};

struct AH_Hinter {
    FT_Memory        memory;
    AH_Hinter_Flags  flags;
    FT_Int           algorithm;
    FT_Face          face;
    AH_Face_Globals* globals;
    AH_Outline*      glyph;
    FT_GlyphLoader*  loader;
    FT_Vector        pp1;
    FT_Vector        pp2;
};

struct FT_AutoHinterRec {
    FT_ModuleRec root;
    AH_Hinter*   hinter;
};

struct TT_Table {
    FT_ULong Tag;      /*        table type */
    FT_ULong CheckSum; /*    table checksum */
    FT_ULong Offset;   /* table file offset */
    FT_ULong Length;   /*      table length */
};

struct TT_Header {
    FT_Fixed Table_Version;
    FT_Fixed Font_Revision;

    FT_Long CheckSum_Adjust;
    FT_Long Magic_Number;

    FT_UShort Flags;
    FT_UShort Units_Per_EM;

    FT_Long Created[2];
    FT_Long Modified[2];

    FT_Short xMin;
    FT_Short yMin;
    FT_Short xMax;
    FT_Short yMax;

    FT_UShort Mac_Style;
    FT_UShort Lowest_Rec_PPEM;

    FT_Short Font_Direction;
    FT_Short Index_To_Loc_Format;
    FT_Short Glyph_Data_Format;
};

struct TT_HoriHeader {
    FT_Fixed Version;
    FT_Short Ascender;
    FT_Short Descender;
    FT_Short Line_Gap;

    FT_UShort advance_Width_Max; /* advance width maximum */

    FT_Short min_Left_Side_Bearing;  /* minimum left-sb       */
    FT_Short min_Right_Side_Bearing; /* minimum right-sb      */
    FT_Short xMax_Extent;            /* xmax extents          */
    FT_Short caret_Slope_Rise;
    FT_Short caret_Slope_Run;
    FT_Short caret_Offset;

    FT_Short Reserved[4];

    FT_Short  metric_Data_Format;
    FT_UShort number_Of_HMetrics;

    /* The following fields are not defined by the TrueType specification */
    /* but they're used to connect the metrics header to the relevant     */
    /* `HMTX' table.                                                      */

    void* long_metrics;
    void* short_metrics;
};

struct TTC_Header {
    FT_ULong  tag;
    FT_Fixed  version;
    FT_Long   count;
    FT_ULong* offsets;
};

struct TT_MaxProfile {
    FT_Fixed  version;
    FT_UShort numGlyphs;
    FT_UShort maxPoints;
    FT_UShort maxContours;
    FT_UShort maxCompositePoints;
    FT_UShort maxCompositeContours;
    FT_UShort maxZones;
    FT_UShort maxTwilightPoints;
    FT_UShort maxStorage;
    FT_UShort maxFunctionDefs;
    FT_UShort maxInstructionDefs;
    FT_UShort maxStackElements;
    FT_UShort maxSizeOfInstructions;
    FT_UShort maxComponentElements;
    FT_UShort maxComponentDepth;
};

struct TT_VertHeader {
    FT_Fixed Version;
    FT_Short Ascender;
    FT_Short Descender;
    FT_Short Line_Gap;

    FT_UShort advance_Height_Max; /* advance height maximum */

    FT_Short min_Top_Side_Bearing;    /* minimum left-sb or top-sb       */
    FT_Short min_Bottom_Side_Bearing; /* minimum right-sb or bottom-sb   */
    FT_Short yMax_Extent;             /* xmax or ymax extents            */
    FT_Short caret_Slope_Rise;
    FT_Short caret_Slope_Run;
    FT_Short caret_Offset;

    FT_Short Reserved[4];

    FT_Short  metric_Data_Format;
    FT_UShort number_Of_VMetrics;

    /* The following fields are not defined by the TrueType specification */
    /* but they're used to connect the metrics header to the relevant     */
    /* `HMTX' or `VMTX' table.                                            */

    void* long_metrics;
    void* short_metrics;
};

struct TT_NameRec {
    FT_UShort platformID;
    FT_UShort encodingID;
    FT_UShort languageID;
    FT_UShort nameID;
    FT_UShort stringLength;
    FT_UShort stringOffset;

    /* this last field is not defined in the spec */
    /* but used by the FreeType engine            */

    FT_Byte* string;
};

struct TT_NameTable {
    FT_UShort   format;
    FT_UShort   numNameRecords;
    FT_UShort   storageOffset;
    TT_NameRec* names;
    FT_Byte*    storage;
};

struct TT_OS2 {
    FT_UShort version; /* 0x0001 - more or 0xFFFF */
    FT_Short  xAvgCharWidth;
    FT_UShort usWeightClass;
    FT_UShort usWidthClass;
    FT_Short  fsType;
    FT_Short  ySubscriptXSize;
    FT_Short  ySubscriptYSize;
    FT_Short  ySubscriptXOffset;
    FT_Short  ySubscriptYOffset;
    FT_Short  ySuperscriptXSize;
    FT_Short  ySuperscriptYSize;
    FT_Short  ySuperscriptXOffset;
    FT_Short  ySuperscriptYOffset;
    FT_Short  yStrikeoutSize;
    FT_Short  yStrikeoutPosition;
    FT_Short  sFamilyClass;

    FT_Byte panose[10];

    FT_ULong ulUnicodeRange1; /* Bits 0-31   */
    FT_ULong ulUnicodeRange2; /* Bits 32-63  */
    FT_ULong ulUnicodeRange3; /* Bits 64-95  */
    FT_ULong ulUnicodeRange4; /* Bits 96-127 */

    FT_Char achVendID[4];

    FT_UShort fsSelection;
    FT_UShort usFirstCharIndex;
    FT_UShort usLastCharIndex;
    FT_Short  sTypoAscender;
    FT_Short  sTypoDescender;
    FT_Short  sTypoLineGap;
    FT_UShort usWinAscent;
    FT_UShort usWinDescent;

    /* only version 1 tables: */

    FT_ULong ulCodePageRange1; /* Bits 0-31   */
    FT_ULong ulCodePageRange2; /* Bits 32-63  */

    /* only version 2 tables: */

    FT_Short  sxHeight;
    FT_Short  sCapHeight;
    FT_UShort usDefaultChar;
    FT_UShort usBreakChar;
    FT_UShort usMaxContext;
};

struct TT_Postscript {
    FT_Fixed FormatType;
    FT_Fixed italicAngle;
    FT_Short underlinePosition;
    FT_Short underlineThickness;
    FT_ULong isFixedPitch;
    FT_ULong minMemType42;
    FT_ULong maxMemType42;
    FT_ULong minMemType1;
    FT_ULong maxMemType1;

    /* Glyph names follow in the file, but we don't   */
    /* load them by default.  See the ttpost.c file.  */
};

struct TT_CMap0 {
    FT_Byte* glyphIdArray;
};

struct TT_CMap2SubHeader {
    FT_UShort firstCode;     /* first valid low byte         */
    FT_UShort entryCount;    /* number of valid low bytes    */
    FT_Short  idDelta;       /* delta value to glyphIndex    */
    FT_UShort idRangeOffset; /* offset from here to 1st code */
};

struct TT_CMap2 {
    FT_UShort* subHeaderKeys;
    /* high byte mapping table            */
    /* value = subHeader index * 8        */

    TT_CMap2SubHeader* subHeaders;
    FT_UShort*         glyphIdArray;
    FT_UShort          numGlyphId; /* control value */
};

struct TT_CMap4Segment {
    FT_UShort endCount;
    FT_UShort startCount;
    FT_Short  idDelta;
    FT_UShort idRangeOffset;
};

struct TT_CMap4 {
    FT_UShort segCountX2;    /* number of segments * 2       */
    FT_UShort searchRange;   /* these parameters can be used */
    FT_UShort entrySelector; /* for a binary search          */
    FT_UShort rangeShift;

    TT_CMap4Segment* segments;
    FT_UShort*       glyphIdArray;
    FT_UShort        numGlyphId; /* control value */

    TT_CMap4Segment* last_segment; /* last used segment; this is a small  */
};

struct TT_CMap6 {
    FT_UShort firstCode;  /* first character code of subrange      */
    FT_UShort entryCount; /* number of character codes in subrange */

    FT_UShort* glyphIdArray;
};

struct TT_CMapTable {
    FT_UShort platformID;
    FT_UShort platformEncodingID;
    FT_UShort format;
    FT_UShort length;
    FT_UShort version;

    FT_Bool  loaded;
    FT_ULong offset;

    union {
        TT_CMap0 cmap0;
        TT_CMap2 cmap2;
        TT_CMap4 cmap4;
        TT_CMap6 cmap6;
    } c;

    TT_CharMap_Func get_index;
};

struct TT_CharMapRec {
    FT_CharMapRec root;
    TT_CMapTable  cmap;
};

struct TT_GlyphZone {
    FT_Memory memory;
    FT_UShort max_points;
    FT_UShort max_contours;
    FT_UShort n_points;   /* number of points in zone    */
    FT_Short  n_contours; /* number of contours          */

    FT_Vector* org; /* original point coordinates  */
    FT_Vector* cur; /* current point coordinates   */

    FT_Byte*   tags;     /* current touch flags         */
    FT_UShort* contours; /* contour end points          */
};

struct TT_Size_Metrics {
    /* for non-square pixels */
    FT_Long x_ratio;
    FT_Long y_ratio;

    FT_UShort ppem;  /* maximum ppem size              */
    FT_Long   ratio; /* current ratio                  */
    FT_Fixed  scale;

    FT_F26Dot6 compensations[4]; /* device-specific compensations  */

    FT_Bool valid;

    FT_Bool rotated;   /* `is the glyph rotated?'-flag   */
    FT_Bool stretched; /* `is the glyph stretched?'-flag */
};

struct TT_SizeRec {
    FT_SizeRec      root;
    TT_Size_Metrics ttmetrics;
    FT_UInt         strike_index;
    FT_Size_Metrics strike_metrics;
    FT_Bool         debug;
};

struct TT_Loader {
    FT_Face         face;
    FT_Size         size;
    FT_GlyphSlot    glyph;
    FT_GlyphLoader* gloader;

    FT_ULong load_flags;
    FT_UInt  glyph_index;

    FT_Stream stream;
    FT_Int    byte_len;

    FT_Short  n_contours;
    FT_BBox   bbox;
    FT_Int    left_bearing;
    FT_Int    advance;
    FT_Bool   preserve_pps;
    FT_Vector pp1;
    FT_Vector pp2;

    FT_ULong glyf_offset;

    /* the zone where we load our glyphs */
    TT_GlyphZone base;
    TT_GlyphZone zone;

    TT_ExecContext exec;
    FT_Byte*       instructions;
    FT_ULong       ins_pos;

    /* for possible extensibility in other formats */
    void* other;
};

struct TT_HdmxRec {
    FT_Byte  ppem;
    FT_Byte  max_width;
    FT_Byte* widths;
};

struct TT_Hdmx {
    FT_UShort   version;
    FT_Short    num_records;
    TT_HdmxRec* records;
};

struct TT_GaspRange {
    FT_UShort maxPPEM;
    FT_UShort gaspFlag;
};

struct TT_Gasp {
    FT_UShort     version;
    FT_UShort     numRanges;
    TT_GaspRange* gaspRanges;
};

struct TT_PCLT {
    FT_Fixed  Version;
    FT_ULong  FontNumber;
    FT_UShort Pitch;
    FT_UShort xHeight;
    FT_UShort Style;
    FT_UShort TypeFamily;
    FT_UShort CapHeight;
    FT_UShort SymbolSet;
    FT_Char   TypeFace[16];
    FT_Char   CharacterComplement[8];
    FT_Char   FileName[6];
    FT_Char   StrokeWeight;
    FT_Char   WidthType;
    FT_Byte   SerifStyle;
    FT_Byte   Reserved;
};

struct TT_SBit_Metrics {
    FT_Byte height;
    FT_Byte width;

    FT_Char horiBearingX;
    FT_Char horiBearingY;
    FT_Byte horiAdvance;

    FT_Char vertBearingX;
    FT_Char vertBearingY;
    FT_Byte vertAdvance;
};

struct TT_SBit_Line_Metrics {
    FT_Char ascender;
    FT_Char descender;
    FT_Byte max_width;
    FT_Char caret_slope_numerator;
    FT_Char caret_slope_denominator;
    FT_Char caret_offset;
    FT_Char min_origin_SB;
    FT_Char min_advance_SB;
    FT_Char max_before_BL;
    FT_Char min_after_BL;
    FT_Char pads[2];
};

struct TT_SBit_Range {
    FT_UShort first_glyph;
    FT_UShort last_glyph;

    FT_UShort index_format;
    FT_UShort image_format;
    FT_ULong  image_offset;

    FT_ULong        image_size;
    TT_SBit_Metrics metrics;
    FT_ULong        num_glyphs;

    FT_ULong*  glyph_offsets;
    FT_UShort* glyph_codes;

    FT_ULong table_offset;
};

struct TT_SBit_Strike {
    FT_Int         num_ranges;
    TT_SBit_Range* sbit_ranges;
    FT_ULong       ranges_offset;

    FT_ULong color_ref;

    TT_SBit_Line_Metrics hori;
    TT_SBit_Line_Metrics vert;

    FT_UShort start_glyph;
    FT_UShort end_glyph;

    FT_Byte x_ppem;
    FT_Byte y_ppem;

    FT_Byte bit_depth;
    FT_Char flags;
};

struct TT_SBit_Scale {
    TT_SBit_Line_Metrics hori;
    TT_SBit_Line_Metrics vert;

    FT_Byte x_ppem;
    FT_Byte y_ppem;

    FT_Byte x_ppem_substitute;
    FT_Byte y_ppem_substitute;
};

struct TT_Post_20 {
    FT_UShort  num_glyphs;
    FT_UShort  num_names;
    FT_UShort* glyph_indices;
    FT_Char**  glyph_names;
};

struct TT_Post_25 {
    FT_UShort num_glyphs;
    FT_Char*  offsets;
};

struct TT_Post_Names {
    FT_Bool loaded;

    union {
        TT_Post_20 format_20;
        TT_Post_25 format_25;

    } names;
};

struct TT_Kern_0_Pair {
    FT_UShort left;  /* index of left  glyph in pair */
    FT_UShort right; /* index of right glyph in pair */
    FT_FWord  value; /* kerning value                */
};

struct TT_FaceRec {
    FT_FaceRec root;

    TTC_Header ttc_header;

    FT_ULong  format_tag;
    FT_UShort num_tables;
    TT_Table* dir_tables;

    TT_Header     header;     /* TrueType header table          */
    TT_HoriHeader horizontal; /* TrueType horizontal header     */

    TT_MaxProfile max_profile;
    FT_ULong      max_components;

    FT_Bool       vertical_info;
    TT_VertHeader vertical; /* TT Vertical header, if present */

    FT_UShort    num_names;  /* number of name records  */
    TT_NameTable name_table; /* name table              */

    TT_OS2        os2;        /* TrueType OS/2 table            */
    TT_Postscript postscript; /* TrueType Postscript table      */

    FT_Int     num_charmaps;
    TT_CharMap charmaps; /* array of TT_CharMapRec */

    TT_Goto_Table_Func goto_table;

    TT_Access_Glyph_Frame_Func access_glyph_frame;
    TT_Load_Glyph_Element_Func read_glyph_header;
    TT_Load_Glyph_Element_Func read_simple_glyph;
    TT_Load_Glyph_Element_Func read_composite_glyph;
    TT_Forget_Glyph_Frame_Func forget_glyph_frame;

    /* a typeless pointer to the SFNT_Interface table used to load     */
    /* the basic TrueType tables in the face object                    */
    void* sfnt;

    /* a typeless pointer to the PSNames_Interface table used to       */
    /* handle glyph names <-> unicode & Mac values                     */
    void* psnames;

    /***********************************************************************/
    /*                                                                     */
    /* Optional TrueType/OpenType tables                                   */
    /*                                                                     */
    /***********************************************************************/

    /* horizontal device metrics */
    TT_Hdmx hdmx;

    /* grid-fitting and scaling table */
    TT_Gasp gasp; /* the `gasp' table */

    /* PCL 5 table */
    TT_PCLT pclt;

    /* embedded bitmaps support */
    FT_Int          num_sbit_strikes;
    TT_SBit_Strike* sbit_strikes;

    FT_Int         num_sbit_scales;
    TT_SBit_Scale* sbit_scales;

    /* postscript names table */
    TT_Post_Names postscript_names;

    /***********************************************************************/
    /*                                                                     */
    /* TrueType-specific fields (ignored by the OTF-Type2 driver)          */
    /*                                                                     */
    /***********************************************************************/

    /* the glyph locations */
    FT_UShort num_locations;
    FT_Long*  glyph_locations;

    /* the font program, if any */
    FT_ULong font_program_size;
    FT_Byte* font_program;

    /* the cvt program, if any */
    FT_ULong cvt_program_size;
    FT_Byte* cvt_program;

    /* the original, unscaled, control value table */
    FT_ULong  cvt_size;
    FT_Short* cvt;

    /* the format 0 kerning table, if any */
    FT_Int          num_kern_pairs;
    FT_Int          kern_table_index;
    TT_Kern_0_Pair* kern_pairs;

    /* A pointer to the bytecode interpreter to use.  This is also */
    /* used to hook the debugger for the `ttdebug' utility.        */
    TT_Interpreter interpreter;

    /***********************************************************************/
    /*                                                                     */
    /* Other tables or fields. This is used by derivative formats like     */
    /* OpenType.                                                           */
    /*                                                                     */
    /***********************************************************************/

    FT_Generic extra;
};

struct T2_DriverRec {
    FT_DriverRec root;
    void*        extension_component;
};

struct T2_GlyphSlotRec {
    FT_GlyphSlotRec root;

    FT_Bool hint;
    FT_Bool scaled;

    FT_Fixed x_scale;
    FT_Fixed y_scale;
};

struct PS_Table_Funcs {
    FT_Error (*init)(PS_Table* table, FT_Int count, FT_Memory memory);

    void (*done)(PS_Table* table);

    FT_Error (*add)(PS_Table* table, FT_Int index, void* object, FT_Int length);

    void (*release)(PS_Table* table);
};

struct PS_Table {
    FT_Byte*       block;    /* current memory block           */
    FT_Int         cursor;   /* current cursor in memory block */
    FT_Int         capacity; /* current size of memory block   */
    FT_Long        init;
    FT_Int         max_elems;
    FT_Int         num_elems;
    FT_Byte**      elements; /* addresses of table elements */
    FT_Int*        lengths;  /* lengths of table elements   */
    FT_Memory      memory;
    PS_Table_Funcs funcs;
};

struct T1_Field {
    const char*       ident; /* field identifier               */
    T1_Field_Location location;
    T1_Field_Type     type; /* type of field                  */
    T1_Field_Parser   reader;
    FT_UInt           offset;    /* offset of field in object      */
    FT_Byte           size;      /* size of field in bytes         */
    FT_UInt           array_max; /* maximal number of elements for */
                                 /* array                          */
    FT_UInt count_offset;        /* offset of element count for    */
                                 /* arrays                         */
};

struct T1_Token {
    FT_Byte*      start; /* first character of token in input stream */
    FT_Byte*      limit; /* first character after the token          */
    T1_Token_Type type;  /* type of token                            */
};

struct T1_Parser_Funcs {
    void (*init)(T1_Parser* parser, FT_Byte* base, FT_Byte* limit, FT_Memory memory);
    void (*done)(T1_Parser* parser);
    void (*skip_spaces)(T1_Parser* parser);
    void (*skip_alpha)(T1_Parser* parser);
    FT_Long (*to_int)(T1_Parser* parser);
    FT_Fixed (*to_fixed)(T1_Parser* parser, FT_Int power_ten);
    FT_Int (*to_coord_array)(T1_Parser* parser, FT_Int max_coords, FT_Short* coords);
    FT_Int (
        *to_fixed_array)(T1_Parser* parser, FT_Int max_values, FT_Fixed* values, FT_Int power_ten);

    void (*to_token)(T1_Parser* parser, T1_Token* token);
    void (*to_token_array)(
        T1_Parser* parser,
        T1_Token*  tokens,
        FT_UInt    max_tokens,
        FT_Int*    pnum_tokens);

    FT_Error (*load_field)(
        T1_Parser* parser,
        T1_Field*  field,
        void**     objects,
        FT_UInt    max_objects,
        FT_ULong*  pflags);

    FT_Error (*load_field_table)(
        T1_Parser* parser,
        T1_Field*  field,
        void**     objects,
        FT_UInt    max_objects,
        FT_ULong*  pflags);
};

struct T1_Parser {
    FT_Byte*        cursor;
    FT_Byte*        base;
    FT_Byte*        limit;
    FT_Error        error;
    FT_Memory       memory;
    T1_Parser_Funcs funcs;
};

struct T1_Builder_Funcs {
    void (*init)(T1_Builder* builder, FT_Face face, FT_Size size, FT_GlyphSlot slot);

    void (*done)(T1_Builder* builder);

    T1_Builder_Check_Points_Func  check_points;
    T1_Builder_Add_Point_Func     add_point;
    T1_Builder_Add_Point1_Func    add_point1;
    T1_Builder_Add_Contour_Func   add_contour;
    T1_Builder_Start_Point_Func   start_point;
    T1_Builder_Close_Contour_Func close_contour;
};

struct T1_Builder {
    FT_Memory        memory;
    FT_Face          face;
    FT_GlyphSlot     glyph;
    FT_GlyphLoader*  loader;
    FT_Outline*      base;
    FT_Outline*      current;
    FT_Vector        last;
    FT_Fixed         scale_x;
    FT_Fixed         scale_y;
    FT_Pos           pos_x;
    FT_Pos           pos_y;
    FT_Vector        left_bearing;
    FT_Vector        advance;
    FT_BBox          bbox; /* bounding box */
    FT_Bool          path_begun;
    FT_Bool          load_points;
    FT_Bool          no_recurse;
    FT_Bool          shift;
    FT_Error         error; /* only used for memory errors */
    FT_Bool          metrics_only;
    T1_Builder_Funcs funcs;
};

struct T1_DesignMap {
    FT_Byte   num_points;
    FT_Fixed* design_points;
    FT_Fixed* blend_points;
};

struct T1_FontInfo {
    FT_String* version;
    FT_String* notice;
    FT_String* full_name;
    FT_String* family_name;
    FT_String* weight;
    FT_Long    italic_angle;
    FT_Bool    is_fixed_pitch;
    FT_Short   underline_position;
    FT_UShort  underline_thickness;
};

struct T1_Private {
    FT_Int    unique_id;
    FT_Int    lenIV;
    FT_Byte   num_blue_values;
    FT_Byte   num_other_blues;
    FT_Byte   num_family_blues;
    FT_Byte   num_family_other_blues;
    FT_Short  blue_values[14];
    FT_Short  other_blues[10];
    FT_Short  family_blues[14];
    FT_Short  family_other_blues[10];
    FT_Fixed  blue_scale;
    FT_Int    blue_shift;
    FT_Int    blue_fuzz;
    FT_UShort standard_width[1];
    FT_UShort standard_height[1];
    FT_Byte   num_snap_widths;
    FT_Byte   num_snap_heights;
    FT_Bool   force_bold;
    FT_Bool   round_stem_up;
    FT_Short  snap_widths[13];  /* reserve one place for the std */
    FT_Short  snap_heights[13]; /* reserve one place for the std */
    FT_Long   language_group;
    FT_Long   password;
    FT_Short  min_feature[2];
};

struct T1_Blend {
    FT_UInt num_designs;
    FT_UInt num_axis;

    FT_String*   axis_names[4];
    FT_Fixed*    design_pos[16];
    T1_DesignMap design_map[4];

    FT_Fixed* weight_vector;
    FT_Fixed* default_weight_vector;

    T1_FontInfo* font_infos[17];
    T1_Private*  privates[17];

    FT_ULong blend_bitflags;
};

struct PS_UniMap {
    FT_UInt unicode;
    FT_UInt glyph_index;
};

struct PS_Unicodes {
    FT_UInt    num_maps;
    PS_UniMap* maps;
};

struct PSNames_Interface {
    PS_Unicode_Value_Func     unicode_value;
    PS_Build_Unicodes_Func    build_unicodes;
    PS_Lookup_Unicode_Func    lookup_unicode;
    PS_Macintosh_Name_Func    macintosh_name;
    PS_Adobe_Std_Strings_Func adobe_std_strings;
    const uint16_t*           adobe_std_encoding;
    const uint16_t*           adobe_expert_encoding;
};

struct T1_Decoder_Funcs {
    FT_Error (*init)(
        T1_Decoder*         decoder,
        FT_Face             face,
        FT_Size             size,
        FT_GlyphSlot        slot,
        FT_Byte**           glyph_names,
        T1_Blend*           blend,
        T1_Decoder_Callback callback);
    void (*done)(T1_Decoder* decoder);
    FT_Error (*parse_charstrings)(T1_Decoder* decoder, FT_Byte* base, FT_UInt len);
};

struct T1_Decoder_Zone {
    FT_Byte* cursor;
    FT_Byte* base;
    FT_Byte* limit;
};

struct T1_Decoder {
    T1_Builder          builder;
    FT_Long             stack[256];
    FT_Long*            top;
    T1_Decoder_Zone     zones[17];
    T1_Decoder_Zone*    zone;
    PSNames_Interface*  psnames; /* for seac */
    FT_UInt             num_glyphs;
    FT_Byte**           glyph_names;
    FT_UInt             lenIV; /* internal for sub routine calls */
    FT_UInt             num_subrs;
    FT_Byte**           subrs;
    FT_Int*             subrs_len; /* array of subrs length (optional) */
    FT_Matrix           font_matrix;
    FT_Vector           font_offset;
    FT_Int              flex_state;
    FT_Int              num_flex_vectors;
    FT_Vector           flex_vectors[7];
    T1_Blend*           blend; /* for multiple master support */
    T1_Decoder_Callback parse_callback;
    T1_Decoder_Funcs    funcs;
};

struct PSAux_Interface {
    PS_Table_Funcs*   ps_table_funcs;
    T1_Parser_Funcs*  t1_parser_funcs;
    T1_Builder_Funcs* t1_builder_funcs;
    T1_Decoder_Funcs* t1_decoder_funcs;

    void (*t1_decrypt)(FT_Byte* buffer, FT_Int length, FT_UShort seed);
};

struct SFNT_Header {
    FT_ULong  format_tag;
    FT_UShort num_tables;
    FT_UShort search_range;
    FT_UShort entry_selector;
    FT_UShort range_shift;
};

struct SFNT_Interface {
    TT_Goto_Table_Func goto_table;

    TT_Init_Face_Func       init_face;
    TT_Load_Face_Func       load_face;
    TT_Done_Face_Func       done_face;
    SFNT_Get_Interface_Func get_interface;

    TT_Load_Any_Func         load_any;
    TT_Load_SFNT_Header_Func load_sfnt_header;
    TT_Load_Directory_Func   load_directory;

    /* these functions are called by `load_face' but they can also  */
    /* be called from external modules, if there is a need to do so */
    TT_Load_Table_Func   load_header;
    TT_Load_Metrics_Func load_metrics;
    TT_Load_Table_Func   load_charmaps;
    TT_Load_Table_Func   load_max_profile;
    TT_Load_Table_Func   load_os2;
    TT_Load_Table_Func   load_psnames;

    TT_Load_Table_Func load_names;
    TT_Free_Table_Func free_names;

    /* optional tables */
    TT_Load_Table_Func load_hdmx;
    TT_Free_Table_Func free_hdmx;

    TT_Load_Table_Func load_kerning;
    TT_Load_Table_Func load_gasp;
    TT_Load_Table_Func load_pclt;

    /* see `ttload.h' */
    TT_Load_Table_Func load_bitmap_header;

    /* see `ttsbit.h' */
    TT_Set_SBit_Strike_Func set_sbit_strike;
    TT_Load_Table_Func      load_sbits;
    TT_Load_SBit_Image_Func load_sbit_image;
    TT_Free_Table_Func      free_sbits;

    /* see `ttpost.h' */
    TT_Get_PS_Name_Func get_psname;
    TT_Free_Table_Func  free_psnames;

    /* see `ttcmap.h' */
    TT_CharMap_Load_Func load_charmap;
    TT_CharMap_Free_Func free_charmap;
};

struct CFF_Index {
    FT_Stream stream;
    FT_UInt   count;
    FT_Byte   off_size;
    FT_ULong  data_offset;

    FT_ULong* offsets;
    FT_Byte*  bytes;
};

struct CFF_Font_Dict {
    FT_UInt   version;
    FT_UInt   notice;
    FT_UInt   copyright;
    FT_UInt   full_name;
    FT_UInt   family_name;
    FT_UInt   weight;
    FT_Bool   is_fixed_pitch;
    FT_Fixed  italic_angle;
    FT_Pos    underline_position;
    FT_Pos    underline_thickness;
    FT_Int    paint_type;
    FT_Int    charstring_type;
    FT_Matrix font_matrix;
    FT_ULong  unique_id;
    FT_BBox   font_bbox;
    FT_Pos    stroke_width;
    FT_ULong  charset_offset;
    FT_ULong  encoding_offset;
    FT_ULong  charstrings_offset;
    FT_ULong  private_offset;
    FT_ULong  private_size;
    FT_Long   synthetic_base;
    FT_UInt   embedded_postscript;
    FT_UInt   base_font_name;
    FT_UInt   postscript;

    /* these should only be used for the top-level font dictionary */
    FT_UInt  cid_registry;
    FT_UInt  cid_ordering;
    FT_ULong cid_supplement;

    FT_Long  cid_font_version;
    FT_Long  cid_font_revision;
    FT_Long  cid_font_type;
    FT_Long  cid_count;
    FT_ULong cid_uid_base;
    FT_ULong cid_fd_array_offset;
    FT_ULong cid_fd_select_offset;
    FT_UInt  cid_font_name;
};

struct CFF_Private {
    FT_Byte num_blue_values;
    FT_Byte num_other_blues;
    FT_Byte num_family_blues;
    FT_Byte num_family_other_blues;

    FT_Pos blue_values[14];
    FT_Pos other_blues[10];
    FT_Pos family_blues[14];
    FT_Pos family_other_blues[10];

    FT_Fixed blue_scale;
    FT_Pos   blue_shift;
    FT_Pos   blue_fuzz;
    FT_Pos   standard_width;
    FT_Pos   standard_height;

    FT_Byte  num_snap_widths;
    FT_Byte  num_snap_heights;
    FT_Pos   snap_widths[13];
    FT_Pos   snap_heights[13];
    FT_Bool  force_bold;
    FT_Fixed force_bold_threshold;
    FT_Int   lenIV;
    FT_Int   language_group;
    FT_Fixed expansion_factor;
    FT_Long  initial_random_seed;
    FT_ULong local_subrs_offset;
    FT_Pos   default_width;
    FT_Pos   nominal_width;
};

struct CFF_SubFont {
    CFF_Font_Dict font_dict;
    CFF_Private   private_dict;

    CFF_Index local_subrs_index;
    FT_UInt   num_local_subrs;
    FT_Byte** local_subrs;
};

struct CFF_FD_Select {
    FT_Byte format;
    FT_UInt range_count;

    /* that's the table, taken from the file `as is' */
    FT_Byte* data;
    FT_UInt  data_size;

    /* small cache for format 3 only */
    FT_UInt cache_first;
    FT_UInt cache_count;
    FT_Byte cache_fd;
};

struct CFF_Font {
    FT_Stream stream;
    FT_Memory memory;
    FT_UInt   num_faces;
    FT_UInt   num_glyphs;

    FT_Byte version_major;
    FT_Byte version_minor;
    FT_Byte header_size;
    FT_Byte absolute_offsize;

    CFF_Index name_index;
    CFF_Index top_dict_index;
    CFF_Index string_index;
    CFF_Index global_subrs_index;

    /* we don't load the Encoding and CharSet tables */

    CFF_Index charstrings_index;
    CFF_Index font_dict_index;
    CFF_Index private_index;
    CFF_Index local_subrs_index;

    FT_String* font_name;
    FT_UInt    num_global_subrs;
    FT_Byte**  global_subrs;

    CFF_SubFont  top_font;
    FT_UInt      num_subfonts;
    CFF_SubFont* subfonts[16];

    CFF_FD_Select fd_select;
};

struct FT_Frame_Field {
    FT_Frame_Op value;
    FT_Byte     size;
    FT_UShort   offset;
};

struct T2_Parser {
    FT_Byte* start;
    FT_Byte* limit;
    FT_Byte* cursor;

    FT_Byte*  stack[97];
    FT_Byte** top;

    FT_UInt object_code;
    void*   object;
};

struct T2_Decoder_Zone {
    FT_Byte* base;
    FT_Byte* limit;
    FT_Byte* cursor;
};

struct T2_Builder {
    FT_Memory       memory;
    TT_Face         face;
    T2_GlyphSlot    glyph;
    FT_GlyphLoader* loader;
    FT_Outline*     base;
    FT_Outline*     current;

    FT_Vector last;

    FT_Fixed scale_x;
    FT_Fixed scale_y;

    FT_Pos pos_x;
    FT_Pos pos_y;

    FT_Vector left_bearing;
    FT_Vector advance;

    FT_BBox bbox; /* bounding box */
    FT_Bool path_begun;
    FT_Bool load_points;
    FT_Bool no_recurse;

    FT_Error error; /* only used for memory errors */
    FT_Bool  metrics_only;
};

struct T2_Decoder {
    T2_Builder builder;
    CFF_Font*  cff;

    FT_Fixed  stack[49];
    FT_Fixed* top;

    T2_Decoder_Zone  zones[33];
    T2_Decoder_Zone* zone;

    FT_Int    flex_state;
    FT_Int    num_flex_vectors;
    FT_Vector flex_vectors[7];

    FT_Pos glyph_width;
    FT_Pos nominal_width;

    FT_Bool   read_width;
    FT_Int    num_hints;
    FT_Fixed* buildchar;
    FT_Int    len_buildchar;

    FT_UInt num_locals;
    FT_UInt num_globals;

    FT_Int locals_bias;
    FT_Int globals_bias;

    FT_Byte** locals;
    FT_Byte** globals;
};

struct CID_FontDict {
    T1_Private private_dict;

    FT_UInt  len_buildchar;
    FT_Fixed forcebold_threshold;
    FT_Pos   stroke_width;
    FT_Fixed expansion_factor;

    FT_Byte   paint_type;
    FT_Byte   font_type;
    FT_Matrix font_matrix;
    FT_Vector font_offset;

    FT_UInt  num_subrs;
    FT_ULong subrmap_offset;
    FT_Int   sd_bytes;
};

struct CID_Info {
    FT_String* cid_font_name;
    FT_Fixed   cid_version;
    FT_Int     cid_font_type;

    FT_String* registry;
    FT_String* ordering;
    FT_Int     supplement;

    T1_FontInfo font_info;
    FT_BBox     font_bbox;
    FT_ULong    uid_base;

    FT_Int   num_xuid;
    FT_ULong xuid[16];

    FT_ULong cidmap_offset;
    FT_Int   fd_bytes;
    FT_Int   gd_bytes;
    FT_ULong cid_count;

    FT_Int        num_dicts;
    CID_FontDict* font_dicts;

    FT_ULong data_offset;
};

struct CID_Subrs {
    FT_UInt   num_subrs;
    FT_Byte** code;
};

struct CID_FaceRec {
    FT_FaceRec root;
    void*      psnames;
    void*      psaux;
    CID_Info   cid;
    void*      afm_data;
    CID_Subrs* subrs;
};

struct CID_Parser {
    T1_Parser root;
    FT_Stream stream;

    FT_Byte* postscript;
    FT_Int   postscript_len;

    FT_ULong data_offset;

    CID_Info* cid;
    FT_Int    num_dict;
};

struct CID_Loader {
    CID_Parser parser;    /* parser used to read the stream */
    FT_Int     num_chars; /* number of characters in encoding */
};

struct CID_GlyphSlotRec {
    FT_GlyphSlotRec root;

    FT_Bool hint;
    FT_Bool scaled;

    FT_Fixed x_scale;
    FT_Fixed y_scale;
};

struct CID_SizeRec {
    FT_SizeRec root;
    FT_Bool    valid;
};

struct T1_Encoding {
    FT_Int num_chars;
    FT_Int code_first;
    FT_Int code_last;

    FT_UShort*  char_index;
    FT_String** char_name;
};

struct T1_Font {
    /* font info dictionary */
    T1_FontInfo font_info;

    /* private dictionary */
    T1_Private private_dict;

    /* top-level dictionary */
    FT_String* font_name;

    T1_EncodingType encoding_type;
    T1_Encoding     encoding;

    FT_Byte* subrs_block;
    FT_Byte* charstrings_block;
    FT_Byte* glyph_names_block;

    FT_Int    num_subrs;
    FT_Byte** subrs;
    FT_Int*   subrs_len;

    FT_Int      num_glyphs;
    FT_String** glyph_names; /* array of glyph names       */
    FT_Byte**   charstrings; /* array of glyph charstrings */
    FT_Int*     charstrings_len;

    FT_Byte   paint_type;
    FT_Byte   font_type;
    FT_Matrix font_matrix;
    FT_Vector font_offset;
    FT_BBox   font_bbox;
    FT_Long   font_id;

    FT_Int stroke_width;
};

struct T1_FaceRec {
    FT_FaceRec    root;
    T1_Font       type1;
    void*         psnames;
    void*         psaux;
    void*         afm_data;
    FT_CharMapRec charmaprecs[2];
    FT_CharMap    charmaps[2];
    PS_Unicodes   unicode_map;

    /* support for Multiple Masters fonts */
    T1_Blend* blend;
};

struct TPoint {
    int32_t x;
    int32_t y;
};

struct TProfile {
    FT_F26Dot6 X;      /* current coordinate during sweep        */
    TProfile*  link;   /* link to next profile - various purpose */
    int32_t*   offset; /* start of profile's data in render pool */
    int32_t    flow;   /* Profile orientation: Asc/Descending    */
    int32_t    height; /* profile's height in scanlines          */
    int32_t    start;  /* profile's starting scanline            */

    uint16_t countL; /* number of lines to step before this    */
                     /* profile becomes drawable               */

    TProfile* next; /* next profile in same contour, used     */
                    /* during drop-out control                */
};

struct TBand {
    int16_t y_min;
    int16_t y_max;
};

struct TRaster_Instance {
    int32_t precision_bits; /* precision related variables         */
    int32_t precision;
    int32_t precision_half;
    int32_t precision_mask;
    int32_t precision_shift;
    int32_t precision_step;
    int32_t precision_jitter;

    int32_t scale_shift; /* == precision_shift   for bitmaps    */
                         /* == precision_shift+1 for pixmaps    */

    int32_t* buff;     /* The profiles buffer                 */
    int32_t* sizeBuff; /* Render pool size                    */
    int32_t* maxBuff;  /* Profiles buffer size                */
    int32_t* top;      /* Current cursor in buffer            */

    FT_Error error;

    int32_t* numTurns; /* number of Y-turns in outline        */

    TPoint* arc; /* current Bezier arc pointer          */

    uint16_t bWidth;  /* target bitmap width                 */
    uint8_t* bTarget; /* target bitmap buffer                */
    uint8_t* gTarget; /* target pixmap buffer                */

    int32_t lastX, lastY, minY, maxY;

    uint16_t num_Profs; /* current number of profiles          */

    bool fresh;         /* signals a fresh new profile which   */
                        /* 'start' field must be completed     */
    bool joint;         /* signals that the last arc ended     */
                        /* exactly on a scanline.  Allows      */
                        /* removal of doublets                 */
    TProfile* cProfile; /* current profile                     */
    TProfile* fProfile; /* head of linked list of profiles     */
    TProfile* gProfile; /* contour's first profile in case     */
                        /* of impact                           */

    TStates state; /* rendering state                     */

    FT_Bitmap  target; /* description of target bit/pixmap    */
    FT_Outline outline;

    int32_t traceOfs; /* current offset in target bitmap     */
    int32_t traceG;   /* current offset in target pixmap     */

    int16_t traceIncr; /* sweep's increment in target bitmap  */

    int16_t gray_min_x; /* current min x during gray rendering */
    int16_t gray_max_x; /* current max x during gray rendering */

    /* dispatch variables */

    Function_Sweep_Init Proc_Sweep_Init;
    Function_Sweep_Span Proc_Sweep_Span;
    Function_Sweep_Span Proc_Sweep_Drop;
    Function_Sweep_Step Proc_Sweep_Step;

    uint8_t dropOutControl; /* current drop_out control method     */

    uint8_t second_pass; /* indicates wether a horizontal pass  */
                         /* should be performed to control      */
                         /* drop-out accurately when calling    */
                         /* Render_Glyph.  Note that there is   */
                         /* no horizontal pass during gray      */
                         /* rendering.                          */

    TPoint arcs[65]; /* The Bezier stack                 */

    TBand   band_stack[16]; /* band stack used for sub-banding     */
    int32_t band_top;       /* band stack top                      */

    int32_t count_table[256]; /* Look-up table used to quickly count */
                              /* set bits in a gray 2x2 cell         */

    void* memory;
};

#endif
