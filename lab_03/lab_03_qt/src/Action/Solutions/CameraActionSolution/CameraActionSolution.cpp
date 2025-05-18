//
// Created by nuelex on 18/05/25.
//

#include "CameraActionSolution.hpp"

#include "../../../Exceptions/Actions/ActionException.hpp"
#include "../../../Exceptions/Managers/TransformManager/TransformManagerException.hpp"
#include "../../CameraAction/Move/CameraActionMove.hpp"
#include "../../CameraAction/Rotate/CameraActionRotate.hpp"


void CameraActionSolution::reg(const std::shared_ptr<BaseTransform> &transform, const std::shared_ptr<CameraAction> &action)
{
    _actions[transform] = action;
}

CameraActionSolution::CameraActionSolution()
{
    try
    {
        reg(std::make_shared<Mover>(), std::make_shared<CameraActionMove>());
        reg(std::make_shared<Rotater>(), std::make_shared<CameraActionRotate>());
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<CameraAction> CameraActionSolution::createAction(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<BaseTransform> &transform)
{
    const auto actions_iter = _actions.find(transform);

    if (actions_iter == _actions.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_transform(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    try
    {
        const auto action = actions_iter->second;
        action->setParams(object, transform);

        return action;
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorAction_invalid_object &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_object(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorAction_invalid_transform &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_transform(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}
