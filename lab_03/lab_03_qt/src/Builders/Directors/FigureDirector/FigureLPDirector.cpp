//
// Created by nuelex on 14/05/25.
//

#include "FigureLPDirector.hpp"

std::shared_ptr<BaseObject> FigureLPDirector::create()
{
    if (_builder->buildPoints() && _builder->buildLinks()) return _builder->getFigureLP();

    return nullptr;
}

