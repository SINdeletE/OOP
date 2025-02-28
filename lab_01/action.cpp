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

err_t action_read_file(model_t &model, FILE *file)
{
    model_t tmp_model;
    err_t res = ERR_NONE;

    if (! file)
        res = ERR_FILE_NOT_FOUND;
    else
    {
        rewind(file);

        res = model_read(tmp_model, file);

        if (! res)
            model = tmp_model;
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
    FILE *file = NULL;
    err_t res = ERR_NONE;

    action_data_t data = action.data;

    // Модель для отрисовки
    static model_t model = model_init();

    if (action.process == FREE_MODEL)
    {
        model_free(model);
    }
    else if (action.process == READ_FILE)
    {
        file = fopen("../../cube.txt", "r");

        res = action_read_file(model, file);

        if (! res && res != ERR_MODEL_IS_EMPTY)
            fclose(file);
    }
    else if (action.process == MOVE_MODEL)
    {
        res = action_move_model(model, data.move);
    }
    else if (action.process == SCALE_MODEL)
    {
        res = action_scale_model(model, data.scale);
    }
    else if (action.process == ROTATE_MODEL)
    {
        res = action_rotate_model(model, data.rotate);
    }
    else if (action.process == DRAW_MODEL)
    {
        res = action_draw_model(model, *data.scene);
    }

    return res;
}
