//
// Created by nuelex on 22/05/25.
//

#ifndef CLEANCOMMAND_HPP
#define CLEANCOMMAND_HPP
#include "BaseDrawCommand.hpp"
#include "../BaseCommand.hpp"


class CleanCommand : public BaseDrawCommand
{
public:
    explicit CleanCommand(const std::shared_ptr<BaseDrawer> &drawer) : _drawer(drawer), _drawManager() {}
    ~CleanCommand() override = default;

    void setManager(const std::shared_ptr<SceneManager> &manager) override {}
    void setManager(const std::shared_ptr<LoadManager> &manager) override {}
    void setManager(const std::shared_ptr<DrawManager> &manager) override { _drawManager = manager; }
    void setManager(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;

    std::shared_ptr<DrawManager> _drawManager;
};



#endif //CLEANCOMMAND_HPP
