#include <memory>
#include <ranges>

template <numType Type>
ListIterator<Type>::ListIterator(std::shared_ptr<Node<Type>> &list)
{
    cur_ptr = list;
    this->index = 0;
}

template <numType Type>
ListIterator<Type>::ListIterator(const ListIterator<Type> &iter)
{
    cur_ptr = iter.cur_ptr;
    this->index = iter.index;
}

template <numType Type>
ListIterator<Type>::ListIterator(ListIterator<Type> &&iter)
{
    cur_ptr = iter.cur_ptr;
    this->index = iter.index;
}














template <numType Type>
ListIterator<Type>& ListIterator<Type>::operator =(const ListIterator<Type> &iter)
{
    cur_ptr = iter.cur_ptr;

    return *this;
}

template <numType Type>
ListIterator<Type>& ListIterator<Type>::operator =(const Node<Type> &head)
{
    cur_ptr = head;

    return *this;
}

template <numType Type>
ListIterator<Type>& ListIterator<Type>::operator =(ListIterator<Type> &&iter)
{
    cur_ptr = iter.cur_ptr;
    iter.cur_ptr = nullptr;

    return *this;
}

template <numType Type>
template <sizeType U>
ListIterator<Type>& ListIterator<Type>::operator +=(const U value)
{
    for (auto i : std::ranges::iota_view(0, value))
        cur_ptr = cur_ptr->GetNext();

    this->index += value;

    return *this;
}

template <numType Type>
template <sizeType U>
ListIterator<Type>& ListIterator<Type>::operator -=(const U value)
{
    for (auto i : std::ranges::iota_view(0, value))
        cur_ptr = cur_ptr->GetParent();

    this->index -= value;

    return *this;
}










template <numType Type>
ListIterator<Type>& ListIterator<Type>::operator ++()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();
    
    cur_ptr = converted->GetNext(); // ОШИБКА
    ++(this->index);
    
    return *this;
}

template <numType Type>
ListIterator<Type> ListIterator<Type>::operator ++(int)
{
    ListIterator<Type> tmp {*this};
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();
    
    cur_ptr = converted->GetNext();
    ++(this->index);

    return tmp;
}

template <numType Type>
ListIterator<Type>& ListIterator<Type>::operator --()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();

    cur_ptr = converted->GetParent();
    --(this->index);
    
    return *this;
}

template <numType Type>
ListIterator<Type> ListIterator<Type>::operator --(int)
{
    ListIterator<Type> tmp {*this};
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();
    
    cur_ptr = converted->GetParent();
    --(this->index);

    return tmp;
}





template <numType Type>
Type ListIterator<Type>::Current()
{
    std::shared_ptr<Node<Type>> converted = cur_ptr.lock();

    return converted->Data();
}

