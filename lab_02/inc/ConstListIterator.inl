#include <memory>
#include <ranges>

template <keyType Type>
ConstListIterator<Type>::ConstListIterator() noexcept : index(0)
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = null_ptr;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(std::shared_ptr<Node<Type>> &list, const ConstListIterator<Type>::difference_type &init_index)
{
    cur_ptr = list;
    index = init_index;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(const ConstListIterator<Type> &iter)
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;
}

template <keyType Type>
ConstListIterator<Type>::ConstListIterator(ConstListIterator<Type> &&iter)
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;
}














template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator =(const ConstListIterator<Type> &iter)
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;

    return *this;
}

template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator =(ConstListIterator<Type> &&iter)
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = iter.cur_ptr;
    iter.cur_ptr = null_ptr; // ОШИБКА

    index = iter.index;
    iter.index = 0;

    return *this;
}

template <keyType Type>
template <sizeType U>
ConstListIterator<Type>& ConstListIterator<Type>::operator +=(const U value)
{
    if (value < 0) {
        throw std::invalid_argument("Negative offset");
    }

    std::shared_ptr<Node<Type>> ptr = cur_ptr.lock();
    for (int i = 0; i < value; i++)
        ptr = ptr->GetNext();
    
    cur_ptr = ptr;

    index += value;

    return *this;
}








template <keyType Type>
ConstListIterator<Type>& ConstListIterator<Type>::next()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();
    
    cur_ptr = converted->GetNext();
    ++(this->index);

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
ConstListIterator<Type>::difference_type ConstListIterator<Type>::operator -(const ConstListIterator<Type> &iter)
{
    return index - iter.index;
}



template <keyType Type>
ConstListIterator<Type>::value_type ConstListIterator<Type>::Current()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();

    return converted->Data();
}

template <keyType Type>
ConstListIterator<Type>::operator bool() const noexcept
{
    return index < 0 || !cur_ptr.expired();
}

template <keyType Type>
ConstListIterator<Type>::reference ConstListIterator<Type>::operator*() const {
    if (auto ptr = cur_ptr.lock())
        return ptr->RefData();

    throw std::runtime_error("Dereferencing invalid iterator");
}

template <keyType Type>
ConstListIterator<Type>::pointer ConstListIterator<Type>::operator->() const {
    if (auto ptr = cur_ptr.lock())
        return &ptr->Data();

    throw std::runtime_error("Accessing invalid iterator");
}






template <keyType Type>
auto ConstListIterator<Type>::operator <=>(const ConstListIterator<Type> &iter) const
{
    if (this->cur_ptr == iter.cur_ptr)
        return index - iter.index; 
    // else
    //     ; // Ошибка, если не тот указатель

    return 3838;
}

template <keyType Type>
bool ConstListIterator<Type>::operator ==(const ConstListIterator<Type> &iter) const
{
    std::shared_ptr<Node<Type>> iter1 = this->cur_ptr.lock();
    std::shared_ptr<Node<Type>> iter2 = iter.cur_ptr.lock();

    std::size_t index1 = this->index;
    std::size_t index2 = iter.index;

    return index1 == index2;
}

template <keyType Type>
bool ConstListIterator<Type>::operator !=(const ConstListIterator<Type> &iter) const
{
    std::shared_ptr<Node<Type>> iter1 = this->cur_ptr.lock();
    std::shared_ptr<Node<Type>> iter2 = iter.cur_ptr.lock();

    std::size_t index1 = this->index;
    std::size_t index2 = iter.index;

    return index1 != index2;
}