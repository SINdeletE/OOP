//
// Created by nuelex on 19/05/25.
//

#ifndef DRAWERDIRECTORHASH_HPP
#define DRAWERDIRECTORHASH_HPP
#include <memory>

#include "../Graphics/BaseGraphics.hpp"


class DrawerDirectorHash
{
public:
    DrawerDirectorHash() = default;
    ~DrawerDirectorHash() = default;

    std::size_t operator()(const std::shared_ptr<BaseGraphics> &graphics) const noexcept { return typeid(*graphics).hash_code(); }
};

class DrawerDirectorEqual {
public:
    bool operator()(
        const std::shared_ptr<BaseGraphics>& a,
        const std::shared_ptr<BaseGraphics>& b
    ) const {
        return typeid(*a) == typeid(*b);
    }
};


#endif //DRAWERDIRECTORHASH_HPP
