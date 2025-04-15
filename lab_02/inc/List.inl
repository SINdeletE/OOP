#include <memory>
#include <ranges>

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
        head = node_ptr;
    else
    {
        ListIterator<Type> iter = this->begin();
        for (auto i : std::ranges::views::iota(0, this->GetSize() - 1))
            iter++;

        std::shared_ptr<Node<Type>> last_node_shared_ptr = iter.GetPtr();
        last_node_shared_ptr->SetNext(node_ptr);
    }

    size++;
}

template <numType Type>
void List<Type>::pop_back()
{
    ListIterator<Type> iter = this->begin();
    for (auto i : std::ranges::views::iota(0, this->GetSize() - 1))
        iter++;

    std::shared_ptr<Node<Type>> node_ptr {nullptr};
    std::shared_ptr<Node<Type>> last_node_ptr = iter.GetPtr();
    std::shared_ptr<Node<Type>> deleting_node_ptr = last_node_ptr->GetNext();
    deleting_node_ptr.reset();

    last_node_ptr->SetNext(node_ptr);

    size--;
}




// Итераторы
template <numType Type>
List<Type>::iterator List<Type>::begin() noexcept
{
    ListIterator<Type> iter {this->head};

    return iter;
}

template <numType Type>
List<Type>::iterator List<Type>::end() noexcept
{
    ListIterator<Type> iter {nullptr, size};

    return iter;
}

template <numType Type>
List<Type>::iterator List<Type>::erase(List<Type>::iterator &pos)
{
    ListIterator<Type> iter {};

    if (this->begin() == pos)
    {
        std::shared_ptr<Node<Type>> erased_node {head};

        head = head.GetNext();
        erased_node.reset();

        iter = head;
    }
    else
    {
        iter = this->begin();
        for (auto i : std::ranges::views::iota(0, pos - this->begin() - 1))
            iter++;

        std::shared_ptr<Node<Type>> pre_deleting_node_ptr = iter.GetPtr();
        std::shared_ptr<Node<Type>> deleting_node_ptr = pre_deleting_node_ptr->GetNext();
        std::shared_ptr<Node<Type>> next_node_ptr = deleting_node_ptr->GetNext();
        
        pre_deleting_node_ptr.SetNext(next_node_ptr);
        deleting_node_ptr.reset();

        iter++;
    }

    size--;

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
