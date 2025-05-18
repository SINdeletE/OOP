//
// Created by nuelex on 12/05/25.
//

#include "TransformManager.hpp"

#include "../../Action/Solutions/ObjectActionSolution.hpp"
#include "../../Exceptions/Managers/TransformManager/TransformManagerException.hpp"

TransformManager::TransformManager(const std::shared_ptr<BaseObject>& object, const std::shared_ptr<BaseTransform>& transform)
{
   this->setParams(object, transform);
}

void TransformManager::request()
{
    if (! _action)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_params(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _action->request();
}

void TransformManager::setParams(const std::shared_ptr<BaseObject>& object, const std::shared_ptr<BaseTransform>& transform)
{
    _object = object;
    _transform = transform;

    ObjectActionSolution object_solution{};
    const auto transform_solution = object_solution.create(_object);
    _action = transform_solution(_object, _transform);

    if (! _action)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_params(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}


