//
// Created by nuelex on 11/05/25.
//

#include "CameraActionMove.hpp"

#include <qvariant.h>
#include <ranges>

#include "../../../Exceptions/Actions/ActionException.hpp"

void CameraActionMove::setParams(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<BaseTransform> &transform)
{
    _camera = dynamic_pointer_cast<Camera>(object);
    if (_camera == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorAction_invalid_object(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _transform = dynamic_pointer_cast<Mover>(transform);
    if (_transform == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorAction_invalid_transform(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void CameraActionMove::request() const
{
    _camera->transform(*_transform);
}


