#include <memory>
#include <ranges>

template <keyType Type>
List<Type>::List() : head(nullptr)
{
    this->size = 0;
}

template <keyType Type>
List<Type>::List(const List<Type> &list)
{
    head = nullptr;
    size = 0;

    for (const auto &v : list)
        this->push_back(v);
}

template <keyType Type>
List<Type>::List(List<Type> &&list) noexcept
{
    head = list.head;
    list.head = nullptr;

    size = list.size;
    list.size = 0;
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
    std::ptrdiff_t index = this->GetSize() - 2;

    if (index == -2)
    {
        // throw
    }
    else if (index == -1) // Если 1 элемент
    {
        head.reset();
        head = nullptr;
    }
    else
    {
        iter += index;

        std::shared_ptr<Node<Type>> node_ptr = nullptr;
        std::shared_ptr<Node<Type>> last_node_ptr = iter.GetPtr();
        std::shared_ptr<Node<Type>> deleting_node_ptr = last_node_ptr->GetNext();
        deleting_node_ptr.reset();

        last_node_ptr->SetNext(node_ptr);
    }

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

template <keyType Type>
List<Type>::iterator List<Type>::insert(List<Type>::iterator &pos, const Type& value)
{
    List<Type>::iterator new_iter;
    std::ptrdiff_t index = pos.GetIndex();

    if (! index)
    {
        this->push_front(value);
        new_iter = this->begin();
    }
    else
    {
        List<Type>::iterator new_iter = this->begin();
        
        new_iter += index - 1;

        std::shared_ptr<Node<Type>> parent_node = new_iter.GetPtr();
        std::shared_ptr<Node<Type>> next_node = parent_node->GetNext();
        
        Node<Type> new_node {value};
        parent_node->SetNext(new_node);

        std::shared_ptr<Node<Type>> node = parent_node->GetNext();
        node->SetNext(next_node);

        new_iter++;
        size++;
    }

    return new_iter;
}




// Итераторы
template <keyType Type>
List<Type>::iterator List<Type>::begin() const noexcept
{
    ListIterator<Type> iter {this->head, 0};

    return iter;
}

template <keyType Type>
List<Type>::iterator List<Type>::end() const noexcept
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    ListIterator<Type> iter {null_ptr, size};

    return iter;
}

template <keyType Type>
List<Type>::const_iterator List<Type>::cbegin() const noexcept
{
    ConstListIterator<Type> iter {this->head, 0};

    return iter;
}

template <keyType Type>
List<Type>::const_iterator List<Type>::cend() const noexcept
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    ConstListIterator<Type> iter {null_ptr, size};

    return iter;
}






template <keyType Type>
List<Type>::iterator List<Type>::erase(List<Type>::iterator &pos)
{
    ListIterator<Type> iter {};
    ListIterator<Type> next_pos {pos};
    next_pos++;

    if (this->end() == next_pos) // Если нода ПОСЛЕДНЯЯ
    {
        this->pop_back();

        iter = this->end();
    }
    else if (this->begin() == pos) // Если нода ПЕРВАЯ
    {
        std::shared_ptr<Node<Type>> erased_node {head};

        head = head->GetNext();
        erased_node.reset();

        iter = this->begin(); // Тут тоже перенос :O
        size--;
    }
    else
    {
        std::ptrdiff_t offset = pos - this->begin() - 1;

        iter = this->begin();
        iter += offset;

        std::shared_ptr<Node<Type>> pre_deleting_node_ptr = iter.GetPtr();
        std::shared_ptr<Node<Type>> deleting_node_ptr = pre_deleting_node_ptr->GetNext();
        std::shared_ptr<Node<Type>> next_node_ptr = deleting_node_ptr->GetNext();
        
        pre_deleting_node_ptr->SetNext(next_node_ptr);
        deleting_node_ptr.reset();

        iter++;
        size--;
    }

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
