//
// Created by nuelex on 20/05/25.
//

#include "ScaleObjectVisitor.hpp"

#include "../../../BaseObject/Figure/Figure.hpp"
#include "../../../Exceptions/Visitors/VisitorException.hpp"

ScaleObjectVisitor::ScaleObjectVisitor(const std::shared_ptr<BaseTransform>& transform) : BaseTransformVisitor(transform)
{
    auto tfm = dynamic_pointer_cast<Scaler>(transform);

    if (tfm == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _transform = tfm;
}

void ScaleObjectVisitor::visitFigure(Figure& figure)
{
    figure.transform(*_transform);
}


