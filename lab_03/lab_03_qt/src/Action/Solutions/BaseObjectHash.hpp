//
// Created by nuelex on 18/05/25.
//

#ifndef BASEOBJECTHASH_HPP
#define BASEOBJECTHASH_HPP
#include <cstddef>
#include <memory>

#include "../../BaseObject/BaseObject.hpp"


class BaseObjectHash
{
public:
    BaseObjectHash() = default;
    ~BaseObjectHash() = default;

    std::size_t operator()(const std::shared_ptr<BaseObject> &object) const;
};



#endif //BASEOBJECTHASH_HPP
