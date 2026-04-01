cmake_minimum_required(VERSION 3.10)
project(binana_profile C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# This is the only way to get a non-empty compile_commands.json
add_library(binana_profile STATIC entry.c)
target_compile_definitions(binana_profile PUBLIC CLANGD=1)
target_precompile_headers(binana_profile PUBLIC include/system/detect.h include/system/types.h)
target_include_directories(binana_profile PRIVATE include)
