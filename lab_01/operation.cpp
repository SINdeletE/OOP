#include <cmath>

#include "point.h"
#include "operation.h"

const point_t center_get(const scale_t &scale)
{
    return scale.center;
}

const point_t center_get(const rotate_t &rotate)
{
    return rotate.center;
}

point_t point_move(point_t &point, const move_t &move)
{
    point_t tmp_point = point;

    tmp_point.x += move.dx;
    tmp_point.y += move.dy;
    tmp_point.z += move.dz;

    return tmp_point;
}

point_t point_scale(point_t &point, const scale_t &scale)
{
    point_t tmp_point = point;

    tmp_point.x *= scale.kx;
    tmp_point.y *= scale.ky;
    tmp_point.z *= scale.kz;

    return tmp_point;
}

double rad_from_degree(double degree)
{
    return degree * M_PI / 180;
}

void point_rotate_ox(point_t &point, const rotate_t &rad_rotate)
{
    double angle = rad_rotate.ox;
    double tmp_point_y = point.y;

    point.y = point.y * cos(angle) - point.z * sin(angle);
    point.z = tmp_point_y * sin(angle) + point.z * cos(angle);
}

void point_rotate_oy(point_t &point, const rotate_t &rad_rotate)
{
    double angle = rad_rotate.oy;
    double tmp_point_x = point.x;

    point.x = point.x * cos(angle) + point.z * sin(angle);
    point.z = point.z * cos(angle) - tmp_point_x * sin(angle);
}

void point_rotate_oz(point_t &point, const rotate_t &rad_rotate)
{
    double angle = rad_rotate.oz;
    double tmp_point_x = point.x;

    point.x = point.x * cos(angle) - point.y * sin(angle);
    point.y = tmp_point_x * sin(angle) + point.y * cos(angle);
}

rotate_t rad_rotate_get(const rotate_t &rotate)
{
    rotate_t rad_rotate;

    rad_rotate.ox = rad_from_degree(rotate.ox);
    rad_rotate.oy = rad_from_degree(rotate.oy);
    rad_rotate.oz = rad_from_degree(rotate.oz);

    return rad_rotate;
}

point_t point_rotate(point_t &point, const rotate_t &rotate)
{
    point_t tmp_point = point;
    rotate_t rad_rotate = rad_rotate_get(rotate);

    // Умножение координат на матрицу поворота
    point_rotate_ox(tmp_point, rad_rotate);
    point_rotate_oy(tmp_point, rad_rotate);
    point_rotate_oz(tmp_point, rad_rotate);

    return tmp_point;
}

err_t operation_move(points_t &points, const move_t &move)
{
    if (is_points_empty(points)) return ERR_MODEL_IS_EMPTY;

    err_t res = ERR_NONE;

    // Перенос
    for (size_t i = 0; i < points.n; i++)
        points.array[i] = point_move(points.array[i], move);

    return res;
}

err_t operation_scale(points_t &points, const scale_t &scale)
{
    if (is_points_empty(points)) return ERR_MODEL_IS_EMPTY;

    err_t res = ERR_NONE;

    // Масштабирование
    for (size_t i = 0; i < points.n; i++)
        points.array[i] = point_scale(points.array[i], scale);

    return res;
}

err_t operation_rotate(points_t &points, const rotate_t &rotate)
{
    if (is_points_empty(points)) return ERR_MODEL_IS_EMPTY;

    err_t res = ERR_NONE;

    // Поворот
    for (size_t i = 0; i < points.n; i++)
        points.array[i] = point_rotate(points.array[i], rotate);

    return res;
}

err_t move(points_t &points, const move_t &move)
{
    if (is_points_empty(points)) return ERR_MODEL_IS_EMPTY;

    err_t res = ERR_NONE;

    res = operation_move(points, move);

    return res;
}

move_t move_neg_from_center(const point_t &center)
{
    move_t move;

    move.dx = -center.x;
    move.dy = -center.y;
    move.dz = -center.z;

    return move;
}

move_t move_pos_from_center(const point_t &center)
{
    move_t move;

    move.dx = center.x;
    move.dy = center.y;
    move.dz = center.z;

    return move;
}

err_t scale(points_t &points, const scale_t &scale)
{
    if (is_points_empty(points)) return ERR_MODEL_IS_EMPTY;

    const point_t center = center_get(scale);
    move_t move_neg = move_neg_from_center(center);

    err_t res = ERR_NONE;

    res = operation_move(points, move_neg);

    if (res == ERR_NONE)
    {
        res = operation_scale(points, scale);

        if (res == ERR_NONE)
        {
            move_t move_pos = move_pos_from_center(center);

            res = operation_move(points, move_pos);
        }
    }

    return res;
}

err_t rotate(points_t &points, const rotate_t &rotate)
{
    if (is_points_empty(points)) return ERR_MODEL_IS_EMPTY;

    const point_t center = center_get(rotate);
    move_t move_neg = move_neg_from_center(center);

    err_t res = ERR_NONE;

    res = operation_move(points, move_neg);

    if (res == ERR_NONE)
    {
        res = operation_rotate(points, rotate);

        if (res == ERR_NONE)
        {
            move_t move_pos = move_pos_from_center(center);

            res = operation_move(points, move_pos);
        }
    }

    return res;
}
