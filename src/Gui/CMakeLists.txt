# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
# Find the QtWidgets library
find_package(Qt5 COMPONENTS REQUIRED Core Widgets  )

include_directories(
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
)


add_library(gui_lib
    RegisterMachineGui.cpp
    RegisterMachineGui.h

    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
)


target_link_libraries(gui_lib
    Qt5::Widgets
    Qt5::Core
)
