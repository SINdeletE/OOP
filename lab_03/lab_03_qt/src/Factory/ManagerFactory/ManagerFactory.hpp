//
// Created by nuelex on 12/05/25.
//

#ifndef MANAGERFACTORY_HPP
#define MANAGERFACTORY_HPP
#include <memory>

#include "ManagerFactoryInterface.hpp"
#include "../../Managers/LoadManager/LoadManager.hpp"
#include "../../Managers/SceneManager/SceneManager.hpp"


class ManagerFactory final: public ManagerFactoryInterface
{
public:
    ManagerFactory() = default;
    ~ManagerFactory() override = default;

    std::shared_ptr<SceneManager> createSceneManager() override;
    std::shared_ptr<LoadManager> createLoadManager() override;
};



#endif //MANAGERFACTORY_HPP
