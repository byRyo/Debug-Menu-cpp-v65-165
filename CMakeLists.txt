cmake_minimum_required(VERSION 3.22.1)
project("Heavy Hook")

add_library(hook SHARED main.cpp)

target_include_directories(hook PRIVATE include)

target_compile_options(hook PRIVATE -std=c++17)

add_library(dobby STATIC IMPORTED)
set_target_properties(dobby PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}/libdobby.a)

target_link_libraries(hook dobby log)