#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

#include "action.h"
#include "scene.h"

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

private slots:
    void on_ImportButton_clicked();

    void on_RotateButton_clicked();

    void on_ScaleButton_clicked();

    void on_MoveButton_clicked();

private:
    Ui::MainWindow *ui;

    scene_t scene;
    action_t draw_action;
};
#endif // MAINWINDOW_H
