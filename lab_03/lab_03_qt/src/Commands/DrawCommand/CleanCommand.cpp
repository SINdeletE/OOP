//
// Created by nuelex on 22/05/25.
//

#include "CleanCommand.hpp"

void CleanCommand::execute()
{
    try
    {
        _action(_drawer);
    }
    catch (...)
    {
        throw;
    }
}
