#ifndef POINTS_H
#define POINTS_H

#include <cstddef>

#include "error.h"
#include "point.h"

struct points_t
{
    size_t n;
    point_t *array;
};

err_t points_alloc(points_t &points, const size_t n);
void points_free(points_t &points);

#endif // POINTS_H
