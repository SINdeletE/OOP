//
// Created by nuelex on 12/05/25.
//

#ifndef DRAWMANAGER_HPP
#define DRAWMANAGER_HPP
#include <memory>

#include "../BaseManager.hpp"
#include "../../BaseObject/Camera/Camera.hpp"
#include "../../Drawer/Drawer/BaseDrawer.hpp"
#include "../SceneManager/Scene/Scene/Scene.hpp"


class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() override = default;

    void setCamera(const std::shared_ptr<Camera> &camera);
    [[nodiscard]] bool IsEmpty() const { return (_camera == nullptr) ; }

    void drawScene(const std::shared_ptr<Scene> &scene, const std::shared_ptr<BaseDrawer> &drawer) const;
    void clear(const std::shared_ptr<BaseDrawer> &drawer) const;

private:
    std::shared_ptr<Camera> _camera;
};



#endif //DRAWMANAGER_HPP
