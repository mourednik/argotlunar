# Argotlunar

<img src="argotlunar.png" width="780" height="225" />

Granulator plugin for AudioUnit / VST hosts.

Licensed under GPLv2

[http://argotlunar.info](http://argotlunar.info)

## Build Instructions

Requirements:
* CMake 3.15
* SDL2

```bash
cd /path/to/argotlunar
cmake . -B cmake-build -DCMAKE_BUILD_TYPE=Release
cmake --build cmake-build --target all 
```