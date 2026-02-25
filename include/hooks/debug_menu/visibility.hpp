#pragma once
#include "position.hpp"

namespace hooks::debug_menu {
    static constexpr int visible = 78;

    inline void hideObject(void* p) {
        if (!p) return;
        *ptr(p, visible) = 0;
        setXY(p, 9999.f, 9999.f);
    }

    inline void showObject(void* p, float x = 0.f, float y = 0.f) {
        if (!p) return;
        setXY(p, x, y);
        *ptr(p, visible) = 1;
    }
}