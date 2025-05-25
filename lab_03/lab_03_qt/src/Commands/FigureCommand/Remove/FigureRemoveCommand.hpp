//
// Created by nuelex on 21/05/25.
//

#ifndef FIGUREREMOVECOMMAND_HPP
#define FIGUREREMOVECOMMAND_HPP
#include "../BaseFigureCommand.hpp"
#include "../../BaseCommand.hpp"


class FigureRemoveCommand : public BaseFigureCommand
{
public:
    explicit FigureRemoveCommand(const size_t id) { _id = id; }

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override { _sceneManager = manager; }
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override { _drawManager = manager; }
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    size_t _id;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<DrawManager> _drawManager;
};



#endif //FIGUREREMOVECOMMAND_HPP
