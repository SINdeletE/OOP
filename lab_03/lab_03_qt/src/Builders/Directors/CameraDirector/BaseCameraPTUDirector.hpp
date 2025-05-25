//
// Created by nuelex on 25/05/25.
//

#ifndef BASECAMERAPTUDIRECTOR_HPP
#define BASECAMERAPTUDIRECTOR_HPP
#include <memory>

#include "../../../BaseObject/BaseObject.hpp"


class BaseCameraPTUDirector
{
public:
    BaseCameraPTUDirector() = default;
    virtual ~BaseCameraPTUDirector() = default;

    [[nodiscard]] virtual std::shared_ptr<BaseObject> create() = 0;
};



#endif //BASECAMERAPTUDIRECTOR_HPP
