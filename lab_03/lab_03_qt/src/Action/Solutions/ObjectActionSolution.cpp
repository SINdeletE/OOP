//
// Created by nuelex on 17/05/25.
//

#include "ObjectActionSolution.hpp"

#include <iostream>

#include "../../BaseObject/Camera/Camera.hpp"
#include "../../BaseObject/Figure/Figure.hpp"
#include "../../Exceptions/Hashes/BaseObjectHashException.hpp"
#include "../../Exceptions/Managers/TransformManager/TransformManagerException.hpp"

void ObjectActionSolution::reg(const std::shared_ptr<BaseObject> &object, const_reference lambda_ref)
{
    try
    {
        _actions[object] = lambda_ref;
    }
    catch (ErrorBaseObjectHash_invalid_key &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_object(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

ObjectActionSolution::ObjectActionSolution()
{
    auto lambda_Figure = [](const std::shared_ptr<BaseObject>&, \
                            const std::shared_ptr<BaseTransform>&) -> std::shared_ptr<BaseAction>
    {
        return nullptr;
    };
    auto lambda_Camera = [](const std::shared_ptr<BaseObject>&, \
                            const std::shared_ptr<BaseTransform>&) -> std::shared_ptr<BaseAction>
    {
        return nullptr;
    };

    try
    {
        this->reg(std::make_shared<Figure>(), lambda_Figure);
        this->reg(std::make_shared<Camera>(), lambda_Camera);
    }
    catch (ErrorBaseObjectHash_invalid_key &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_object(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

ObjectActionSolution::value_type ObjectActionSolution::create(const std::shared_ptr<BaseObject>& object)
{
    try
    {
        const auto bucket = _actions.find(object);
        if (bucket == _actions.end())
        {
            const time_t cur_time = time(nullptr);
            throw ErrorTransformManager_invalid_object(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }

        return bucket->second;
    }
    catch (ErrorBaseObjectHash_invalid_key &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorTransformManager_invalid_object(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

