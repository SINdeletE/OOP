//
// Created by nuelex on 10/05/25.
//

#include "CameraPTU.hpp"

#include "../../Visitors/Visitor.hpp"

void CameraPTU::accept(const BaseDrawTemplateVisitor& visitor)
{
    if (const auto cv = dynamic_cast<const Visitor<BaseCameraPTU>*>(&visitor))
        cv->visit(*this);
}
