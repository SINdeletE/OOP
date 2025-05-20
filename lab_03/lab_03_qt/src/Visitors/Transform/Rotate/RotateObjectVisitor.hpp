//
// Created by nuelex on 20/05/25.
//

#ifndef ROTATEOBJECTVISITOR_HPP
#define ROTATEOBJECTVISITOR_HPP
#include "../BaseTransformVisitor.hpp"


class RotateObjectVisitor : public BaseTransformVisitor
{
public:
    explicit RotateObjectVisitor(const std::shared_ptr<BaseTransform>& transform);
    ~RotateObjectVisitor() override = default;

    void visitFigure(Figure& figure) override;
    void visitCamera(Camera& camera) override;

private:
    std::shared_ptr<Rotater> _transform;
};



#endif //ROTATEOBJECTVISITOR_HPP
