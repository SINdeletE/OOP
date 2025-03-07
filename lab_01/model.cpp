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

bool is_model_empty(const model_t &model)
{
    return is_points_empty(model.points);
}

err_t model_move(model_t &model, const move_t &move_data)
{
    if (is_model_empty(model)) return ERR_MODEL_IS_EMPTY;

    err_t res = ERR_NONE;

    res = move(model.points, move_data);

    return res;
}

err_t model_scale(model_t &model, const scale_t &scale_data)
{
    if (is_model_empty(model)) return ERR_MODEL_IS_EMPTY;

    err_t res = ERR_NONE;

    res = scale(model.points, scale_data);

    return res;
}

err_t model_rotate(model_t &model, const rotate_t &rotate_data)
{
    if (is_model_empty(model)) return ERR_MODEL_IS_EMPTY;

    err_t res = ERR_NONE;

    res = rotate(model.points, rotate_data);

    return res;
}

err_t model_read_from_file(model_t &model, FILE *file)
{
    if (! file) return ERR_FILE_NOT_FOUND;

    err_t res = ERR_NONE;

    res = points_read(model.points, file);

    if (res == ERR_NONE)
    {
        res = links_read(model.links, file);

        if (res)
            points_free(model.points);
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

    err_t res = ERR_NONE;

    res = model_read_from_file(model, file);

    if (res == ERR_NONE)
    {
        res = model_is_valid(model);

        if (res)
            model_free(model);
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
