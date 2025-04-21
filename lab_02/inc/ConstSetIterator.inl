template <keyType Key>
ConstSetIterator<Key>& ConstSetIterator<Key>::operator =(const ConstSetIterator<Key> &iter) 
{
    this->list_iter = iter.list_iter;
    
    return *this;
}

template <keyType Key>
ConstSetIterator<Key>& ConstSetIterator<Key>::operator =(ConstSetIterator<Key> &&iter)
{
    this->list_iter = std::move(iter.list_iter);

    return *this; 
}

template <keyType Key>
template <sizeType U> 
ConstSetIterator<Key>& ConstSetIterator<Key>::operator +=(const U value)
{
    list_iter += value;

    return *this;
}


template <keyType Key>
ConstSetIterator<Key>& ConstSetIterator<Key>::next()
{
    ++list_iter;

    return *this;
}

template <keyType Key>
ConstSetIterator<Key>& ConstSetIterator<Key>::operator ++()
{
    return this->next();
}

template <keyType Type>
ConstSetIterator<Type> ConstSetIterator<Type>::operator ++(int)
{
    ConstSetIterator<Type> tmp {*this};
    
    this->next();

    return tmp;
}

template <keyType Key>
ConstSetIterator<Key>::difference_type ConstSetIterator<Key>::operator-(const ConstSetIterator<Key> &iter) const
{
    return this->list_iter - iter->list_iter;
}

template <keyType Key>
ConstSetIterator<Key>::value_type ConstSetIterator<Key>::Current() const
{
    return list_iter.Current();
}

template <keyType Key>
ConstSetIterator<Key>::operator bool() const noexcept
{
    return bool(list_iter);
}

template <keyType Key>
ConstSetIterator<Key>::reference ConstSetIterator<Key>::operator *() const
{   
    // try:
    //     return *iter;
    // catch 
    // {

    // }

    return *list_iter;
}

template <keyType Key>
ConstSetIterator<Key>::pointer ConstSetIterator<Key>::operator ->() const
{
    // try:
    //     return iter->;
    // catch 
    // {

    // }

    return &(*list_iter);
}
