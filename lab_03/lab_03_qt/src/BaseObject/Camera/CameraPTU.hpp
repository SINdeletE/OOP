//
// Created by nuelex on 10/05/25.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "BaseCameraPTU.hpp"
#include "../BaseObject.hpp"
#include "../../Transforms/Vec.hpp"

class CameraPTU : public BaseCameraPTU
{
public:
    CameraPTU() : _position(), _target(), _up() {}
    ~CameraPTU() override = default;

    bool VisibilityCheck() override { return false; }
    bool CompositeCheck() override { return false; }

    BaseObject::iterator begin() override { return BaseObject::iterator(nullptr); }
    BaseObject::iterator end() override { return BaseObject::iterator(nullptr); }

    [[nodiscard]] const Point &getPosition() const override { return _position; }
    void setPosition(const Point &position) override { _position = position; }
    void setPosition(Point&& position) override { _position = position; }

    [[nodiscard]] const Point &getTarget() const override { return _target; }
    void setTarget(const Point &target) override { _target = target; }
    void setTarget(Point &&target) override { _target = target; }

    [[nodiscard]] const Vec &getUp() const override { return _up; }
    void setUp(const Point &up) override { _up = up; }
    void setUp(Point &&up) override { _up = up; }
    void setUp(const Vec &up) override { _up = up; }
    void setUp(Vec &&up) override { _up = up; }

    void transform(const Mover &mover) override;
    void transform(const Rotater &rotater) override;

    void accept(const BaseDrawTemplateVisitor& visitor) override;
    void accept(BaseTransformVisitor &visitor) override { visitor.visitCamera(*this); }

private:
    Point _position;
    Point _target;
    Vec _up;

    static Rotater radFromDegree(const Rotater &rotater);
};



#endif //CAMERA_HPP
