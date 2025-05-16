//
// Created by nuelex on 11/05/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.hpp"

#include <QFile>
#include <QFileDialog>
#include "ui_mainwindow.h"
#include "src/Exceptions/Facade/FacadeException.hpp"


mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    try
    {
        _facade = std::make_unique<Facade>(Facade());
        this->initialization_check = true;
    }
    catch (ErrorFacade_bad_alloc &e)
    {
        this->initialization_check = false;
    }
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::on_actionAdd_from_file_triggered()
{
    QFile objectFile = QFileDialog::getOpenFileName(this, tr("Open File"), \
                                                    QDir::currentPath(), tr("*.txt (*.txt)"));
}

void mainwindow::on_actionAdd_Scene_triggered()
{
    QFile objectFile = QFileDialog::getOpenFileName(this, tr("Open File"), \
                                                    QDir::currentPath(), tr("*.txt (*.txt)"));
}
