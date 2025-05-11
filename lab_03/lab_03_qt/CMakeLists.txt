cmake_minimum_required(VERSION 3.31)
project(lab_03_qt)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab_03_qt main.cpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Links/Links.cpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Links/Links.hpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Links/LinksIterator.hpp
        src/Exceptions/BaseException.hpp
        src/Exceptions/Figure/LinksException.hpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.cpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp
        src/Exceptions/Figure/PointsException.hpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/PointsIterator.hpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/FigureLP/FigureLP.cpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/FigureLP/FigureLP.hpp
        src/BaseObject/Figure/ConcreteFigure/BaseConcreteFigure.hpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/ConcreteFigureLP.cpp
        src/BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/ConcreteFigureLP.hpp
        src/BaseObject/Figure/Figure.cpp
        src/BaseObject/Figure/Figure.hpp
        src/Transforms/Transforms.cpp
        src/Transforms/Transforms.hpp
        src/BaseObject/BaseObject.cpp
        src/BaseObject/BaseObject.hpp
        src/BaseObject/Composite/CompositeObject.cpp
        src/BaseObject/Composite/CompositeObject.hpp
        src/BaseObject/Camera/Camera.cpp
        src/BaseObject/Camera/Camera.hpp
        src/Exceptions/BaseObject/CompositeException.hpp
        src/Scene/Scene/Scene.cpp
        src/Scene/Scene/Scene.hpp
        src/Scene/BaseScene.hpp
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui
        src/Exceptions/Scene/SceneException.hpp
)

target_link_libraries(lab_03_qt
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

