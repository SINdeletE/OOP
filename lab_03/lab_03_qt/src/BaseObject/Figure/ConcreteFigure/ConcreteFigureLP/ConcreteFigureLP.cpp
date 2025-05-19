//
// Created by nuelex on 09/05/25.
//

#include "ConcreteFigureLP.hpp"

#include "../../../../Visitors/Visitor.hpp"


void ConcreteFigureLP::accept(const BaseVisitor& visitor)
{
    if (const auto cv = dynamic_cast<const Visitor<BaseConcreteFigureLP>*>(&visitor))
        cv->visit(*this);
}
