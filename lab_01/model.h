#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "points.h"
#include "links.h"

struct model_t
{
    links_t links;
    points_t points;

    point_t center;
};

#endif // MODEL_H
