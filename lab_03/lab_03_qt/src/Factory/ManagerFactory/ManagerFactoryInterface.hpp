//
// Created by nuelex on 12/05/25.
//

#ifndef MANAGERFACTORYINTERFACE_HPP
#define MANAGERFACTORYINTERFACE_HPP
#include <memory>

#include "../BaseFactory.hpp"
#include "../../Managers/LoadManager/LoadManager.hpp"
#include "../../Managers/SceneManager/SceneManager.hpp"


class ManagerFactoryInterface : public BaseFactory
{
public:
    ManagerFactoryInterface() = default;
    ~ManagerFactoryInterface() override = default;

    virtual std::shared_ptr<SceneManager> createSceneManager() = 0;
    virtual std::shared_ptr<LoadManager> createLoadManager() = 0;
};



#endif //MANAGERFACTORYINTERFACE_HPP
