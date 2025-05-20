//
// Created by nuelex on 09/05/25.
//

#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <memory>

#include "../BaseObject.hpp"
#include "../../Transforms/Transforms.hpp"
#include "../../Visitors/Transform/BaseTransformVisitor.hpp"

class Figure : public BaseObject
{
public:
    Figure() = default;
    ~Figure() override = default;

    bool CompositeCheck() override { return false; }
    bool VisibilityCheck() override { return true; }

    void addChild(const std::shared_ptr<BaseObject> &child) override {}
    void removeChild(std::shared_ptr<BaseObject> &child) override {}

    BaseObject::iterator begin() override { return BaseObject::iterator(nullptr); }
    BaseObject::iterator end() override { return BaseObject::iterator(nullptr); }

    void transform(const Mover &mover) override {}
    void transform(const Rotater &rotater) override {}
    void transform(const Scaler &scaler) override {}

    void accept(const BaseVisitor &visitor) override;
    void accept(BaseTransformVisitor &visitor) override { visitor.visitFigure(*this); }
};



#endif //FIGURE_HPP
