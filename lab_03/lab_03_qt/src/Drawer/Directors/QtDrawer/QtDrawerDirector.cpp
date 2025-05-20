//
// Created by nuelex on 19/05/25.
//

#include "QtDrawerDirector.hpp"


std::shared_ptr<BaseDrawer> QtDrawerDirector::createDrawer(const std::shared_ptr<BaseColorParameters>& color)
{
    if (_builder == nullptr)
        _builder = std::shared_ptr<>;
    else
        _builder->reset();
}

