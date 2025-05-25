//
// Created by nuelex on 12/05/25.
//

#include "LoadManager.hpp"

#include "../../Builders/Moderators/Solution/LoadModeratorSolution.hpp"
#include "../../Exceptions/Directors/DirectorException.hpp"
#include "../../Exceptions/Managers/LoadManagerException.hpp"
#include "../../Exceptions/Moderator/ModeratorException.hpp"

std::shared_ptr<BaseObject> LoadManager::loadObject(const std::string& filename)
{
    try
    {
        LoadModeratorSolution solution{};
        auto moderator = solution.createLoadModerator(filename);

        auto object = moderator->load(filename);
        if (object == nullptr)
        {
            const time_t cur_time = time(nullptr);
            throw ErrorLoadManager_invalid_file(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }

        return object;
    }
    catch (ErrorModerator_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorLoadManager_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    catch (ErrorModerator_invalid_filename &e)
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

