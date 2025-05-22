//
// Created by nuelex on 22/05/25.
//

#include "DrawCommand.hpp"

#include "../../Exceptions/Managers/DrawManagerException.hpp"

void DrawCommand::execute()
{
    try
    {
        _drawManager->drawScene(_sceneManager->getScene(), _drawer);
    }
    catch (ErrorDrawManager_no_camera &e)
    {
        ;
    }
    catch (...)
    {
        throw;
    }
}

