//
// Created by nuelex on 10/05/25.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "BaseCamera.hpp"
#include "../BaseObject.hpp"

class CameraPTU : public BaseCamera
{
public:
    CameraPTU() : _position(), _target(), _up() {}
    ~CameraPTU() override = default;

    bool VisibilityCheck() override { return false; }
    bool CompositeCheck() override { return false; }

    void addChild(const std::shared_ptr<BaseObject> &child) override {}
    void removeChild(std::shared_ptr<BaseObject> &child) override {}

    BaseObject::iterator begin() override { return BaseObject::iterator(nullptr); }
    BaseObject::iterator end() override { return BaseObject::iterator(nullptr); }

    [[nodiscard]] const Point &getPosition() const { return _position; }
    void setPosition(const Point &position) { _position = position; }
    void setPosition(Point&& position) { _position = position; }

    [[nodiscard]] const Point &getTarget() const { return _target; }
    void setTarget(const Point &target) { _target = target; }
    void setTarget(Point &&target) { _target = target; }

    [[nodiscard]] const Point &getUp() const { return _up; }
    void setUp(const Point &up) { _up = up; }
    void setUp(Point &&up) { _up = up; }

    void transform(const Mover &mover) override {}
    void transform(const Rotater &rotater) override {}

    void draw() override {}

private:
    Point _position;
    Point _target;
    Point _up;
};



#endif //CAMERA_HPP
