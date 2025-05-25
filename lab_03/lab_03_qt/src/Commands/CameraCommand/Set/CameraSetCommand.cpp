//
// Created by nuelex on 23/05/25.
//

#include "CameraSetCommand.hpp"

#include "../../../Exceptions/Commands/CommandsException.hpp"
#include "../../../Exceptions/Managers/DrawManagerException.hpp"
#include "../../../Exceptions/Scene/SceneException.hpp"

void CameraSetCommand::execute()
{
    try
    {
        _action(_camera);
    }
    catch(ErrorDrawManager_invalid_camera &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

