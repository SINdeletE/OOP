//
// Created by nuelex on 23/05/25.
//

#ifndef CAMERASETCOMMAND_HPP
#define CAMERASETCOMMAND_HPP
#include "../BaseCameraCommand.hpp"
#include "../../BaseCommand.hpp"


class CameraSetCommand : public BaseCameraCommand
{
public:
    explicit CameraSetCommand(size_t id) : _id(id) {}
    ~CameraSetCommand() override = default;

    void setManager(const std::shared_ptr<SceneManager> &manager) override { _sceneManager = manager; }
    void setManager(const std::shared_ptr<LoadManager> &manager) override {}
    void setManager(const std::shared_ptr<DrawManager> &manager) override { _drawManager = manager; }
    void setManager(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    size_t _id;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<DrawManager> _drawManager;
};



#endif //CAMERASETCOMMAND_HPP
