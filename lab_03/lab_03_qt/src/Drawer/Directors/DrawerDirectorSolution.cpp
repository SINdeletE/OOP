//
// Created by nuelex on 19/05/25.
//

#include "DrawerDirectorSolution.hpp"

#include "../Graphics/Qt/QtGraphicsScene.hpp"
#include "QtDrawer/QtDrawerDirector.hpp"

DrawerDirectorSolution::DrawerDirectorSolution()
{
    try
    {
        std::shared_ptr<QGraphicsScene> tmp_scene = nullptr;
        reg({std::make_shared<QtGraphicsScene>(tmp_scene, nullptr), std::make_unique<ConcreteDrawerDirectorCreator<QtDrawerDirector>>()});
    }
    catch (std::bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

}

void DrawerDirectorSolution::reg(std::pair<std::shared_ptr<BaseGraphics>, std::unique_ptr<DrawerDirectorCreator>> &&other)
{
    auto [fst, snd] = std::move(other);
    _creators[fst] = std::move(snd);
}

std::shared_ptr<BaseDrawerDirector> DrawerDirectorSolution::createDrawerDirector(const std::shared_ptr<BaseGraphics> &graphics)
{
    const auto iter = _creators.find(graphics);

    if (iter == _creators.end())
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawer_invalid_data(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return iter->second->createDirector();
}


