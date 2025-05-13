//
// Created by nuelex on 09/05/25.
//

#ifndef BASECONCRETEFIGURE_HPP
#define BASECONCRETEFIGURE_HPP

#include "../Figure.hpp"
#include "../../../Transforms/Transforms.hpp"
#include "ConcreteFigureLP/Links/Links.hpp"
#include "ConcreteFigureLP/Point/Points.hpp"

class BaseConcreteFigure : public Figure
{
public:
    BaseConcreteFigure() = default;
    ~BaseConcreteFigure() override = default;

    [[nodiscard]] virtual const Links& getLinks() noexcept = 0;
    [[nodiscard]] virtual const Points& getPoints() noexcept = 0;
    virtual void setLinks(const Links &links) = 0;
    virtual void setLinks(Links &&links) noexcept = 0;
    virtual void setPoints(const Points &points) = 0;
    virtual void setPoints(Points &&points) noexcept = 0;

    void move(const Mover &mover) override {}
    void rotate(const Rotater &rotater) override {}
    void scale(const Scaler &scaler) override {}
};



#endif //BASECONCRETEFIGURE_HPP
