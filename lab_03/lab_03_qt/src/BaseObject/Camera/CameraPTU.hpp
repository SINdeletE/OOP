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
    using value_type = BaseObject;
    using size_type = size_t;
    using iterator = std::list<std::shared_ptr<value_type>>::const_iterator;
    using const_iterator = std::list<std::shared_ptr<value_type>>::const_iterator;

    CameraPTU();
    ~CameraPTU() override;

    bool CompositeCheck() override { return false; }

    void addChild(const std::shared_ptr<BaseObject> &child) override {}
    void removeChild(std::shared_ptr<BaseObject> &child) override {}

    BaseObject::iterator begin() override;
    BaseObject::iterator end() override;

    void move(const Mover &mover) override {}
    void rotate(const Rotater &rotater) override {}

    void draw() override {}

private:
    Point _position;
    Point _target;
    Point _up;
};



#endif //CAMERA_HPP
