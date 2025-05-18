//
// Created by nuelex on 11/05/25.
//

#ifndef CAMERAACTION_HPP
#define CAMERAACTION_HPP
#include <memory>

#include "../BaseAction.hpp"
#include "../../BaseObject/Camera/Camera.hpp"


class CameraAction : public BaseAction
{
public:
    CameraAction() = default;
    CameraAction(const std::shared_ptr<Camera> &camera, const std::shared_ptr<BaseTransform> &transform) : _camera(camera), _transform(transform) {}
    ~CameraAction() override = default;

    void request() const override {}

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseTransform> _transform;
};



#endif //CAMERAACTION_HPP
