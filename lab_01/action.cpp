#include <cstdio>
#include <cstddef>

#include "action.h"

err_t action_read_file(model_t &model, FILE *file)
{
    model_t tmp_model;
    err_t res = ERR_NONE;

    if (! file)
        return ERR_FILE_NOT_FOUND;

    rewind(file);

    res = model_read(tmp_model, file);

    if (! res)
        model = tmp_model;

    return res;
}

err_t action_perform(model_t &model, const action_t &action)
{
    FILE *file = NULL;
    err_t res = ERR_NONE;

    action_data_t data = action.data;

    if (action.process == READ_FILE)
    {
        file = fopen(data.filename, "r");

        res = action_read_file(model, file);

        fclose(file);
    }

    return res;
}
