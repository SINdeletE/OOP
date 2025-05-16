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
        src/Managers/SceneManager/Scene/Scene/Scene.cpp
        src/Managers/SceneManager/Scene/Scene/Scene.hpp
        src/Managers/SceneManager/Scene/BaseScene.hpp
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui
        src/Exceptions/Scene/SceneException.hpp
        src/Managers/SceneManager/SceneManager.cpp
        src/Managers/SceneManager/SceneManager.hpp
        src/Managers/BaseManager.hpp
        src/Managers/SceneManager/History/BaseHistory.hpp
        src/Managers/SceneManager/History/History.cpp
        src/Managers/SceneManager/History/History.hpp
        src/Action/BaseAction.hpp
        src/Action/FigureAction/FigureAction.hpp
        src/Action/FigureAction/Draw/FigureActionDraw.cpp
        src/Action/FigureAction/Draw/FigureActionDraw.hpp
        src/Action/FigureAction/Move/FigureActionMove.cpp
        src/Action/FigureAction/Move/FigureActionMove.hpp
        src/Action/FigureAction/Rotate/FigureActionRotate.cpp
        src/Action/FigureAction/Rotate/FigureActionRotate.hpp
        src/Action/FigureAction/Scale/FigureActionScale.cpp
        src/Action/FigureAction/Scale/FigureActionScale.hpp
        src/Action/FigureAction/ZBuffer/FigureActionZBuffer.cpp
        src/Action/FigureAction/ZBuffer/FigureActionZBuffer.hpp
        src/Action/CameraAction/CameraAction.hpp
        src/Action/CameraAction/Move/CameraActionMove.cpp
        src/Action/CameraAction/Move/CameraActionMove.hpp
        src/Action/CameraAction/Rotate/CameraActionRotate.cpp
        src/Action/CameraAction/Rotate/CameraActionRotate.hpp
        src/Action/CameraAction/Set/CameraActionSet.cpp
        src/Action/CameraAction/Set/CameraActionSet.hpp
        src/Facade/Facade.cpp
        src/Facade/Facade.hpp
        src/Builders/BaseBuilder.hpp
        src/Factory/BaseFactory.hpp
        src/Factory/ManagerFactory/ManagerFactory.cpp
        src/Factory/ManagerFactory/ManagerFactory.hpp
        src/Factory/ManagerFactory/ManagerFactoryInterface.hpp
        src/Exceptions/Factory/ManagerFactoryException.hpp
        src/Exceptions/Facade/FacadeException.hpp
        src/Commands/BaseCommand.hpp
        src/Managers/LoadManager/LoadManager.cpp
        src/Managers/LoadManager/LoadManager.hpp
        src/Managers/DrawManager/DrawManager.cpp
        src/Managers/DrawManager/DrawManager.hpp
        src/Managers/TransformManager/TransformManager.cpp
        src/Managers/TransformManager/TransformManager.hpp
        src/Builders/Directors/BaseDirector.hpp
        src/Builders/Readers/BaseReader.hpp
        src/Builders/Readers/LPReaders/BaseLPReader.hpp
        src/Builders/Readers/LPReaders/txt/TXTLPReader.cpp
        src/Builders/Readers/LPReaders/txt/TXTLPReader.hpp
        src/Exceptions/Reader/ReaderException.hpp
        src/Builders/Readers/LPReaders/LPReaderSolution.cpp
        src/Builders/Readers/LPReaders/LPReaderSolution.hpp
        src/Exceptions/Factory/ReaderFactoryException.hpp
        src/Builders/Directors/DirectorSolution.cpp
        src/Builders/Directors/DirectorSolution.hpp
        src/Builders/Directors/FigureDirector/FigureLPDirector.cpp
        src/Builders/Directors/FigureDirector/FigureLPDirector.hpp
        src/Builders/Readers/LPReaders/LPReaderCreator.hpp
        src/Builders/Directors/DirectorCreator.hpp
        src/Exceptions/Directors/DirectorException.hpp
        src/Builders/Builders/FigureLPBuilder/BaseFigureLPBuilder.hpp
        src/Builders/Builders/FigureLPBuilder/FigureLPBuilder.cpp
        src/Builders/Builders/FigureLPBuilder/FigureLPBuilder.hpp
        src/Exceptions/Builders/BuildersException.hpp
)

target_link_libraries(lab_03_qt
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

