//
// Created by nuelex on 18/05/25.
//

#include "QtDrawer.hpp"

#include "../../Exceptions/Drawer/DrawerException.hpp"
#include "../Graphics/Qt/QtGraphicsScene.hpp"

void QtDrawer::setScene(const std::shared_ptr<BaseGraphics>& graphics)
{
    _scene = std::dynamic_pointer_cast<QtGraphicsScene>(graphics);

    if (_scene == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void QtDrawer::setPen(const std::shared_ptr<BasePen>& pen)
{
    _pen = std::dynamic_pointer_cast<QtPen>(pen);

    if (_pen == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}


