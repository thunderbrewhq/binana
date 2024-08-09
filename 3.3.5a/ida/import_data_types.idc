#include <idc.idc>

static import_data_types() {
  apply_type(0x004804F0, "void __cdecl func(EvtContext* context, EVENTID id, void* handler, void* param, float priority)");
  apply_type(0x004806A0, "int32_t __cdecl func(EvtContext* context, EVENTID id, void *data, size_t bytes)");
  apply_type(0x0076E540, "void* __stdcall func(uint32_t bytes, char* filename, int32_t linenumber, uint32_t flags)");
  apply_type(0x0076E5A0, "int32_t __stdcall func(void* ptr, char* filename, int32_t linenumber, uint32_t flags)");
  apply_type(0x0076E5E0, "void* __stdcall func(void* ptr, uint32_t bytes, char* filename, int32_t linenumber, uint32_t flags)");
  apply_type(0x0076F070, "int32_t __stdcall func(char* dest, size_t maxchars, char* format, ...)");
  apply_type(0x00774620, "SCritSect* __thiscall func(SCritSect* this)");
  apply_type(0x00774630, "void __thiscall func(SCritSect *this)");
  apply_type(0x00774640, "void __thiscall func(SCritSect *this)");
  apply_type(0x00774650, "void __thiscall func(SCritSect *this)");
  apply_type(0x00819EA0, "void __stdcall func(int32_t function, FrameScript_Object* object, int32_t args, char* args_fmt, FrameScript_EventObject* eventObject)");
  apply_type(0x00B417C8, "uint32_t");
  apply_type(0x00B417D0, "int32_t");
  apply_type(0x00B41850, "CDataRecycler");
  apply_type(0x00C26DF0, "CImVector[54][1024]");
}
