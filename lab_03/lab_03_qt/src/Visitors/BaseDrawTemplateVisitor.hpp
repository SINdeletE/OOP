//
// Created by nuelex on 19/05/25.
//

#ifndef BASEVISITOR_HPP
#define BASEVISITOR_HPP
#include <memory>

#include "../Drawer/Drawer/BaseDrawer.hpp"
#include "../Transforms/CameraTransformer/BaseCameraTransformer.hpp"

class ConcreteFigureLP;

class BaseDrawTemplateVisitor
{
public:
    BaseDrawTemplateVisitor() = default;
    explicit BaseDrawTemplateVisitor(const std::shared_ptr<BaseCameraTransformer> &transformer, const std::shared_ptr<BaseDrawer> &drawer) {}
    virtual ~BaseDrawTemplateVisitor() = default;

    virtual void visit(const ConcreteFigureLP &figure) const = 0;
};



#endif //BASEVISITOR_HPP
