//
// Created by nuelex on 10/05/25.
//

#ifndef SCENE_HPP
#define SCENE_HPP
#include <memory>

#include "../BaseScene.hpp"


class Scene final: public BaseScene
{
public:
    Scene() = default;
    Scene(const Scene& other) = default;
    ~Scene() override = default;

    void clean() override;
    [[nodiscard]] std::shared_ptr<BaseScene> clone() override;

private:
    CompositeObject _objects;
};



#endif //SCENE_HPP
