//
// Created by nuelex on 20/05/25.
//

#ifndef MOVEOBJECTVISITOR_HPP
#define MOVEOBJECTVISITOR_HPP
#include "../BaseTransformVisitor.hpp"


class MoveObjectVisitor : public BaseTransformVisitor
{
public:
    explicit MoveObjectVisitor(const std::shared_ptr<BaseTransform> &transform);
    ~MoveObjectVisitor() override = default;

    void visitFigure(Figure& figure) override;
    void visitCamera(Camera& camera) override;

private:
    std::shared_ptr<Mover> _transform;
};



#endif //MOVEOBJECTVISITOR_HPP
