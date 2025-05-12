//
// Created by nuelex on 12/05/25.
//

#ifndef FACADE_HPP
#define FACADE_HPP
#include <memory>

#include "../Commands/BaseCommand.hpp"
#include "../Managers/SceneManager/SceneManager.hpp"


class Facade final
{
public:
    Facade();
    ~Facade() = default;

    void execute(BaseCommand &command);

private:
    std::shared_ptr<SceneManager> _sceneManager;
};



#endif //FACADE_HPP
