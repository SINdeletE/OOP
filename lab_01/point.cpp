#include <cmath>

#include "point.h"

point_t point_init()
{
    return (point_t){0.0, 0.0, 0.0};
}

// Может лучше error_t? Думаю нет, так как будет использоваться в чтении в файле, где лучше True и False.
int point_read(point_t &point, FILE *file)
{
    point_t tmp_point = point_init();

    if (fscanf(file, "%lf%lf%lf", &tmp_point.x, &tmp_point.y, &tmp_point.z) != 3)
        return 1;

    point = tmp_point;

    return 0;
}

point_t point_move(point_t &point, const double x, const double y, const double z)
{
    point_t tmp_point = point;

    tmp_point.x += x;
    tmp_point.y += y;
    tmp_point.z += z;

    return tmp_point;
}

point_t point_scale(point_t &point, const double kx, const double ky, const double kz)
{
    point_t tmp_point = point;

    tmp_point.x *= kx;
    tmp_point.y *= ky;
    tmp_point.z *= kz;

    return tmp_point;
}

double rad_from_degree(double degree)
{
    return degree * M_PI / 180;
}

double coordinate_rotate(const double coord_1, const double coord_2, const double degree)
{
    double rad = rad_from_degree(degree);

    return coord_1 * cos(rad) + coord_2 * sin(rad);
}

void point_rotate_x(point_t &point, const double ox, const double oy, const double oz)
{
    double component_1 = point.x * (cos(oy) * cos(oz));
    double component_2 = point.y * (sin(ox) * sin(oy) * cos(oz) + sin(oz) * cos(ox));
    double component_3 = point.z * (sin(ox) * sin(oz) - sin(oy) * cos(ox) * cos(oz));

    point.x = component_1 + component_2 + component_3;
}

void point_rotate_y(point_t &point, const double ox, const double oy, const double oz)
{
    double component_1 = point.x * -(sin(oz) * cos(oy));
    double component_2 = point.y * (-sin(ox) * sin(oy) * sin(oz) + cos(ox) * cos(oz));
    double component_3 = point.z * (sin(ox) * cos(oz) + sin(oy) * sin(oz) * cos(ox));

    point.y = component_1 + component_2 + component_3;
}

void point_rotate_z(point_t &point, const double ox, const double oy, const double oz)
{
    double component_1 = point.x * sin(oy);
    double component_2 = point.y * -(sin(ox) * cos(oy));
    double component_3 = point.z * cos(ox) * cos(oy);

    point.z = component_1 + component_2 + component_3;
}

point_t point_rotate(point_t &point, const double ox, const double oy, const double oz)
{
    point_t tmp_point = point;

    // Умножение координат на матрицу поворота
    point_rotate_x(tmp_point, ox, oy, oz);
    point_rotate_y(tmp_point, ox, oy, oz);
    point_rotate_z(tmp_point, ox, oy, oz);

    return tmp_point;
}
