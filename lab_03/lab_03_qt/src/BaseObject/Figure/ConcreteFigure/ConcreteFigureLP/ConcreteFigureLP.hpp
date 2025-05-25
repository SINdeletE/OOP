//
// Created by nuelex on 09/05/25.
//

#ifndef CONCRETEFIGURELP_HPP
#define CONCRETEFIGURELP_HPP

#include "../BaseConcreteFigureLP.hpp"
#include "FigureLP/FigureLP.hpp"
#include "Links/Links.hpp"
#include "Point/Points.hpp"
#include "../../../../Transforms/Transforms.hpp"

class ConcreteFigureLP : public BaseConcreteFigureLP
{
    friend class DrawFigureLPVisitor;
    friend class TXTLPReader;
    friend class FigureLPBuilder;

public:
    ConcreteFigureLP() : figureLP_() {}
    explicit ConcreteFigureLP(const ConcreteFigureLP &other) { figureLP_ = other.figureLP_; }
    ~ConcreteFigureLP() override = default;

    ConcreteFigureLP& operator=(const ConcreteFigureLP &other) { figureLP_ = other.figureLP_; return *this; }

    void transform(const Mover &mover) override { figureLP_.transform(mover); }
    void transform(const Rotater &rotater) override { figureLP_.transform(rotater); }
    void transform(const Scaler &scaler) override { figureLP_.transform(scaler); }

    void accept(const BaseDrawTemplateVisitor& visitor) override;
    void accept(BaseTransformVisitor &visitor) override { visitor.visitFigure(*this); }

protected:
    FigureLP figureLP_;
};



#endif //CONCRETEFIGURELP_HPP
