include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)
file(GLOB SRC_FILES_CMD ${CMAKE_CURRENT_SOURCE_DIR}/*.c*
                         ${CMAKE_CURRENT_SOURCE_DIR}/*.h*)
                         
add_library(command_lib ${SRC_FILES_CMD})
