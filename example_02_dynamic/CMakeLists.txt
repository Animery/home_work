cmake_minimum_required(VERSION 3.16)
project(02-sdl-dyn)



# Fedora - dnf install sdl2-devel sdl2-static
#set(SDL2_DIR /usr/local/lib/cmake/SDL2) # uncomment for local SDL2 build
find_package(SDL2 REQUIRED)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
add_executable(02-sdl-dynamic main.cpp)
target_compile_features(02-sdl-dynamic PUBLIC cxx_std_17)

#find_library(SDL2_LIB_D libSDL2-2.0.so.0)

#target_link_libraries(02-sdl-dynamic PRIVATE ${SDL2_LIB_D})
target_link_libraries(02-sdl-dynamic PRIVATE SDL2::SDL2 )

#target_link_libraries(02-sdl-dynamic PRIVATE SDL2::SDL2 SDL2::SDL2main)свю

install(TARGETS 02-sdl-dynamic
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)