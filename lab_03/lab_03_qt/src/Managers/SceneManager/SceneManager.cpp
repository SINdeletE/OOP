//
// Created by nuelex on 11/05/25.
//

#include "SceneManager.hpp"

SceneManager::SceneManager(const SceneManager &scene)
{
    _scene = scene._scene;
    _history = scene._history;
}

SceneManager::SceneManager(SceneManager &&scene) noexcept
{
    _scene = scene._scene;
    scene._scene = nullptr;

    _history = std::move(scene._history);
}

SceneManager& SceneManager::operator=(const SceneManager &scene)
{
    if (this != &scene)
    {
        _scene = scene._scene;
        _history = scene._history;
    }

    return *this;
}

SceneManager& SceneManager::operator=(SceneManager &&scene) noexcept
{
    _scene = scene._scene;
    scene._scene = nullptr;

    _history = std::move(scene._history);

    return *this;
}

