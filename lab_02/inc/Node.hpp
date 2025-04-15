#pragma once

#include <memory>

#include "concept.hpp"

template <numType Type>
class Node
{
    private:
        Type data;

        std::shared_ptr<Node<Type>> next;
    
    public:
        Node() : data(0), next(nullptr) {};

        explicit Node(const Type &value);
        explicit Node(const Node<Type>& node);

        Node<Type>& operator=(const Type &value);
        Node<Type>& operator=(const Node<Type>& node);
        Node<Type>& operator=(std::shared_ptr<Node<Type>> &node);

        std::shared_ptr<Node<Type>> GetNext();

        void SetNext(std::shared_ptr<Node<Type>> &node);
        void SetNext(Node<Type> &node);

        Type& RefData();
        Type Data();
};

#include "Node.inl"
