//
// Created by nuelex on 18/05/25.
//

#ifndef BASEDRAWER_HPP
#define BASEDRAWER_HPP
#include "../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp"


class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point &start, const Point &end) = 0;
    virtual void clear() = 0;
};



#endif //BASEDRAWER_HPP
