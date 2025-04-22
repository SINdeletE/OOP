#pragma once

#include <cstddef>
#include <stdbool.h>

#include <memory>
#include <ranges>
#include <iterator>

#include "Node.hpp"
#include "BaseIterator.hpp"
#include "ListException.hpp"
#include "concept.hpp"

template <keyType Type>
class ListIterator : public BaseIterator
{
    private:
        std::weak_ptr<Node<Type>> cur_ptr;
        std::ptrdiff_t index;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Type;
        using difference_type = std::ptrdiff_t;
        using pointer = Type*;
        using reference = Type&;

        ListIterator() noexcept;
        explicit ListIterator(const std::shared_ptr<Node<Type>> &list, const difference_type &index) noexcept;
        ListIterator(const ListIterator<Type>&) noexcept;
        ListIterator(ListIterator<Type>&&) noexcept;
        ~ListIterator() = default;

        ListIterator<Type>& operator =(const ListIterator<Type>&);
        ListIterator<Type>& operator =(ListIterator<Type>&&);
        template <sizeType U> ListIterator<Type>& operator +=(const U value);

        ListIterator<Type>& next();
        ListIterator<Type>& operator ++();
        ListIterator<Type> operator ++(int);
        difference_type operator-(const ListIterator<Type>&) const;

        value_type Current() const;
        explicit operator bool() const noexcept;
        reference operator *() const;
        pointer operator ->() const;

        auto operator <=>(const ListIterator<Type>&) const noexcept;
        bool operator ==(const ListIterator<Type>&) const noexcept;
        bool operator !=(const ListIterator<Type>&) const noexcept;

        [[nodiscard]] std::shared_ptr<Node<Type>> GetPtr() const noexcept { return cur_ptr.lock(); }
        [[nodiscard]] difference_type GetIndex() const noexcept { return this->index; }
};

static_assert(std::forward_iterator<ListIterator<int>>);

#include "ListIterator.inl"

