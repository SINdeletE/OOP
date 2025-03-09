#ifndef DRAW_H
#define DRAW_H

#include "error.h"
#include "scene.h"
#include "point.h"

err_t scene_add_line(scene_t &scene, const point_t &point_1, const point_t &point_2);

#endif // DRAW_H
