#include "model.h"

int is_model_empty(const model_t &model)
{
    return is_points_empty(model.points);
}

err_t model_move(model_t &model, const double x, const double y, const double z)
{
    if (is_model_empty(model))
        return ERR_MODEL_IS_EMPTY;

    points_move(model.points, x, y, z);
    point_move(model.center, x, y, z);

    return ERR_NONE;
}

err_t model_scale(model_t &model, const double kx, const double ky, const double kz)
{
    if (is_model_empty(model))
        return ERR_MODEL_IS_EMPTY;

    points_scale(model.points, model.center, kx, ky, kz);

    return ERR_NONE;
}

err_t model_rotate(model_t &model, const double x, const double y, const double z)
{
    if (is_model_empty(model))
        return ERR_MODEL_IS_EMPTY;

    points_rotate(model.points, x, y, z);

    return ERR_NONE;
}
