#pragma once

#include <memory>

#include "concept.hpp"

template <keyType Type>
class Node
{
    private:
        Type data;

        std::shared_ptr<Node<Type>> next;
    
    public:
        Node() : data(), next(nullptr) {};

        explicit Node(const Type &value);
        explicit Node(const Node<Type>& node);

        Node<Type>& operator=(const Type &value);
        Node<Type>& operator=(const Node<Type>& node);
        Node<Type>& operator=(std::shared_ptr<Node<Type>> &node);

        std::shared_ptr<Node<Type>> GetNext() noexcept;

        void SetNext(std::shared_ptr<Node<Type>> &node);
        void SetNext(Node<Type> &node);

        [[nodiscard]] const Type& RefData() noexcept;
        [[nodiscard]] const Type Data() const noexcept;
};

template <keyType Type>
requires Printable_concept<Type>
std::ostream& operator <<(std::ostream &os, std::shared_ptr<Node<Type>> &node)
{
    os << node->Data();

    return os;
}

#include "Node.inl"
