#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <cstdio>
#include <cstdbool>

#include "error.h"
#include "operation.h"
#include "action.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    err_t res = ERR_NONE;

    res = scene_init(this->scene, ui->graphicsView);
    if (res)
        throw std::runtime_error("Ошибка создания сцены");
    else
    {
        scene_configure(this->scene, ui->graphicsView);

        draw_action_init(this->draw_action, this->scene);
    }
}

MainWindow::~MainWindow()
{
    action_t action;

    action.process = FREE_MODEL;
    action_perform(action);

    delete ui;
}

void draw_action_init(action_t &action, scene_t &scene)
{
    action.process = DRAW_MODEL;
    action.scene = &scene;
}

void action_filename_read(action_t &action, Ui::MainWindow *ui)
{
    action.filename = ui->ImportFilename->text().toUtf8().constData();
}

err_t action_move_read_data(move_t &move, Ui::MainWindow *ui)
{
    err_t res = ERR_NONE;
    bool convert_res;

    move.dx = ui->MoveEditX->text().toDouble(&convert_res);

    if (! convert_res)
        res = ERR_ACTION_INVALID_ENTERED_DATA;
    else
    {
        move.dy = ui->MoveEditY->text().toDouble(&convert_res);

        if (! convert_res)
            res = ERR_ACTION_INVALID_ENTERED_DATA;
        else
        {
            move.dz = ui->MoveEditZ->text().toDouble(&convert_res);

            if (! convert_res)
                res = ERR_ACTION_INVALID_ENTERED_DATA;
        }
    }

    return res;
}

err_t action_move_read(action_t &action, Ui::MainWindow *ui)
{
    err_t res = ERR_NONE;

    res = action_move_read_data(action.move, ui);

    return res;
}

err_t action_center_read_data(scale_t &scale, Ui::MainWindow *ui)
{
    point_t &center = scale.center;

    err_t res = ERR_NONE;
    bool convert_res;

    center.x = ui->CenterEditX->text().toDouble(&convert_res);

    if (! convert_res)
        res = ERR_ACTION_INVALID_ENTERED_DATA;
    else
    {
        center.y = ui->CenterEditY->text().toDouble(&convert_res);

        if (! convert_res)
            res = ERR_ACTION_INVALID_ENTERED_DATA;
        else
        {
            center.z = ui->CenterEditZ->text().toDouble(&convert_res);

            if (! convert_res)
                res = ERR_ACTION_INVALID_ENTERED_DATA;
        }
    }

    return res;
}

err_t action_scale_read_data(scale_t &scale, Ui::MainWindow *ui)
{
    err_t res = ERR_NONE;
    bool convert_res;

    scale.kx = ui->ScaleEditX->text().toDouble(&convert_res);

    if (! convert_res)
        res = ERR_ACTION_INVALID_ENTERED_DATA;
    else
    {
        scale.ky = ui->ScaleEditY->text().toDouble(&convert_res);

        if (! convert_res)
            res = ERR_ACTION_INVALID_ENTERED_DATA;
        else
        {
            scale.kz = ui->ScaleEditZ->text().toDouble(&convert_res);

            if (! convert_res)
                res = ERR_ACTION_INVALID_ENTERED_DATA;
        }
    }

    return res;
}

err_t action_scale_read(action_t &action, Ui::MainWindow *ui)
{
    err_t res = ERR_NONE;

    res = action_scale_read_data(action.scale, ui);

    if (res == ERR_NONE)
        res = action_center_read_data(action.scale, ui);

    return res;
}

err_t action_center_read_data(rotate_t &rotate, Ui::MainWindow *ui)
{
    point_t &center = rotate.center;

    err_t res = ERR_NONE;
    bool convert_res;

    center.x = ui->CenterEditX->text().toDouble(&convert_res);

    if (! convert_res)
        res = ERR_ACTION_INVALID_ENTERED_DATA;
    else
    {
        center.y = ui->CenterEditY->text().toDouble(&convert_res);

        if (! convert_res)
            res = ERR_ACTION_INVALID_ENTERED_DATA;
        else
        {
            center.z = ui->CenterEditZ->text().toDouble(&convert_res);

            if (! convert_res)
                res = ERR_ACTION_INVALID_ENTERED_DATA;
        }
    }

    return res;
}

err_t action_rotate_read_data(rotate_t &rotate, Ui::MainWindow *ui)
{
    err_t res = ERR_NONE;
    bool convert_res;

    rotate.ox = ui->RotateEditX->text().toDouble(&convert_res);

    if (! convert_res)
        res = ERR_ACTION_INVALID_ENTERED_DATA;
    else
    {
        rotate.oy = ui->RotateEditY->text().toDouble(&convert_res);

        if (! convert_res)
            res = ERR_ACTION_INVALID_ENTERED_DATA;
        else
        {
            rotate.oz = ui->RotateEditZ->text().toDouble(&convert_res);

            if (! convert_res)
                res = ERR_ACTION_INVALID_ENTERED_DATA;
        }
    }

    return res;
}

err_t action_rotate_read(action_t &action, Ui::MainWindow *ui)
{
    err_t res = ERR_NONE;

    res = action_rotate_read_data(action.rotate, ui);

    if (res == ERR_NONE)
        res = action_center_read_data(action.rotate, ui);

    return res;
}

void MainWindow::on_ImportButton_clicked()
{
    action_t action;

    err_t res = ERR_NONE;

    action.process = READ_FILE;
    action_filename_read(action, this->ui);

    res = action_perform(action);

    if (res == ERR_NONE)
        res = action_perform(this->draw_action);

    if (res)
        error_msg(res);
}

void MainWindow::on_MoveButton_clicked()
{
    action_t action;

    err_t res = ERR_NONE;

    action.process = MOVE_MODEL;

    res = action_move_read(action, this->ui);

    if (res == ERR_NONE)
    {
        res = action_perform(action);

        if (res == ERR_NONE)
            res = action_perform(this->draw_action);
    }

    if (res)
        error_msg(res);
}

void MainWindow::on_ScaleButton_clicked()
{
    action_t action;

    err_t res = ERR_NONE;

    action.process = SCALE_MODEL;

    res = action_scale_read(action, this->ui);

    if (res == ERR_NONE)
    {
        res = action_perform(action);

        if (res == ERR_NONE)
            res = action_perform(this->draw_action);
    }

    if (res)
        error_msg(res);
}

void MainWindow::on_RotateButton_clicked()
{
    action_t action;

    err_t res = ERR_NONE;

    action.process = ROTATE_MODEL;

    res = action_rotate_read(action, this->ui);

    if (res == ERR_NONE)
    {
        res = action_perform(action);

        if (res == ERR_NONE)
            res = action_perform(this->draw_action);
    }

    if (res)
        error_msg(res);
}
