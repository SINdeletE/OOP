//
// Created by nuelex on 10/05/25.
//

#ifndef BASESCENE_HPP
#define BASESCENE_HPP
#include "../BaseObject/Composite/CompositeObject.hpp"


class BaseScene
{
public:
    BaseScene();
    virtual ~BaseScene() = default;

    virtual void addObject(std::shared_ptr<BaseObject> object) = 0;

    virtual void clean() = 0;
    [[nodiscard]] virtual std::shared_ptr<BaseScene> clone() const = 0;
};



#endif //BASESCENE_HPP
