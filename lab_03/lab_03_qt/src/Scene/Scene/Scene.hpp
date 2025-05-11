//
// Created by nuelex on 10/05/25.
//

#ifndef SCENE_HPP
#define SCENE_HPP
#include <memory>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "../BaseScene.hpp"


class Scene final: public BaseScene
{
public:
    Scene() = default;
    Scene(const Scene& other) = default;
    ~Scene() override = default;

    void addObject(std::shared_ptr<BaseObject> object) override;

    void clean() override;
    [[nodiscard]] std::shared_ptr<BaseScene> clone() const override;

private:
    CompositeObject _objects;
    std::shared_ptr<QGraphicsScene> _scene;
};



#endif //SCENE_HPP
