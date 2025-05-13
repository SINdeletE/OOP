//
// Created by nuelex on 12/05/25.
//

#ifndef FACADE_HPP
#define FACADE_HPP
#include <memory>

#include "../Commands/BaseCommand.hpp"
#include "../Managers/SceneManager/SceneManager.hpp"
#include "../Factory/ManagerFactory/ManagerFactory.hpp"


class Facade final
{
public:
    Facade();
    ~Facade() = default;

    void execute(BaseCommand &command) const;

private:
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<TransformManager> _transformManager;

    void createSceneManager(const ManagerFactory& managerFactory);
    void createLoadManager(const ManagerFactory& managerFactory);
    void createDrawManager(const ManagerFactory& managerFactory);
    void createTransformManager(const ManagerFactory& managerFactory);

};



#endif //FACADE_HPP
