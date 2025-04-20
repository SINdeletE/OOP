#pragma once

#include <iostream>
#include <memory>
#include <functional>

#include "Node.hpp"

template <keyType Type>
std::ostream& operator <<(std::ostream &os, std::shared_ptr<Node<Type>> &node)
{
    os << node->Data();

    return os;
}

template <keyType Type>
std::ostream& operator <<(std::ostream &os, List<Type> &list)
{
    for (auto &v : list)
        os << v << ' ';

    os << std::endl;

    return os;
}

template <
        keyType Key, 
        typename Compare = std::less<Key>
>
std::ostream& operator <<(std::ostream &os, Set<Key, Compare> &set)
{
    for (const auto &v : set)
        os << v << ' ';

    os << std::endl;

    return os;
}
