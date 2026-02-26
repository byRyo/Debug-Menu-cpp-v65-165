#pragma once
#include <cstdlib>
#include <android/log.h>
#include <pthread.h>
#include <unistd.h>
#include "data.hpp"
#include "position.hpp"
#include "visibility.hpp"
#include "string_ptr.hpp"
#include "libg/functions.hpp"
#include "libg/addresses.hpp"

#define LOG_TAG "Heavy-Hook"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

namespace hooks::debug_menu 
{
    inline void* stagePtr() 
    {
        return *reinterpret_cast<void**>(libg::addresses::stageInstance);
    }

    inline void setMovieClip(void* instance, void* movieClip) 
    {
        using fn_t = void(*)(void*, void*, bool);
        void** vtable = *reinterpret_cast<void***>(instance);
        auto fn = reinterpret_cast<fn_t>(vtable[352 / 8]);
        fn(instance, movieClip, true);
    }

    inline Category createCategory(const char* name) 
    {
        void* ins = malloc(544);
        libg::functions::GameButton_GameButton(ins);
        void* mc = libg::functions::StringTable_getMovieClip("sc/debug.sc", "debug_menu_category");
        setMovieClip(ins, mc);
        libg::functions::TextField_setText(ins, makeScPtr(name), true);
        return { ins, name };
    }

    inline Button createButton(const char* name, const char* cat) 
    {
        void* ins = malloc(544);
        libg::functions::GameButton_GameButton(ins);
        void* mc = libg::functions::StringTable_getMovieClip("sc/debug.sc", "debug_menu_item");
        setMovieClip(ins, mc);
        libg::functions::TextField_setText(ins, makeScPtr(name), true);
        return { ins, cat };
    }

    inline void createDButton() 
    {
        if (g_dButton) return;
        g_dButton = malloc(544);
        libg::functions::GameButton_GameButton(g_dButton);
        void* mc = libg::functions::StringTable_getMovieClip("sc/debug.sc", "debug_button");
        setMovieClip(g_dButton, mc);
        libg::functions::TextField_setText(g_dButton, makeScPtr("D"), true);
        setXY(g_dButton, 0.f, 560.f);
        setHW(g_dButton, 1.f, 1.f);
        *ptr(g_dButton, visible) = 1;
        libg::functions::Stage_addChild(stagePtr(), g_dButton);
    }

}
