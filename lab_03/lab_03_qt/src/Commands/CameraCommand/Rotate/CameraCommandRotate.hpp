//
// Created by nuelex on 23/05/25.
//

#ifndef CAMERACOMMANDROTATE_HPP
#define CAMERACOMMANDROTATE_HPP
#include "../BaseCameraCommand.hpp"


class CameraCommandRotate : public BaseCameraCommand
{
public:
    explicit CameraCommandRotate(const size_t id, const std::shared_ptr<Rotater> &transform) : _id(id), _transform(transform) {}
    ~CameraCommandRotate() override = default;

    void setManager(const std::shared_ptr<SceneManager> &manager) override { _sceneManager = manager; }
    void setManager(const std::shared_ptr<LoadManager> &manager) override {}
    void setManager(const std::shared_ptr<DrawManager> &manager) override {}
    void setManager(const std::shared_ptr<TransformManager> &manager) override { _transformManager = manager; }

    void execute() override;

private:
    size_t _id;
    std::shared_ptr<Rotater> _transform;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
};



#endif //CAMERACOMMANDROTATE_HPP
