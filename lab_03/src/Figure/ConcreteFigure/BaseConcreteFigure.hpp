//
// Created by nuelex on 09/05/25.
//

#ifndef BASECONCRETEFIGURE_HPP
#define BASECONCRETEFIGURE_HPP
#include "../Figure.hpp"
#include "ConcreteFigureLP/Point/Points.hpp"

class BaseConcreteFigure : public Figure
{
protected:
    ~BaseConcreteFigure() override = default;
public:
    [[nodiscard]] virtual Points&& getPoints() noexcept = 0;

    virtual void setPoints(const Points &points) = 0;
};



#endif //BASECONCRETEFIGURE_HPP
