#ifndef VISUAL_MODEL_H
#define VISUAL_MODEL_H

#include <QPainter>
#include <QPen>
#include <cstddef>

struct visual_points_t
{
    size_t n;
    QPoint *points;
};

struct visual_model_t
{
    QPainter painter();
    QPen pen;

    visual_points_t points;
};

#endif // VISUAL_MODEL_H
