//
// Created by nuelex on 11/05/25.
//

#include "CameraActionRotate.hpp"

#include "../../../Exceptions/Actions/ActionException.hpp"

void CameraActionRotate::setParams(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<BaseTransform> &transform)
{
    _camera = std::dynamic_pointer_cast<Camera>(object);
    if (_camera == nullptr)
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

void CameraActionRotate::request() const
{
    _camera->transform(*_transform);
}

