//
// Created by nuelex on 19/05/25.
//

#include "Camera.hpp"

#include "../../Visitors/Visitor.hpp"

void Camera::accept(const BaseDrawTemplateVisitor& visitor)
{
    if (const auto cv = dynamic_cast<const Visitor<Camera>*>(&visitor))
        cv->visit(*this);
}

