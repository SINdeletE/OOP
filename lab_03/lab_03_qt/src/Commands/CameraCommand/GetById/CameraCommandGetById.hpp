//
// Created by nuelex on 25/05/25.
//

#ifndef CAMERACOMMANDGETBYID_HPP
#define CAMERACOMMANDGETBYID_HPP
#include <functional>

#include "../BaseCameraCommand.hpp"


class CameraCommandGetById : public BaseCameraCommand
{
public:
    CameraCommandGetById(std::shared_ptr<BaseObject>& object, size_t id) : _id(id), _object(object) {}
    ~CameraCommandGetById() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override { _action = \
                                    [manager](size_t id) { return manager->getCameraByID(id); }; }
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    std::function<BaseObject::shared_ptr_type(size_t)> _action;

    size_t _id;
    std::shared_ptr<BaseObject>& _object;
};



#endif //CAMERACOMMANDGETBYID_HPP
