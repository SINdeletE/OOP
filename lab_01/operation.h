#ifndef OPERATION_H
#define OPERATION_H

#include "point.h"
#include "points.h"

struct move_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_data_t
{
    double kx;
    double ky;
    double kz;
};

struct scale_t
{
    scale_data_t data;

    point_t center;
};

struct rotate_data_t
{
    double ox;
    double oy;
    double oz;
};

struct rotate_t
{
    rotate_data_t data;

    point_t center;
};

void operation_move(points_t &points, const move_t &move);
void operation_scale(points_t &points, const scale_t &scale);
void operation_rotate(points_t &points, const rotate_t &rotate);

#endif // OPERATION_H
