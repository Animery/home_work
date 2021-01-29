cmake_minimum_required(VERSION 3.16)
project(02-sdl-dynamic)

#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
        message("SDL2 FOUND")
endif(SDL2_FOUND)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)