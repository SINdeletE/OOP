//
// Created by nuelex on 18/05/25.
//

#ifndef ACTIONHASH_HPP
#define ACTIONHASH_HPP
#include <cstddef>
#include <memory>

#include "../../Transforms/Transforms.hpp"

class ActionHash
{
public:
    ActionHash() = default;
    ~ActionHash() = default;

    std::size_t operator()(const std::shared_ptr<BaseTransform> &transform) const { return typeid(*transform).hash_code(); }
};

#endif //ACTIONHASH_HPP
