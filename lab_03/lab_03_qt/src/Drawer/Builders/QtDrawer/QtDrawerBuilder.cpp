//
// Created by nuelex on 20/05/25.
//

#include "QtDrawerBuilder.hpp"

#include "../../../Exceptions/Drawer/DrawerException.hpp"
#include "../../Drawer/QtDrawer.hpp"
#include "../../Factory/Factory/DrawerFactory/QtGraphicsViewFactory.hpp"

QtDrawerBuilder::QtDrawerBuilder(const std::shared_ptr<BaseGraphics> &graphics, const std::shared_ptr<BaseColorParameters>& color_parameters) : BaseQtDrawerBuilder(graphics, color_parameters), \
                     total(0), _graphics(graphics), _color_parameters(color_parameters), \
                  _color(nullptr), _pen(nullptr), _drawer(nullptr), _factory(nullptr)
{
    try
    {
        _factory = std::make_shared<QtGraphicsViewFactory>();
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

bool QtDrawerBuilder::buildColor()
{
    try
    {
        _color = _factory->createColor(_color_parameters);

        total++;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool QtDrawerBuilder::buildPen()
{
    try
    {
        _pen = _factory->createPen(_color);

        total++;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool QtDrawerBuilder::buildDrawer()
{
    try
    {
        _drawer = std::make_shared<QtDrawer>();
        _drawer->setPen(_pen);
        _drawer->setScene(_graphics);

        total++;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

std::shared_ptr<BaseDrawer> QtDrawerBuilder::getDrawer()
{
    return _drawer;
}
