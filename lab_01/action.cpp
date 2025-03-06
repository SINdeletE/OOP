#include <cstdio>

#include "model.h"
#include "action.h"

void draw_action_init(action_t &action, scene_t &scene)
{
    action.process = DRAW_MODEL;
    action.scene = &scene;
}

err_t action_perform(const action_t &action)
{
    // Модель для отрисовки
    static model_t model = model_init();

    err_t res = ERR_NONE;

    switch (action.process)
    {
        case FREE_MODEL:
            model_free(model);

            break;
        case READ_FILE:
            res = model_read_file(model, action.filename);

            break;
        case MOVE_MODEL:
            res = model_move(model, action.move);

            break;
        case SCALE_MODEL:
            res = model_scale(model, action.scale);

            break;
        case ROTATE_MODEL:
            res = model_rotate(model, action.rotate);

            break;
        case DRAW_MODEL:
            res = scene_draw_model(*action.scene, model);

            break;
    }

    return res;
}
