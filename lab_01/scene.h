#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "error.h"

struct scene_t
{
    QGraphicsScene *scene;
    QPen pen;
};

err_t scene_init(scene_t &scene, QGraphicsView *gV);
void scene_free(scene_t &scene);

#endif // SCENE_H
