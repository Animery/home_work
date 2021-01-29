cmake_minimum_required(VERSION 3.16)
project(02-sdl-dynamic)

#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
#execute_process(COMMAND /usr/local/bin/sdl2-config --cflags OUTPUT_VARIABLE SDL2_CFLAGS_INCLUDE)
#set(SDL2_CFLAGS_INCLUDE -I/usr/local/include/SDL2)
execute_process(COMMAND sdl2-config --libs OUTPUT_VARIABLE SDL2_CFLAGS_LIBS)

message("SDL2_CFLAGS_LIBS=${SDL2_CFLAGS_INCLUDE}")
message("SDL2_CFLAGS_LIBS=${SDL2_CFLAGS_LIBS}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 ${SDL2_CFLAGS_INCLUDE} ${SDL2_CFLAGS_LIBS}")

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)