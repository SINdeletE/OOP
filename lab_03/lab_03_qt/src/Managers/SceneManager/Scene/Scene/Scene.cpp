//
// Created by nuelex on 10/05/25.
//

#include "Scene.hpp"

#include "../../../../Exceptions/BaseObject/CompositeException.hpp"
#include "../../../../Exceptions/Scene/SceneException.hpp"
#include "../../../../Visitors/Draw/Solution/DrawVisitorSolution.hpp"


std::shared_ptr<Scene> Scene::clone() const
{
    Scene tmp_scene {*this};

    return std::make_shared<Scene>(tmp_scene);
}

bool Scene::addObject(const std::shared_ptr<BaseObject>& object)
{
    return _objects.addChild(object);
}

bool Scene::addCamera(const std::shared_ptr<BaseObject>& object)
{
    return _cameras.addChild(object);
}

std::shared_ptr<BaseObject> Scene::getFigureByID(const size_t index)
{
    try
    {
        return _objects.getObjectByID(index);
    }
    catch (ErrorCompositeObject_out_of_range &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorScene_out_of_range(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

std::shared_ptr<BaseObject> Scene::getCameraByID(const size_t index)
{
    try
    {
        return _cameras.getObjectByID(index);
    }
    catch (ErrorCompositeObject_out_of_range &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorScene_out_of_range(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

bool Scene::removeObject(const size_t id)
{
    return _objects.removeChild(id);
}

bool Scene::removeCamera(const size_t id)
{
    return _cameras.removeChild(id);
}



