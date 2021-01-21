cmake_minimum_required(VERSION 3.17)
project(ex_1_hello_world CXX)

add_executable(ex_1_hello_world main.cpp)
target_compile_features(ex_1_hello_world PUBLIC cxx_std_17)

install(TARGETS ex_1_hello_world
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex01/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex01/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex01/lib)

##########
#include(CTest)

#add_test(NAME run-dynamic
#         COMMAND hello-bin-dynamic)