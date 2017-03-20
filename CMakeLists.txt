cmake_minimum_required(VERSION 3.5)
project(register_machine)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package (Threads REQUIRED)


find_package(Qt5Core REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Qt5Core_INCLUDE_DIRS}
)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*
     ${CMAKE_CURRENT_SOURCE_DIR}/src/Commands/*.h*
      ${CMAKE_CURRENT_SOURCE_DIR}/src/Commands/*.c*)

message(${SRC_FILES})
add_executable(register_machine_exec ${SRC_FILES})

target_link_libraries(register_machine_exec
    Threads::Threads
#qt core and network libs
        Qt5::Core
)
