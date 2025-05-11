//
// Created by nuelex on 09/05/25.
//

#ifndef BASECONCRETEFIGURE_HPP
#define BASECONCRETEFIGURE_HPP

#include "../Figure.hpp"
#include "../../../Transforms/Transforms.hpp"
#include "ConcreteFigureLP/Point/Points.hpp"

class BaseConcreteFigure : public Figure
{
protected:
    ~BaseConcreteFigure() override = default;
public:
    [[nodiscard]] virtual Points&& getPoints() noexcept = 0;
    virtual void setPoints(const Points &points) = 0;

    void move(const Mover &mover) override {}
    void rotate(const Rotater &rotater) override {}
    void scale(const Scaler &scaler) override {}

    void draw() override;
};



#endif //BASECONCRETEFIGURE_HPP
