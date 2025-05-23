//
// Created by nuelex on 11/05/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.hpp"

#include <iostream>
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

#include "consts.hpp"
#include "src/Commands/CameraCommand/Move/CameraCommandMove.hpp"
#include "src/Commands/CameraCommand/Remove/CameraRemoveCommand.hpp"
#include "src/Commands/CameraCommand/Rotate/CameraCommandRotate.hpp"
#include "src/Commands/CameraCommand/Set/CameraSetCommand.hpp"
#include "src/Commands/FigureCommand/Move/FigureCommandMove.hpp"
#include "src/Commands/FigureCommand/Remove/FigureRemoveCommand.hpp"
#include "src/Commands/FigureCommand/Rotate/FigureCommandRotate.hpp"
#include "src/Commands/FigureCommand/Scale/FigureCommandScale.hpp"
#include "src/Exceptions/Managers/DrawManagerException.hpp"


mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainwindow), scene(nullptr)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setFrameShape(QFrame::NoFrame);

    try
    {
        this->objectTableInit();
        this->cameraTableInit();

        auto scene = new QGraphicsScene(ui->graphicsView);
        scene->setSceneRect(-HALF_SCENE_WIDTH, -HALF_SCENE_HEIGHT, HALF_SCENE_WIDTH, HALF_SCENE_HEIGHT);
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

        this->redraw();

        _objectTable->pushItem(QFileInfo(fileName).baseName());
    }
}

void mainwindow::redraw() const
{
    this->clean();

    try
    {
        this->draw();
    }
    catch (ErrorDrawManager_invalid_draw &e)
    {
        ;
    }
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

        this->redraw();

        _cameraTable->pushItem(QFileInfo(fileName).baseName());
    }
}

void mainwindow::objectTableInit()
{
    auto table = new QTableWidget();
    table->setColumnCount(1);
    table->setColumnWidth(0, 379);

    table->setUpdatesEnabled(true);
    QStringList columnNames = {"Object name"};
    table->setHorizontalHeaderLabels(columnNames);

    QVBoxLayout* layout = new QVBoxLayout(ui->ObjectContainer);
    layout->addWidget(table);
    ui->ObjectContainer->setLayout(layout);

    _objectTable = std::make_unique<Table>(table);
}

void mainwindow::cameraTableInit()
{
    auto table = new QTableWidget();
    table->setColumnCount(1);
    table->setColumnWidth(0, 379);

    table->setUpdatesEnabled(true);
    QStringList columnNames = {"Camera name"};
    table->setHorizontalHeaderLabels(columnNames);

    QVBoxLayout* layout = new QVBoxLayout(ui->CameraContainer);
    layout->addWidget(table);
    ui->CameraContainer->setLayout(layout);

    _cameraTable = std::make_unique<Table>(table);
}

void mainwindow::on_DeleteObjectButton_clicked() const
{
    const auto id = _objectTable->selectedItem();

    if (id != -1)
    {
        FigureRemoveCommand command{static_cast<size_t>(id)};

        _facade->execute(command);

        _objectTable->removeItem(id);

        this->redraw();
    }
}

void mainwindow::on_DeleteCameraButton_clicked() const
{
    const auto id = _cameraTable->selectedItem();

    if (id != -1)
    {
        CameraRemoveCommand command{static_cast<size_t>(id)};

        _facade->execute(command);

        _cameraTable->removeItem(id);

        this->redraw();
    }
}

std::shared_ptr<Mover> mainwindow::moverFromGUI() const
{
    Point center{};
    std::shared_ptr<Mover> result = nullptr;
    bool flag = true;

    double dy, dz;

    double dx = ui->LineEditDx->text().toDouble(&flag);
    if (flag)
    {
        dy = ui->LineEditDy->text().toDouble(&flag);

        if (flag)
        {
            dz = ui->LineEditDz->text().toDouble(&flag);
        }
    }

    if (flag)
    {
        result = std::make_shared<Mover>(dx, dy, dz, center);
    }

    return result;
}

void mainwindow::on_MoveButton_clicked() const
{
    const auto id = _objectTable->selectedItem();
    auto mover = this->moverFromGUI();

    if (mover != nullptr && id != -1)
    {
        FigureCommandMove transform{static_cast<size_t>(id), mover};

        _facade->execute(transform);

        this->redraw();
    }
}

std::shared_ptr<Point> mainwindow::centerFromGUI() const
{
    std::shared_ptr<Point> result = nullptr;
    bool flag = true;

    double y, z;
    double x = ui->LineEditX->text().toDouble(&flag);
    if (flag)
    {
        y = ui->LineEditY->text().toDouble(&flag);

        if (flag)
        {
            z = ui->LineEditZ->text().toDouble(&flag);
        }
    }

    if (flag)
    {
        result = std::make_shared<Point>(x, y, z);
    }

    return result;
}

