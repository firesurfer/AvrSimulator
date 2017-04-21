cmake_minimum_required(VERSION 3.5)
project(register_machine)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)


add_subdirectory(src)
add_subdirectory(test/unit_tests)
