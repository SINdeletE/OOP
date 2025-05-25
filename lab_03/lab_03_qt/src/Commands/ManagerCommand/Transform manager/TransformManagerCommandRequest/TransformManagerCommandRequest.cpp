//
// Created by nuelex on 21/05/25.
//

#include "TransformManagerCommandRequest.hpp"

#include "../../../../Exceptions/Commands/CommandsException.hpp"
#include "../../../../Exceptions/Managers/TransformManager/TransformManagerException.hpp"

void TransformManagerCommandRequest::execute()
{
    try
    {
        _action();
    }
    catch (ErrorTransformManager_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorTransformManager_invalid_transform &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorTransformManager_invalid_object &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

