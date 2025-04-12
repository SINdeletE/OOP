#include <memory>

template <numType Type>
List<Type>::List() : head(nullptr)
{
    this->size = 0;
}

template <numType Type>
std::size_t List<Type>::GetSize() const
{
    return this->size;
}

template <numType Type>
bool List<Type>::IsEmpty() const
{
    return this->size == 0;
}
