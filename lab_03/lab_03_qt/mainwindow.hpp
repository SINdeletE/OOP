//
// Created by nuelex on 11/05/25.
//

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

private:
    Ui::mainwindow *ui;
};


#endif //MAINWINDOW_HPP
