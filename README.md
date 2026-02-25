# Debug Menu – C++ (v65.165)

Custom debug menu developed for Brawl Stars v65.165 (arm64-v8a).  
The framework is written entirely in C++ and demonstrates how in-game debug overlays and internal tooling can be implemented using low-level techniques.

---

## Project Overview

This is a fully homemade project built to explore runtime modification and internal tool development.

It showcases:

- Code injection using C++
- Hooking with Dobby
- Runtime memory interaction
- Custom overlay rendering
- Modular feature design

The entire project can be rewritten or adapted from scratch thanks to its clear structure.

---

## Architecture

The framework is structured into the following components:

- Core runtime abstraction layer  
- Hook management system  
- Memory utilities  
- UI / overlay renderer  
- Feature modules  

Each module is designed to remain isolated and extensible.

---

## Tools Used

- IDA Pro  
- Dobby (hooking library)  
- Offline Server v65.165  
  https://t.me/heavybrawl  

---

## Build

### Requirements

- Android NDK r21e  
- CMake v4.2.3  
- Ninja (recommended)

Downloads:

- NDK: https://developer.android.com/ndk/downloads/revision_history  
- CMake: https://cmake.org/download/  

### Build Steps

```bash
cd build

cmake .. -G "Ninja" ^
-DCMAKE_TOOLCHAIN_FILE=C:/Users/USERNAME/Downloads/android-ndk-r21e/build/cmake/android.toolchain.cmake ^
-DANDROID_ABI=arm64-v8a ^
-DANDROID_PLATFORM=android-21 ^
-DCMAKE_BUILD_TYPE=Release

cmake --build .

## Credits

- **BSD Brawl** – APK with Promon Shield removed
- **NBS Offline** – Assistance with Offline client build process  
- **@soufgameyt** – JNI configuration and project structure
