#pragma once

#include <memory>
#include <iostream>

#include "concept.hpp"

template <numType Type>
class Node
{
    private:
        Type data;

        std::shared_ptr<Node<Type>> parent;
        std::shared_ptr<Node<Type>> next;
    
    public:
        Node() : data(0), parent(nullptr), next(nullptr) {};

        explicit Node(const Type &value); // Конструктор с 1-м параметром
        explicit Node(const Node<Type>& node); // Конструктор копирования
        // Node(std::shared_ptr<Node<Type>> &node) // Пока нет необходимости

        Node<Type>& operator=(const Type &value);
        Node<Type>& operator=(const Node<Type>& node);
        Node<Type>& operator=(std::shared_ptr<Node<Type>> &node);

        std::shared_ptr<Node<Type>> GetNext();
        std::shared_ptr<Node<Type>> GetParent();

        void SetNext(std::shared_ptr<Node<Type>> &node);
        void SetNext(Node<Type> &node);
        void SetParent(std::shared_ptr<Node<Type>> &node);
        void SetParent(Node<Type> &node);

        void AddNext(std::shared_ptr<Node<Type>> &node); // Добавление только в конец
        void AddNext(Node<Type> &node); // Добавление только в конец
        void AddParent(std::shared_ptr<Node<Type>> &node); // Добавление только в начало
        void AddParent(Node<Type> &node); // Добавление только в начало

        Type Data();
};

#include "Node.inl"
