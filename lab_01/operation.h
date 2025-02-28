#ifndef OPERATION_H
#define OPERATION_H

#include "points.h"

struct move_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_t
{
    double kx;
    double ky;
    double kz;
};

struct rotate_t
{
    double ox;
    double oy;
    double oz;
};

void operation_move(points_t &points, const move_t &move);
void operation_scale(points_t &points, const scale_t &scale);
void operation_rotate(points_t &points, const rotate_t &rotate);

#endif // OPERATION_H
