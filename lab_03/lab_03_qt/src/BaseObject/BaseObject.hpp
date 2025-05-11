//
// Created by nuelex on 10/05/25.
//

#ifndef BASEOBJECT_HPP
#define BASEOBJECT_HPP
#include <memory>

#include "../Transforms/Transforms.hpp"


class BaseObject
{
public:
    using value_type = BaseObject;
    using size_type = size_t;
    using iterator = std::list<std::shared_ptr<value_type>>::const_iterator;
    using const_iterator = std::list<std::shared_ptr<value_type>>::const_iterator;

    BaseObject() = default;
    BaseObject(const BaseObject&) = default;
    virtual ~BaseObject() = default;

    BaseObject& operator=(const BaseObject&) = default;

    virtual bool CompositeCheck() { return false; }
    virtual bool VisibilityCheck() = 0;

    virtual void addChild(const std::shared_ptr<BaseObject> &child) {}
    virtual void removeChild(std::shared_ptr<BaseObject> &child) {}

    virtual iterator begin() = 0;
    virtual iterator end() = 0;

    virtual void move(const Mover &mover) {}
    virtual void rotate(const Rotater &rotater) {}
    virtual void scale(const Scaler &scaler) {}

    virtual void draw() {}
};



#endif //BASEOBJECT_HPP
