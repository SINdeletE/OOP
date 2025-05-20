//
// Created by nuelex on 11/05/25.
//

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
#include <memory>

#include "../BaseManager.hpp"
#include "../../BaseObject/Camera/CameraPTU.hpp"
#include "History/BaseHistory.hpp"
#include "History/History.hpp"
#include "Scene/Scene/Scene.hpp"

class DrawManager;

class SceneManager : public BaseManager
{
    friend class DrawManager;

public:
    SceneManager() : _scene(std::make_shared<Scene>()) {}
    SceneManager(const SceneManager &);
    SceneManager(SceneManager &&) noexcept;
    ~SceneManager() override = default;

    SceneManager &operator=(const SceneManager &);
    SceneManager &operator=(SceneManager &&) noexcept;

    void setScene(const std::shared_ptr<Scene> &scene) { _scene = scene; }
    void setCamera(const std::shared_ptr<BaseCameraPTU> &camera) { _camera = camera; }

    void addObject(const std::shared_ptr<BaseObject> &object) const;

protected:
    std::shared_ptr<Scene>& getScene() { return _scene; }

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<BaseCameraPTU> _camera;
    SceneHistory _history;
};



#endif //SCENEMANAGER_HPP
