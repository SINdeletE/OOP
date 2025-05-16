//
// Created by nuelex on 12/05/25.
//

#ifndef LOADMANAGER_HPP
#define LOADMANAGER_HPP
#include <memory>

#include "../BaseManager.hpp"
#include "../../BaseObject/BaseObject.hpp"
#include "../SceneManager/Scene/BaseScene.hpp"


class LoadManager final: public BaseManager
{
public:
    LoadManager() = default;
    ~LoadManager() override = default;

    std::shared_ptr<BaseObject> loadObject(const std::string &filename);
    std::shared_ptr<BaseScene> loadScene(const std::string &filename);
};



#endif //LOADMANAGER_HPP
