//
// Created by nuelex on 11/05/25.
//

#include "SceneManager.hpp"

#include "History/History.hpp"

SceneManager::SceneManager()
{
    SceneHistory tmp{};

    _scene = nullptr;
    _history = std::make_shared<SceneHistory>(tmp);
}

