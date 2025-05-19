//
// Created by nuelex on 18/05/25.
//

#ifndef BASEDRAWER_HPP
#define BASEDRAWER_HPP
#include "../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp"
#include "../ColorParameters/BaseColorParameters.hpp"


class BaseDrawer
{
public:
    BaseDrawer() = default;
    explicit  BaseDrawer(const std::shared_ptr<BaseColorParameters> &pen);
    virtual ~BaseDrawer() = default;

    virtual void setPen(const std::shared_ptr<BaseColorParameters> &pen) = 0;

    virtual void drawLine(const Point &start, const Point &end) = 0;
    virtual void clear() = 0;
};



#endif //BASEDRAWER_HPP
