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
    CameraAction(const CameraAction& copy) = default;
    CameraAction(const std::shared_ptr<Camera> &camera, const std::shared_ptr<BaseTransform> &transform) {}
    ~CameraAction() override = default;

    void setParams(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&) override {}

    void request() const override {}
};



#endif //CAMERAACTION_HPP
