//
// Created by nuelex on 20/05/25.
//

#include "QtPen.hpp"

#include "../../../../../Exceptions/Drawer/DrawerException.hpp"

QtPen::QtPen(const std::shared_ptr<BaseColor>& color) : BaseQtPen(color)
{
    const auto qtColor = std::dynamic_pointer_cast<QtColor>(color);

    if (qtColor == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    try
    {
        _pen = std::make_shared<QPen>(qtColor->getColor());
    }
    catch (std::bad_alloc& e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

