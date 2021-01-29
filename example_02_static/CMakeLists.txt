cmake_minimum_required(VERSION 3.16)
project(02-sdl-static)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)


# The modern way, using cmake config files
#find_package(SDL2 REQUIRED)
#if(SDL2_FOUND)
#        message("yep SDL2_package")     
#        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2-static)
#
#        else()
#        include(FindPkgConfig)
#        pkg_search_module(SDL2 REQUIRED sdl2)
#        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2-static)
#endif(SDL2_FOUND)
       
find_library(SDL2_LIB libSDL2.a)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB} 
                -lm
                -ldl
                -ldbus-1
                -Wl,--no-undefined
                -lpthread
                )


# The trusty old way, using pkg-config
#include(FindPkgConfig)
#pkg_search_module(SDL2 REQUIRED sdl2)
#target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
#message("sdl2_lib =  $SDL2_LIBRARIES")

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)
