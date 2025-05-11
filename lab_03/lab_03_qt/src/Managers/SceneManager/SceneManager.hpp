//
// Created by nuelex on 11/05/25.
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
#include <memory>

#include "../BaseManager.hpp"
#include "History/BaseHistory.hpp"
#include "History/History.hpp"
#include "Scene/BaseScene.hpp"


class SceneManager : public BaseManager
{
public:
    SceneManager();
    ~SceneManager() override = default;

    void setScene(const std::shared_ptr<BaseScene> &scene) { _scene = scene; }
    std::shared_ptr<BaseScene>& getScene() { return _scene; }

private:
    std::shared_ptr<BaseScene> _scene;
    std::shared_ptr<SceneHistory> _history;
};



#endif //SCENEMANAGER_HPP
