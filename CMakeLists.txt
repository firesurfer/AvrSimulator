cmake_minimum_required(VERSION 3.5)
project(register_machine)

set (CMAKE_CXX_STANDARD 14)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)


add_subdirectory(src)
add_subdirectory(test/unit_tests)
