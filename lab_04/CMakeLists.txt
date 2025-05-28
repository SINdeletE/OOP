cmake_minimum_required(VERSION 3.31)
project(lab_04)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/nuelex/Qt/6.8.2/gcc_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab_04 main.cpp
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui
        src/Elevator/door/ElevatorDoor.cpp
        src/Elevator/door/ElevatorDoor.hpp
        src/Elevator/Elevator.cpp
        src/Elevator/Elevator.hpp
        src/Elevator/Controller/Controller.cpp
        src/Elevator/Controller/Controller.hpp
        src/consts.h
        src/ElevatorSystem.cpp
        src/ElevatorSystem.hpp
        src/Elevator/buttons/ElevatorButton.cpp
        src/Elevator/buttons/ElevatorButton.hpp
)
target_link_libraries(lab_04
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

