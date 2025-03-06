#ifndef MODEL_H
#define MODEL_H

#include <cstdio>
#include <cstddef>

#include "error.h"
#include "points.h"
#include "links.h"
#include "operation.h"

struct model_t
{
    links_t links;
    points_t points;
};

model_t model_init();
err_t model_alloc(model_t &model, size_t n_links, size_t n_points);
void model_free(model_t &model);

int is_model_empty(const model_t &model);

err_t model_move(model_t &model, const move_t &move);
err_t model_scale(model_t &model, const scale_t &scale);
err_t model_rotate(model_t &model, const rotate_t &rotate);

err_t model_read_file(model_t &model, const char *filename);
err_t model_is_valid(const model_t &model);

#endif // MODEL_H
