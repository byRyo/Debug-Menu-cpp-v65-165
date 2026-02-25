#pragma once
#include <cstdlib>
#include "libg/functions.hpp"

namespace hooks::debug_menu {
    inline void* makeScPtr(const char* str) {
        void* mem = malloc(40);
        libg::functions::stringctor(mem, str);
        return mem;
    }
}