//
// Created by nuelex on 11/05/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.hpp"

#include <QFileDialog>
#include "ui_mainwindow.h"
#include "src/Commands/CameraCommand/Add/CameraCommandAdd.hpp"
#include "src/Commands/DrawCommand/CleanCommand.hpp"
#include "src/Commands/DrawCommand/DrawCommand.hpp"
#include "src/Commands/FigureCommand/Add/FigureCommandAdd.hpp"
#include "src/Drawer/ColorParameters/RGBColor.hpp"
#include "src/Drawer/Directors/DrawerDirectorSolution.hpp"
#include "src/Drawer/Graphics/Qt/QtGraphicsScene.hpp"
#include <QWidget>


mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainwindow), scene(nullptr)
{
    ui->setupUi(this);

    try
    {
        this->objectTableInit();
        this->cameraTableInit();

        auto scene = new QGraphicsScene(ui->graphicsView);
        scene->setSceneRect(100, 100, 100, 100);
        ui->graphicsView->setScene(scene);

        const auto color = std::make_shared<RGBColor>(0, 0, 0);

        const auto gs = std::make_shared<QtGraphicsScene>(scene, ui->graphicsView);
        DrawerDirectorSolution solution{};
        const auto director = solution.createDrawerDirector(gs);
        _drawer = director->createDrawer(gs, color);

        _facade = std::make_unique<Facade>();

        this->initialization_check = true;
    }
    catch (...)
    {
        this->initialization_check = false;
    }
}

mainwindow::~mainwindow() {
    delete ui;

    delete _objectTable;
    delete _cameraTable;
}

void mainwindow::on_actionAdd_Object_triggered()
{
    const QString fileName = QFileDialog::getOpenFileName(this,
                                                tr("Open Figure File"),
                                                QDir::currentPath(),
                                                tr("Figure Files (*.txt)"));
    const QString relativePath = QDir().relativeFilePath(fileName.toUtf8().constData());
    if (! fileName.isEmpty())
    {
        FigureCommandAdd command{relativePath.toStdString()};

        _facade->execute(command);
    }

    this->redraw();
}

void mainwindow::redraw() const
{
    this->clean();
    this->draw();
}

void mainwindow::draw() const
{
    DrawCommand drawCommand{_drawer};

    _facade->execute(drawCommand);
}

void mainwindow::clean() const
{
    CleanCommand cleanCommand{_drawer};

    _facade->execute(cleanCommand);
}

void mainwindow::on_actionAdd_Camera_triggered()
{
    const QString fileName = QFileDialog::getOpenFileName(this,
                                                tr("Open Camera File"),
                                                QDir::currentPath(),
                                                tr("Camera Files (*.cmr)"));
    const QString relativePath = QDir().relativeFilePath(fileName.toUtf8().constData());
    if (! fileName.isEmpty())
    {
        CameraCommandAdd command{relativePath.toStdString()};

        _facade->execute(command);
    }

    this->redraw();
}

void mainwindow::objectTableInit()
{
    _objectTable = new QTableWidget();
    _objectTable->setColumnCount(2);
    _objectTable->setColumnWidth(0, 189);
    _objectTable->setColumnWidth(1, 189);

    _objectTable->setUpdatesEnabled(true);
    QStringList columnNames = {"ID", "Object name"};
    _objectTable->setHorizontalHeaderLabels(columnNames);

    QVBoxLayout* layout = new QVBoxLayout(ui->ObjectContainer);
    layout->addWidget(_objectTable);
    ui->ObjectContainer->setLayout(layout);
}

void mainwindow::cameraTableInit()
{
    _cameraTable = new QTableWidget();
    _cameraTable->setColumnCount(2);
    _cameraTable->setColumnWidth(0, 189);
    _cameraTable->setColumnWidth(1, 189);

    _cameraTable->setUpdatesEnabled(true);
    QStringList columnNames = {"ID", "Camera name"};
    _cameraTable->setHorizontalHeaderLabels(columnNames);

    QVBoxLayout* layout = new QVBoxLayout(ui->CameraContainer);
    layout->addWidget(_cameraTable);
    ui->CameraContainer->setLayout(layout);
}

