//
// Created by nuelex on 22/05/25.
//

#ifndef DRAWCOMMAND_HPP
#define DRAWCOMMAND_HPP
#include <functional>
#include <memory>

#include "BaseDrawCommand.hpp"
#include "../BaseCommand.hpp"


class DrawCommand : public BaseDrawCommand
{
public:
    explicit DrawCommand(const std::shared_ptr<Scene>& scene, const std::shared_ptr<BaseDrawer> &drawer) : _scene(scene), _drawer(drawer) {}
    ~DrawCommand() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override
    {
        _action = [manager](const std::shared_ptr<Scene> &scene, const std::shared_ptr<BaseDrawer> &drawer)
        {
            manager->drawScene(scene, drawer);
        };
    }
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<BaseDrawer> _drawer;

    std::function<void(const std::shared_ptr<Scene>&, const std::shared_ptr<BaseDrawer> &)> _action;
};



#endif //DRAWCOMMAND_HPP
