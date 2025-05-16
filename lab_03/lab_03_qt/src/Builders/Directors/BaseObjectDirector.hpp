//
// Created by nuelex on 13/05/25.
//

#ifndef BASEDIRECTOR_HPP
#define BASEDIRECTOR_HPP
#include "../../BaseObject/BaseObject.hpp"


class BaseObjectDirector
{
public:
    explicit BaseObjectDirector(const std::string &filename) {}
    virtual ~BaseObjectDirector() = default;

    [[nodiscard]] virtual std::shared_ptr<BaseObject> create() = 0;
};



#endif //BASEDIRECTOR_HPP
