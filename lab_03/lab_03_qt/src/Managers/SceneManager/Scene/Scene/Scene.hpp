//
// Created by nuelex on 10/05/25.
//

#ifndef SCENE_HPP
#define SCENE_HPP
#include <memory>
#include <QGraphicsScene>

#include "../../../../BaseObject/BaseObject.hpp"
#include "../../../../BaseObject/Composite/CompositeObject.hpp"

class Scene final
{
    friend class DrawVisitor;

public:
    Scene() = default;
    Scene(const Scene& other) = default;
    ~Scene() = default;

    Scene& operator=(const Scene& other) = default;

    void addObject(const std::shared_ptr<BaseObject> &object);

    void clean();
    [[nodiscard]] std::shared_ptr<Scene> clone() const;

protected:
    const CompositeObject& getCompositeObject() const { return _objects; }

private:
    CompositeObject _objects;
    CompositeObject _cameras;
    std::shared_ptr<QGraphicsScene> _scene;
};



#endif //SCENE_HPP
