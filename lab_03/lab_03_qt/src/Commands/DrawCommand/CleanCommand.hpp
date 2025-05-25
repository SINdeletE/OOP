//
// Created by nuelex on 22/05/25.
//

#ifndef CLEANCOMMAND_HPP
#define CLEANCOMMAND_HPP
#include <functional>

#include "BaseDrawCommand.hpp"
#include "../BaseCommand.hpp"


class CleanCommand : public BaseDrawCommand
{
public:
    explicit CleanCommand(const std::shared_ptr<BaseDrawer> &drawer) : _drawer(drawer) {}
    ~CleanCommand() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override
    {
        _action = [manager](const std::shared_ptr<BaseDrawer> &drawer){ manager->clear(drawer); };
    }
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::function<void(const std::shared_ptr<BaseDrawer> &)> _action;
};



#endif //CLEANCOMMAND_HPP
