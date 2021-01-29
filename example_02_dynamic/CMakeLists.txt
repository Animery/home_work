cmake_minimum_required(VERSION 3.16)
project(02-sdl-dynamic)

#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

#find_package(SDL2 REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

#find specific lib
find_library(sdl2-dynamic-lib libSDL2-2.0.so.0)

#set pathes to headers
#target_include_directories(${PROJECT_NAME} 
#	PRIVATE ${SDL2_INCLUDE_DIRS} #SDL headers
#	PRIVATE ${PROJECT_BINARY_DIR} #for Configure.h
#)

#link with specific lib
target_link_libraries(${PROJECT_NAME} 
	${sdl2-dynamic-lib}
)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/bin
        LIBRARY DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib
        ARCHIVE DESTINATION ${CMAKE_CURRENT_LIST_DIR}/../tests/ex02/lib)