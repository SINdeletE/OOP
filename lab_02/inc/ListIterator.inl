#include <memory>

template <numType Type>
ListIterator<Type>::ListIterator(const List<Type> &list) cur_ptr(list.head) {}
template <numType Type>
ListIterator<Type>::ListIterator(const ListIterator<Type> &iter) : cur_ptr(iter.cur_ptr) {}

template <numType Type>
ListIterator<Type>::ListIterator(ListIterator<Type> &&iter) cur_ptr(iter.cur_ptr)
{
    iter.cur_ptr = nullptr;
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
