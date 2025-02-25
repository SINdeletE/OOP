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

double deg_to_rad(double deg)
{
    return deg * M_PI / 180;
}

point_t point_rotate(point_t &point, const double ox, const double oy, const double oz)
{
    point_t tmp_point = point;

    tmp_point.x *= ox;
    tmp_point.y *= oy;
    tmp_point.z *= oz;

    return tmp_point;
}
