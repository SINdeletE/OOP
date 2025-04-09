#include <cstddef>

template <typename Type>
Iterator::Iterator(const Iterator<Type> &iter)
{
    data_ptr = iter;
    index = 0;
    size = 0;
}

template <typename Type>
Iterator::Iterator(const Set<Type> &set)
{
    data_ptr = std::static_cast<std::weak_ptr<Type []>>(set.data);
    index = 0;
    size = Set.GetSize();
}

template <typename Type>
Iterator<Type>& Iterator::operator =(const Iterator<Type>&)
{
    // Позже
}

template <typename Type>
Iterator<Type>& Iterator::operator =(const Set<Type []>&)
{
    // Позже
}

template <typename Type>
Iterator<Type>& Iterator::operator ++()
{
    // Обработка ошибки

    ++index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator::operator ++(int)
{
    // Обработка ошибки
    Iterator<Type> tmp {*this};

    ++index;
    return tmp;
}

template <typename Type>
Iterator<Type>& Iterator::operator --()
{
    // Обработка ошибки

    --index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator::operator --(int)
{
    // Обработка ошибки
    Iterator<Type> tmp {*this};

    --index;
    return tmp;
}

template <typename Type>
Type& Iterator::operator [](size_t index)
{
    return data_ptr[index];
}
