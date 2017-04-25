add_subdirectory(Commands)
add_subdirectory(Periphery)
add_subdirectory(Logger)
add_subdirectory(Network)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Commands
    ${CMAKE_CUREENT_SOURCE_DIR}/Periphery
    ${CMAKE_CUREENT_SOURCE_DIR}/Logger
    ${CMAKE_CUREENT_SOURCE_DIR}/Network
)   


file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h*
                    ${CMAKE_CURRENT_SOURCE_DIR}/*.c*)
add_executable(register_machine ${SRC_FILES})

set_target_properties(register_machine
    PROPERTIES

    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_link_libraries(register_machine
    command_lib
    periph_lib
    logger_lib
    network_lib
    Threads::Threads
#qt core and network libs
  #      Qt5::Core
)
