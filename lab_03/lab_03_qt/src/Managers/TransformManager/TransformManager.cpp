//
// Created by nuelex on 12/05/25.
//

#include "TransformManager.hpp"

#include "../../Exceptions/Managers/TransformManager/TransformManagerException.hpp"
#include "../../Exceptions/Visitors/VisitorException.hpp"
#include "../../Visitors/Transform/TransformVisitorSolution.hpp"

TransformManager::TransformManager(const std::shared_ptr<BaseObject>& object, const std::shared_ptr<BaseTransform>& transform)
{
    this->setParams(object, transform);
}

void TransformManager::request()
{
    if (_object == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_object(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    try
    {
        TransformVisitorSolution solution{};
        auto vis = solution.createVisitor(_transform);
        _object->accept(*vis);
    }
    catch (ErrorVisitor_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorVisitor_invalid_data &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_transform(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void TransformManager::setParams(const std::shared_ptr<BaseObject>& object, const std::shared_ptr<BaseTransform>& transform)
{
    _object = object;
    _transform = transform;
}


