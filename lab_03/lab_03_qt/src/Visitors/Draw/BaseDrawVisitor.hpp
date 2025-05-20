//
// Created by nuelex on 20/05/25.
//

#ifndef BASEDRAWVISITOR_HPP
#define BASEDRAWVISITOR_HPP
#include "../../Drawer/Drawer/BaseDrawer.hpp"


class Scene;
class Figure;

class BaseDrawVisitor
{
public:
    BaseDrawVisitor() = delete;
    BaseDrawVisitor(const std::shared_ptr<BaseDrawer> &drawer) {}
    virtual ~BaseDrawVisitor() = default;

    virtual void visitScene(const Scene &scene) = 0;
};



#endif //BASEDRAWVISITOR_HPP
