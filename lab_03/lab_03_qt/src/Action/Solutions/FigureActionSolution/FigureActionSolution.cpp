//
// Created by nuelex on 18/05/25.
//

#include "FigureActionSolution.hpp"

#include "../../../Exceptions/Actions/ActionException.hpp"
#include "../../../Exceptions/Managers/TransformManager/TransformManagerException.hpp"
#include "../../FigureAction/Move/FigureActionMove.hpp"
#include "../../FigureAction/Rotate/FigureActionRotate.hpp"
#include "../../FigureAction/Scale/FigureActionScale.hpp"

void FigureActionSolution::reg(const std::shared_ptr<BaseTransform> &transform, const std::shared_ptr<FigureAction> &action)
{
    _actions[transform] = action;
}

FigureActionSolution::FigureActionSolution()
{
    try
    {
        reg(std::make_shared<Mover>(), std::make_shared<FigureActionMove>());
        reg(std::make_shared<Rotater>(), std::make_shared<FigureActionRotate>());
        reg(std::make_shared<Scaler>(), std::make_shared<FigureActionScale>());
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<FigureAction> FigureActionSolution::createAction(const std::shared_ptr<BaseObject> &object, const std::shared_ptr<BaseTransform> &transform)
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


