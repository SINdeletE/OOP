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

    virtual void setManager(const std::shared_ptr<SceneManager> &manager) = 0;
    virtual void setManager(const std::shared_ptr<LoadManager> &manager) = 0;
    virtual void setManager(const std::shared_ptr<DrawManager> &manager) = 0;
    virtual void setManager(const std::shared_ptr<TransformManager> &manager) = 0;

    virtual void execute() = 0;
};



#endif //BASECOMMAND_HPP
