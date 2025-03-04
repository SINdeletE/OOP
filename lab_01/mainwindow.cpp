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

void action_filename_read(action_data_t &data, Ui::MainWindow *ui)
{
    action_data_t tmp_data;

    tmp_data.filename = ui->ImportFilename->text().toUtf8().constData();

    data = tmp_data;
}

err_t action_move_read(action_data_t &data, Ui::MainWindow *ui)
{
    action_data_t tmp_data;
    move_t tmp_move;

    err_t res = ERR_NONE;
    bool convert_res;

    tmp_move.dx = ui->MoveEditX->text().toDouble(&convert_res);

    if (convert_res)
    {
        tmp_move.dy = ui->MoveEditY->text().toDouble(&convert_res);

        if (convert_res)
            tmp_move.dz = ui->MoveEditZ->text().toDouble(&convert_res);
    }

    if (! convert_res)
        res = ERR_ACTION_INVALID_ENTERED_DATA;
    else
    {
        tmp_data.move = tmp_move;
        data = tmp_data;
    }

    return res;
}

err_t action_scale_read(action_data_t &data, Ui::MainWindow *ui)
{
    action_data_t tmp_data;
    scale_t tmp_scale;

    err_t res = ERR_NONE;
    bool convert_res;

    tmp_scale.kx = ui->ScaleEditX->text().toDouble(&convert_res);

    if (convert_res)
    {
        tmp_scale.ky = ui->ScaleEditY->text().toDouble(&convert_res);

        if (convert_res)
            tmp_scale.kz = ui->ScaleEditZ->text().toDouble(&convert_res);
    }

    if (! convert_res)
        res = ERR_ACTION_INVALID_ENTERED_DATA;
    else
    {
        tmp_data.scale = tmp_scale;
        data = tmp_data;
    }

    return res;
}

err_t action_rotate_read(action_data_t &data, Ui::MainWindow *ui)
{
    action_data_t tmp_data;
    rotate_t tmp_rotate;

    err_t res = ERR_NONE;
    bool convert_res;

    tmp_rotate.ox = ui->RotateEditX->text().toDouble(&convert_res);

    if (! convert_res)
    {
        tmp_rotate.oy = ui->RotateEditY->text().toDouble(&convert_res);

        if (! convert_res)
            tmp_rotate.oz = ui->RotateEditZ->text().toDouble(&convert_res);
    }

    if (! convert_res)
        res = ERR_ACTION_INVALID_ENTERED_DATA;
    else
    {
        tmp_data.rotate = tmp_rotate;
        data = tmp_data;
    }

    return res;
}

void MainWindow::on_ImportButton_clicked()
{
    action_t action;

    err_t res = ERR_NONE;

    action.process = READ_FILE;
    action_filename_read(action.data, this->ui);

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

    res = action_move_read(action.data, this->ui);

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

    res = action_scale_read(action.data, this->ui);

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

    res = action_rotate_read(action.data, this->ui);

    if (res == ERR_NONE)
    {
        res = action_perform(action);

        if (res == ERR_NONE)
            res = action_perform(this->draw_action);
    }

    if (res)
        error_msg(res);
}
