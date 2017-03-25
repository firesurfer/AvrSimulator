add_subdirectory(Commands)
add_subdirectory(Periphery)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Commands
    ${CMAKE_CUREENT_SOURCE_DIR}/Periphery
)


file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h*
                    ${CMAKE_CURRENT_SOURCE_DIR}/*.c*)
add_executable(register_machine ${SRC_FILES})

target_link_libraries(register_machine
    command_lib
    periph_lib
    Threads::Threads
#qt core and network libs
  #      Qt5::Core
)
