//
// Created by nuelex on 19/05/25.
//

#include "FigureCommandAdd.hpp"

#include <iostream>

#include "../../../Exceptions/Commands/CommandsException.hpp"
#include "../../../Exceptions/Managers/LoadManagerException.hpp"
#include "../../../Exceptions/Scene/SceneException.hpp"

void FigureCommandAdd::execute()
{
    try
    {
        const auto object = _loadManager->loadObject(_filename);
        _sceneManager->addObject(object);
    }
    catch (ErrorScene_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorLoadManager_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorLoadManager_invalid_file &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorLoadManager_invalid_loading &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorCommand_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

