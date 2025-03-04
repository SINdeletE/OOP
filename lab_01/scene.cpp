#include <cstddef>

#include "scene.h"
#include "links.h"
#include "point.h"
#include "points.h"

err_t scene_init(scene_t &scene, QGraphicsView *gV)
{
    scene_t tmp_scene;
    QGraphicsScene *tmp_graphics_scene;
    QPen tmp_pen;

    err_t res = ERR_NONE;

    tmp_graphics_scene = new QGraphicsScene(gV);

    if (! tmp_graphics_scene)
        res = ERR_SCENE_INVALID_ALLOC;
    else
    {
        tmp_pen = QPen(Qt::red);

        tmp_scene.scene = tmp_graphics_scene;
        tmp_scene.pen = tmp_pen;
    }

    if (res == ERR_NONE)
        scene = tmp_scene;

    return res;
}

void scene_clear(scene_t &scene)
{
    scene.scene->clear();
}

void points_get_by_link(point_t &p1, point_t &p2, const points_t &points, const link_t &link)
{
    p1 = points.array[link.beg];
    p2 = points.array[link.end];
}

void model_draw_by_links(scene_t &scene, const model_t &model)
{
    const links_t links = model.links;
    const points_t points = model.points;

    point_t p1, p2;

    for (size_t i = 0; i < links.n; i++)
    {
        points_get_by_link(p1, p2, points, links.array[i]);

        scene.scene->addLine(p1.x, p1.y, p2.x, p2.y, scene.pen);
    }
}

err_t scene_draw_model(scene_t &scene, const model_t &model)
{
    err_t res = ERR_NONE;

    if (is_model_empty(model))
        res = ERR_ACTION_NO_MODEL;
    else
    {
        scene_clear(scene);

        model_draw_by_links(scene, model);
    }

    return res;
}

void scene_configure(scene_t &scene, QGraphicsView *gV)
{
    gV->setScene(scene.scene);
    gV->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}
