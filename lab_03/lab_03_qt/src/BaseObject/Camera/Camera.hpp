//
// Created by nuelex on 18/05/25.
//

#ifndef CAMERA_TRANSFORM_HPP
#define CAMERA_TRANSFORM_HPP
#include "../BaseObject.hpp"
#include "../../Visitors/BaseVisitor.hpp"


class Camera : public BaseObject
{
public:
    Camera() = default;
    ~Camera() override = default;

    bool CompositeCheck() override { return false; }
    bool VisibilityCheck() override { return false; }

    void addChild(const std::shared_ptr<BaseObject> &child) override {}
    void removeChild(std::shared_ptr<BaseObject> &child) override {}

    BaseObject::iterator begin() override { return BaseObject::iterator(nullptr); }
    BaseObject::iterator end() override { return BaseObject::iterator(nullptr); }

    void transform(const Mover &mover) override {}
    void transform(const Rotater& rotater) override {}

    void accept(const BaseVisitor& visitor) override;
};



#endif //CAMERA_TRANSFORM_HPP
