//
// Created by nuelex on 20/05/25.
//

#include "DrawVisitorSolution.hpp"

#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/ConcreteFigureLP.hpp"
#include "../../../Exceptions/Visitors/VisitorException.hpp"

DrawVisitorSolution::DrawVisitorSolution()
{
    try
    {
        this->reg(std::make_shared<ConcreteFigureLP>(), std::make_shared<ConcreteDrawVisitorCreator<DrawFigureLPVisitor>>());
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void DrawVisitorSolution::reg(const std::shared_ptr<BaseObject>& object, const std::shared_ptr<DrawVisitorCreator>& creator)
{
    _creators[object] = creator;
}

std::shared_ptr<BaseDrawTemplateVisitor> DrawVisitorSolution::createDrawTemplateVisitor(const std::shared_ptr<BaseObject>& object, const std::shared_ptr<BaseDrawer> &drawer)
{
    const auto iter = _creators.find(object);

    if (iter == _creators.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    try
    {
        return iter->second->createDrawVisitor(drawer);
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorVisitor_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}



