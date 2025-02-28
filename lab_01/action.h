#ifndef ACTION_H
#define ACTION_H

#include "error.h"
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
    struct move_t move;
    struct scale_t scale;
    struct rotate_t rotate;
};

struct action_t
{
    process_t process;
    action_data_t data;
};

err_t action_perform(action_t &action);

#endif // ACTION_H
