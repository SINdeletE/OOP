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

struct scale_t
{
    struct
    {
        double kx;
        double ky;
        double kz;
    };

    point_t center;
};

struct rotate_t
{
    struct
    {
        double ox;
        double oy;
        double oz;
    };

    point_t center;
};

err_t move(points_t &points, const move_t &move);
err_t scale(points_t &points, const scale_t &scale);
err_t rotate(points_t &points, const rotate_t &rotate);

#endif // OPERATION_H
