#ifndef POINTS_H
#define POINTS_H

#include <cstddef>

#include "error.h"
#include "point.h"

struct points_t
{
    size_t n;
    point_t *array;

    point_t center;
};

err_t points_alloc(points_t &points, const size_t n);
void points_free(points_t &points);

int is_points_empty(const points_t &points);

void points_move(points_t &points, const double x, const double y, const double z);
void points_scale(points_t &points, const point_t center, const double kx, const double ky, const double kz);
void points_rotate(points_t &points, const double ox, const double oy, const double oz);

#endif // POINTS_H
