#pragma once

#include <iostream>
#include <memory>

#include "Node.hpp"

template <numType Type>
std::ostream& operator <<(std::ostream &os, std::shared_ptr<Node<Type>> &node)
{
    os << node->Data();

    return os;
}
