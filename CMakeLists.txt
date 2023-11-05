cmake_minimum_required(VERSION 3.16)
project(t)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(enable_testing TRUE)

if(${enable_testing})
    message("Testing Mode On")
else()
    message("Testing Mode Off")
endif()

set_property(GLOBAL PROPERTY CMAKE_CXX_COMPILER_LAUNCHER ccache)

include_directories(${PROJECT_SOURCE_DIR}/header)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if(${enable_testing})
	add_subdirectory(test)
endif()
