//
// Created by nuelex on 11/05/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.hpp"

#include <iostream>
#include <QFile>
#include <QFileDialog>
#include "ui_mainwindow.h"
#include "src/Commands/CameraCommand/Add/CameraCommandAdd.hpp"
#include "src/Commands/DrawCommand/CleanCommand.hpp"
#include "src/Commands/DrawCommand/DrawCommand.hpp"
#include "src/Commands/FigureCommand/Add/FigureCommandAdd.hpp"
#include "src/Drawer/ColorParameters/RGBColor.hpp"
#include "src/Drawer/Directors/DrawerDirectorSolution.hpp"
#include "src/Drawer/Graphics/Qt/QtGraphicsScene.hpp"
#include "src/Exceptions/Facade/FacadeException.hpp"


mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    try
    {
        auto new_scene = new QGraphicsScene(ui->graphicsView);
        ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        ui->graphicsView->setScene(new_scene);

        const auto color = std::make_shared<RGBColor>(255, 255, 255);

        const auto gs = std::make_shared<QtGraphicsScene>(new_scene, ui->graphicsView);
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
        std::cout << "0_0" << std::endl;
    }

    this->redraw();
}

void mainwindow::redraw()
{
    this->clean();
    this->draw();
}

void mainwindow::draw()
{
    DrawCommand drawCommand{_drawer};

    _facade->execute(drawCommand);
}

void mainwindow::clean()
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
        std::cout << "0_0" << std::endl;
    }

    this->redraw();
}
