//
// Created by nuelex on 22/05/25.
//

#ifndef CAMERAREMOVECOMMAND_HPP
#define CAMERAREMOVECOMMAND_HPP
#include <functional>

#include "../BaseCameraCommand.hpp"
#include "../../BaseCommand.hpp"


class CameraRemoveCommand : public BaseCameraCommand
{
public:
    explicit CameraRemoveCommand(const size_t id) { _id = id; }

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override
    {
        _action = [manager](size_t id) { manager->removeCamera(id); };
    }
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    size_t _id;
    std::function<void(size_t)> _action;
};



#endif //CAMERAREMOVECOMMAND_HPP
