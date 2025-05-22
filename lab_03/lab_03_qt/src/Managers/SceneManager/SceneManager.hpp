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

class SceneManager : public BaseManager
{
public:
    SceneManager() : _scene(std::make_shared<Scene>()) {}
    SceneManager(const SceneManager &);
    SceneManager(SceneManager &&) noexcept;
    ~SceneManager() override = default;

    SceneManager &operator=(const SceneManager &);
    SceneManager &operator=(SceneManager &&) noexcept;

    void setScene(const std::shared_ptr<Scene> &scene) { _scene = scene; }
    std::shared_ptr<Scene>& getScene() { return _scene; }

    void addObject(const std::shared_ptr<BaseObject> &object) const;
    void addCamera(const std::shared_ptr<BaseObject> &camera) const;

    [[nodiscard]] BaseObject::shared_ptr_type getFigureByID(const size_t index) const { return _scene->getFigureByID(index); }

private:
    std::shared_ptr<Scene> _scene;
    SceneHistory _history;
};



#endif //SCENEMANAGER_HPP
