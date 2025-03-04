#include "model.h"

model_t model_init()
{
    model_t tmp_model;

    tmp_model.links = links_init();
    tmp_model.points = points_init();

    return tmp_model;
}

err_t model_alloc(model_t &model, size_t n_links, size_t n_points)
{
    err_t res = ERR_NONE;
    model_t tmp_model;

    points_t tmp_points;
    links_t tmp_links;

    res = points_alloc(tmp_points, n_points);

    if (res == ERR_NONE)
    {
        res = links_alloc(tmp_links, n_links);
        if (res == ERR_NONE)
        {
            tmp_model.points = tmp_points;
            tmp_model.links = tmp_links;

            model = tmp_model;
        }
    }

    return res;
}

void model_free(model_t &model)
{
    links_free(model.links);
    points_free(model.points);
}

int is_model_empty(const model_t &model)
{
    return is_points_empty(model.points);
}

err_t model_move(model_t &model, const move_t &move)
{
    err_t res = ERR_NONE;

    if (is_model_empty(model)) res = ERR_MODEL_IS_EMPTY;

    if (res == ERR_NONE)
        operation_move(model.points, move);

    return ERR_NONE;
}

err_t model_scale(model_t &model, const scale_t &scale)
{
    err_t res = ERR_NONE;

    if (is_model_empty(model)) res = ERR_MODEL_IS_EMPTY;

    if (res == ERR_NONE)
        operation_scale(model.points, scale);

    return ERR_NONE;
}

err_t model_rotate(model_t &model, const rotate_t &rotate)
{
    err_t res = ERR_NONE;

    if (is_model_empty(model)) res = ERR_MODEL_IS_EMPTY;

    if (res == ERR_NONE)
        operation_rotate(model.points, rotate);

    return ERR_NONE;
}

err_t model_read(model_t &model, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    model_t tmp_model = model_init();

    err_t res = ERR_NONE;

    res = points_read(tmp_model.points, file);

    if (res == ERR_NONE)
    {
        res = links_read(tmp_model.links, file, points_get_size(tmp_model.points));

        if (res)
            model_free(tmp_model);
        else
            model = tmp_model;
    }

    return res;
}
