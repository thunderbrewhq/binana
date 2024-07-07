# binana

This repository hosts some work related to studying the original game binaries.

You can use the information here to get a headstart when working on the [Whoa project](https://github.com/whoahq/whoa).

# Header files

To make reverse engineering easier, C header files matching the original memory layout are provided.

## Importing headers

To use these headers in Ghidra,

  1. go to `File` > `Parse C Source...`. 
  2. Select `clib.prf` as your parse configuration, and clear all source files and input paths.
  3. Add the header `<game version>/include/main.h` to the `Source files to parse` combo box.
  4. press `Parse to Program`.

TODO: equivalent guide for IDA Pro.

## Maintaining headers

Headers should be restricted at all times to the C programming language only. C++ syntax will break type analysis.

To convert C++ namespaces, use double-underscores. For instance:

```cpp
void Name::Space::Thing();
```

should become:

```c
void Name__Space__Thing();
```

# Symbol files

Symbol files are text files that map function names and data labels to addresses. 