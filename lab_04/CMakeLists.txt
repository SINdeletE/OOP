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
)
target_link_libraries(lab_04
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

