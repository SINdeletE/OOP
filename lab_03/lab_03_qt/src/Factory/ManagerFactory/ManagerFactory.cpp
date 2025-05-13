//
// Created by nuelex on 12/05/25.
//

#include "ManagerFactory.hpp"

#include "../../Exceptions/Factory/ManagerFactoryException.hpp"

std::shared_ptr<SceneManager> ManagerFactory::createSceneManager() const
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

std::shared_ptr<LoadManager> ManagerFactory::createLoadManager() const
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

std::shared_ptr<DrawManager> ManagerFactory::createDrawManager() const
{
    DrawManager drawManager{};

    try
    {
        return std::make_shared<DrawManager>(drawManager);
    }
    catch (std::bad_alloc& e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorManagerFactory_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<TransformManager> ManagerFactory::createTransformManager() const
{
    TransformManager transformManager{};

    try
    {
        return std::make_shared<TransformManager>(transformManager);
    }
    catch (std::bad_alloc& e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorManagerFactory_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

