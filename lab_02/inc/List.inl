#include <memory>
#include <ranges>

template <keyType Type>
List<Type>::List() noexcept : head(nullptr)
{
    this->_size = 0;
}

template <keyType Type>
List<Type>::List(const List<Type> &list)
{
    head = nullptr;
    _size = 0;

    for (const auto &v : list)
        this->push_back(v);
}

template <keyType Type>
List<Type>::List(List<Type> &&list) noexcept
{
    head = list.head;
    list.head = nullptr;

    _size = list.size();
    list._size = 0;
}


template <keyType Type>
List<Type>& List<Type>::operator =(const List<Type> &list)
{
    head = nullptr;
    _size = 0;

    for (const auto &v : list)
        this->push_back(v);

    return *this;
}

template <keyType Type>
List<Type>& List<Type>::operator =(List<Type> &&list) noexcept
{
    head = list.head;
    list.head = nullptr;

    _size = list.size();
    list._size = 0;

    return *this;
}

template <keyType Type>
List<Type>::iterator List<Type>::push_back(const Type& value)
{
    Node<Type> node {value};
    std::shared_ptr<Node<Type>> node_ptr {};

    try
    {
        node_ptr = std::make_shared<Node<Type>>(node);
    }
    catch (std::bad_alloc &error)
    {
        time_t cur_time = time(NULL);
        throw ErrorList_BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    
    ListIterator<Type> iter {};

    if (head == nullptr)
    {
        head = node_ptr;

        iter = this->begin();
    }
    else
    {
        iter = this->begin();
        iter += this->size() - 1;

        std::shared_ptr<Node<Type>> last_node_shared_ptr = iter.GetPtr();
        last_node_shared_ptr->SetNext(node_ptr);

        iter++;
    }

    _size++;

    return iter;
}

template <keyType Type>
void List<Type>::pop_back()
{
    ListIterator<Type> iter = this->begin();
    std::ptrdiff_t index = this->size() - 2;

    if (index == -2) // Нет элементов
    {
        time_t cur_time = time(NULL);
        throw ErrorList_IsEmpty(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
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

    _size--;
}

template <keyType Type>
void List<Type>::push_front(const Type& value)
{
    Node<Type> node {value};
    std::shared_ptr<Node<Type>> node_ptr {};
    
    try
    {
        node_ptr = std::make_shared<Node<Type>>(node);
    }
    catch (std::bad_alloc &error)
    {
        time_t cur_time = time(NULL);
        throw ErrorList_BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    node_ptr->SetNext(this->head);
    this->head = node_ptr;

    _size++;
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
        new_iter = this->begin();
        new_iter += index - 1;

        std::shared_ptr<Node<Type>> parent_node = new_iter.GetPtr();
        std::shared_ptr<Node<Type>> next_node = parent_node->GetNext();
        
        Node<Type> new_node {value};
        try
        {
            parent_node->SetNext(new_node);
        }
        catch (std::bad_alloc &error)
        {
            time_t cur_time = time(NULL);
            throw ErrorList_BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }

        std::shared_ptr<Node<Type>> node = parent_node->GetNext();
        node->SetNext(next_node);

        new_iter++;
        _size++;
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
    std::shared_ptr<Node<Type>> null_ptr = nullptr;
    ListIterator<Type> iter {null_ptr, _size};

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
    ConstListIterator<Type> iter {null_ptr, _size};

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
        _size--;
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
        _size--;
    }

    return iter;
}








template <keyType Type>
List<Type>::size_type List<Type>::size() const noexcept
{
    return this->_size;
}

template <keyType Type>
bool List<Type>::IsEmpty() const noexcept
{
    return this->_size == 0;
}
