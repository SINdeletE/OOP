#ifndef POINT_H
#define POINT_H

#include <cstdio>

struct point_t
{
    double x;
    double y;
    double z;
};

point_t point_init();
int point_read(point_t &point, const FILE *file);

#endif // POINT_H
