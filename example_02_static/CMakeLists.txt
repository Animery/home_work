cmake_minimum_required(VERSION 3.16)
project(02-sdl-static)


add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

#find_package(SDL2 REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2-static)

#find SDL
#find_package(SDL2 REQUIRED)

#find specific lib
find_library(sdl2-static-lib1 libSDL2.a)
find_library(sdl2-static-lib2 libSDL2main.a)

message("path to static lib: ${sdl2-static-lib}")

#add pathes to include files
target_include_directories(${PROJECT_NAME} 
    PRIVATE ${SDL2_INCLUDE_DIRS} #SDL headers
    PUBLIC ${PROJECT_BINARY_DIR} #Configure.h
)

#link with specific libs
target_link_libraries(
        ${PROJECT_NAME}
        ${sdl2-static-lib1}
        ${sdl2-static-lib2}
        -Wl,--no-undefined 
        -lm
        -ldl
        -lpthread
        -lrt
        -lX11 
        -lXext 
        -lXcursor
        -lXinerama
        -lXi
        -lXrandr
        -lXss
        -lXxf86vm
        -lwayland-egl
        -lwayland-client
        -lwayland-cursor
        -lxkbcommon
        -lasound
        -lpulse-simple
        -lpulse
        )

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)
