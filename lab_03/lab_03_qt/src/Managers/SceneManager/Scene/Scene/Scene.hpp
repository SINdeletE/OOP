//
// Created by nuelex on 10/05/25.
//

#ifndef SCENE_HPP
#define SCENE_HPP
#include <memory>

#include "../../../../BaseObject/BaseObject.hpp"
#include "../../../../BaseObject/Composite/CompositeObject.hpp"

class DrawManager;

class Scene final
{
    friend class DrawManager;

public:
    Scene() = default;
    Scene(const Scene& other) = default;
    ~Scene() = default;

    Scene& operator=(const Scene& other) = default;

    void addObject(const std::shared_ptr<BaseObject> &object);
    void addCamera(const std::shared_ptr<BaseObject> &camera);

    [[nodiscard]] std::shared_ptr<BaseObject> getFigureByID(size_t index);
    [[nodiscard]] std::shared_ptr<BaseObject> getCameraByID(size_t index);

    [[nodiscard]] std::shared_ptr<Scene> clone() const;

protected:
    [[nodiscard]] const CompositeObject& getCompositeObject() { return _objects; }

private:
    CompositeObject _objects;
    CompositeObject _cameras;
};



#endif //SCENE_HPP
