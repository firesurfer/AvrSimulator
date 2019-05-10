enable_testing()
find_package(GTest)

if(NOT ${GTEST_FOUND})
    MESSAGE("Did not find googletest - not building tests")
    #return()
endif()

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/avr)

add_executable(HeaderFileParser_Test HeaderFileParser_Test.cpp)
target_link_libraries(HeaderFileParser_Test
    avr
    Boost::filesystem
)
