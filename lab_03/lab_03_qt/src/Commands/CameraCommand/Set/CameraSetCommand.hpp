//
// Created by nuelex on 23/05/25.
//

#ifndef CAMERASETCOMMAND_HPP
#define CAMERASETCOMMAND_HPP
#include <functional>

#include "../BaseCameraCommand.hpp"
#include "../../BaseCommand.hpp"


class CameraSetCommand : public BaseCameraCommand
{
public:
    explicit CameraSetCommand(const std::shared_ptr<BaseObject>& object) : _camera(object) {}
    ~CameraSetCommand() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override
    {
        _action = [manager](const std::shared_ptr<BaseObject>& object) { manager->setCamera(object); };
    }
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    std::function<void(const std::shared_ptr<BaseObject>&)> _action;
    std::shared_ptr<BaseObject> _camera;
};



#endif //CAMERASETCOMMAND_HPP
