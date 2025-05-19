//
// Created by nuelex on 10/05/25.
//

#ifndef COMPOSITEOBJECT_HPP
#define COMPOSITEOBJECT_HPP
#include "../BaseObject.hpp"


class CompositeObject : public BaseObject
{
public:
    using const_reference = const std::shared_ptr<BaseObject>&;

    CompositeObject() : children() {}
    CompositeObject(const CompositeObject& other) = default;
    ~CompositeObject() override = default;

    CompositeObject& operator=(const CompositeObject& other) = default;

    bool CompositeCheck() override { return true; }
    bool VisibilityCheck() override { return false; }

    void addChild(const std::shared_ptr<BaseObject> &child) override;
    void removeChild(std::shared_ptr<BaseObject> &child) override {} // Пока так

    BaseObject::iterator begin() override { return children.begin(); }
    BaseObject::iterator end() override { return children.end(); }
    const_reference operator[] (size_type size);

    void accept(const BaseVisitor& visitor) override;

private:
    std::vector<std::shared_ptr<BaseObject>> children;
};



#endif //COMPOSITEOBJECT_HPP
