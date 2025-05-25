//
// Created by nuelex on 19/05/25.
//

#ifndef DRAWFIGURELPVISITOR_HPP
#define DRAWFIGURELPVISITOR_HPP
#include "../../BaseDrawTemplateVisitor.hpp"

class ConcreteFigureLP;

class DrawFigureLPVisitor : public BaseDrawTemplateVisitor
{
public:
    DrawFigureLPVisitor() = delete;
    explicit DrawFigureLPVisitor(const std::shared_ptr<BaseCameraTransformer> &transformer, const std::shared_ptr<BaseDrawer> &drawer) : _drawer(drawer), _transformer(transformer) {}
    ~DrawFigureLPVisitor() override = default;

    void visit(const ConcreteFigureLP &figure) const override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<BaseCameraTransformer> _transformer;
};



#endif //DRAWFIGURELPVISITOR_HPP
