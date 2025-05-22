//
// Created by nuelex on 11/05/25.
//

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "src/Drawer/Drawer/BaseDrawer.hpp"
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
    void on_actionAdd_Object_triggered();
    void on_actionAdd_Camera_triggered();

private:
    Ui::mainwindow *ui;

    bool initialization_check;
    std::unique_ptr<Facade> _facade;
    std::shared_ptr<BaseDrawer> _drawer;

    void redraw();
    void draw();
    void clean();
};

#endif //MAINWINDOW_HPP
