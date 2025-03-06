#include <cstdio>
#include <cstddef>

#include "model.h"
#include "action.h"

void draw_action_init(action_t &action, scene_t &scene)
{
    action.process = DRAW_MODEL;
    action.scene = &scene;
}

void action_free_model(model_t &model)
{
    model_free(model);
}

err_t action_read_file(model_t &model, const char *filename)
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

    err_t res = ERR_NONE;

    switch (action.process)
    {
        case FREE_MODEL:
            action_free_model(model);

            break;
        case READ_FILE:
            res = action_read_file(model, action.filename);

            break;
        case MOVE_MODEL:
            res = action_move_model(model, action.move);

            break;
        case SCALE_MODEL:
            res = action_scale_model(model, action.scale);

            break;
        case ROTATE_MODEL:
            res = action_rotate_model(model, action.rotate);

            break;
        case DRAW_MODEL:
            res = action_draw_model(model, *action.scene);

            break;
    }

    return res;
}
