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
        const auto object = _sceneManager->getCameraByID(_id);
        _drawManager->setCamera(object);
    }
    catch(ErrorScene_out_of_range &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_out_of_range(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch(ErrorDrawManager_invalid_camera &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

