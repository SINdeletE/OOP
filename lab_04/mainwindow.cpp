//
// Created by nuelex on 27/05/25.
//

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &MainWindow::floorButtonClicked,
            &_system, &ElevatorSystem::handleFloorCall);
    connect(this, &MainWindow::elevatorButtonClicked,
            &_system, &ElevatorSystem::handleElevatorCall);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B1_UP_clicked()
{
    emit floorButtonClicked(1, UP);
}

void MainWindow::on_B2_UP_clicked()
{
    emit floorButtonClicked(2, UP);
}

void MainWindow::on_B2_DOWN_clicked()
{
    emit floorButtonClicked(2, DOWN);
}

void MainWindow::on_B3_UP_clicked()
{
    emit floorButtonClicked(3, UP);
}

void MainWindow::on_B3_DOWN_clicked()
{
    emit floorButtonClicked(3, DOWN);
}

void MainWindow::on_B4_UP_clicked()
{
    emit floorButtonClicked(4, UP);
}

void MainWindow::on_B4_DOWN_clicked()
{
    emit floorButtonClicked(4, DOWN);
}

void MainWindow::on_B5_DOWN_clicked()
{
    emit floorButtonClicked(5, DOWN);
}

void MainWindow::on_E1_1_clicked()
{
    emit elevatorButtonClicked(1);
}

void MainWindow::on_E2_1_clicked()
{
    emit elevatorButtonClicked(2);
}

void MainWindow::on_E3_1_clicked()
{
    emit elevatorButtonClicked(3);
}

void MainWindow::on_E4_1_clicked()
{
    emit elevatorButtonClicked(4);
}

void MainWindow::on_E5_1_clicked()
{
    emit elevatorButtonClicked(5);
}
