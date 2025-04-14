#pragma once

#include <cstddef>
#include <stdbool.h>

#include <memory>
#include <ranges>
#include <iterator>

#include "Node.hpp"
#include "BaseIterator.hpp"
#include "concept.hpp"

template <numType Type>
class ListIterator : public BaseIterator
{
    private:
        std::weak_ptr<Node<Type>> cur_ptr;
        std::ptrdiff_t index;
        std::size_t size;

    protected:
        std::shared_ptr<Node<Type>> GetPtr() { return cur_ptr.lock(); };

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = Type;
        using difference_type = std::ptrdiff_t;
        using pointer = Type*;
        using reference = Type&;

        ListIterator() noexcept = default;
        ListIterator(std::shared_ptr<Node<Type>> &list); // Инициализация
        ListIterator(const ListIterator<Type>&); // Копирование
        ListIterator(ListIterator<Type>&&); // Перенос
        ListIterator(std::size_t size) = delete; // delete (конструктор с 1-м параметром у итератора быть не может)
        ~ListIterator() = default; // override; // Деструктор (так-то для weak_ptr не нужно особо)

        ListIterator<Type>& operator =(const ListIterator<Type>&);
        ListIterator<Type>& operator =(const Node<Type>&);
        ListIterator<Type>& operator =(ListIterator<Type>&&);

        template <sizeType U> ListIterator<Type>& operator +=(const U value);
        template <sizeType U> ListIterator<Type>& operator -=(const U value);

        ListIterator<Type>& next();
        ListIterator<Type>& prev();
        ListIterator<Type>& operator ++();
        ListIterator<Type> operator ++(int);
        ListIterator<Type>& operator --();
        ListIterator<Type> operator --(int);

        Type Current();
        explicit operator bool() const noexcept; // bool в возвращаемом значении нельзя, так как и так подразумевается bool
        reference operator *() const;
        pointer operator ->() const;

        auto operator <=>(const ListIterator<Type>&) const;
        bool operator ==(const ListIterator<Type>&) const;
        bool operator !=(const ListIterator<Type>&) const;
};

static_assert(std::bidirectional_iterator<ListIterator<int>>);

#include "ListIterator.inl"

