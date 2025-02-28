#include "scene.h"

err_t scene_init(scene_t &scene, QGraphicsView *gV)
{
    scene_t tmp_scene;
    QGraphicsScene *tmp_graphics_scene;
    QPen tmp_pen;

    err_t res = ERR_NONE;

    tmp_graphics_scene = new QGraphicsScene(gV);
    if (! tmp_graphics_scene)
        res = ERR_SCENE_INVALID_ALLOC;

    if (! res)
    {
        tmp_pen = QPen(Qt::red);

        tmp_scene.scene = tmp_graphics_scene;
        tmp_scene.pen = tmp_pen;
    }

    return res;
}
