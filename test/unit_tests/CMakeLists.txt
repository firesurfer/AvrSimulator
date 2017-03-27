enable_testing()
find_package(GTest REQUIRED)

if(NOT ${GTEST_FOUND})
    MESSAGE("Did not find googletest - not building tests")
    return()
endif()

include_directories(${CMAKE_SOURCE_DIR}/src)
