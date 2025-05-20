//
// Created by nuelex on 12/05/25.
//

#include "DrawManager.hpp"

#include "../../BaseObject/Figure/ConcreteFigure/ConcreteFigureLP/Point/Points.hpp"
#include "../../Exceptions/Drawer/DrawerException.hpp"

void DrawManager::clear() const
{
    if (_drawer == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _drawer->clear();
}

void DrawManager::drawScene(const std::shared_ptr<Scene>& scene) const
{

}



