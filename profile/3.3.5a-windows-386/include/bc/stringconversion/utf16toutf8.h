#ifndef BC_STRING_CONVERSION_UTF16_TO_UTF8_H
#define BC_STRING_CONVERSION_UTF16_TO_UTF8_H

DECLARE_STRUCT(Blizzard__StringConversion_UTF16ToUTF8__ToNative);

#include "bc/util/buffer.h"

// class Blizzard::UTF16ToUTF8::ToNative : Blizzard::Util::Buffer<300, wchar_t>
struct Blizzard__StringConversion_UTF16ToUTF8__ToNative {
    // Never ever use wchar_t!!!
    Blizzard__Util__Buffer_300_uint16_t _;
};

#endif
