#include <memory>

template <keyType Type>
Node<Type>::Node(const Type &value)
{
    data = value;

    next = nullptr;
}

template <keyType Type>
Node<Type>::Node(const Node<Type>& node) : Node{node.data} {}

template <keyType Type>
Node<Type>& Node<Type>::operator=(const Type &value)
{
    data = value;

    return *this;
}

template <keyType Type>
Node<Type>& Node<Type>::operator=(const Node<Type>& node) 
{
    if (this != &node)
        data = node.data;

    return *this;
}

template <keyType Type>
Node<Type>& Node<Type>::operator=(std::shared_ptr<Node<Type>> &node)
{
    if (this != node)
        data = node.data;

    return *this;
}

template <keyType Type>
std::shared_ptr<Node<Type>> Node<Type>::GetNext() noexcept
{
    return next;
}

template <keyType Type>
void Node<Type>::SetNext(std::shared_ptr<Node<Type>> &node)
{
    next = node;
}

template <keyType Type>
void Node<Type>::SetNext(Node<Type> &node)
{
    next = std::make_shared<Node<Type>>(node);
}

template <keyType Type>
std::shared_ptr<const Type> Node<Type>::get_value() const
{
    std::shared_ptr<const Node<Type>> work = this->shared_from_this();

    return { work, &work->data };
}
