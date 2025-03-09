#ifndef POINTS_H
#define POINTS_H

#include <cstdbool>
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
void points_free(points_t &points_array);
size_t points_get_size(const points_t &points);

bool is_points_empty(const points_t &points);
err_t points_are_valid(const points_t &points);

err_t points_read(points_t &points, FILE *file);

#endif // POINTS_H
