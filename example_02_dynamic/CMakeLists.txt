cmake_minimum_required(VERSION 3.16)
project(02-sdl-dynamic)


#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

find_package(SDL2 REQUIRED)
#if(SDL2_FOUND)
         # The modern way, using cmake config files
#        message("yep SDL2_package")     
#        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)
#
#        else()
#        include(FindPkgConfig)
#        pkg_search_module(SDL2 REQUIRED sdl2)
#        target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)
#endif(SDL2_FOUND)

find_library(SDL2_LIB_dyn libSDL2-2.0.so.0)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_dyn}
                -lSDL2
                )

#find_package(SDL2 REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)

# The trusty old way, using pkg-config
#include(FindPkgConfig)
#pkg_search_module(SDL2 REQUIRED sdl2)
#target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)