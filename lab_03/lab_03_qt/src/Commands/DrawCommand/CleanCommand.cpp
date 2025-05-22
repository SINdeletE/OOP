//
// Created by nuelex on 22/05/25.
//

#include "CleanCommand.hpp"

void CleanCommand::execute()
{
    try
    {
        _drawManager->clear(_drawer);
    }
    catch (...)
    {
        throw;
    }
}
