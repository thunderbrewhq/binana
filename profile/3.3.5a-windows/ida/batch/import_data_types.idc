#include <idc.idc>

static import_data_types() {
	// Give types to data labels
	apply_type(0x00408070, "void __stdcall func(float* minX, float* maxX, float* minY, float* maxY, float* minZ, float* maxZ)");
	apply_type(0x00409670, "void __thiscall func(CGxDevice* this)");
	apply_type(0x004804F0, "void __cdecl func(EvtContext* context, EVENTID id, void* handler, void* param, float priority)");
	apply_type(0x004806A0, "int32_t __cdecl func(EvtContext* context, EVENTID id, void *data, size_t bytes)");
	apply_type(0x00494EE0, "int32_t __thiscall func(CFrameStrata* this, int32_t a2)");
	apply_type(0x00494F30, "void __thiscall func(CFrameStrata* this)");
	apply_type(0x004B5510, "int32_t __stdcall func(uint32_t width, uint32_t height)");
	apply_type(0x004B7220, "MipBits* __stdcall func(PIXEL_FORMAT format, uint32_t width, uint32_t height)");
	apply_type(0x004B7300, "void func(MipBits* image)");
	apply_type(0x004B78A0, "int32_t __usercall func@<eax>(char* ext@<eax>, char* filename, int32_t a3, MipBits** mipBits, uint32_t* width, uint32_t* height, PIXEL_FORMAT* texFormat, int32_t* isOpaque@<ecx>, uint32_t* alphaBits, PIXEL_FORMAT* dataFormat)");
	apply_type(0x004B8070, "int32_t __usercall func@<eax>(char* ext@<eax>, char* filename@<ebx>, int32_t a3, MipBits** mipBits, uint32_t* width, uint32_t* height, uint32_t* isOpaque, uint32_t* alphaBits, PIXEL_FORMAT* dataFormat)");
	apply_type(0x004B81D0, "MipBits* func(const char* filename, uint32_t* width, uint32_t* height, PIXEL_FORMAT* dataFormat, int32_t* isOpaque, CStatus* status, uint32_t* alphaBits, int32_t a8)");
	apply_type(0x00532AF0, "CGxCaps* __thiscall func(CGxDevice* this)");
	apply_type(0x006160B0, "int32_t __usercall func@<eax>(uint32_t** image@<eax>, MipBits* mipImages@<ecx>, uint32_t width@<edx>, uint32_t height)");
	apply_type(0x00616800, "void __stdcall func(CURSORMODE mode)");
	apply_type(0x00681F60, "void __stdcall func(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)");
	apply_type(0x00682CB0, "void __thiscall func(CGxDevice* this, int32_t (*windowProc)(void*, uint32_t, uintptr_t, intptr_t), CGxFormat* format)");
	apply_type(0x00682CD0, "void __thiscall func(CGxDevice* this, CGxFormat* format)");
	apply_type(0x00682CF0, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00682D00, "void __thiscall func(CGxDevice* this, uint32_t baseMipLevel)");
	apply_type(0x00682D20, "EGxApi __thiscall func(CGxDevice* this)");
	apply_type(0x00682D40, "int32_t __thiscall func(CGxDevice* this)");
	apply_type(0x00682D70, "CRect* __thiscall func(CGxDevice* this)");
	apply_type(0x00682DC0, "int32_t __thiscall func(CGxDevice* this, int32_t a2)");
	apply_type(0x00682E20, "int32_t __thiscall func(CGxDevice* this, int32_t a2)");
	apply_type(0x00682E50, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00682F40, "uint32_t __stdcall func(EGxPrim primType, uint32_t indexCount)");
	apply_type(0x00683080, "void __thiscall func(CGxDevice* this, uint32_t whichLight, int32_t enable)");
	apply_type(0x006830B0, "int32_t __thiscall func(CGxDevice* this, uint32_t app, uint32_t hw, uint32_t appDisables, uint32_t hwDisables, uint32_t flagPos, int32_t* enable)");
	apply_type(0x00683100, "int32_t __thiscall func(CGxDevice* this, EGxMasterEnables state)");
	apply_type(0x00683130, "int32_t __thiscall func(CGxDevice* this, CGxBuf* buf, void *data, uint32_t size, uint32_t offset)");
	apply_type(0x00683150, "uint8_t* __thiscall func(CGxDevice* this, CGxBuf* buf)");
	apply_type(0x00683180, "int32_t __thiscall func(CGxDevice* this, CGxBuf* buf, uint32_t size)");
	apply_type(0x006833A0, "void __thiscall func(CGxDevice* this)");
	apply_type(0x006833E0, "void __thiscall func(CGxDevice* this, EGxShTarget target, uint32_t index, float* constants, uint32_t count)");
	apply_type(0x00683560, "uint8_t* __thiscall func(CGxDevice* this, EGxShTarget target)");
	apply_type(0x00683580, "void __thiscall func(CGxDevice* this, EGxShTarget target, uint32_t index, uint32_t count)");
	apply_type(0x006835E0, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00683610, "void __stdcall func(EGxTexCommand command, uint32_t width, uint32_t height, uint32_t face, uint32_t level, void* userArg, uint32_t* texelStrideInBytes, void** texels)");
	apply_type(0x00683640, "void __thiscall func(CGxDevice* this, int32_t visible)");
	apply_type(0x00683650, "uint32_t* __thiscall func(CGxDevice* this)");
	apply_type(0x00683660, "void __thiscall func(CGxDevice* this, float depth)");
	apply_type(0x006840F0, "int32_t __thiscall func(CGxDevice* this, CGxFormat* format)");
	apply_type(0x00684170, "void __thiscall func(CGxDevice* this, float gamma)");
	apply_type(0x00684190, "int32_t __thiscall func(CGxDevice* this, CGxGammaRamp* ramp)");
	apply_type(0x00684360, "void __thiscall func(CGxDevice* this, CRect* rect)");
	apply_type(0x006843B0, "void __thiscall func(CGxDevice* this)");
	apply_type(0x006843E0, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00684410, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00684440, "void __thiscall func(CGxDevice* this, uint32_t a2, C4Plane* plane)");
	apply_type(0x006847D0, "void __thiscall func(CGxDevice* this, uint32_t a2, CGxLight* light, C3Vector* pos)");
	apply_type(0x00684850, "void __thiscall func(CGxDevice* this, EGxPoolTarget target, uint32_t itemSize, uint32_t itemCount)");
	apply_type(0x006848A0, "void __thiscall func(CGxDevice* this, CGxTex* texId, CiRect* updateRect, int32_t immediate)");
	apply_type(0x00684900, "void __thiscall func(CGxDevice* this, CGxTex* texId)");
	apply_type(0x00684970, "int32_t __thiscall func(CGxDevice* this, CGxShader** shaders, EGxShTarget target, char* a4, char* a5, int32_t permutations)");
	apply_type(0x00684AD0, "void __thiscall func(CGxDevice* this, CGxFormat* format)");
	apply_type(0x00684B50, "void __thiscall func(CGxDevice* this, uint32_t x, uint32_t y)");
	apply_type(0x00684C20, "void __stdcall func(char* format, ...)");
	apply_type(0x00684C40, "void __stdcall func(CGxCaps* caps)");
	apply_type(0x00684D10, "void __stdcall func(CGxFormat* format)");
	apply_type(0x006853B0, "void __thiscall func(CGxDevice* this, DEVICERESTOREDCALLBACK fn)");
	apply_type(0x006853D0, "int32_t __thiscall func(CGxDevice* this, DEVICERESTOREDCALLBACK fn)");
	apply_type(0x00685460, "void __thiscall func(CGxDevice* this, TEXTURERECREATIONCALLBACK fn)");
	apply_type(0x00685480, "int32_t __thiscall func(CGxDevice* this, TEXTURERECREATIONCALLBACK fn)");
	apply_type(0x00685510, "void __thiscall func(CGxDevice* this, DISPLAYCHANGECALLBACK fn)");
	apply_type(0x00685530, "int32_t __thiscall func(CGxDevice* this, DISPLAYCHANGECALLBACK fn)");
	apply_type(0x00685970, "void __thiscall func(CGxDevice* this, EGxRenderState which)");
	apply_type(0x006859E0, "void __thiscall func(CGxDevice* this, EGxRenderState which)");
	apply_type(0x00685A70, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00685B50, "void __thiscall func(CGxDevice* this, int32_t force)");
	apply_type(0x00685C60, "void __thiscall func(CGxDevice* this, EGxTexTarget target, uint32_t width, uint32_t height, uint32_t depth, EGxTexFormat format, EGxTexFormat dataFormat, CGxTexFlags flags, void* userArg, void (*userFunc)(EGxTexCommand, uint32_t, uint32_t, uint32_t, uint32_t, void*, uint32_t*, void**), char* name, CGxTex** texId)");
	apply_type(0x00685EB0, "void __thiscall func(CGxDevice* this, EGxMasterEnables state, int32_t enable)");
	apply_type(0x00685F50, "void __thiscall func(CGxDevice* this, EGxRenderState which, void* value)");
	apply_type(0x00685FB0, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00687660, "CGxBuf* __thiscall func(CGxDevice* this, CGxPool* pool, uint32_t itemSize, uint32_t itemCount, uint32_t index)");
	apply_type(0x006876D0, "CGxPool* __thiscall func(CGxDevice* this, EGxPoolTarget target, EGxPoolUsage usage, uint32_t size, EGxPoolHintBits hint, char* name)");
	apply_type(0x00687A90, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00688340, "void __thiscall func(CGxDevice* this, CGxPool* pool)");
	apply_type(0x00688690, "void __thiscall func(CGxDevice* this)");
	apply_type(0x006890C0, "void __thiscall func(CGxDevice* this)");
	apply_type(0x00689690, "void __thiscall func(CGxDevice *this, uint8_t __flags)");
	apply_type(0x006897C0, "void __thiscall func(CGxDevice* this, CGxShader**, EGxShTarget, char*, char*, int32_t)");
	apply_type(0x00689EF0, "CGxDevice* __stdcall func()");
	apply_type(0x0068BF20, "CGxDevice* __stdcall func()");
	apply_type(0x0068C220, "CGxDevice* __stdcall func()");
	apply_type(0x006A5A30, "void __thiscall func(CGxDeviceD3d* this)");
	apply_type(0x006A5EF0, "void __thiscall func(CGxDevice* this, CGxTex* texId, uint32_t* width, uint32_t* height, uint32_t* baseMip, uint32_t* mipCount)");
	apply_type(0x006AA3B0, "int32_t __thiscall func(CTgaFile* this)");
	apply_type(0x006AA3E0, "uint32_t __thiscall func(CTgaFile* this)");
	apply_type(0x006AA420, "void __thiscall func(CTgaFile* this, uint8_t* pAlphaData, uint8_t* pNoAlphaData, uint8_t* alpha)");
	apply_type(0x006AA630, "int32_t __thiscall func(CTgaFile* this, uint8_t* pRLEData, uint8_t* pData)");
	apply_type(0x006AA700, "void __thiscall func(CTgaFile* this, int32_t set)");
	apply_type(0x006AA840, "TGA32Pixel* __thiscall func(CTgaFile* this)");
	apply_type(0x006AA870, "int32_t __thiscall func(CTgaFile* this)");
	apply_type(0x006AAF40, "int32_t __thiscall func(CTgaFile* this)");
	apply_type(0x006AAFB0, "int32_t __thiscall func(CTgaFile* this, char* filename, int32_t a3)");
	apply_type(0x006AB390, "int32_t __thiscall func(CTgaFile* this, void* pImg)");
	apply_type(0x006AB4B0, "int32_t __thiscall func(CTgaFile* this, int32_t flags)");
	apply_type(0x006AB620, "uint32_t __cdecl func(uint32_t level, uint32_t width, uint32_t height, uint32_t fourCC)");
	apply_type(0x006AB700, "uint32_t __stdcall func(uint32_t width, uint32_t height)");
	apply_type(0x006AB760, "MipBits* __stdcall func(uint32_t fourCC, uint32_t width, uint32_t height, char* filename, int32_t linenumber)");
	apply_type(0x006AB810, "void __stdcall func(uint32_t fourCC, uint32_t width, uint32_t height, MipBits* bits)");
	apply_type(0x006AB860, "void _stdcall func(C4Pixel* dest, uint32_t destWidth, uint32_t destHeight, C4Pixel* source, uint32_t sourceWidth, uint32_t sourceHeight)");
	apply_type(0x006AE8B0, "void __thiscall func(CBLPFile* this)");
	apply_type(0x006AE900, "int32_t __thiscall func(CBLPFile* this, void* fileBits)");
	apply_type(0x006AE990, "void __thiscall func(CBLPFile* this, uint8_t* data, void* tempbuffer, uint32_t colorSize)");
	apply_type(0x006AE9E0, "void __thiscall func(CBLPFile* this, uint8_t* data, void* tempbuffer, uint32_t colorSize)");
	apply_type(0x006AEBA0, "void __thiscall func(CBLPFile* this, uint8_t* data, void* tempbuffer, uint32_t width, uint32_t height)");
	apply_type(0x006AEE70, "void __thiscall func(CBLPFile* this, uint8_t* data, void* tempbuffer, uint32_t width, uint32_t height)");
	apply_type(0x006AF140, "void __thiscall func(CBLPFile* this, uint8_t* data, void* tempbuffer, uint32_t width, uint32_t height)");
	apply_type(0x006AF340, "void __thiscall func(CBLPFile* this, uint8_t* data, void* tempbuffer, uint32_t width, uint32_t height)");
	apply_type(0x006AF6A0, "uint32_t __thiscall func(CBLPFile* this, uint32_t mipLevel)");
	apply_type(0x006AF730, "int32_t __thiscall func(CBLPFile *this, PIXEL_FORMAT format, uint32_t mipLevel, uint32_t* size, uint32_t* stride)");
	apply_type(0x006AF810, "int32_t __thiscall func(CBLPFile* this, PIXEL_FORMAT format, uint32_t mipLevel, uint8_t* data, void* tempBuffer)");
	apply_type(0x006AFCE0, "int32_t __thiscall func(CBLPFile* this, char* fileName, PIXEL_FORMAT format, uint32_t mipLevel, unsigned char* data, uint32_t* stride)");
	apply_type(0x006AFF10, "int32_t __thiscall func(CBLPFile* this, char* filename)");
	apply_type(0x006AFFD0, "int32_t __thiscall func(CBLPFile* this, char* fileName, PIXEL_FORMAT format, MipBits** images, uint32_t mipLevel, int32_t a6)");
	apply_type(0x006BF4C0, "void __stdcall GxuXformCreateOrtho(float minX, float maxX, float minY, float maxY, float minZ, float maxZ, C44Matrix* dst)");
	apply_type(0x0076E540, "void* __stdcall func(uint32_t bytes, char* filename, int32_t linenumber, uint32_t flags)");
	apply_type(0x0076E5A0, "int32_t __stdcall func(void* ptr, char* filename, int32_t linenumber, uint32_t flags)");
	apply_type(0x0076E5E0, "void* __stdcall func(void* ptr, uint32_t bytes, char* filename, int32_t linenumber, uint32_t flags)");
	apply_type(0x0076F070, "int32_t __stdcall func(char* dest, size_t maxchars, char* format, ...)");
	apply_type(0x00774620, "SCritSect* __thiscall func(SCritSect* this)");
	apply_type(0x00774630, "void __thiscall func(SCritSect *this)");
	apply_type(0x00774640, "void __thiscall func(SCritSect *this)");
	apply_type(0x00774650, "void __thiscall func(SCritSect *this)");
	apply_type(0x00777420, "void __stdcall func(HSRGN handle, RECTF* rect, void* param, int32_t combinemode)");
	apply_type(0x00777590, "void __stdcall func(HSRGN handle, RECTF* rect)");
	apply_type(0x00819EA0, "void __stdcall func(int32_t function, FrameScript_Object* object, int32_t args, char* args_fmt, FrameScript_EventObject* eventObject)");
	apply_type(0x0095F3A0, "void __thiscall func(CSimpleModel* this)");
	apply_type(0x0095F420, "FrameScript_Object__ScriptIx* __thiscall func(CSimpleModel* this, char* name, FrameScript_Object__ScriptData* data)");
	apply_type(0x0095F4D0, "void __stdcall func(CM2Model* model, void* arg)");
	apply_type(0x0095F4F0, "void __thiscall func(CSimpleModel* this, HCAMERA camera)");
	apply_type(0x0095F540, "void __thiscall func(CSimpleModel* this, uint32_t id)");
	apply_type(0x0095F5C0, "void __thiscall func(CSimpleModel* this, CM2Light* light)");
	apply_type(0x0095F5E0, "void __thiscall func(CSimpleModel* this, uint32_t sequence)");
	apply_type(0x0095F610, "int32_t __thiscall func(CSimpleModel* this, uint32_t sequence, int32_t time)");
	apply_type(0x0095F680, "void __thiscall func(CSimpleModel* this)");
	apply_type(0x0095F7D0, "void __thiscall func(CSimpleModel* this, uint32_t __flags)");
	apply_type(0x0095F800, "void __thiscall func(CSimpleModel* this, XMLNode* node, CStatus* status)");
	apply_type(0x0095F990, "void __thiscall func(CSimpleModel* this, char* sourcefile)");
	apply_type(0x0095F9F0, "void __thiscall func(CSimpleModel* this, uint32_t index)");
	apply_type(0x0095FBA0, "void __thiscall func(CSimpleModel* this)");
	apply_type(0x0095FC30, "void __stdcall func(void* arg)");
	apply_type(0x00960070, "void __stdcall func(CM2Model* model, CM2Lighting* lighting, void* userArg)");
	apply_type(0x009600E0, "void __thiscall func(CSimpleModel* this, CM2Model* model)");
	apply_type(0x00960190, "void __thiscall func(CSimpleModel* this, CM2Model* model)");
	apply_type(0x00960280, "void __thiscall func(CSimpleModel* this, float elapsedSec)");
	apply_type(0x009603D0, "void __stdcall func(lua_State* L)");
	apply_type(0x00960530, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009605D0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00960620, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00960660, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009606E0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00960760, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009607E0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009608B0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00960970, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00960A10, "int32_t __stdcall func(lua_State* L, int32_t a2, CM2Light* light)");
	apply_type(0x00960D20, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00960DD0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00960FC0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00961040, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00961090, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009610E0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00961120, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009611A0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00961200, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009612D0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00961350, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009613A0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00961420, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00961470, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x009614B0, "int32_t __stdcall func(lua_State* L)");
	apply_type(0x00A2DDC0, "CGxDevice__vtable");
	apply_type(0x00AC1B9C, "TSExplicitList_CILayer");
	apply_type(0x00AD2808, "char*[53]");
	apply_type(0x00AD90B0, "uint8_t[16]");
	apply_type(0x00AD90C0, "uint8_t[2]");
	apply_type(0x00B417C8, "uint32_t");
	apply_type(0x00B417D0, "int32_t");
	apply_type(0x00B41850, "CDataRecycler");
	apply_type(0x00B6A9DC, "MipBits*");
	apply_type(0x00C25CD0, "int8_t");
	apply_type(0x00C25DE8, "uint32_t[1024]");
	apply_type(0x00C26DE8, "CURSORMODE");
	apply_type(0x00C26DF0, "uint32_t[53][1024]");
	apply_type(0x00C5DF88, "CGxDevice*");
}
