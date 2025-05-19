//
// Created by nuelex on 18/05/25.
//

#ifndef QTDRAWER_HPP
#define QTDRAWER_HPP
#include <QGraphicsScene>

#include "BaseDrawer.hpp"


class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = default;
    ~QtDrawer() override = default;

    void drawLine(const Point& start, const Point& end) override { scene->addLine(start.GetX(), start.GetY(), end.GetX(), end.GetY()); }
    void clear() override { scene->clear(); }

private:
    QGraphicsScene *scene;
};



#endif //QTDRAWER_HPP
