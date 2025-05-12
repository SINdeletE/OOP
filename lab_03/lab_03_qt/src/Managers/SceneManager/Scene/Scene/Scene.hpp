//
// Created by nuelex on 10/05/25.
//

#ifndef SCENE_HPP
#define SCENE_HPP
#include <memory>
#include <QGraphicsScene>

#include "../BaseScene.hpp"
#include "../../../../BaseObject/BaseObject.hpp"
#include "../../../../BaseObject/Composite/CompositeObject.hpp"


class Scene final: public BaseScene
{
public:
    Scene() = default;
    Scene(const Scene& other) = default;
    ~Scene() override = default;

    Scene& operator=(const Scene& other) = default;

    void addObject(const std::shared_ptr<BaseObject> &object) override;

    void clean() override;
    [[nodiscard]] std::shared_ptr<BaseScene> clone() const override;

protected:
    CompositeObject& getCompositeObject() override { return _objects; }

private:
    CompositeObject _objects;
    CompositeObject _cameras;
    std::shared_ptr<QGraphicsScene> _scene;
};



#endif //SCENE_HPP
