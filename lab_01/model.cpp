#include "model.h"

model_t model_init()
{
    model_t tmp_model;

    tmp_model.links = links_init();
    tmp_model.points = points_init();

    return tmp_model;
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

err_t model_read_from_file(model_t &model, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    model_t tmp_model = model_init();

    err_t res = ERR_NONE;

    res = points_read(tmp_model.points, file);

    if (res == ERR_NONE)
    {
        res = links_read(tmp_model.links, file);

        if (res)
            points_free(tmp_model.points);
        else
            model = tmp_model;
    }

    return res;
}

err_t model_is_valid(const model_t &model)
{
    err_t res = ERR_NONE;

    res = points_are_valid(model.points);

    if (res == ERR_NONE)
    {
        size_t points_n = points_get_size(model.points);

        res = links_are_valid(model.links, points_n);
    }

    return res;
}

err_t model_read(model_t &model, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    model_t tmp_model = model_init();

    err_t res = ERR_NONE;

    res = model_read_from_file(tmp_model, file);

    if (res == ERR_NONE)
    {
        res = model_is_valid(tmp_model);

        if (res)
            model_free(tmp_model);
        else
            model = tmp_model;
    }

    return res;
}

err_t model_read_file(model_t &model, const char *filename)
{
    if (! filename) return ERR_FILE_NOT_FOUND;

    FILE *file = NULL;

    err_t res = ERR_NONE;

    file = fopen(filename, "r");
    if (! file)
        res = ERR_FILE_NOT_FOUND;
    else
    {
        model_t tmp_model;

        res = model_read(tmp_model, file);

        fclose(file);

        if (res == ERR_NONE)
        {
            model_free(model);

            model = tmp_model;
        }
    }

    return res;
}
