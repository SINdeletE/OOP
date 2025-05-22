//
// Created by nuelex on 22/05/25.
//

#include "CameraRemoveCommand.hpp"

#include "../../../Exceptions/Commands/CommandsException.hpp"
#include "../../../Exceptions/Scene/SceneException.hpp"

void CameraRemoveCommand::execute()
{
    try
    {
        if (_drawManager->getCamera() == _sceneManager->getCameraByID(_id))
        {
            _drawManager->setCamera(nullptr);
        }

        _sceneManager->removeCamera(_id);
    }
    catch (ErrorScene_out_of_range &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_out_of_range(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

