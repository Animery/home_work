cmake_minimum_required(VERSION 3.17)

project(ex_2_hello CXX)

add_subdirectory(hello_bin)
add_subdirectory(hello_lib)


##########
#include(CTest)

#add_test(NAME run-dynamic
#         COMMAND hello-bin-dynamic)

#add_test(NAME run-static
#         COMMAND hello-bin-static)
