#include "draw.h"

err_t scene_add_line(scene_t &scene, const point_t &point_1, const point_t &point_2)
{
    err_t res = ERR_NONE;

    if (is_scene_is_empty(scene.scene))
        res = ERR_SCENE_IS_EMPTY;
    else
        scene.scene->addLine(point_1.x, point_1.y, point_2.x, point_2.y, scene.pen);

    return res;
}
