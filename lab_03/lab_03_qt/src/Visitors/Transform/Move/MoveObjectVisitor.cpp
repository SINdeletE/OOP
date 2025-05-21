//
// Created by nuelex on 20/05/25.
//

#include "MoveObjectVisitor.hpp"

#include <qvariant.h>

#include "../../../BaseObject/Camera/Camera.hpp"
#include "../../../BaseObject/Figure/Figure.hpp"
#include "../../../Exceptions/Visitors/VisitorException.hpp"

MoveObjectVisitor::MoveObjectVisitor(const std::shared_ptr<BaseTransform>& transform) : BaseTransformVisitor(transform)
{
    const auto tfm = dynamic_pointer_cast<Mover>(transform);

    if (tfm == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _transform = tfm;
}

void MoveObjectVisitor::visitFigure(Figure& figure)
{
    figure.transform(*_transform);
}

void MoveObjectVisitor::visitCamera(Camera& camera)
{
    camera.transform(*_transform);
}


