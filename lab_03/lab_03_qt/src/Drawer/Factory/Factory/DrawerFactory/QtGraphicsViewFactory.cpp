//
// Created by nuelex on 19/05/25.
//

#include "QtGraphicsViewFactory.hpp"

#include <qvariant.h>

#include "../../../../Exceptions/Drawer/DrawerException.hpp"
#include "../Color/QtColor/QtColor.hpp"
#include "../Pen/QtPen/QtPen.hpp"

std::shared_ptr<BaseColor> QtGraphicsViewFactory::createColor(const std::shared_ptr<BaseColorParameters>& color_param)
{
    try
    {
        return std::make_shared<QtColor>(color_param);
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<BasePen> QtGraphicsViewFactory::createPen(const std::shared_ptr<BaseColor>& color)
{
    try
    {
        return std::make_shared<QtPen>(color);
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

