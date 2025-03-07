#include <cmath>

#include "point.h"

point_t point_init()
{
    return (point_t){0.0, 0.0, 0.0};
}

err_t point_read(point_t &point, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    err_t res = ERR_NONE;

    if (fscanf(file, "%lf%lf%lf", &point.x, &point.y, &point.z) != 3)
        res = ERR_FILE_INVALID_DATA;

    return res;
}
