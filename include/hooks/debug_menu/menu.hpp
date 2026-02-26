#pragma once
#include <cstdlib>
#include "data.hpp"
#include "position.hpp"
#include "visibility.hpp"
#include "string_ptr.hpp"
#include "buttons.hpp"
#include "category.hpp"
#include "libg/functions.hpp"
#include "libg/addresses.hpp"

namespace hooks::debug_menu 
{
    inline void initMenu(void* instance) 
    {
        libg::functions::Sprite_Sprite(instance, 1);
        void* mc = libg::functions::StringTable_getMovieClip("sc/debug.sc", "debug_menu");
        libg::functions::dropGUIContainer_DropGUIContainer(instance, mc);
        setHW(instance, 1.f, 1.f);
        hideObject(instance);
        libg::functions::Stage_addChild(stagePtr(), instance);
    }

    inline void setTitle(void* instance, const char* title) 
    {
        libg::functions::movieClipsettext(instance, "title", makeScPtr(title));
    }

    inline void removeMenu() 
    {
        closeCategoryAndButtons();
        hideObject(g_debugMenu);
        g_debugMenu = nullptr;
        g_menuOpened = false;
    }

    inline void openMenu() 
    {
        if (!g_debugMenu) 
        {
            g_debugMenu = malloc(1000);
            initMenu(g_debugMenu);
            setTitle(g_debugMenu, "Debug Menu");

            g_categories.push_back(createCategory("Hack"));
            g_categories.push_back(createCategory("Misc"));
            g_categories.push_back(createCategory("Visual"));
            g_categories.push_back(createCategory("Brawler"));

            g_buttons.push_back(createButton("Dodge", "Hack"));
            g_buttons.push_back(createButton("Aimbot", "Hack"));
            g_buttons.push_back(createButton("Autoshoot", "Hack"));
            g_buttons.push_back(createButton("Spin", "Hack"));

            g_buttons.push_back(createButton("Team Spam", "Misc"));
            g_buttons.push_back(createButton("Club Spam", "Misc"));
            g_buttons.push_back(createButton("Send Empty Emote", "Misc"));

            g_buttons.push_back(createButton("Next Camera Mode", "Visual"));
            g_buttons.push_back(createButton("Remove Outline", "Visual"));
            
            g_buttons.push_back(createButton("Dyna Jump", "Brawler"));
        }

        void* stage = stagePtr();
        float v1 = 0.1f;
        float v2 = *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(stage) + 88);
        float v3 = *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(stage) + 84);
        float stageScale = *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(stage) + 7232);
        if (stageScale != 0.f) v1 = stageScale;
        int   v4 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(stage) + 7376);
        float proVal = v4 - (v3 + v2) / v1;

        *ptr(g_debugMenu, visible) = 1;
        libg::functions::DisplayObject_setPixelSnappedXY(g_debugMenu, proVal, 0.f);
        libg::functions::Stage_addChild(stage, g_debugMenu);

        int y = 0;
        for (auto& c : g_categories) 
        {
            showObject(c.ins, getX(g_debugMenu) - 150.f, (y * 55.f) + 100.f);
            libg::functions::Stage_addChild(stage, c.ins);
            y++;
        }
        for (auto& b : g_buttons) 
        {
            if (b.cat.empty()) 
            {
                showObject(b.ins, getX(g_debugMenu) - 150.f, (y * 55.f) + 100.f);
                libg::functions::Stage_addChild(stage, b.ins);
                y++;
            }
        }
    }
}
