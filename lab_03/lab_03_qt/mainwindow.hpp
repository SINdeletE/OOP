//
// Created by nuelex on 11/05/25.
//

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "src/Facade/Facade.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

    [[nodiscard]] bool init_check() const noexcept { return initialization_check; }

private slots:
    void on_actionAdd_from_file_triggered();

private:
    Ui::mainwindow *ui;

    bool initialization_check;
    std::unique_ptr<Facade> _facade;
};

#endif //MAINWINDOW_HPP
