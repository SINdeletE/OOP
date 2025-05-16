//
// Created by nuelex on 12/05/25.
//

#include "LoadManager.hpp"

#include "../../Builders/Directors/DirectorSolution.hpp"
#include "../../Exceptions/Directors/DirectorException.hpp"
#include "../../Exceptions/Managers/LoadManagerException.hpp"

std::shared_ptr<BaseObject> LoadManager::loadObject(const std::string& filename)
{
    try
    {
        DirectorSolution solution;
        const std::shared_ptr<BaseObjectDirector> object_director = solution.createDirector(filename);

        return object_director->create();
    }
    catch (ErrorDirector_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorLoadManager_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorDirector_invalid_file &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorLoadManager_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (...)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorLoadManager_invalid_loading(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

