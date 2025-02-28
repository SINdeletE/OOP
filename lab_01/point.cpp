#include <cmath>

#include "point.h"

point_t point_init()
{
    return (point_t){0.0, 0.0, 0.0};
}

err_t point_read(point_t &point, FILE *file)
{
    point_t tmp_point;

    err_t res = ERR_NONE;

    if (fscanf(file, "%lf%lf%lf", &tmp_point.x, &tmp_point.y, &tmp_point.z) != 3)
        res = ERR_FILE_INVALID_DATA;

    if (! res)
        point = tmp_point;

    return res;
}
