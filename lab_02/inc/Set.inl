#include <iostream>

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
Set<Key, Compare>::iterator Set<Key, Compare>::erase(const Key &value)
{
    bool flag = true;
    Compare comp;
    ListIterator<Key> iter = data.begin();

    while (flag && iter != data.end())
    {
        if (!comp(*iter, value) && !comp(value, *iter))
        {
            iter = data.erase(iter);
            flag = false;

            this->size--;
        }
        
        if (flag && iter != data.end())
        {
            iter++;
        }
    }
    
    SetIterator<Key> set_iter {iter};
    return set_iter;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::iterator Set<Key, Compare>::erase(Set<Key, Compare>::iterator &pos)
{
    return this->erase(*pos);
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::const_iterator Set<Key, Compare>::erase(Set<Key, Compare>::const_iterator &pos)
{
    return this->erase(*pos);
}









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
Set<Key, Compare>::iterator Set<Key, Compare>::find(const Key &value)
{
    bool flag = true;
    iterator res_iter = this->end();
    Compare comp;

    for (auto iter = this->begin(); flag && iter != this->end(); ++iter)
        if (!comp(*iter, value) && !comp(value, *iter))
        {
            res_iter = iter;
            flag = false;
        }
    
    return res_iter;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::const_iterator Set<Key, Compare>::cfind(const Key &value) const
{
    bool flag = true;
    const_iterator res_iter = this->cend();
    Compare comp;

    for (const_iterator iter = this->cbegin(); flag && iter != this->cend(); iter++)
        if (!comp(*iter, value) && !comp(value, *iter))
        {
            res_iter = iter;
            flag = false;
        }
    
    return res_iter;
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
    ConstListIterator<Key> list_iter {data.cend()};
    ConstSetIterator<Key> iter {list_iter};

    return iter;
}







// ИЛИ

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

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator +(const Set<Key, Compare> &set)
{
    return *this | set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator +(const Key &value)
{
    return *this | value;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator +=(const Set<Key, Compare> &set)
{
    return *this |= set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator +=(const Key &value)
{
    return *this |= value;
}



// И

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator &=(const Set<Key, Compare> &set)
{
    for (auto iter = this->begin(); iter != this->end();)
        if (set.cfind(*iter) == set.cend())
            iter = this->erase(*iter);
        else
            iter++;
    
    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator &=(const Key &value)
{
    for (auto iter = this->begin(); iter != this->end();) // erase_if
        if (*iter != value)
            iter = this->erase(*iter);
        else
            iter++;
    
    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator &(const Set<Key, Compare> &set)
{
    Set<Key, Compare> tmp {*this};
    
    tmp &= set;

    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator &(const Key &value)
{
    Set<Key, Compare> tmp {*this};
    
    tmp &= value;

    return tmp;
}


// Разность

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator -=(const Set<Key, Compare> &set)
{
    for (const auto &v : set)
        this->erase(v);

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator -=(const Key &value)
{
    this->erase(value);

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator -(const Set<Key, Compare> &set)
{
    Set<Key, Compare> tmp {*this};

    tmp -= set;
    
    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator -(const Key &value)
{
    Set<Key, Compare> tmp {*this};

    tmp -= value;
    
    return tmp;
}

