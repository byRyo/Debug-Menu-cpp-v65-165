#pragma once
#include <cstring>

namespace hooks::debug_menu 
{
    static constexpr int pos_x = 32;
    static constexpr int pos_y = 36;
    static constexpr int Height = 16;
    static constexpr int Width = 28;

    inline uint8_t* ptr(void* p, int off) 
    {
        return reinterpret_cast<uint8_t*>(p) + off;
    }

    inline float getX(void* p) 
    {
        float v;
        memcpy(&v, ptr(p, pos_x), 4);
        return v; 
    }

    inline float getY(void* p) 
    {
        float v;
        memcpy(&v, ptr(p, pos_y), 4);
        return v; 
    }

    inline void setX(void* p, float v) 
    {
        memcpy(ptr(p, pos_x), &v, 4);
    }

    inline void setY(void* p, float v) 
    {
        memcpy(ptr(p, pos_y), &v, 4);
    }

    inline void setXY(void* p, float x, float y) 
    {
        setX(p, x); setY(p, y);
    }
    
    inline void setHW(void* p, float h, float w) 
    {
        memcpy(ptr(p, Height), &h, 4);
        memcpy(ptr(p, Width),  &w, 4);
    }
}
