cmake_minimum_required(VERSION 3.16)
project(02-sdl-static)

execute_process(COMMAND /usr/local/bin/sdl2-config --static-libs OUTPUT_VARIABLE SDL2_CFLAGS_LIBS)
message("SDL2_CFLAGS_LIBS=${SDL2_CFLAGS_LIBS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 ${SDL2_CFLAGS_LIBS}")

add_executable(${PROJECT_NAME} main.cpp)
#target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

#find_package(SDL2 REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2-static)



install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)
