//
// Created by nuelex on 09/05/25.
//

#ifndef BASECONCRETEFIGURE_HPP
#define BASECONCRETEFIGURE_HPP

#include "../Figure.hpp"
#include "../../../Transforms/Transforms.hpp"
#include "../../../Visitors/Draw/FigureLP/DrawFigureLPVisitor.hpp"
#include "ConcreteFigureLP/Links/Links.hpp"
#include "ConcreteFigureLP/Point/Points.hpp"

class BaseConcreteFigureLP : public Figure
{
public:
    BaseConcreteFigureLP() = default;
    ~BaseConcreteFigureLP() override = default;

    void transform(const Mover &mover) override {}
    void transform(const Rotater &rotater) override {}
    void transform(const Scaler &scaler) override {}

    void accept(const BaseDrawTemplateVisitor &visitor) override {}
    void accept(BaseTransformVisitor &visitor) override { visitor.visitFigure(*this); }
};



#endif //BASECONCRETEFIGURE_HPP
