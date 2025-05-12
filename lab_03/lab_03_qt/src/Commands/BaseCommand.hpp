//
// Created by nuelex on 12/05/25.
//

#ifndef BASECOMMAND_HPP
#define BASECOMMAND_HPP
#include <memory>

#include "../Managers/DrawManager/DrawManager.hpp"
#include "../Managers/LoadManager/LoadManager.hpp"
#include "../Managers/SceneManager/SceneManager.hpp"
#include "../Managers/TransformManager/TransformManager.hpp"


class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void setManagers(std::shared_ptr<SceneManager> &sceneManager);

    void addManager(const std::shared_ptr<SceneManager> &sceneManager) { _sceneManager = sceneManager; }
    void addManager(const std::shared_ptr<LoadManager> &loadManager) { _loadManager = loadManager; }
    void addManager(const std::shared_ptr<DrawManager> &drawManager) { _drawManager = drawManager; }
    void addManager(const std::shared_ptr<TransformManager> &transformManager) { _transformManager = transformManager; }

private:
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<TransformManager> _transformManager;
};



#endif //BASECOMMAND_HPP
