//
// Created by nuelex on 20/05/25.
//

#include "RotateObjectVisitor.hpp"

#include "../../../BaseObject/Camera/Camera.hpp"
#include "../../../BaseObject/Camera/CameraPTU.hpp"
#include "../../../BaseObject/Figure/Figure.hpp"
#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/ConcreteFigureLP.hpp"
#include "../../../Exceptions/Visitors/VisitorException.hpp"


RotateObjectVisitor::RotateObjectVisitor(const std::shared_ptr<BaseTransform>& transform) : BaseTransformVisitor(transform)
{
    const auto tfm = dynamic_pointer_cast<Rotater>(transform);

    if (tfm == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _transform = tfm;
}

void RotateObjectVisitor::visit(ConcreteFigureLP& figure)
{
    figure.figureLP_->transform(*_transform);
}

void RotateObjectVisitor::visit(CameraPTU& camera)
{
    camera._cameraPTU->transform(*_transform);
}





