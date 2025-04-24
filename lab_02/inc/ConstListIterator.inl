#include <memory>
#include <ranges>

template <keyType Type>
ConstListIterator<Type>::ConstListIterator() noexcept : index(-1)
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = null_ptr;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(const std::shared_ptr<Node<Type>> &list, const ConstListIterator<Type>::difference_type &init_index) noexcept
{
    cur_ptr = list;
    index = init_index;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(const ConstListIterator<Type> &iter) noexcept
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(ConstListIterator<Type> &&iter) noexcept : ConstListIterator(iter)
{
    iter.cur_ptr.reset();
    index = 0;
}














template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator =(const ConstListIterator<Type> &iter) noexcept
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;

    return *this;
}

template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator =(ConstListIterator<Type> &&iter) noexcept
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = iter.cur_ptr;
    iter.cur_ptr = null_ptr; // ОШИБКА

    index = iter.index;
    iter.index = 0;

    return *this;
}

template <keyType Type>
template <sizeType U>
ConstListIterator<Type>& ConstListIterator<Type>::operator +=(const U &value)
{
    if (value < 0)
    {
        time_t cur_time = time(NULL);
        throw ErrorConstListIterator_BadOffset(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    std::shared_ptr<Node<Type>> ptr = cur_ptr.lock();
    for (int i = 0; i < value; i++) // ЗАМЕНИТЬ НА Ranges
        ptr = ptr->GetNext();
    
    cur_ptr = ptr;

    index += value;

    return *this;
}








template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::next()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();
    
    cur_ptr = converted->GetNext();
    ++(this->index);

    return *this;
}

template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator ++()
{
    return this->next();
}

template <keyType Type>
ConstListIterator<Type> ConstListIterator<Type>::operator ++(int)
{
    ConstListIterator<Type> tmp {*this};
    
    this->next();

    return tmp;
}

template <keyType Type>
ConstListIterator<Type>::difference_type ConstListIterator<Type>::operator -(const ConstListIterator<Type> &iter) const
{
    return index - iter.index;
}



template <keyType Type>
ConstListIterator<Type>::value_type ConstListIterator<Type>::Current() const
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();

    return *(*this);
}

template <keyType Type>
ConstListIterator<Type>::operator bool() const noexcept
{
    return ! cur_ptr.expired();
}

template <keyType Type>
ConstListIterator<Type>::reference ConstListIterator<Type>::operator*() const 
{
    if (! bool(*this))
    {
        time_t cur_time = time(NULL);
        throw ErrorConstListIterator_IsInvalid(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
    else
    {
        auto ptr = cur_ptr.lock();
        return ptr->RefData();
    }
}

template <keyType Type>
ConstListIterator<Type>::pointer ConstListIterator<Type>::operator->() const 
{
    return &(*(*this));
}






template <keyType Type>
bool ConstListIterator<Type>::operator ==(const ConstListIterator<Type> &iter) const noexcept
{
    std::shared_ptr<Node<Type>> iter1 = this->cur_ptr.lock();
    std::shared_ptr<Node<Type>> iter2 = iter.cur_ptr.lock();

    return iter1 == iter2;
}

template <keyType Type>
bool ConstListIterator<Type>::operator !=(const ConstListIterator<Type> &iter) const noexcept
{
    return ! (*this == iter);
}
