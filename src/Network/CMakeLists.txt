find_package(Boost 1.58 REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Logger)

file(GLOB SRC_FILES_NETWORK ${CMAKE_CURRENT_SOURCE_DIR}/*.c*
				${CMAKE_CURRENT_SOURCE_DIR}/*.h*)

add_library(network_lib ${SRC_FILES_NETWORK})
target_link_libraries(network_lib ${Boost_LIBRARIES})
