//
// Created by nuelex on 20/05/25.
//

#ifndef SCALEOBJECTVISITOR_HPP
#define SCALEOBJECTVISITOR_HPP
#include "../BaseTransformVisitor.hpp"


class ScaleObjectVisitor : public BaseTransformVisitor
{
public:
    explicit ScaleObjectVisitor(const std::shared_ptr<BaseTransform> &transform);
    ~ScaleObjectVisitor() override = default;

    void visitFigure(Figure& figure) override;
    void visitCamera(Camera& camera) override {}

private:
    std::shared_ptr<Scaler> _transform;
};



#endif //SCALEOBJECTVISITOR_HPP
