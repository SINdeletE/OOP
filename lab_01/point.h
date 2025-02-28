#ifndef POINT_H
#define POINT_H

#include <cstdio>

#include "error.h"

struct point_t
{
    double x;
    double y;
    double z;
};

point_t point_init();
err_t point_read(point_t &point, FILE *file);

#endif // POINT_H
