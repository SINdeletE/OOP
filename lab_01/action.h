#ifndef ACTION_H
#define ACTION_H

#include "error.h"
#include "model.h"
#include "operation.h"

enum process_t
{
    READ_FILE,
    MOVE_FIGURE,
    SCALE_FIGURE,
    ROTATE_FIGURE
};

union action_data_t
{
    const char *filename;
    struct move_t move;
    struct scale_t scale;
    struct rotate_t rotate;
};

struct action_t
{
    process_t process;
    action_data_t data;
};

err_t action_perform(model_t &model, const action_t &action);

#endif // ACTION_H
