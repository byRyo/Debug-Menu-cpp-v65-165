#include <jni.h>
#include <pthread.h>
#include <utils/memory.hpp>
#include <libg/addresses.hpp>
#include <libg/functions.hpp>
#include <hooks/debug_menu/debug_menu.hpp>
#include <dobby.hpp>

void* hack_thread(void*) 
{
    utils::memory::wait_for_lib("libg.so");

    libg::addresses::init();
    libg::functions::init();

    DobbyHook(
        (void*)libg::addresses::ResourceListener_addFile,
        (void*)&hooks::debug_menu::hk_ResourceListener_addFile,
        (void**)&hooks::debug_menu::orig_ResourceListener_addFile
    );

    DobbyHook(
        (void*)libg::addresses::CustomButton_buttonPressed,
        (void*)&hooks::debug_menu::hk_CustomButton_buttonPressed,
        (void**)&hooks::debug_menu::orig_CustomButton_buttonPressed
    );

    return nullptr;
}

__attribute__((constructor))
void init() 
{
    pthread_t t;
    pthread_create(&t, nullptr, hack_thread, nullptr);
    pthread_detach(t);

}
