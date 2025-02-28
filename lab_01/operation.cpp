#include <cmath>

#include "point.h"
#include "operation.h"

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

void point_rotate_x(point_t &point, const rotate_t &rotate)
{
    double ox = rotate.ox;
    double oy = rotate.oy;
    double oz = rotate.oz;

    double component_1 = point.x * (cos(oy) * cos(oz));
    double component_2 = point.y * (sin(ox) * sin(oy) * cos(oz) + sin(oz) * cos(ox));
    double component_3 = point.z * (sin(ox) * sin(oz) - sin(oy) * cos(ox) * cos(oz));

    point.x = component_1 + component_2 + component_3;
}

void point_rotate_y(point_t &point, const rotate_t &rotate)
{
    double ox = rotate.ox;
    double oy = rotate.oy;
    double oz = rotate.oz;

    double component_1 = point.x * -(sin(oz) * cos(oy));
    double component_2 = point.y * (-sin(ox) * sin(oy) * sin(oz) + cos(ox) * cos(oz));
    double component_3 = point.z * (sin(ox) * cos(oz) + sin(oy) * sin(oz) * cos(ox));

    point.y = component_1 + component_2 + component_3;
}

void point_rotate_z(point_t &point, const rotate_t &rotate)
{
    double ox = rotate.ox;
    double oy = rotate.oy;
    // double oz = rotate.oz; // Не используется

    double component_1 = point.x * sin(oy);
    double component_2 = point.y * -(sin(ox) * cos(oy));
    double component_3 = point.z * cos(ox) * cos(oy);

    point.z = component_1 + component_2 + component_3;
}

point_t point_rotate(point_t &point, const rotate_t &rotate)
{
    point_t tmp_point = point;

    // Умножение координат на матрицу поворота
    point_rotate_x(tmp_point, rotate);
    point_rotate_y(tmp_point, rotate);
    point_rotate_z(tmp_point, rotate);

    return tmp_point;
}

void operation_move(points_t &points, const move_t &move)
{
    // Перенос
    for (size_t i = 0; i < points.n; i++)
        points.array[i] = point_move(points.array[i], move);
}

void operation_scale(points_t &points, const scale_t &scale)
{
    // Масштабирование
    for (size_t i = 0; i < points.n; i++)
        points.array[i] = point_scale(points.array[i], scale);
}

void operation_rotate(points_t &points, const rotate_t &rotate)
{
    // Поворот
    for (size_t i = 0; i < points.n; i++)
        points.array[i] = point_rotate(points.array[i], rotate);
}
