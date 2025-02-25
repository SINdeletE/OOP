#ifndef POINT_H
#define POINT_H

#include <cstdio>

struct point_t
{
    double x;
    double y;
    double z;
};

point_t point_init();
int point_read(point_t &point, FILE *file);

point_t point_move(point_t &point, const double x, const double y, const double z);
point_t point_scale(point_t &point, const double kx, const double ky, const double kz);
point_t point_rotate(point_t &point, const double ox, const double oy, const double oz);

#endif // POINT_H
