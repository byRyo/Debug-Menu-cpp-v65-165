#pragma once
#include <cstdint>
#include "utils/memory.hpp"

namespace libg::addresses 
{
    inline uintptr_t StringTable_getMovieClip;
    inline uintptr_t stringctor;
    inline uintptr_t Stage_addChild;
    inline uintptr_t TextField_setText;
    inline uintptr_t GameButton_GameButton;
    inline uintptr_t ResourceListener_addFile;
    inline uintptr_t dropGUIContainer_DropGUIContainer;
    inline uintptr_t stageInstance;
    inline uintptr_t movieClipsettext;
    inline uintptr_t Sprite_Sprite;
    inline uintptr_t DisplayObject_setPixelSnappedXY;
    inline uintptr_t CustomButton_buttonPressed;

    inline void init() 
    {
        auto rebase = [](uintptr_t offset) 
        {
            return utils::memory::rebase("libg.so", offset);
        };
        dropGUIContainer_DropGUIContainer = rebase(0x56BD18); // v65
        StringTable_getMovieClip = rebase(0x94AD5C); // v65
        stringctor = rebase(0xB27390); // v65
        Stage_addChild = rebase(0x98B3F0); // v65
        TextField_setText = rebase(0x56AF00); // v65
        GameButton_GameButton = rebase(0x56A8B0); // v65
        ResourceListener_addFile = rebase(0x9EF38C); // v65
        stageInstance = rebase(0x1160FD8); // v65
        movieClipsettext = rebase(0x9A5750); // v65
        Sprite_Sprite = rebase(0x982794); // v65
        DisplayObject_setPixelSnappedXY = rebase(0x96D948); // v65
        CustomButton_buttonPressed = rebase(0x9A498C); // v65
    }
}
