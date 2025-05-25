//
// Created by nuelex on 20/05/25.
//

#ifndef TRANSFORMVISITORCREATOR_HPP
#define TRANSFORMVISITORCREATOR_HPP
#include <memory>

#include "BaseTransformVisitor.hpp"


class TransformVisitorCreator
{
public:
    TransformVisitorCreator() = default;
    virtual ~TransformVisitorCreator() = default;

    [[nodiscard]] virtual std::shared_ptr<BaseTransformVisitor> createVisitor(const std::shared_ptr<BaseTransform> &transform) = 0;
};

template <typename T>
requires std::is_base_of_v<BaseTransformVisitor, T> && (! std::is_abstract_v<T>)
class ConcreteTransformVisitorCreator : public TransformVisitorCreator
{
public:
    ConcreteTransformVisitorCreator() = default;
    ~ConcreteTransformVisitorCreator() override = default;

    [[nodiscard]] std::shared_ptr<BaseTransformVisitor> createVisitor(const std::shared_ptr<BaseTransform> &transform) override
    {
        return std::make_shared<T>(transform);
    }
};



#endif //TRANSFORMVISITORCREATOR_HPP
