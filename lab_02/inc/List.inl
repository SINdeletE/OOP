#include <memory>
#include <ranges>

template <keyType Type>
List<Type>::List() : head(nullptr)
{
    this->size = 0;
}



template <keyType Type>
void List<Type>::push_back(const Type& value)
{
    Node<Type> node {value};
    std::shared_ptr<Node<Type>> node_ptr = std::make_shared<Node<Type>>(node);

    if (head == nullptr)
        head = node_ptr;
    else
    {
        ListIterator<Type> iter = this->begin();
        iter += this->GetSize() - 1;

        std::shared_ptr<Node<Type>> last_node_shared_ptr = iter.GetPtr();
        last_node_shared_ptr->SetNext(node_ptr);
    }

    size++;
}

template <keyType Type>
void List<Type>::pop_back()
{
    ListIterator<Type> iter = this->begin();
    iter += this->GetSize() - 1;

    std::shared_ptr<Node<Type>> node_ptr {nullptr};
    std::shared_ptr<Node<Type>> last_node_ptr = iter.GetPtr();
    std::shared_ptr<Node<Type>> deleting_node_ptr = last_node_ptr->GetNext();
    deleting_node_ptr.reset();

    last_node_ptr->SetNext(node_ptr);

    size--;
}

template <keyType Type>
void List<Type>::push_front(const Type& value)
{
    Node<Type> node {value};
    std::shared_ptr<Node<Type>> node_ptr = std::make_shared<Node<Type>>(node);

    node_ptr->SetNext(this->head);
    this->head = node_ptr;

    size++;
}





// Итераторы
template <keyType Type>
List<Type>::iterator List<Type>::begin() noexcept
{
    ListIterator<Type> iter {this->head, 0};

    return iter;
}

template <keyType Type>
List<Type>::iterator List<Type>::end() noexcept
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    ListIterator<Type> iter {null_ptr, size};

    return iter;
}

template <keyType Type>
List<Type>::iterator List<Type>::erase(List<Type>::iterator &pos)
{
    ListIterator<Type> iter {};

    if (this->begin() == pos)
    {
        std::shared_ptr<Node<Type>> erased_node {head};

        head = head->GetNext();
        erased_node.reset();

        iter = this->begin(); // Тут тоже перенос :O
    }
    else
    {
        iter = this->begin();
        iter += pos - this->begin() - 1;

        std::shared_ptr<Node<Type>> pre_deleting_node_ptr = iter.GetPtr();
        std::shared_ptr<Node<Type>> deleting_node_ptr = pre_deleting_node_ptr->GetNext();
        std::shared_ptr<Node<Type>> next_node_ptr = deleting_node_ptr->GetNext();
        
        pre_deleting_node_ptr->SetNext(next_node_ptr);
        deleting_node_ptr.reset();

        iter++;
    }

    size--;

    return iter;
}








template <keyType Type>
List<Type>::size_type List<Type>::GetSize() const
{
    return this->size;
}

template <keyType Type>
bool List<Type>::IsEmpty() const
{
    return this->size == 0;
}
