add_subdirectory(Commands)
add_subdirectory(Periphery)
add_subdirectory(Logger)
add_subdirectory(Network)
add_subdirectory(Gui)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Commands
    ${CMAKE_CURRENT_SOURCE_DIR}/Periphery
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger
    ${CMAKE_CURRENT_SOURCE_DIR}/Network
    ${CMAKE_CURRENT_SOURCE_DIR}/Gui
    ${CMAKE_CURRENT_SOURCE_DIR}/avr
)   


file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h*
                    ${CMAKE_CURRENT_SOURCE_DIR}/*.c*)
add_executable(register_machine ${SRC_FILES})

file(GLOB AVR_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/avr/*.h*
                     ${CMAKE_CURRENT_SOURCE_DIR}/avr/*.c*)
add_library(avr ${AVR_FILES})

set_target_properties(register_machine
    PROPERTIES

    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_link_libraries(register_machine
    avr
    command_lib
    periph_lib
    logger_lib
    network_lib
    Threads::Threads
    gui_lib
)
