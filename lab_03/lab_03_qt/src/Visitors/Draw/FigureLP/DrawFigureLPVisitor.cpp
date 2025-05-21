//
// Created by nuelex on 19/05/25.
//

#include "DrawFigureLPVisitor.hpp"

#include "../../../BaseObject/Figure/ConcreteFigure/BaseConcreteFigureLP.hpp"

void DrawFigureLPVisitor::visit(const BaseConcreteFigureLP& figure) const
{
    auto iterator = figure.getLinks().CreateConstIterator();

    for (iterator.First(); ! iterator.IsDone(); iterator.Next())
        _drawer->drawLine(_transformer->transform(figure.getPoints()[iterator.Current()->GetBeginID()]), \
                            _transformer->transform(figure.getPoints()[iterator.Current()->GetEndID()]));
}

