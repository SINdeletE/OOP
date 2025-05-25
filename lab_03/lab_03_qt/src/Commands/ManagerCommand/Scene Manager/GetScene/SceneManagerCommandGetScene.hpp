//
// Created by nuelex on 25/05/25.
//

#ifndef SCENEMANAGERCOMMANDGETSCENE_HPP
#define SCENEMANAGERCOMMANDGETSCENE_HPP
#include <functional>

#include "../BaseSceneManagerCommand.hpp"


class SceneManagerCommandGetScene : public BaseSceneManagerCommand
{
public:
    SceneManagerCommandGetScene(std::shared_ptr<Scene>& scene) : _scene(scene) {}
    ~SceneManagerCommandGetScene() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override
    {
        _action = [manager](){ return manager->getScene(); };
    }
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    std::shared_ptr<Scene>& _scene;
    std::function<std::shared_ptr<Scene>()> _action;
};



#endif //SCENEMANAGERCOMMANDGETSCENE_HPP
