cmake_minimum_required(VERSION 3.16)
project(02-sdl-static)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

find_package(sdl2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2-static)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)
