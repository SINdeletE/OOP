//
// Created by nuelex on 19/05/25.
//

#include "DrawFigureLPVisitor.hpp"

#include <iostream>

#include "../../../BaseObject/Figure/ConcreteFigure/BaseConcreteFigureLP.hpp"
#include "../../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/ConcreteFigureLP.hpp"

void DrawFigureLPVisitor::visit(const ConcreteFigureLP& figure) const
{
    auto iterator = figure.figureLP_->getLinks().CreateConstIterator();

    for (iterator.First(); ! iterator.IsDone(); iterator.Next())
    {
        try
        {
            _drawer->drawLine(_transformer->transform(figure.figureLP_->getPoints()[iterator.Current()->GetBeginID()]), \
                            _transformer->transform(figure.figureLP_->getPoints()[iterator.Current()->GetEndID()]));
        }
        catch (...)
        {
            ;
        }
    }

}

