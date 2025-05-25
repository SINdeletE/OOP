//
// Created by nuelex on 20/05/25.
//

#include "MoveObjectVisitor.hpp"

#include <qvariant.h>

#include "../../../BaseObject/Camera/CameraPTU.hpp"
#include "../../../BaseObject/Figure/Figure.hpp"
#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/ConcreteFigureLP.hpp"
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

void MoveObjectVisitor::visit(ConcreteFigureLP& figure)
{
    figure.figureLP_->transform(*_transform);
}

void MoveObjectVisitor::visit(CameraPTU& camera)
{
    camera._cameraPTU->transform(*_transform);
}


