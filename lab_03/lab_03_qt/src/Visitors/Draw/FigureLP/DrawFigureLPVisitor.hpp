//
// Created by nuelex on 19/05/25.
//

#ifndef DRAWFIGURELPVISITOR_HPP
#define DRAWFIGURELPVISITOR_HPP
#include "../../Visitor.hpp"
#include "../../../Drawer/Drawer/BaseDrawer.hpp"

class BaseConcreteFigureLP;

class DrawFigureLPVisitor : public Visitor<BaseConcreteFigureLP>
{
public:
    DrawFigureLPVisitor() = delete;
    explicit DrawFigureLPVisitor(const std::shared_ptr<Camera> &camera, const std::shared_ptr<BaseDrawer> &drawer) : _camera(camera), _drawer(drawer) {}
    ~DrawFigureLPVisitor() override = default;

    void visit(const BaseConcreteFigureLP &figure) const override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
};



#endif //DRAWFIGURELPVISITOR_HPP
