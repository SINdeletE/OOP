//
// Created by nuelex on 20/05/25.
//

#ifndef BASETRANSFORMVISITOR_HPP
#define BASETRANSFORMVISITOR_HPP
#include <memory>

#include "../../Transforms/Transforms.hpp"

class Figure;
class Camera;
class ConcreteFigureLP;
class CameraPTU;

class BaseTransformVisitor
{
public:
    explicit BaseTransformVisitor(const std::shared_ptr<BaseTransform> &transform) {}
    virtual ~BaseTransformVisitor() = default;

    virtual void visit(ConcreteFigureLP &figure) {}
    virtual void visit(CameraPTU &camera) {}
};



#endif //BASETRANSFORMVISITOR_HPP
