# binana

This repository hosts some work related to studying the original game binaries.

You can use the information here to get a headstart when working on the [Whoa project](https://github.com/whoahq/whoa).

# Header files

To make reverse engineering easier, C header files matching the original memory layout are provided.

The header `<game version>/include/main.h` to import type definitions into your analysis repository.

Headers should be restricted at all times to the C programming language only. C++ syntax will break type analysis.

To convert C++ namespaces, use double-underscores. For instance:

```cpp
void Name::Space::Thing();
```

should become:

```c
void Name__Space__Thing();
```
