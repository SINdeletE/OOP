//
// Created by nuelex on 09/05/25.
//

#ifndef BASECONCRETEFIGURE_HPP
#define BASECONCRETEFIGURE_HPP

#include "../Figure.hpp"
#include "../../../Transforms/Transforms.hpp"
#include "../../../Visitors/Draw/DrawFigureLPVisitor.hpp"
#include "ConcreteFigureLP/Links/Links.hpp"
#include "ConcreteFigureLP/Point/Points.hpp"

class BaseConcreteFigureLP : public Figure
{
    friend class DrawFigureLPVisitor;

protected:
    [[nodiscard]] virtual const Links& getLinks() const noexcept = 0;
    [[nodiscard]] virtual const Points& getPoints() const noexcept = 0;

public:
    BaseConcreteFigureLP() = default;
    ~BaseConcreteFigureLP() override = default;

    virtual void setLinks(const Links &links) = 0;
    virtual void setLinks(Links &&links) noexcept = 0;
    virtual void setPoints(const Points &points) = 0;
    virtual void setPoints(Points &&points) noexcept = 0;

    void transform(const Mover &mover) override {}
    void transform(const Rotater &rotater) override {}
    void transform(const Scaler &scaler) override {}

    void accept(const BaseDrawTemplateVisitor &visitor) override {}
    void accept(BaseTransformVisitor &visitor) override { visitor.visitFigure(*this); }
};



#endif //BASECONCRETEFIGURE_HPP
