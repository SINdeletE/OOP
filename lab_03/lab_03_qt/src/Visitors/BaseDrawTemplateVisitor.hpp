//
// Created by nuelex on 19/05/25.
//

#ifndef BASEVISITOR_HPP
#define BASEVISITOR_HPP
#include <memory>

#include "../Drawer/Drawer/BaseDrawer.hpp"
#include "../Transforms/CameraTransformer/BaseCameraTransformer.hpp"


class BaseDrawTemplateVisitor
{
public:
    BaseDrawTemplateVisitor() = default;
    explicit BaseDrawTemplateVisitor(const std::shared_ptr<BaseCameraTransformer> &transformer, const std::shared_ptr<BaseDrawer> &drawer) {}
    virtual ~BaseDrawTemplateVisitor() = default;
};



#endif //BASEVISITOR_HPP
