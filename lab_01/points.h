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

points_t points_init();
size_t points_get_size(points_t &points);
err_t points_alloc(points_t &points, const size_t n);
void points_free(points_t &points);

int is_points_empty(const points_t &points);

err_t points_read(points_t &points, FILE *file);

#endif // POINTS_H
