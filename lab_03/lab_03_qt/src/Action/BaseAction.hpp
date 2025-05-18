//
// Created by nuelex on 11/05/25.
//

#ifndef BASEACTION_HPP
#define BASEACTION_HPP
#include "../BaseObject/BaseObject.hpp"


class BaseAction
{
public:
    BaseAction() = default;
    BaseAction(const BaseAction &) = default;
    virtual ~BaseAction() = default;

    virtual void setParams(const std::shared_ptr<BaseObject>&, const std::shared_ptr<BaseTransform>&) = 0;

    virtual void request() const = 0;
};



#endif //BASEACTION_HPP
