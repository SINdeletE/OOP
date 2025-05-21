//
// Created by nuelex on 21/05/25.
//

#ifndef FIGURECOMMANDROTATE_HPP
#define FIGURECOMMANDROTATE_HPP
#include "../../BaseCommand.hpp"


class FigureCommandRotate : public BaseCommand
{
public:
    explicit FigureCommandRotate(const size_t id, const std::shared_ptr<Rotater> &transform) : _id(id), _transform(transform) {}
    ~FigureCommandRotate() override = default;

    void setManager(const std::shared_ptr<SceneManager> &manager) override { _sceneManager = manager; }
    void setManager(const std::shared_ptr<LoadManager> &manager) override {}
    void setManager(const std::shared_ptr<DrawManager> &manager) override { _drawManager = manager; }
    void setManager(const std::shared_ptr<TransformManager> &manager) override { _transformManager = manager; }

    void execute() override;

private:
    size_t _id;
    std::shared_ptr<Rotater> _transform;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<TransformManager> _transformManager;
};



#endif //FIGURECOMMANDROTATE_HPP
