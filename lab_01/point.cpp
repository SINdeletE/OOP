#include <cmath>

#include "point.h"

point_t point_init()
{
    return (point_t){0.0, 0.0, 0.0};
}

// Может лучше error_t? Думаю нет, так как будет использоваться в чтении в файле, где лучше True и False.
int point_read(point_t &point, FILE *file)
{
    point_t tmp_point = point_init();

    if (fscanf(file, "%lf%lf%lf", &tmp_point.x, &tmp_point.y, &tmp_point.z) != 3)
        return 1;

    point = tmp_point;

    return 0;
}