std::shared_ptr<Rotater> mainwindow::rotaterFromGUI() const
{
    bool flag = true;
    const std::shared_ptr<Point> center = this->centerFromGUI();

    if (center == nullptr)
        flag = false;

    double ox, oy, oz;

    if (flag)
    {
        ox = ui->LineEditOx->text().toDouble(&flag);

        if (flag)
        {
            oy = ui->LineEditOy->text().toDouble(&flag);

            if (flag)
            {
                oz = ui->LineEditOz->text().toDouble(&flag);
            }
        }
    }


    std::shared_ptr<Rotater> result = nullptr;
    if (flag)
    {
        result = std::make_shared<Rotater>(ox, oy, oz, *center);
    }

    return result;
}

std::shared_ptr<Scaler> mainwindow::scalerFromGUI() const
{
    bool flag = true;
    const std::shared_ptr<Point> center = this->centerFromGUI();

    if (center == nullptr)
        flag = false;

    double kx, ky, kz;

    if (flag)
    {
        kx = ui->LineEditKx->text().toDouble(&flag);

        if (flag)
        {
            ky = ui->LineEditKy->text().toDouble(&flag);

            if (flag)
            {
                kz = ui->LineEditKz->text().toDouble(&flag);
            }
        }
    }


    std::shared_ptr<Scaler> result = nullptr;
    if (flag)
    {
        result = std::make_shared<Scaler>(kx, ky, kz, *center);
    }

    return result;
}

void mainwindow::on_RotateButton_clicked() const
{
    const auto id = _objectTable->selectedItem();
    auto rotater = this->rotaterFromGUI();

    if (rotater != nullptr && id != -1)
    {
        FigureCommandRotate transform{static_cast<size_t>(id), rotater};

        _facade->execute(transform);

        this->redraw();
    }
}

void mainwindow::on_ScaleButton_clicked() const
{
    const auto id = _objectTable->selectedItem();
    auto scaler = this->scalerFromGUI();

    if (scaler != nullptr && id != -1)
    {
        FigureCommandScale transform{static_cast<size_t>(id), scaler};

        _facade->execute(transform);

        this->redraw();
    }
}

void mainwindow::on_SetCameraButton_clicked() const
{
    const auto id = _cameraTable->selectedItem();

    if (id != -1)
    {
        CameraSetCommand command{static_cast<size_t>(id)};

        _facade->execute(command);

        this->redraw();
    }
}

std::shared_ptr<Mover> mainwindow::moverCamFromGUI() const
{
    Point center{};
    std::shared_ptr<Mover> result = nullptr;
    bool flag = true;

    double dy, dz;

    double dx = ui->LineEditDx_Cam->text().toDouble(&flag);
    if (flag)
    {
        dy = ui->LineEditDy_Cam->text().toDouble(&flag);

        if (flag)
        {
            dz = ui->LineEditDz_Cam->text().toDouble(&flag);
        }
    }

    if (flag)
    {
        result = std::make_shared<Mover>(dx, dy, dz, center);
    }

    return result;
}

std::shared_ptr<Rotater> mainwindow::rotaterCamFromGUI() const
{
    Point center{};
    std::shared_ptr<Rotater> result = nullptr;
    bool flag = true;

    double oy, oz;

    double ox = ui->LineEditOx_Cam->text().toDouble(&flag);
    if (flag)
    {
        oy = ui->LineEditOy_Cam->text().toDouble(&flag);

        if (flag)
        {
            oz = ui->LineEditOz_Cam->text().toDouble(&flag);
        }
    }

    if (flag)
    {
        result = std::make_shared<Rotater>(ox, oy, oz, center);
    }

    return result;
}

void mainwindow::on_MoveButton_Cam_clicked() const
{
    const auto id = _cameraTable->selectedItem();
    auto mover = this->moverCamFromGUI();

    if (mover != nullptr && id != -1)
    {
        CameraCommandMove transform{static_cast<size_t>(id), mover};

        _facade->execute(transform);

        this->redraw();
    }
}

void mainwindow::on_RotateButton_Cam_clicked() const
{
    const auto id = _cameraTable->selectedItem();
    auto rotater = this->rotaterCamFromGUI();

    if (rotater != nullptr && id != -1)
    {
        CameraCommandRotate transform{static_cast<size_t>(id), rotater};

        _facade->execute(transform);

        this->redraw();
    }
}

