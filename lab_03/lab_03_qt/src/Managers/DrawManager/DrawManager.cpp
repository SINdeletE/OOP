//
// Created by nuelex on 12/05/25.
//

#include "DrawManager.hpp"

#include "../../Exceptions/Drawer/DrawerException.hpp"
#include "../../Exceptions/Managers/DrawManagerException.hpp"
#include "../../Transforms/CameraTransformer/Solution/CameraTransformerSolution.hpp"
#include "../../Visitors/Draw/Solution/DrawVisitorSolution.hpp"

void DrawManager::clear() const
{
    if (_drawer == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawManager_invalid_drawer(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    _drawer->clear();
}

void DrawManager::drawScene(const std::shared_ptr<Scene> &scene) const
{
    if (_drawer == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawManager_invalid_drawer(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    if (_camera == nullptr)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawManager_invalid_drawer(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    DrawVisitorSolution solutionDraw{};
    CameraTransformerSolution solutionCameraTransformer{};

    auto objects = scene->getCompositeObject();
    try
    {
        for (const auto &object : objects)
        {
            object->accept(*solutionDraw.createDrawTemplateVisitor(object, \
                        nullptr, _drawer)); // Выбор посетителя для определённой фигуры
        }
    }
    catch (...)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorDrawManager_invalid_draw(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void DrawManager::setCamera(const std::shared_ptr<Camera>& camera)
{
    _camera = camera;
}

