//
// Created by nuelex on 09/05/25.
//

#include "Figure.hpp"

#include "../../Visitors/Visitor.hpp"

void Figure::accept(const BaseVisitor& visitor)
{
    if (const auto cv = dynamic_cast<const Visitor<Figure>*>(&visitor))
        cv->visit(*this);
}

