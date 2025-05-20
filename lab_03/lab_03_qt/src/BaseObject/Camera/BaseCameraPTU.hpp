//
// Created by nuelex on 16/05/25.
//

#ifndef BASECAMERA_HPP
#define BASECAMERA_HPP
#include "Camera.hpp"
#include "../BaseObject.hpp"


class BaseCameraPTU : public Camera
{
public:
    BaseCameraPTU() = default;
    ~BaseCameraPTU() override = default;

    bool VisibilityCheck() override { return false; }

    [[nodiscard]] virtual const Point &getPosition() const = 0;
    virtual void setPosition(const Point &position) = 0;
    virtual void setPosition(Point&& position) = 0;

    [[nodiscard]] virtual const Point &getTarget() const = 0;
    virtual void setTarget(const Point &target) = 0;
    virtual void setTarget(Point &&target) = 0;

    [[nodiscard]] virtual const Point &getUp() const = 0;
    virtual void setUp(const Point &up) = 0;
    virtual void setUp(Point &&up) = 0;

    void transform(const Mover &mover) override {}
    void transform(const Rotater &rotater) override {}

    void accept(const BaseVisitor& visitor) override {}
    void accept(BaseTransformVisitor &visitor) override { visitor.visitCamera(*this); }
};



#endif //BASECAMERA_HPP
