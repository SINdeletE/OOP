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
List<Type>::const_iterator List<Type>::push_back(const Type& value)
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
    
    ConstListIterator<Type> iter {};

    if (head == nullptr)
    {
        head = node_ptr;

        iter = this->cbegin();
    }
    else
    {
        iter = this->cbegin();
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
    ConstListIterator<Type> iter = this->cbegin();
    std::ptrdiff_t offset = this->size() - 2;

    if (offset == -2) // Нет элементов
    {
        time_t cur_time = time(NULL);
        throw ErrorList_IsEmpty(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    else if (offset == -1) // Если 1 элемент
    {
        head.reset();
        head = nullptr;
    }
    else
    {
        iter += offset;

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
List<Type>::const_iterator List<Type>::insert(List<Type>::const_iterator &pos, const Type& value)
{
    List<Type>::const_iterator new_iter;

    if (pos == this->cbegin())
    {
        this->push_front(value);
        new_iter = this->cbegin();
    }
    else
    {
        new_iter = prev_iter(pos);

        if (new_iter == this->cend())
            new_iter = this->cend();
        else
        {
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
    }

    return new_iter;
}




// Итераторы

template <keyType Type>
List<Type>::iterator List<Type>::begin() const noexcept
{
    iterator iter {this->head};

    return iter;
}

template <keyType Type>
List<Type>::iterator List<Type>::end() const noexcept
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    iterator iter {null_ptr};

    return iter;
}

template <keyType Type>
List<Type>::const_iterator List<Type>::cbegin() const noexcept
{
    const_iterator iter {this->head};

    return iter;
}

template <keyType Type>
List<Type>::const_iterator List<Type>::cend() const noexcept
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    const_iterator iter {null_ptr};

    return iter;
}






template <keyType Type>
List<Type>::const_iterator List<Type>::erase(List<Type>::const_iterator &pos)
{
    ConstListIterator<Type> iter {};
    ConstListIterator<Type> next_pos {pos};
    next_pos++;

    if (this->cend() == next_pos) // Если нода ПОСЛЕДНЯЯ
    {
        this->pop_back();

        iter = this->cend();
    }
    else if (this->cbegin() == pos) // Если нода ПЕРВАЯ
    {
        std::shared_ptr<Node<Type>> erased_node {head};

        head = head->GetNext();
        erased_node.reset();

        iter = this->cbegin(); // Тут тоже перенос :O
        _size--;
    }
    else
    {
        iter = prev_iter(pos);

        if (iter == this->cend())
            iter = this->cend();
        else
        {
            std::shared_ptr<Node<Type>> pre_deleting_node_ptr = iter.GetPtr();
            std::shared_ptr<Node<Type>> deleting_node_ptr = pre_deleting_node_ptr->GetNext();
            std::shared_ptr<Node<Type>> next_node_ptr = deleting_node_ptr->GetNext();
            
            pre_deleting_node_ptr->SetNext(next_node_ptr);
            deleting_node_ptr.reset();

            iter++;
            _size--;
        }
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






template <keyType Type>
List<Type>::const_iterator List<Type>::prev_iter(const List<Type>::const_iterator &pos)
{
    const_iterator it = this->cbegin();

    if (it == pos)
    {
        it = this->cend();
    }
    else
    {
        while (it != this->cend() && (it + 1) != pos)
            it++;
    }

    return it;
}


