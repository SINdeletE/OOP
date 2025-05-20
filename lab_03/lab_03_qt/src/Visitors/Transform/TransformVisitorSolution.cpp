//
// Created by nuelex on 20/05/25.
//

#include "TransformVisitorSolution.hpp"

#include <qvariant.h>

#include "../../Exceptions/Visitors/VisitorException.hpp"
#include "Move/MoveObjectVisitor.hpp"
#include "Rotate/RotateObjectVisitor.hpp"
#include "Scale/ScaleObjectVisitor.hpp"

TransformVisitorSolution::TransformVisitorSolution()
{
    try
    {
        this->reg(std::make_shared<Mover>(), std::make_shared<ConcreteTransformVisitor<MoveObjectVisitor>>());
        this->reg(std::make_shared<Rotater>(), std::make_shared<ConcreteTransformVisitor<RotateObjectVisitor>>());
        this->reg(std::make_shared<Scaler>(), std::make_shared<ConcreteTransformVisitor<ScaleObjectVisitor>>());
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void TransformVisitorSolution::reg(const std::shared_ptr<BaseTransform>& transform, const std::shared_ptr<TransformVisitorCreator>& creator)
{
    _creators[transform] = creator;
}

std::shared_ptr<BaseTransformVisitor> TransformVisitorSolution::createVisitor(const std::shared_ptr<BaseTransform>& transform)
{
    const auto iter = _creators.find(transform);
    if (iter == _creators.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    try
    {
        return iter->second->createVisitor(transform);
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}



