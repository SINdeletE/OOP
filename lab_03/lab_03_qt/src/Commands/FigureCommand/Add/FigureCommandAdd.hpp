//
// Created by nuelex on 19/05/25.
//

#ifndef FIGURECOMMANDADD_HPP
#define FIGURECOMMANDADD_HPP
#include <functional>

#include "../BaseFigureCommand.hpp"
#include "../../BaseCommand.hpp"


class FigureCommandAdd : public BaseFigureCommand
{
public:
    explicit FigureCommandAdd(const BaseObject::shared_ptr_type& object) : _object(object) {}
    ~FigureCommandAdd() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override
    {
        _action = [manager](const BaseObject::shared_ptr_type& object) { manager->addObject(object); };
    }
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override { _loadManager = manager; }
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override { _drawManager = manager; }
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    BaseObject::shared_ptr_type _object;
    std::function<void(const BaseObject::shared_ptr_type&)> _action;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<DrawManager> _drawManager;
};



#endif //FIGURECOMMANDADD_HPP
