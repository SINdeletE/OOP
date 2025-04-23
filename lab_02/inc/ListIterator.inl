#include <memory>
#include <ranges>

template <keyType Type>
ListIterator<Type>::ListIterator() noexcept : index(-1)
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = null_ptr;
}

template <keyType Type>
ListIterator<Type>::ListIterator(const std::shared_ptr<Node<Type>> &list, const ListIterator<Type>::difference_type &init_index) noexcept
{
    cur_ptr = list;
    index = init_index;
}

template <keyType Type>
ListIterator<Type>::ListIterator(const ListIterator<Type> &iter) noexcept
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;
}

template <keyType Type>
ListIterator<Type>::ListIterator(ListIterator<Type> &&iter) noexcept : ListIterator(iter)
{
    iter.cur_ptr.reset();
    index = 0;
}














template <keyType Type>
ListIterator<Type>& ListIterator<Type>::operator =(const ListIterator<Type> &iter)
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;

    return *this;
}

template <keyType Type>
ListIterator<Type>& ListIterator<Type>::operator =(ListIterator<Type> &&iter)
{
    std::shared_ptr<Node<Type>> null_ptr = nullptr;
    cur_ptr = iter.cur_ptr;
    iter.cur_ptr = null_ptr; // ОШИБКА

    index = iter.index;
    iter.index = 0;

    return *this;
}

template <keyType Type>
template <sizeType U>
ListIterator<Type>& ListIterator<Type>::operator +=(const U &value)
{
    if (value < 0)
    {
        time_t cur_time = time(NULL);
        throw ErrorListIterator_BadOffset(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    std::shared_ptr<Node<Type>> ptr = cur_ptr.lock();
    for (int i = 0; i < value; i++) // ЗАМЕНИТЬ НА Ranges
        ptr = ptr->GetNext();
    
    cur_ptr = ptr;

    index += value;

    return *this;
}








template <keyType Type>
ListIterator<Type>& ListIterator<Type>::next()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();
    
    cur_ptr = converted->GetNext();
    ++(this->index);

    return *this;
}

template <keyType Type>
ListIterator<Type>& ListIterator<Type>::operator ++()
{
    return this->next();
}

template <keyType Type>
ListIterator<Type> ListIterator<Type>::operator ++(int)
{
    ListIterator<Type> tmp {*this};
    
    this->next();

    return tmp;
}

template <keyType Type>
ListIterator<Type>::difference_type ListIterator<Type>::operator -(const ListIterator<Type> &iter) const
{
    return index - iter.index;
}



template <keyType Type>
ListIterator<Type>::value_type ListIterator<Type>::Current() const
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();

    return *(*this);
}

template <keyType Type>
ListIterator<Type>::operator bool() const noexcept
{
    return index >= 0 && ! cur_ptr.expired();
}

template <keyType Type>
ListIterator<Type>::reference ListIterator<Type>::operator*() const 
{
    if (! bool(*this))
    {
        time_t cur_time = time(NULL);
        throw ErrorListIterator_IsInvalid(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    else
    {
        auto ptr = cur_ptr.lock();
        return ptr->RefData();
    }
}

template <keyType Type>
ListIterator<Type>::pointer ListIterator<Type>::operator->() const 
{
    return &(*(*this));
}






template <keyType Type>
bool ListIterator<Type>::operator ==(const ListIterator<Type> &iter) const noexcept
{
    std::shared_ptr<Node<Type>> iter1 = this->cur_ptr.lock();
    std::shared_ptr<Node<Type>> iter2 = iter.cur_ptr.lock();

    std::size_t index1 = this->index;
    std::size_t index2 = iter.index;

    return index1 == index2;
}

template <keyType Type>
bool ListIterator<Type>::operator !=(const ListIterator<Type> &iter) const noexcept
{
    return ! (*this == iter);
}