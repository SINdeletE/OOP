//
// Created by nuelex on 09/05/25.
//

#include "ConcreteFigureLP.hpp"

#include "../../../../Visitors/Visitor.hpp"


void ConcreteFigureLP::accept(const BaseDrawTemplateVisitor& visitor)
{
    if (const auto cv = dynamic_cast<const Visitor<ConcreteFigureLP>*>(&visitor))
        cv->visit(*this);
}
