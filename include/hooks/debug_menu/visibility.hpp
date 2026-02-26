#pragma once
#include <cstdint>

namespace hooks::debug_menu 
{
    inline void setVisible(void* p, bool state) 
    {
        if (!p) return;

        *reinterpret_cast<int*>(
            reinterpret_cast<uint8_t*>(p) + 8
        ) = state ? 1 : 0;
    }

    inline void hideObject(void* p) 
    {
        setVisible(p, false);
    }

    inline void showObject(void* p) 
    {
        setVisible(p, true);
    }
}
