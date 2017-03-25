include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)
file(GLOB SRC_FILES_PERIPH ${CMAKE_CURRENT_SOURCE_DIR}/*.c*
                         ${CMAKE_CURRENT_SOURCE_DIR}/*.h*)
                         
add_library(periph_lib ${SRC_FILES_PERIPH})
