#pragma once

#include <memory>

#include "concept.hpp"

template <keyType Type>
class Node : public std::enable_shared_from_this<Node<Type>>
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

        [[nodiscard]] std::shared_ptr<const Type> get_value() const;
};

template <keyType Type>
requires Printable_concept<Type>
std::ostream& operator <<(std::ostream &os, std::shared_ptr<Node<Type>> &node)
{
    os << *(node->get_value());

    return os;
}

#include "Node.inl"
