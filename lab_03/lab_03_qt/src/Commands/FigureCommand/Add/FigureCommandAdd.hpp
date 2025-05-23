//
// Created by nuelex on 19/05/25.
//

#ifndef FIGURECOMMANDADD_HPP
#define FIGURECOMMANDADD_HPP
#include "../BaseFigureCommand.hpp"
#include "../../BaseCommand.hpp"


class FigureCommandAdd : public BaseFigureCommand
{
public:
    explicit FigureCommandAdd(const std::string &filename) : _filename(filename) {}
    ~FigureCommandAdd() override = default;

    void setManager(const std::shared_ptr<SceneManager> &manager) override { _sceneManager = manager; }
    void setManager(const std::shared_ptr<LoadManager> &manager) override { _loadManager = manager; }
    void setManager(const std::shared_ptr<DrawManager> &manager) override { _drawManager = manager; }
    void setManager(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    const std::string _filename;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<DrawManager> _drawManager;
};



#endif //FIGURECOMMANDADD_HPP
