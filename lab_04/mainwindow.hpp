//
// Created by nuelex on 27/05/25.
//

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "./src/ElevatorSystem.hpp"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_B1_UP_clicked();

    void on_B2_UP_clicked();
    void on_B2_DOWN_clicked();

    void on_B3_UP_clicked();
    void on_B3_DOWN_clicked();

    void on_B4_UP_clicked();
    void on_B4_DOWN_clicked();

    void on_B5_DOWN_clicked();

    // -----------------------------------------

    void on_E1_1_clicked();
    void on_E2_1_clicked();
    void on_E3_1_clicked();
    void on_E4_1_clicked();
    void on_E5_1_clicked();

signals:
    void floorButtonClicked(int floor, Direction direction);
    void elevatorButtonClicked(int floor);

private:
    Ui::MainWindow *ui;
    ElevatorSystem _system{};
};

#endif //MAINWINDOW_HPP
