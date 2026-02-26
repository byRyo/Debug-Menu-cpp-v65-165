#pragma once
#include "data.hpp"
#include "position.hpp"
#include "visibility.hpp"
#include "buttons.hpp"
#include "libg/functions.hpp"

namespace hooks::debug_menu {
    inline void closeCategory(const std::string& category) 
    {
        g_openedCat = "";
        for (auto& b : g_buttons)
            if (b.cat == category) hideObject(b.ins);
    }

    inline void closeCategoryAndButtons() 
    {
        g_openedCat = "";
        for (auto& c : g_categories) hideObject(c.ins);
        for (auto& b : g_buttons) hideObject(b.ins);
        g_categories.clear();
        g_buttons.clear();
    }

    inline void openCategory(const std::string& category) 
    {
        if (g_openedCat == category) 
        {
            closeCategory(category); return; 
        }

        for (auto& c : g_categories)
            if (c.name != category) closeCategory(c.name);
        for (auto& b : g_buttons) hideObject(b.ins);

        g_openedCat = category;
        int y = 1;
        for (auto& b : g_buttons) 
        {
            if (b.cat != category) continue;
            Category* targetCat = nullptr;
            for (auto& c : g_categories)
                if (c.name == category) 
                {
                    targetCat = &c; break;
                }
            float catY = targetCat ? getY(targetCat->ins) : 100.f;
            showObject(b.ins, getX(g_debugMenu) - 150.f, catY + (y * 55.f));
            libg::functions::Stage_addChild(stagePtr(), b.ins);
            y++;
        }
    }
}
