//
// Created by nuelex on 21/05/25.
//

#ifndef FIGURECOMMANDMOVE_HPP
#define FIGURECOMMANDMOVE_HPP
#include <functional>
#include <memory>

#include "../../../BaseCommand.hpp"
#include "../../../../Managers/LoadManager/LoadManager.hpp"
#include "../../../../Managers/SceneManager/SceneManager.hpp"
#include "../../../../Managers/TransformManager/TransformManager.hpp"
#include "../BaseTransformManagerCommand.hpp"


class TransformManagerCommandRequest : public BaseTransformManagerCommand
{
public:
    TransformManagerCommandRequest() = default;
    ~TransformManagerCommandRequest() override = default;

    void setManagerAction(const std::shared_ptr<SceneManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<LoadManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<DrawManager> &manager) override {}
    void setManagerAction(const std::shared_ptr<TransformManager> &manager) override
    {
        _action = [manager](){ manager->request(); };
    }

    void execute() override;

private:
    std::function<void()> _action;
};



#endif //FIGURECOMMANDMOVE_HPP
