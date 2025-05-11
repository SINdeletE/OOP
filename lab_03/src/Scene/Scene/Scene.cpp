//
// Created by nuelex on 10/05/25.
//

#include "Scene.hpp"

void Scene::clean()
{

}

std::shared_ptr<BaseScene> Scene::clone()
{
    Scene tmp_scene {*this};

    return std::make_shared<Scene>(tmp_scene);
}


