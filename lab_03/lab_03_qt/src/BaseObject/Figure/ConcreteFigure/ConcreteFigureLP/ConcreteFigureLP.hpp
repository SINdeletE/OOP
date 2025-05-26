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
    friend class MoveObjectVisitor;
    friend class RotateObjectVisitor;
    friend class ScaleObjectVisitor;

    friend class TXTLPReader;
    friend class FigureLPBuilder;

public:
    ConcreteFigureLP() = default;
    explicit ConcreteFigureLP(const ConcreteFigureLP &other) { figureLP_ = other.figureLP_; }
    explicit ConcreteFigureLP(const std::shared_ptr<AbstractFigureLP> &figure) {figureLP_ = figure;}
    ~ConcreteFigureLP() override = default;

    ConcreteFigureLP& operator=(const ConcreteFigureLP &other) { figureLP_ = other.figureLP_; return *this; }
    ConcreteFigureLP& operator=(const std::shared_ptr<AbstractFigureLP> &figure) {figureLP_ = figure; return *this; }

    void accept(const BaseDrawTemplateVisitor& visitor) override;
    void accept(BaseTransformVisitor &visitor) override { visitor.visit(*this); }
};



#endif //CONCRETEFIGURELP_HPP
