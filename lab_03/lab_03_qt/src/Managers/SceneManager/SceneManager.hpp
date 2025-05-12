//
// Created by nuelex on 11/05/25.
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
#include <memory>

#include "../BaseManager.hpp"
#include "../../BaseObject/Camera/Camera.hpp"
#include "History/BaseHistory.hpp"
#include "History/History.hpp"
#include "Scene/BaseScene.hpp"


class SceneManager : public BaseManager
{
public:
    SceneManager() = default;
    SceneManager(const SceneManager &);
    SceneManager(SceneManager &&) noexcept;
    ~SceneManager() override = default;

    SceneManager &operator=(const SceneManager &);
    SceneManager &operator=(SceneManager &&) noexcept;

public:
    friend class ManagerFactory;

    void setScene(const std::shared_ptr<BaseScene> &scene) { _scene = scene; }
    std::shared_ptr<BaseScene>& getScene() { return _scene; }

    void setCamera(const std::shared_ptr<BaseCamera> &camera) { _camera = camera; }

private:
    std::shared_ptr<BaseScene> _scene;
    std::shared_ptr<BaseCamera> _camera;
    SceneHistory _history;
};



#endif //SCENEMANAGER_HPP
