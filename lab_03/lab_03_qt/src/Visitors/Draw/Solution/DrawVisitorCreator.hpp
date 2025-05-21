//
// Created by nuelex on 20/05/25.
//

#ifndef DRAWVISITORCREATOR_HPP
#define DRAWVISITORCREATOR_HPP
#include <memory>

#include "../../../BaseObject/BaseObject.hpp"


class BaseDrawer;

class DrawVisitorCreator
{
public:
    DrawVisitorCreator() = default;
    virtual ~DrawVisitorCreator() = default;

    [[nodiscard]] virtual std::shared_ptr<BaseDrawTemplateVisitor> createDrawVisitor(const std::shared_ptr<Camera> &camera, const std::shared_ptr<BaseDrawer> &drawer) const = 0;
};

template <typename T>
requires std::is_base_of_v<BaseDrawTemplateVisitor, T> && (! std::is_abstract_v<T>)
class ConcreteDrawVisitorCreator : public DrawVisitorCreator
{
public:
    ConcreteDrawVisitorCreator() = default;
    ~ConcreteDrawVisitorCreator() override = default;

    [[nodiscard]] std::shared_ptr<BaseDrawTemplateVisitor> createDrawVisitor(const std::shared_ptr<Camera> &camera, const std::shared_ptr<BaseDrawer> &drawer) const override
    {
        return std::make_shared<T>(camera, drawer);
    }
};

#endif //DRAWVISITORCREATOR_HPP
