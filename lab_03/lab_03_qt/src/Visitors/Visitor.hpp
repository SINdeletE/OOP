//
// Created by nuelex on 19/05/25.
//

#ifndef VISITOR_HPP
#define VISITOR_HPP
#include "BaseDrawTemplateVisitor.hpp"


template <typename Type>
class Visitor : public BaseDrawTemplateVisitor
{
public:
    Visitor() = default;
    explicit Visitor(const std::shared_ptr<BaseCameraTransformer> &transformer, const std::shared_ptr<BaseDrawer> &drawer) : BaseDrawTemplateVisitor(transformer, drawer) {}
    ~Visitor() override = default;

    virtual void visit(const Type &) const = 0;
};



#endif //VISITOR_HPP
