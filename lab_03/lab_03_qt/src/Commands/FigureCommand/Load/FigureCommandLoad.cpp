//
// Created by nuelex on 25/05/25.
//

#include "FigureCommandLoad.hpp"

#include "../../../Exceptions/Commands/CommandsException.hpp"
#include "../../../Exceptions/Managers/LoadManagerException.hpp"


void FigureCommandLoad::execute()
{
    try
    {
        _object = _action(_filename);
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
