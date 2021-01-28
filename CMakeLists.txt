cmake_minimum_required(VERSION 3.17)

project(home_work CXX)

add_subdirectory(example_01_1)
add_subdirectory(example_01_2)
add_subdirectory(example_02_dynamic)
add_subdirectory(example_02_static)

##########
include(CTest)

add_test(NAME runs-dynamic
         COMMAND hello-bin-dynamic)

add_test(NAME runs-static
         COMMAND hello-bin-static)

add_test(NAME runs-hello_world
         COMMAND ex_1_hello_world)
