#ifndef MODEL_H
#define MODEL_H

#include "error.h"
#include "point.h"
#include "points.h"
#include "links.h"

struct model_t
{
    links_t links;
    points_t points;

    point_t center;
};

err_t model_move(model_t &model, const double x, const double y, const double z);
err_t model_scale(model_t &model, const double kx, const double ky, const double kz);
err_t model_rotate(model_t &model, const double x, const double y, const double z);

#endif // MODEL_H
