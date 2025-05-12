//
// Created by nuelex on 12/05/25.
//

#include "ManagerFactory.hpp"

#include "../../Exceptions/Factory/ManagerFactoryException.hpp"

std::shared_ptr<SceneManager> ManagerFactory::createSceneManager()
{
    SceneManager sceneManager{};

    try
    {
        return std::make_shared<SceneManager>(sceneManager);
    }
    catch (std::bad_alloc& e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorManagerFactory_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<LoadManager> ManagerFactory::createLoadManager()
{
    LoadManager loadManager{};

    try
    {
        return std::make_shared<LoadManager>(loadManager);
    }
    catch (std::bad_alloc& e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorManagerFactory_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}


