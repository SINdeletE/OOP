//
// Created by nuelex on 22/05/25.
//

#ifndef CAMERACOMMANDADD_HPP
#define CAMERACOMMANDADD_HPP
#include "../BaseCameraCommand.hpp"
#include "../../BaseCommand.hpp"


class CameraCommandAdd : public BaseCameraCommand
{
public:
    explicit CameraCommandAdd(const std::string &filename) : _filename(filename) {}
    ~CameraCommandAdd() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override { _sceneManager = manager; }
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override { _loadManager = manager; }
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override { _drawManager = manager; }
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override {}

    void execute() override;

private:
    const std::string _filename;

    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<DrawManager> _drawManager;
};



#endif //CAMERACOMMANDADD_HPP
