//
// Created by nuelex on 10/05/25.
//

#include "Scene.hpp"

#include "../../Exceptions/Scene/SceneException.hpp"

void Scene::clean()
{
    try
    {
        _scene->clear();
    }
    catch (...)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorScene_invalid_scene(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<BaseScene> Scene::clone() const
{
    Scene tmp_scene {*this};

    return std::make_shared<Scene>(tmp_scene);
}


