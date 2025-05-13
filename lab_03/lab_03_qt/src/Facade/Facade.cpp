//
// Created by nuelex on 12/05/25.
//

#include "Facade.hpp"

#include "../Exceptions/Facade/FacadeException.hpp"
#include "../Exceptions/Factory/ManagerFactoryException.hpp"
#include "../Factory/ManagerFactory/ManagerFactory.hpp"

void Facade::createSceneManager(const ManagerFactory& managerFactory)
{
    try
    {
        _sceneManager = managerFactory.createSceneManager();
    }
    catch (ErrorManagerFactory_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorFacade_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void Facade::createLoadManager(const ManagerFactory& managerFactory)
{
    try
    {
        _loadManager = managerFactory.createLoadManager();
    }
    catch (ErrorManagerFactory_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorFacade_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void Facade::createDrawManager(const ManagerFactory& managerFactory)
{
    try
    {
        _drawManager = managerFactory.createDrawManager();
    }
    catch (ErrorManagerFactory_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorFacade_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void Facade::createTransformManager(const ManagerFactory& managerFactory)
{
    try
    {
        _transformManager = managerFactory.createTransformManager();
    }
    catch (ErrorManagerFactory_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorFacade_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}


Facade::Facade()
{
    const ManagerFactory managerFactory{};

    createSceneManager(managerFactory);
    createLoadManager(managerFactory);
    createDrawManager(managerFactory);
    createTransformManager(managerFactory);
}

void Facade::execute(BaseCommand& command) const
{
    command.setManager(_sceneManager);
    command.setManager(_loadManager);
    command.setManager(_drawManager);
    command.setManager(_transformManager);

    command.execute();
}


