#pragma once

#include <iostream>
#include <memory>
#include <ranges>

#include "Node.hpp"

template <numType Type>
std::ostream& operator <<(std::ostream &os, std::shared_ptr<Node<Type>> &node)
{
    os << node->Data();

    return os;
}

template <numType Type>
std::ostream& operator <<(std::ostream &os, List<Type> &list)
{
    for (auto iter = list.begin(); iter != list.end(); iter++)
        os << *iter << ' ';

    os << std::endl;

    return os;
}
