// #include "iterator.hpp"

#include <cstddef>

template <typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &iter)
{
    data_ptr = iter;
    index = 0;
    size = iter.size;
}

template <typename Type>
Iterator<Type>::Iterator(const Set<Type> &set)
{
    data_ptr = std::static_cast<std::weak_ptr<Type []>>(set.data);
    index = 0;
    size = Set.GetSize();
}

// ---------------------------------------------------------------------------

template <typename Type>
Iterator<Type>& Iterator<Type>::operator =(const Iterator<Type> &iter)
{
    // Позже
    
    data_ptr = iter;
    index = 0;
    size = iter.size;

    return *this;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator =(const Set<Type> &set)
{
    // Позже

    data_ptr = std::static_cast<std::weak_ptr<Type []>>(set.data);
    index = 0;
    size = Set.GetSize();

    return *this;
}

// ---------------------------------------------------------------------------


template <typename Type>
template <sizeType U>
Iterator<T> Iterator::operator +(const U value) const
{
    Iterator<T> tmp {*this};
    tmp.index += value;
    
    return tmp;
}

template <typename Type>
template <sizeType U>
Iterator<T> Iterator::operator -(const U value) const
{
    Iterator<T> tmp {*this};
    tmp.index -= value;
    
    return tmp;
}

template <typename Type>
template <sizeType U>
Iterator<T>& Iterator::operator +=(const U value) const
{
    index += value;
    
    return *this;
}

template <typename Type>
template <sizeType U>
Iterator<T>& Iterator::operator -=(const U value) const
{
    index -= value;
    
    return *this;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator ++()
{
    // Обработка ошибки

    ++index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator ++(int)
{
    // Обработка ошибки
    Iterator<Type> tmp {*this};

    ++index;
    return tmp;
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator --()
{
    // Обработка ошибки

    --index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator --(int)
{
    // Обработка ошибки
    Iterator<Type> tmp {*this};

    --index;
    return tmp;
}

// ---------------------------------------------------------------------------

template <typename Type>
Type& Iterator<Type>::operator [](size_t index)
{
    return data_ptr[index];
}

template <typename Type>
auto Iterator<Type>::operator <=>(const Iterator<Type>& iter) const
{
    return index <=> iter.index;
}

template <typename Type>
bool Iterator<Type>::operator bool()() const noexcept
{
    if (index >= size || data_ptr.expired())
        return false;

    return true;
}
