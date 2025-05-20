//
// Created by nuelex on 20/05/25.
//

#ifndef BASETRANSFORMVISITOR_HPP
#define BASETRANSFORMVISITOR_HPP
#include <memory>

#include "../../Transforms/Transforms.hpp"

class Figure;
class Camera;

class BaseTransformVisitor
{
public:
    explicit BaseTransformVisitor(const std::shared_ptr<BaseTransform> &transform) {}
    virtual ~BaseTransformVisitor() = default;

    virtual void visitFigure(Figure &figure) = 0;
    virtual void visitCamera(Camera &camera) = 0;
};



#endif //BASETRANSFORMVISITOR_HPP
