#include <memory>
#include <ranges>

template <numType Type>
ListIterator<Type>::ListIterator() noexcept : index(0)
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = null_ptr;
}

template <numType Type>
ListIterator<Type>::ListIterator(std::shared_ptr<Node<Type>> &list, const ListIterator<Type>::difference_type &init_index)
{
    cur_ptr = list;
    index = init_index;
}

template <numType Type>
ListIterator<Type>::ListIterator(const ListIterator<Type> &iter)
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;
}

template <numType Type>
ListIterator<Type>::ListIterator(ListIterator<Type> &&iter)
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;
}














template <numType Type>
ListIterator<Type>& ListIterator<Type>::operator =(const ListIterator<Type> &iter)
{
    cur_ptr = iter.cur_ptr;
    index = iter.index;

    return *this;
}

template <numType Type>
ListIterator<Type>& ListIterator<Type>::operator =(ListIterator<Type> &&iter)
{
    std::shared_ptr<Node<Type>> null_ptr {nullptr};
    cur_ptr = iter.cur_ptr;
    iter.cur_ptr = null_ptr; // ОШИБКА

    index = iter.index;
    iter.index = 0;

    return *this;
}

template <numType Type>
template <sizeType U>
ListIterator<Type>& ListIterator<Type>::operator +=(const U value)
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








template <numType Type>
ListIterator<Type>& ListIterator<Type>::next()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();
    
    cur_ptr = converted->GetNext();
    ++(this->index);

    return *this;
}

template <numType Type>
ListIterator<Type>& ListIterator<Type>::operator ++()
{
    return this->next();
}

template <numType Type>
ListIterator<Type> ListIterator<Type>::operator ++(int)
{
    ListIterator<Type> tmp {*this};
    
    this->next();

    return tmp;
}

template <numType Type>
ListIterator<Type>::difference_type ListIterator<Type>::operator -(const ListIterator<Type> &iter)
{
    return index - iter.index;
}



template <numType Type>
ListIterator<Type>::value_type ListIterator<Type>::Current()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();

    return converted->Data();
}

template <numType Type>
ListIterator<Type>::operator bool() const noexcept
{
    return index < 0 || !cur_ptr.expired();
}

template <numType Type>
typename ListIterator<Type>::reference ListIterator<Type>::operator*() const {
    if (auto ptr = cur_ptr.lock())
        return ptr->RefData();

    throw std::runtime_error("Dereferencing invalid iterator");
}

template <numType Type>
typename ListIterator<Type>::pointer ListIterator<Type>::operator->() const {
    if (auto ptr = cur_ptr.lock())
        return &ptr->Data();

    throw std::runtime_error("Accessing invalid iterator");
}






template <numType Type>
auto ListIterator<Type>::operator <=>(const ListIterator<Type> &iter) const
{
    if (this->cur_ptr == iter.cur_ptr)
        return index - iter.index; 
    // else
    //     ; // Ошибка, если не тот указатель

    return 3838;
}

template <numType Type>
bool ListIterator<Type>::operator ==(const ListIterator<Type> &iter) const
{
    std::shared_ptr<Node<Type>> iter1 = this->cur_ptr.lock();
    std::shared_ptr<Node<Type>> iter2 = iter.cur_ptr.lock();

    std::size_t index1 = this->index;
    std::size_t index2 = iter.index;

    return index1 == index2;
}

template <numType Type>
bool ListIterator<Type>::operator !=(const ListIterator<Type> &iter) const
{
    std::shared_ptr<Node<Type>> iter1 = this->cur_ptr.lock();
    std::shared_ptr<Node<Type>> iter2 = iter.cur_ptr.lock();

    std::size_t index1 = this->index;
    std::size_t index2 = iter.index;

    return index1 != index2;
}