#pragma once

#include <memory>

#include "concepts.hpp"

enum Color {RED, BLACK};

template <numType Type>
class Node
{
    friend class RBTree;

    private:
        Type data;
        color Color;

        std::shared_ptr<Type> parent;
        std::shared_ptr<Type> left;
        std::shared_ptr<Type> right;
    
    public:
        Node() = delete;
        explicit Node(const Type &value); // Конструктор с 1-м параметром
        ~Node();
};

#include "node.inl"
