#include <ranges>
#include <algorithm>
#include <ctime>
#include <cmath>

#include "SetException.hpp"

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(const Set<Key, Compare> &set) : data(set.data)
{
    this->_size = set.size();
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(Set<Key, Compare> &&set) noexcept
{
    this->data = std::move(set.data);

    this->_size = set.size();
    set._size = 0;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(std::initializer_list<Key> list)
{
    this->clear();
    std::ranges::for_each(list, [this](const Key &value) { append(value); });
}

template <
        keyType Key,
        typename Compare 
>
template <typename U>
requires Convertible_concept<U, Key>
Set<Key, Compare>::Set(std::initializer_list<U> list)
{
    this->clear();
    std::ranges::for_each(list, [this](const U &value) { append(value); });
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::Set(Set<Key, Compare>::size_type array_len, const Key *array)
{
    this->clear();
    std::ranges::for_each(array, array + array_len, [this](const auto &value) { append(value); });
}


template <
        keyType Key,
        typename Compare 
>
template <typename U>
requires Convertible_concept<U, Key>
Set<Key, Compare>::Set(Set<Key, Compare>::size_type array_len, const U *array)
{
    this->clear();
    std::ranges::for_each(array, array + array_len, [this](const auto &value) { append(value); });
}

template <
        keyType Key,
        typename Compare 
>
template <std::input_iterator Beg, std::sentinel_for<Beg> End>
requires std::convertible_to<std::iter_value_t<Beg>, Key>
Set<Key, Compare>::Set(Beg begin, End end)
{
    this->clear();
    std::ranges::for_each(begin, end, [this] (const auto &value) { this->append(static_cast<Key>(value)); });
}

template <
        keyType Key,
        typename Compare 
>
template <typename R>
requires Range_concept<R, Key>
Set<Key, Compare>::Set(R&& range)
{
    this->clear();
    std::ranges::for_each(std::forward<R>(range), [this] (const auto &value) { this->append(value); });
}

template <
        keyType Key,
        typename Compare 
>
template <typename R>
requires Range_concept<R, Key>
Set<Key, Compare>::Set(R&& range, Set<Key, Compare>::size_type size)
{
    this->clear();

    auto range_size = std::ranges::distance(range);

    if (size <= 1)
    {
        time_t cur_time = time(NULL);
        throw ErrorSet_BadSize(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
    }

    if (std::ranges::empty(range))
    {
        return; // Пустое мн-во
    }
    else
    {
        double range_beg = *std::ranges::begin(range);
        double range_end = *std::ranges::next(std::ranges::begin(range), range_size - 1);

        auto diapason = std::ranges::iota_view(0u, static_cast<unsigned int>(size))
                        | std::views::transform([=](auto i) 
                        {
                            return std::lerp(range_beg, range_end, static_cast<double>(i) / (size - 1));
                        });
        
        std::ranges::for_each(diapason, [this] (const auto &value) { append(static_cast<Key>(value)); });
    }
}

template <
        keyType Key,
        typename Compare 
>
template <typename C>
requires (! std::same_as<C, Set<Key, Compare>>) && Container_range_concept<C, Key>
Set<Key, Compare>::Set(const C& container)
{
    this->clear();
    std::ranges::for_each(container, [this] (const auto &value) { append(value); });
}

template <
        keyType Key,
        typename Compare 
>
template <typename... Args>
requires (sizeof...(Args) > 0) && 
        (std::convertible_to<Args, Key> && ...)
Set<Key, Compare>::Set(Args&&... args)
{
    this->clear();
    (append(std::forward<Args>(args)), ...);
}






template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator=(const Set<Key, Compare> &set)
{
    this->clear();
    std::ranges::for_each(set, [this](const auto &value) { append(value); });

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator=(Set<Key, Compare> &&set) noexcept
{
    data = std::move(set.data);
    
    _size = set.size();
    set._size = 0;

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
template <Container_concept C>
requires (! std::same_as<C, Set<Key, Compare>>) && Container_range_concept<C, Key>
Set<Key, Compare>& Set<Key, Compare>::operator=(const C& container)
{
    this->clear();
    std::ranges::for_each(container, [this] (const auto &value) { append(value); });

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
template <typename R>
requires Range_concept<R, Key>
Set<Key, Compare>& Set<Key, Compare>::operator=(R&& range)
{
    this->clear();
    std::ranges::for_each(std::forward<R>(range), [this] (const auto &value) { append(value); });

    return *this;
}







template <
        keyType Key,
        typename Compare 
>
bool Set<Key, Compare>::erase(const Key &value)
{
    bool flag = true;
    Compare comp;
    ConstListIterator<Key> iter = data.cbegin();

    while (flag && iter != data.cend())
    {
        if (!comp(*iter, value) && !comp(value, *iter))
        {
            try
            {
                iter = data.erase(iter);
            }
            catch (ErrorList_IsEmpty &error)
            {
                flag = false;
                iter = data.cend();
                this->_size++;
            }

            flag = false;

            this->_size--;
        }
        
        if (flag && iter != data.cend())
        {
            iter++;
        }
    }

    flag = ! flag;

    return flag;
}

template <
        keyType Key,
        typename Compare 
>
bool Set<Key, Compare>::erase(Set<Key, Compare>::const_iterator &pos)
{
    return this->erase(*pos);
}









template <
        keyType Key,
        typename Compare 
>
bool Set<Key, Compare>::append(const Key &value)
{
    bool flag = true;
    Compare comp;
    ConstListIterator<Key> res_list_iter {};

    bool result_flag = false;
    for (auto iter = data.cbegin(); flag && iter != data.cend(); iter++)
        if (!comp(*iter, value) && !comp(value, *iter))
        {
            res_list_iter = iter;
            flag = false;
        }
        else if (!comp(*iter, value))
        {
            try
            {
                res_list_iter = data.insert(iter, value);
            }
            catch (ErrorList_IsEmpty &error)
            {
                time_t cur_time = time(NULL);
                throw ErrorSet_BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
            }
            flag = false;
            result_flag = true;

            this->_size++;
        }
    
    if (flag)
    {
        try
        {
            res_list_iter = data.push_back(value); // В конец, если value больше всех значений
        }
        catch (ErrorList_IsEmpty &error)
        {
            time_t cur_time = time(NULL);
            throw ErrorSet_BadAlloc(__FILE__, typeid(*this).name(), __LINE__, ctime(&cur_time));
        }

        this->_size++;

        res_list_iter = data.cbegin();
        res_list_iter += this->size() - 1;

        result_flag = true;
    }

    return result_flag;
}

template <
        keyType Key,
        typename Compare 
>
template <typename U>
requires Convertible_concept<U, Key>
bool Set<Key, Compare>::append(const U &value)
{
    return this->append(static_cast<Key>(value));
}



template <
        keyType Key,
        typename Compare 
>
bool Set<Key, Compare>::find(const Key &value) const
{
    bool flag = true;
    Compare comp;

    for (const_iterator iter = this->cbegin(); flag && iter != this->cend(); iter++)
        if (!comp(*iter, value) && !comp(value, *iter))
            flag = false;
    
    return ! flag;
}







template <
        keyType Key,
        typename Compare 
>
void Set<Key, Compare>::clear()
{
    bool flag = true;
    ConstSetIterator<Key> tmp {};

    if (! data.IsEmpty())
    {
        for (auto iter = this->cbegin(); flag && iter != this->cend();)
        {    
            tmp = iter;
            ++iter;

            try
            {
                this->erase(tmp);
            }
            catch (ErrorList_IsEmpty &error)
            {
                flag = false;
            }
        }
    }
    
    this->_size = 0;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::iterator Set<Key, Compare>::begin() const noexcept
{
    iterator iter {data.cbegin()};

    return iter;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::iterator Set<Key, Compare>::end() const noexcept
{
    ConstListIterator<Key> list_iter {data.cend()};
    iterator iter {list_iter};

    return iter;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::const_iterator Set<Key, Compare>::cbegin() const noexcept
{
    const_iterator iter {data.cbegin()};

    return iter;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>::const_iterator Set<Key, Compare>::cend() const noexcept
{
    ConstListIterator<Key> list_iter {data.cend()};
    const_iterator iter {list_iter};

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
        tmp.append(v);

    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator |(const Key &value) const
{
    Set<Key, Compare> tmp {*this};

    tmp |= value;

    return tmp;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator |=(const Set<Key, Compare> &set)
{
    for (const auto &v : set)
        *this |= v;

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator |=(const Key &value)
{
    this->append(value);

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

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::Or(std::initializer_list<Key> list)
{
    std::ranges::for_each(list, [this](const Key &value){ append(value); });

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
template <typename U>
requires Convertible_concept<U, Key>
Set<Key, Compare>& Set<Key, Compare>::Or(std::initializer_list<U> list)
{
    std::ranges::for_each(list, [this](const U &value){ append(value); });

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::Or_const(const Set<Key, Compare> &set) const
{
    return *this | set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::Or_const(const Key &value) const
{
    return *this | value;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::Or(const Set<Key, Compare> &set)
{
    return *this |= set;
}







// И

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator &=(const Set<Key, Compare> &set)
{
    bool flag = true;
    ConstSetIterator<Key> tmp {};

    for (auto iter = this->cbegin(); flag && iter != this->cend();)
        if (! set.find(*iter))
        {
            tmp = iter;
            ++iter;

            try
            {
                this->erase(tmp);
            }
            catch (ErrorList_IsEmpty &error)
            {
                flag = false;
            }
        }
        else
            ++iter;
    
    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator &=(const Key &value)
{
    bool flag = true;
    ConstSetIterator<Key> tmp {};

    for (auto iter = this->cbegin(); flag && iter != this->cend();) // erase_if
        if (*iter != value)
        {
            tmp = iter;
            ++iter;

            try
            {
                this->erase(tmp);
            }
            catch (ErrorList_IsEmpty &error)
            {
                flag = false;
            }
        }
        else
            ++iter;
    
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

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator *(const Set<Key, Compare> &set) const
{
    return *this & set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::operator *(const Key &value) const
{
    return *this & value;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator *=(const Set<Key, Compare> &set)
{
    return *this &= set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator *=(const Key &value)
{
    return *this &= value;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::And(std::initializer_list<Key> list)
{
    Set<Key, Compare> set {list};

    return *this &= set;
}

template <
        keyType Key,
        typename Compare 
>
template <typename U>
requires Convertible_concept<U, Key>
Set<Key, Compare>& Set<Key, Compare>::And(std::initializer_list<U> list)
{
    Set<Key, Compare> set {list};

    return *this &= set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::And_const(const Set<Key, Compare> &set) const
{
    return *this & set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::And_const(const Key &value) const
{
    return *this & value;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::And(const Set<Key, Compare> &set)
{
    return *this &= set;
}




// Разность

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator -=(const Set<Key, Compare> &set)
{
    for (const auto &v : set)
        try
        {
            this->erase(v);
        }
        catch (ErrorList_IsEmpty &error)
        {}

    return *this;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::operator -=(const Key &value)
{
    try
    {
        this->erase(value);
    }
    catch (ErrorList_IsEmpty &error)
    {}

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

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::Diff(std::initializer_list<Key> list)
{
    Set<Key, Compare> set {list};

    return *this -= set;
}

template <
        keyType Key,
        typename Compare 
>
template <typename U>
requires Convertible_concept<U, Key>
Set<Key, Compare>& Set<Key, Compare>::Diff(std::initializer_list<U> list)
{
    Set<Key, Compare> set {list};

    return *this -= set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::Diff_const(const Set<Key, Compare> &set) const
{
    return *this - set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::Diff_const(const Key &value) const
{
    return *this - value;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::Diff(const Set<Key, Compare> &set)
{
    return *this -= set;
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
        this->append(value);

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

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::Xor(std::initializer_list<Key> list)
{
    Set<Key, Compare> set {list};

    return *this ^= set;
}

template <
        keyType Key,
        typename Compare 
>
template <typename U>
requires Convertible_concept<U, Key>
Set<Key, Compare>& Set<Key, Compare>::Xor(std::initializer_list<U> list)
{
    Set<Key, Compare> set {list};

    return *this ^= set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::Xor_const(const Set<Key, Compare> &set) const
{
    return *this ^ set;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare> Set<Key, Compare>::Xor_const(const Key &value) const
{
    return *this ^ value;
}

template <
        keyType Key,
        typename Compare 
>
Set<Key, Compare>& Set<Key, Compare>::Xor(const Set<Key, Compare> &set)
{
    return *this ^= set;
}




// Равенство

template <
        keyType Key,
        typename Compare 
>
bool Set<Key, Compare>::operator ==(const Set<Key, Compare> &set) const
{
    bool is_equal = true;

    if (this->_size != set._size)
        is_equal = false;
    else
    {
        Set<Key, Compare> tmp {};
        tmp = *this ^ set;

        if (! tmp.IsEmpty())
            is_equal = false;
    }

    return is_equal;
}

template <
        keyType Key,
        typename Compare 
>
bool Set<Key, Compare>::operator !=(const Set<Key, Compare> &set) const
{
    return ! (*this == set);
}

