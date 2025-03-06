#ifndef ACTION_H
#define ACTION_H

#include "error.h"
#include "operation.h"
#include "scene.h"

enum process_t
{
    FREE_MODEL,
    READ_FILE,
    MOVE_MODEL,
    SCALE_MODEL,
    ROTATE_MODEL,
    DRAW_MODEL
};


struct action_t
{
    process_t process;

    union
    {
        const char *filename;
        move_t move;
        scale_t scale;
        rotate_t rotate;
        scene_t *scene; // Невозможно передать просто структуру, так как внутри структуры элемент с нетривиальным конструктором
    };
};

void draw_action_init(action_t &action, scene_t &scene);
err_t action_perform(const action_t &action);

#endif // ACTION_H
