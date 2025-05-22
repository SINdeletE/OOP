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

void Scene::addObject(const std::shared_ptr<BaseObject>& object)
{
    try
    {
        _objects.addChild(object);
    }
    catch (ErrorCompositeObject_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorScene_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void Scene::addCamera(const std::shared_ptr<BaseObject>& object)
{
    try
    {
        _cameras.addChild(object);
    }
    catch (ErrorCompositeObject_bad_alloc &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorScene_bad_alloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
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

void Scene::removeObject(const size_t id)
{
    try
    {
        _objects.removeChild(id);
    }
    catch (ErrorCompositeObject_out_of_range &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorScene_out_of_range(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

void Scene::removeCamera(const size_t id)
{
    try
    {
        _cameras.removeChild(id);
    }
    catch (ErrorCompositeObject_out_of_range &e)
    {
        const time_t cur_time = time(nullptr);
        throw ErrorScene_out_of_range(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}



