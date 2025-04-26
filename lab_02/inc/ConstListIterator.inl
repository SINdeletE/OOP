#include <memory>
#include <ranges>

template <keyType Type>
ConstListIterator<Type>::ConstListIterator() noexcept
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = null_ptr;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(const std::shared_ptr<Node<Type>> &list) noexcept
{
    cur_ptr = list;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(const ConstListIterator<Type> &iter) noexcept
{
    cur_ptr = iter.cur_ptr;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(ConstListIterator<Type> &&iter) noexcept : ConstListIterator(iter)
{
    iter.cur_ptr.reset();
}














template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator =(const ConstListIterator<Type> &iter) noexcept
{
    cur_ptr = iter.cur_ptr;

    return *this;
}

template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator =(ConstListIterator<Type> &&iter) noexcept
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = iter.cur_ptr;
    iter.cur_ptr = null_ptr;

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
    for (U i = 0; i < value; i++)
        ptr = ptr->GetNext();
    
    cur_ptr = ptr;

    return *this;
}








template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::next() noexcept
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();
    
    if (bool(*this) && converted != nullptr)
    {
        cur_ptr = converted->GetNext();
    }

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
template <sizeType U>
ConstListIterator<Type> ConstListIterator<Type>::operator +(const U &offset) const noexcept
{
    ConstListIterator<Type> tmp {*this};
    
    for (U i = 0; i < offset; ++i)
        tmp.next();

    return tmp;
}



template <keyType Type>
ConstListIterator<Type>::value_type ConstListIterator<Type>::Current() const
{
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
    
    auto ptr = cur_ptr.lock();
    std::shared_ptr<const Type> value = ptr->get_value();

    if (value.use_count() == 0)
    {
        time_t cur_time = time(NULL);
        throw ErrorConstListIterator_IsInvalid(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return *value;
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
