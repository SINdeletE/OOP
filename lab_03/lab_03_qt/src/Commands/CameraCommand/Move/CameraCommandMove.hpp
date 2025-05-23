//
// Created by nuelex on 23/05/25.
//

#ifndef CAMERAMOVECOMMAND_HPP
#define CAMERAMOVECOMMAND_HPP
#include "../BaseCameraCommand.hpp"


class CameraCommandMove : public BaseCameraCommand
{
public:
    explicit CameraCommandMove(const size_t id, const std::shared_ptr<Mover> &transform) : _id(id), _transform(transform) {}
    ~CameraCommandMove() override = default;

    void setManager(const std::shared_ptr<SceneManager> &manager) override { _sceneManager = manager; }
    void setManager(const std::shared_ptr<LoadManager> &manager) override {}
    void setManager(const std::shared_ptr<DrawManager> &manager) override {}
    void setManager(const std::shared_ptr<TransformManager> &manager) override { _transformManager = manager; }

    void execute() override;

private:
    size_t _id;
    std::shared_ptr<Mover> _transform;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
};



#endif //CAMERAMOVECOMMAND_HPP
