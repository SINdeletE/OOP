//
// Created by nuelex on 11/05/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.hpp"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
}

mainwindow::~mainwindow() {
    delete ui;
}
