#include <iostream>
#include <cstddef>

#include "scene.h"
#include "link.h"
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

bool is_scene_is_empty(QGraphicsScene *scene)
{
    return ! scene;
}

err_t scene_clear(scene_t &scene)
{
    err_t res = ERR_NONE;

    if (is_scene_is_empty(scene.scene))
        res = ERR_SCENE_IS_EMPTY;
    else
        scene.scene->clear();

    return res;
}

bool points_assign_by_link(point_t &p1, point_t &p2, const points_t &points, const link_t &link)
{
    bool res = true;

    if (! is_link_field_is_valid(link.beg, points.n))
        res = false;
    else
    {
        if (! is_link_field_is_valid(link.beg, points.n))
            res = false;
        else
        {
            p1 = points.array[link.beg];
            p2 = points.array[link.end];
        }
    }

    return res;
}

err_t points_get_by_link(point_t &p1, point_t &p2, const points_t &points, const link_t &link)
{
    err_t res = ERR_NONE;
    bool valid_res;

    const size_t points_n = points_get_size(points);

    valid_res = is_link_is_valid(link, points_n);
    if (! valid_res)
        res = ERR_LINKS_INVALID_LINK;
    else
    {
        valid_res = points_assign_by_link(p1, p2, points, link);

        if (! valid_res)
            res = ERR_LINKS_INVALID_LINK;
    }

    return res;
}

err_t scene_add_line(scene_t &scene, const point_t &point_1, const point_t &point_2)
{
    err_t res = ERR_NONE;

    if (is_scene_is_empty(scene.scene))
        res = ERR_SCENE_IS_EMPTY;
    else
        scene.scene->addLine(point_1.x, point_1.y, point_2.x, point_2.y, scene.pen);

    return res;
}

err_t model_draw_by_links(scene_t &scene, const model_t &model)
{
    const links_t links = model.links;
    const points_t points = model.points;

    point_t p1, p2;

    err_t res = ERR_NONE;

    for (size_t i = 0; res == ERR_NONE && i < links.n; i++)
    {
        res = points_get_by_link(p1, p2, points, links.array[i]);

        if (res == ERR_NONE)
            res = scene_add_line(scene, p1, p2);
    }

    return res;
}

err_t scene_draw_model(scene_t &scene, const model_t &model)
{
    err_t res = ERR_NONE;

    if (is_model_empty(model))
        res = ERR_ACTION_NO_MODEL;
    else
    {
        res = scene_clear(scene);

        if (res == ERR_NONE)
        {
            res = model_draw_by_links(scene, model);

            if (res != ERR_NONE)
                res = scene_clear(scene);
        }
    }

    return res;
}

void scene_configure(scene_t &scene, QGraphicsView *gV)
{
    gV->setScene(scene.scene);
    gV->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}
