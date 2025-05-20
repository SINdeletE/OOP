//
// Created by nuelex on 20/05/25.
//

#ifndef DRAWVISITOR_HPP
#define DRAWVISITOR_HPP
#include "BaseDrawVisitor.hpp"


class DrawVisitor : public BaseDrawVisitor
{
public:
    DrawVisitor() = delete;
    explicit DrawVisitor(const std::shared_ptr<BaseDrawer> &drawer) : BaseDrawVisitor(drawer) { _drawer = drawer; }
    ~DrawVisitor() override = default;

    void visitScene(const Scene& scene) override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};



#endif //DRAWVISITOR_HPP
