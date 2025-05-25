//
// Created by nuelex on 25/05/25.
//

#ifndef CAMERAPTUIMPL_HPP
#define CAMERAPTUIMPL_HPP
#include "../../Transforms/Transforms.hpp"
#include "../../Transforms/Vec.hpp"


class CameraPTUImpl
{
public:
    CameraPTUImpl() = default;
    ~CameraPTUImpl() = default;

    bool VisibilityCheck()  { return false; }
    bool CompositeCheck()  { return false; }

    [[nodiscard]] const Point &getPosition() const  { return _position; }
    void setPosition(const Point &position)  { _position = position; }
    void setPosition(Point&& position)  { _position = position; }

    [[nodiscard]] const Point &getTarget() const  { return _target; }
    void setTarget(const Point &target)  { _target = target; }
    void setTarget(Point &&target)  { _target = target; }

    [[nodiscard]] const Vec &getUp() const  { return _up; }
    void setUp(const Point &up)  { _up = up; }
    void setUp(Point &&up)  { _up = up; }
    void setUp(const Vec &up)  { _up = up; }
    void setUp(Vec &&up)  { _up = up; }

    void transform(const Mover &mover);
    void transform(const Rotater &rotater);

private:
    Point _position;
    Point _target;
    Vec _up;

    static Rotater radFromDegree(const Rotater &rotater);
};



#endif //CAMERAPTUIMPL_HPP
