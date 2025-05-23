//
// Created by nuelex on 11/05/25.
//

#include "SceneManager.hpp"

SceneManager::SceneManager(const SceneManager &scene)
{
    _scene = scene._scene;
}

SceneManager::SceneManager(SceneManager &&scene) noexcept
{
    _scene = scene._scene;
    scene._scene = nullptr;
}

SceneManager& SceneManager::operator=(const SceneManager &scene)
{
    if (this != &scene)
    {
        _scene = scene._scene;
    }

    return *this;
}

SceneManager& SceneManager::operator=(SceneManager &&scene) noexcept
{
    _scene = scene._scene;
    scene._scene = nullptr;

    return *this;
}

void SceneManager::addObject(const std::shared_ptr<BaseObject>& object) const
{
    _scene->addObject(object);
}

void SceneManager::addCamera(const std::shared_ptr<BaseObject>& camera) const
{
    _scene->addCamera(camera);
}

