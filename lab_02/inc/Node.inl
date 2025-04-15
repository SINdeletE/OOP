#include <memory>

template <numType Type>
Node<Type>::Node(const Type &value)
{
    data = value;

    next = nullptr;
}

template <numType Type>
Node<Type>::Node(const Node<Type>& node) : Node{node.data} {}

template <numType Type>
Node<Type>& Node<Type>::operator=(const Type &value)
{
    data = value;

    return *this;
}

template <numType Type>
Node<Type>& Node<Type>::operator=(const Node<Type>& node) 
{
    if (this != &node)
        data = node.data;

    return *this;
}

template <numType Type>
Node<Type>& Node<Type>::operator=(std::shared_ptr<Node<Type>> &node)
{
    if (this != node)
        data = node.data;

    return *this;
}

template <numType Type>
std::shared_ptr<Node<Type>> Node<Type>::GetNext()
{
    return next;
}

template <numType Type>
void Node<Type>::SetNext(std::shared_ptr<Node<Type>> &node)
{
    next = node;
}

template <numType Type>
void Node<Type>::SetNext(Node<Type> &node)
{
    next = std::make_shared<Node<Type>>(node);
}

template <numType Type>
Type& Node<Type>::RefData()
{
    return data;
}

template <numType Type>
Type Node<Type>::Data()
{
    return data;
}
