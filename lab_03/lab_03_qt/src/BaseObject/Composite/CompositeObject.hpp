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
    using reference = std::shared_ptr<BaseObject>&;

    CompositeObject() : children() {}
    CompositeObject(const CompositeObject& other) = default;
    ~CompositeObject() override = default;

    CompositeObject& operator=(const CompositeObject& other) = default;
    std::shared_ptr<BaseObject> operator[](const size_t index) const { return children[index]; }

    bool CompositeCheck() override { return true; }
    bool VisibilityCheck() override { return false; }

    void addChild(const std::shared_ptr<BaseObject> &child) override;
    void removeChild(const size_t id) override;

    BaseObject::iterator begin() override { return children.begin(); }
    BaseObject::iterator end() override { return children.end(); }

    BaseObject::shared_ptr_type getObjectByID(size_type index) override;

    void accept(const BaseDrawTemplateVisitor& visitor) override;
    void accept(BaseTransformVisitor& visitor) override;

private:
    std::vector<std::shared_ptr<BaseObject>> children;
};



#endif //COMPOSITEOBJECT_HPP
