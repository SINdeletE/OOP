#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "error.h"
#include "model.h"

struct scene_t
{
    QGraphicsScene *scene;
    QPen pen;
};

err_t scene_init(scene_t &scene, QGraphicsView *gV);
void scene_configure(scene_t &scene, QGraphicsView *gV);

err_t scene_draw_model(scene_t &scene, const model_t &model);

#endif // SCENE_H

