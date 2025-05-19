//
// Created by nuelex on 19/05/25.
//

#ifndef BASEVISITOR_HPP
#define BASEVISITOR_HPP
#include <memory>

class Figure;
class Camera;
class Scene;

class BaseVisitor
{
public:
    BaseVisitor();
    virtual ~BaseVisitor() = default;

    virtual void visitFigure(Figure &figure) = 0;
    virtual void visitCamera(Camera &camera) = 0;
    virtual void visitScene(Scene &scene) = 0;
};



#endif //BASEVISITOR_HPP
