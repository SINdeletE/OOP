//
// Created by nuelex on 11/05/25.
//

#include "FigureActionRotate.hpp"

#include "../../../Exceptions/Actions/ActionException.hpp"

void FigureActionRotate::setParams(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<BaseTransform> &transform)
{
    _figure = std::dynamic_pointer_cast<Figure>(object);
    if (_figure == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorAction_invalid_object(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _transform = dynamic_pointer_cast<Rotater>(transform);
    if (_transform == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorAction_invalid_transform(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void FigureActionRotate::request() const
{
    _figure->transform(*_transform);
}



