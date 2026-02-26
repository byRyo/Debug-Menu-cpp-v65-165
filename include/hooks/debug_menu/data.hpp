#pragma once
#include <vector>
#include <string>

namespace hooks::debug_menu 
{
    struct Button 
    {
        void* ins; std::string cat; 
    };
    struct Category 
    { 
        void* ins; std::string name; 
    };

    inline void* g_debugMenu = nullptr;
    inline void* g_dButton = nullptr;
    inline bool g_menuOpened = false;
    inline std::string g_openedCat = "";
    inline std::vector<Category> g_categories;
    inline std::vector<Button> g_buttons;
}
