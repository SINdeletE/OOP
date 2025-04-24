template <keyType Key>
SetIterator<Key>& SetIterator<Key>::operator =(const SetIterator<Key> &iter)
{
    this->list_iter = iter.list_iter;
    
    return *this;
}

template <keyType Key>
SetIterator<Key>& SetIterator<Key>::operator =(SetIterator<Key> &&iter) noexcept
{
    this->list_iter = std::move(iter.list_iter);
    
    return *this;
}

template <keyType Key>
template <sizeType U> SetIterator<Key>& SetIterator<Key>::operator +=(const U &value)
{
    try
    {
        list_iter += value;
    }
    catch (ErrorListIterator_BadOffset &error)
    {
        time_t cur_time = time(NULL);
        throw ErrorSetIterator_BadOffset(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return *this;
}


template <keyType Key>
SetIterator<Key>& SetIterator<Key>::next()
{
    ++list_iter;

    return *this;
}

template <keyType Key>
SetIterator<Key>& SetIterator<Key>::operator ++()
{
    return this->next();
}

template <keyType Type>
SetIterator<Type> SetIterator<Type>::operator ++(int)
{
    SetIterator<Type> tmp {*this};
    
    this->next();

    return tmp;
}

template <keyType Key>
SetIterator<Key>::difference_type SetIterator<Key>::operator-(const SetIterator<Key> &iter) const
{
    return this->list_iter - iter->list_iter;
}

template <keyType Key>
SetIterator<Key>::value_type SetIterator<Key>::Current()
{
    return list_iter.Current();
}

template <keyType Key>
SetIterator<Key>::operator bool() const noexcept
{
    return bool(list_iter);
}

template <keyType Key>
SetIterator<Key>::reference SetIterator<Key>::operator *() const
{   
    try
    {
        return *list_iter;
    }
    catch (ErrorListIterator_IsInvalid &error) 
    {
        time_t cur_time = time(NULL);
        throw ErrorSetIterator_IsInvalid(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }
}

template <keyType Key>
SetIterator<Key>::pointer SetIterator<Key>::operator ->() const
{
    try
    {
        return &(*list_iter);
    }
    catch (ErrorListIterator_IsInvalid &error) 
    {
        time_t cur_time = time(NULL);
        throw ErrorSetIterator_IsInvalid(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    return &(*list_iter);
}
