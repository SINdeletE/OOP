//
// Created by nuelex on 19/05/25.
//

#include "QtDrawerDirector.hpp"

#include "../../Builders/QtDrawer/QtDrawerBuilder.hpp"


std::shared_ptr<BaseDrawer> QtDrawerDirector::createDrawer(const std::shared_ptr<BaseGraphics> &graphics, const std::shared_ptr<BaseColorParameters>& color)
{
    this->init_builder(graphics, color);

    if (_builder->buildColor() && _builder->buildPen() && _builder->buildDrawer()) return _builder->getDrawer();

    return nullptr;
}

void QtDrawerDirector::init_builder(const std::shared_ptr<BaseGraphics> &graphics, const std::shared_ptr<BaseColorParameters>& color)
{
    if (_builder == nullptr)
        _builder = std::make_shared<QtDrawerBuilder>(graphics, color);
    else
        _builder->reset();
}



