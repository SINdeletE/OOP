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

    void setManager(const std::shared_ptr<BaseManager> &unusual_manager) {}

    virtual void execute() = 0;
};



#endif //BASECOMMAND_HPP
