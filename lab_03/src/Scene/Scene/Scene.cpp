//
// Created by nuelex on 10/05/25.
//

#include "Scene.hpp"

void Scene::clean()
{

}

std::shared_ptr<BaseScene> Scene::clone()
{
    return std::make_shared<Scene>(*this);
}


