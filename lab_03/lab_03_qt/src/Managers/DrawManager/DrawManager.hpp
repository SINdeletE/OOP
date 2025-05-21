//
// Created by nuelex on 12/05/25.
//

#ifndef DRAWMANAGER_HPP
#define DRAWMANAGER_HPP
#include <memory>

#include "../BaseManager.hpp"
#include "../../BaseObject/Camera/Camera.hpp"
#include "../../Drawer/Drawer/BaseDrawer.hpp"


class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() override = default;

    void setDrawer(const std::shared_ptr<BaseDrawer> &drawer) { _drawer = drawer; }
    void setCamera(const std::shared_ptr<Camera> &camera);

    void drawScene(const std::shared_ptr<Scene> &scene) const;
    void clear() const;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
};



#endif //DRAWMANAGER_HPP
