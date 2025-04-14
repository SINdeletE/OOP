#include <memory>

template <numType Type>
List<Type>::List() : head(nullptr)
{
    this->size = 0;
}



template <numType Type>
void List<Type>::push_back(const Type& value)
{
    Node<Type> node {value};
    std::shared_ptr<Node<Type>> node_ptr = std::make_shared<Node<Type>>(node);

    if (head == nullptr)
        head = node;
    else
    {
        ListIterator<Type> iter = this->begin();
        for (auto i : std::ranges::views::iota(0, this->GetSize() - 1))
            iter++;

        std::shared_ptr<Node<Type>> node_ptr = iter.GetPtr();
        node_ptr->SetNext(node_ptr);
    }

    size++;
}

// Итераторы
template <numType Type>
List<Type>::iterator List<Type>::begin() noexcept
{
    ListIterator<Type> iter {*this};

    return iter;
}

template <numType Type>
List<Type>::iterator List<Type>::end() noexcept
{
    ListIterator<Type> iter {nullptr, size};

    return iter;
}

template <numType Type>
List<Type>::size_type List<Type>::GetSize() const
{
    return this->size;
}

template <numType Type>
bool List<Type>::IsEmpty() const
{
    return this->size == 0;
}
