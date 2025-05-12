//
// Created by nuelex on 12/05/25.
//

#include "Facade.hpp"

#include "../Exceptions/Facade/FacadeException.hpp"
#include "../Exceptions/Factory/ManagerFactoryException.hpp"
#include "../Factory/ManagerFactory/ManagerFactory.hpp"

Facade::Facade()
{
    ManagerFactory managerFactory{};

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

void Facade::execute(BaseCommand& command)
{

}


