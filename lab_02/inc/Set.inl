template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(const Set<Key, Compare> &set) : data(set.data)
{
    this->size = set.size;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(Set<Key, Compare> &&set) : data(std::move(set.data))
{
    this->size = set.size;
    set.size = 0;
}







template <
        keyType Key,
        typename Compare 
>
void Set<Key, Compare>::erase(const Key &value)
{
    bool flag = true;
    Compare comp;
    ListIterator<Key> iter = data.begin();

    for (; flag && iter != data.end(); iter++)
        if (!comp(*iter, value) && !comp(value, *iter))
        {
            data.erase(iter);
            flag = false;

            this->size--;
        }
}

template <
        keyType Key,
        typename Compare 
>
void Set<Key, Compare>::erase(Set<Key, Compare>::iterator &pos)
{
    this->erase(*pos);
}

// template <
//         keyType Key,
//         typename Compare 
// >
// void Set<Key, Compare>::erase(Set<Key, Compare>::const_iterator &pos)
// {
//     this->erase(*pos);
// }









template <
        keyType Key,
        typename Compare 
>
void Set<Key, Compare>::insert(const Key &value)
{
    bool flag = true;
    Compare comp;
    ListIterator<Key> iter = data.begin();
    
    for (; flag && iter != data.end(); iter++)
        if (!comp(*iter, value) && !comp(value, *iter))
            flag = false;
        else if (!comp(*iter, value))
        {
            data.insert(iter, value);
            flag = false;

            this->size++;
        }
    
    if (flag)
    {
        data.push_back(value); // В конец, если value больше всех значений

        this->size++;
    }
}












template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::iterator Set<Key, Compare>::begin() const noexcept
{
    SetIterator<Key> iter {data.begin()};

    return iter;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::iterator Set<Key, Compare>::end() const noexcept
{
    ListIterator<Key> list_iter {data.end()};
    SetIterator<Key> iter {list_iter};

    return iter;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::const_iterator Set<Key, Compare>::cbegin() const noexcept
{
    ConstSetIterator<Key> iter {data.cbegin()};

    return iter;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::const_iterator Set<Key, Compare>::cend() const noexcept
{
    ListIterator<Key> list_iter {data.cend()};
    SetIterator<Key> iter {list_iter};

    return iter;
}









template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator |(const Set<Key, Compare> &set)
{
    Set<Key, Compare> tmp {*this};

    for (const auto &v : set)
        tmp.insert(v);

    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator |(const Key &value)
{
    Set<Key, Compare> tmp {*this};

    tmp.insert(value);

    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator |=(const Set<Key, Compare> &set)
{
    for (const auto &v : set)
        this->insert(v);

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator |=(const Key &value)
{
    this->insert(value);

    return *this;
}
