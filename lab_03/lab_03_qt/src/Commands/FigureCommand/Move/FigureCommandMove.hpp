//
// Created by nuelex on 21/05/25.
//

#ifndef FIGURECOMMANDMOVE_HPP
#define FIGURECOMMANDMOVE_HPP
#include <memory>

#include "../BaseFigureCommand.hpp"
#include "../../BaseCommand.hpp"
#include "../../../Managers/LoadManager/LoadManager.hpp"
#include "../../../Managers/SceneManager/SceneManager.hpp"
#include "../../../Managers/TransformManager/TransformManager.hpp"
#include "../../../Transforms/Transforms.hpp"


class FigureCommandMove : public BaseFigureCommand
{
public:
    explicit FigureCommandMove(const size_t id, const std::shared_ptr<Mover> &transform) : _id(id), _transform(transform) {}
    ~FigureCommandMove() override = default;

    void setManager(const std::shared_ptr<SceneManager> &manager) override { _sceneManager = manager; }
    void setManager(const std::shared_ptr<LoadManager> &manager) override {}
    void setManager(const std::shared_ptr<DrawManager> &manager) override { _drawManager = manager; }
    void setManager(const std::shared_ptr<TransformManager> &manager) override { _transformManager = manager; }

    void execute() override;

private:
    size_t _id;
    std::shared_ptr<Mover> _transform;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<TransformManager> _transformManager;
};



#endif //FIGURECOMMANDMOVE_HPP
