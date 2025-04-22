#include <ranges>
#include <algorithm>
#include <ctime>
#include <SetException.hpp>

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
Set<Key, Compare>::Set(Set<Key, Compare> &&set) noexcept : data(std::move(set.data))
{
    this->size = set.size;
    set.size = 0;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(std::initializer_list<Key> list)
{
    this->clear();
    std::ranges::for_each(list, [this](const auto &value) { insert(value); });
}

// template <
//         keyType Key,
//         typename Compare 
// >
// Set(Args&&... args)

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(Set<Key, Compare>::size_type n,...)
{
    time_t cur_time = time(NULL);
    this->clear();

    if (n <= 0)
    {
        throw ErrorSet_BadSize(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    va_list vl; 
    va_start(vl, n);
    
    for (std::ptrdiff_t i = 0; i < n; ++i)
    {
        Key arg = va_arg(vl, Key);

        try
        {
            this->insert(arg);
        }
        catch (ErrorList_BadAlloc &error) // BadAlloc list
        {
            throw ErrorSet_BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }
    }

}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(Set<Key, Compare>::size_type array_len, const Key *array)
{
    this->clear();
    std::ranges::for_each(array, array + array_len, [this](const auto &value) { insert(value); });
}






template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator=(const Set<Key, Compare> &set)
{
    this->clear();
    std::ranges::for_each(set, [this](const auto &value) { insert(value); });

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator=(Set<Key, Compare> &&set) noexcept
{
    *this = Set(std::move(set));

    return *this;
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
Set<Key, Compare>::iterator Set<Key, Compare>::insert(const Key &value)
{
    bool flag = true;
    Compare comp;
    ListIterator<Key> res_list_iter {};

    for (auto iter = data.begin(); flag && iter != data.end(); iter++)
        if (!comp(*iter, value) && !comp(value, *iter))
        {
            res_list_iter = iter;
            flag = false;
        }
        else if (!comp(*iter, value))
        {
            res_list_iter = data.insert(iter, value);
            flag = false;

            this->size++;
        }
    
    if (flag)
    {
        res_list_iter = data.push_back(value); // В конец, если value больше всех значений

        this->size++;

        res_list_iter = data.begin();
        res_list_iter += this->GetSize() - 1;
    }

    SetIterator<Key> res_iter {res_list_iter};

    return res_iter;
}


template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::iterator Set<Key, Compare>::find(const Key &value) const
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
void Set<Key, Compare>::clear()
{
    for (auto iter = this->begin(); iter != this->end();)
        iter = this->erase(*iter);
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
Set<Key, Compare> Set<Key, Compare>::operator |(const Set<Key, Compare> &set) const
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
Set<Key, Compare> Set<Key, Compare>::operator |(const Key &value) const
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
Set<Key, Compare> Set<Key, Compare>::operator +(const Set<Key, Compare> &set) const
{
    return *this | set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator +(const Key &value) const
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
Set<Key, Compare> Set<Key, Compare>::operator &(const Set<Key, Compare> &set) const
{
    Set<Key, Compare> tmp {*this};
    
    tmp &= set;

    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator &(const Key &value) const
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
Set<Key, Compare> Set<Key, Compare>::operator -(const Set<Key, Compare> &set) const
{
    Set<Key, Compare> tmp {*this};

    tmp -= set;
    
    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator -(const Key &value) const
{
    Set<Key, Compare> tmp {*this};

    tmp -= value;
    
    return tmp;
}









// Симметрическая разность (Исключающее ИЛИ)

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator ^=(const Set<Key, Compare> &set)
{
    Set<Key, Compare> tmp {*this};
    tmp &= set;

    *this |= set;
    *this -= tmp;

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator ^=(const Key &value)
{
    bool is_contains = false;

    if (this->contains(value))
        is_contains = true;

    this->clear();

    if (! is_contains)
        this->insert(value);

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator ^(const Set<Key, Compare> &set) const
{
    Set<Key, Compare> tmp {*this};

    tmp ^= set;

    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator ^(const Key &value) const
{
    Set<Key, Compare> tmp {*this};

    tmp ^= value;

    return tmp;
}
