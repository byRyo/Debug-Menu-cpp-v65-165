#pragma once
#include <cstdint>
#include "libg/addresses.hpp"

namespace libg::functions {
    using fn_getMovieClip = void*(*)(const char*, const char*);
    using fn_stringctor = void*(*)(void*, const char*);
    using fn_Stage_addChild = void*(*)(void*, void*);
    using fn_TextField_setText = void*(*)(void*, void*, bool);
    using fn_GameButton_GameButton = void(*)(void*);
    using fn_ResourceListener_addFile = void(*)(void*, void*, void*);
    using fn_dropGUIContainer = void(*)(void*, void*);
    using fn_movieClipsettext = void(*)(void*, const char*, void*);
    using fn_Sprite_Sprite = void(*)(void*, int);
    using fn_setPixelSnappedXY = void*(*)(void*, float, float);

    inline fn_getMovieClip StringTable_getMovieClip;
    inline fn_stringctor stringctor;
    inline fn_Stage_addChild Stage_addChild;
    inline fn_TextField_setText TextField_setText;
    inline fn_GameButton_GameButton GameButton_GameButton;
    inline fn_ResourceListener_addFile ResourceListener_addFile;
    inline fn_dropGUIContainer dropGUIContainer_DropGUIContainer;
    inline fn_movieClipsettext movieClipsettext;
    inline fn_Sprite_Sprite Sprite_Sprite;
    inline fn_setPixelSnappedXY DisplayObject_setPixelSnappedXY;

    inline void init() {
        StringTable_getMovieClip = (fn_getMovieClip) libg::addresses::StringTable_getMovieClip;
        stringctor = (fn_stringctor) libg::addresses::stringctor;
        Stage_addChild = (fn_Stage_addChild) libg::addresses::Stage_addChild;
        TextField_setText = (fn_TextField_setText) libg::addresses::TextField_setText;
        GameButton_GameButton = (fn_GameButton_GameButton) libg::addresses::GameButton_GameButton;
        ResourceListener_addFile = (fn_ResourceListener_addFile) libg::addresses::ResourceListener_addFile;
        dropGUIContainer_DropGUIContainer = (fn_dropGUIContainer) libg::addresses::dropGUIContainer_DropGUIContainer;
        movieClipsettext = (fn_movieClipsettext) libg::addresses::movieClipsettext;
        Sprite_Sprite = (fn_Sprite_Sprite) libg::addresses::Sprite_Sprite;
        DisplayObject_setPixelSnappedXY = (fn_setPixelSnappedXY) libg::addresses::DisplayObject_setPixelSnappedXY;
    }
}