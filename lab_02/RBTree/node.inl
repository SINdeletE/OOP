template <numType Type>
Node::Node(const Type &value)
{
    data = value;
    color = RED;

    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

