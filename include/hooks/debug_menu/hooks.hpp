#pragma once
#include <unistd.h>
#include <pthread.h>
#include <android/log.h>
#include "data.hpp"
#include "buttons.hpp"
#include "menu.hpp"
#include "category.hpp"
#include "string_ptr.hpp"
#include "libg/functions.hpp"

#define LOG_TAG "Heavy-Hook"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

namespace hooks::debug_menu 
{
    inline void (*orig_ResourceListener_addFile)(void*, void*, void*) = nullptr;
    inline void hk_ResourceListener_addFile(void* self, void* file, void* listener) 
    {
        if (orig_ResourceListener_addFile)
            orig_ResourceListener_addFile(self, file, listener);

        static bool fired = false;
        if (!fired) 
        {
            fired = true;
            LOGI("sc/debug.sc injected");
            if (orig_ResourceListener_addFile)
                orig_ResourceListener_addFile(self, makeScPtr("sc/debug.sc"), listener);
            struct Tmp { static void* run(void*) 
                {
                usleep(9999999);
                createDButton();
                return nullptr;
            }};
            pthread_t t;
            pthread_create(&t, nullptr, Tmp::run, nullptr);
            pthread_detach(t);
        }
    }

    inline void (*orig_CustomButton_buttonPressed)(void*) = nullptr;
    inline void hk_CustomButton_buttonPressed(void* self) 
    {
        if (self == g_dButton) 
        {
            g_menuOpened ? removeMenu() : openMenu();
            g_menuOpened = !g_menuOpened;
            return;
        }
        for (auto& c : g_categories) 
        {
            if (self == c.ins) {
                openCategory(c.name);
                return;
            }
        }
        orig_CustomButton_buttonPressed(self);
    }
}
