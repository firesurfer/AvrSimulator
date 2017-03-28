include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)
file(GLOB SRC_FILES_LOG ${CMAKE_CURRENT_SOURCE_DIR}/*.c*
                         ${CMAKE_CURRENT_SOURCE_DIR}/*.h*)
                         
add_library(logger_lib ${SRC_FILES_LOG})

