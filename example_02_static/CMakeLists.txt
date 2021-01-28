cmake_minimum_required(VERSION 3.16)
project(02-sdl-static)

add_executable(02-sdl-static main.cpp)
target_compile_features(02-sdl-static PUBLIC cxx_std_17)

find_package(SDL2 REQUIRED)
target_include_directories(02-sdl-static PRIVATE ${SDL2_INCLUDE_DIRS})
find_library(SDL2_LIB libSDL2.a)

target_link_libraries(02-sdl-static
            ${SDL2_LIB} # full path to libSDL2.a force to staticaly link with it
            # -Wl,--no-undefined # not compiled on MacOS
               -lm
               -ldl
               -lpthread
               -lrt
               )

install(TARGETS 02-sdl-static
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)