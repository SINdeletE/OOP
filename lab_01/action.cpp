#include <cstdio>
#include <cstddef>

#include "model.h"
#include "action.h"

void draw_action_init(action_t &action, scene_t &scene)
{
    action_data_t tmp_data;

    tmp_data.scene = &scene;

    action.process = DRAW_MODEL;
    action.data = tmp_data;
}

void action_free_model(model_t &model)
{
    model_free(model);
}

err_t action_read_file(model_t &model, const char *filename)
{
    if (! filename) return ERR_FILE_NOT_FOUND;

    FILE *file = NULL;

    model_t tmp_model;
    err_t res = ERR_NONE;

    file = fopen(filename, "r");
    if (! file)
        res = ERR_FILE_NOT_FOUND;
    else
    {
        rewind(file);

        res = model_read(tmp_model, file);

        if (res == ERR_NONE)
        {
            model_free(model);

            model = tmp_model;
        }
    }

    if (res == ERR_NONE)
        fclose(file);

    return res;
}

err_t action_move_model(model_t &model, const move_t &move)
{
    return model_move(model, move);
}

err_t action_scale_model(model_t &model, const scale_t &scale)
{
    return model_scale(model, scale);
}

err_t action_rotate_model(model_t &model, const rotate_t &rotate)
{
    return model_rotate(model, rotate);
}

err_t action_draw_model(const model_t &model, scene_t &scene)
{
    return scene_draw_model(scene, model);
}

err_t action_perform(const action_t &action)
{
    // Модель для отрисовки
    static model_t model = model_init();

    action_data_t data = action.data;

    err_t res = ERR_NONE;

    switch (action.process)
    {
        case FREE_MODEL:
            action_free_model(model);

            break;
        case READ_FILE:
            res = action_read_file(model, data.filename);

            break;
        case MOVE_MODEL:
            res = action_move_model(model, data.move);

            break;
        case SCALE_MODEL:
            res = action_scale_model(model, data.scale);

            break;
        case ROTATE_MODEL:
            res = action_rotate_model(model, data.rotate);

            break;
        case DRAW_MODEL:
            res = action_draw_model(model, *data.scene);

            break;
    }

    return res;
}
