//
// Created by nuelex on 25/05/25.
//

#ifndef CAMERACOMMANDGETACTIVE_HPP
#define CAMERACOMMANDGETACTIVE_HPP
#include <functional>

#include "../BaseCameraCommand.hpp"


class CameraCommandGetActive : public BaseCameraCommand
{
public:
    explicit CameraCommandGetActive(std::shared_ptr<BaseObject>& object) : _object(object) {}
    ~CameraCommandGetActive() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override { _action = \
                                    [manager]() { return manager->getCamera(); }; }
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    std::function<BaseObject::shared_ptr_type()> _action;
    std::shared_ptr<BaseObject>& _object;
};



#endif //CAMERACOMMANDGETACTIVE_HPP
